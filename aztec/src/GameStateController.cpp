#include "GameEngine.h"
#include "EventDispatcher.h"
#include "GameStateController.h"
#include "ResourceManager.h"
#include "PropertyManager.h"
#include "Config.h"
#include "Sprite.h"
#include "Sensor.h"
#include "PointList2D.h"
#include "Music.h"
#include "Sound.h"
#include <Tmx.h>
#include <iostream>
#include <vector>

namespace Aztec {
  GameStateController::GameStateController() : _tmx_path(NULL)
  {
    _className.assign("GameStateController");
    _amLoaded = false;
  }

  GameStateController::GameStateController(const char *tmx_path) : _tmx_path(strdup(tmx_path))
  {
    _className.assign("GameStateController");
    _amLoaded = false;
  }


  GameStateController::~GameStateController()
  {
    unload();
    tolua_release(GameEngine::LUA_STATE, this);
  }

  bool GameStateController::isLoaded()
  {
    return _amLoaded;
  }

  void GameStateController::parseTMX()
  {

    float        opacity              = 1.0f;
    unsigned int first_layer_zorder   = 0;
    unsigned int current_layer_zorder = 0;
    if (_tmx_path == NULL)
      return;

    for (int i = 0; i < strlen(_tmx_path); i++) {
      if (_tmx_path[i] == '\\')
        _tmx_path[i] = '/';
    }

    Tmx::Map *  tmx_map = new Tmx::Map();
    std::string path(_tmx_path);
    std::string directory = path;

    int pos = directory.find_last_of('/');

    if (pos != -1)
      directory.resize(pos);

    tmx_map->ParseFile(path);

    if (tmx_map->HasError()) {
      GameEngine::getInstance()->registerError("Couldn't load TMX file %s\n\t Tmx Error %d:%s\n", _tmx_path, tmx_map->GetErrorCode(), tmx_map->GetErrorText().c_str());
    }


    std::map<std::string, std::string> propertyList = tmx_map->GetProperties().GetList();
    setProperty("Width", std::to_string(tmx_map->GetWidth()).c_str());
    setProperty("Height", std::to_string(tmx_map->GetHeight()).c_str());
    for (std::map<std::string, std::string>::iterator i = propertyList.begin(); i != propertyList.end(); ++i) {
      setProperty(i->first.c_str(), i->second.c_str());
    }

    string background_color = tmx_map->GetBackgroundColor().ToString();

    GLfloat r = 0, g = 0, b = 0, a = 1;
    if (background_color.size() >= 7) {
      /*
        1 3 5 7
        012456789
        #AARRGGBB
        */
      a = std::stoul(background_color.substr(1, 2), nullptr, 16) / 255.0f;
      r = std::stoul(background_color.substr(3, 2), nullptr, 16) / 255.0f;
      g = std::stoul(background_color.substr(5, 2), nullptr, 16) / 255.0f;
      b = std::stoul(background_color.substr(7, 2), nullptr, 16) / 255.0f;
    }

    setClearColor(r, g, b, a);

    // The tmxparser library has an issue where the zorder of different map's layers is affected by previously loaded maps (i.e., if a first map with 5 layers has been open, then the layer 0 of the second tmx map will start at 5)
    if (tmx_map->GetNumLayers() > 0) {
      first_layer_zorder = tmx_map->GetLayers()[0]->GetZOrder();
      //printf("First layer zorder %u for %s\n", first_layer_zorder, _tmx_path);
    }

    for (int i = 0; i < tmx_map->GetNumImageLayers(); i++) {
      const Tmx::ImageLayer *imageLayer = tmx_map->GetImageLayer(i);
      opacity                           = imageLayer->GetOpacity();

      string tile_image_path = directory + "/" + imageLayer->GetImage()->GetSource();

      Sprite *tileImage = new Sprite((char *)tile_image_path.c_str());

      std::map<std::string, std::string> propertyList = imageLayer->GetProperties().GetList();
      for (std::map<std::string, std::string>::iterator i = propertyList.begin(); i != propertyList.end(); ++i) {
        tileImage->setProperty(i->first.c_str(), i->second.c_str());
      }

      tileImage->getPlane()->setColorBalance(1, 1, 1, opacity);
      current_layer_zorder = imageLayer->GetZOrder() - first_layer_zorder;
      add(tileImage, current_layer_zorder);
      GameObject *layer = _layers.find(current_layer_zorder)->second;
      layer->setProperty("Name", imageLayer->GetName().c_str());
      tileImage->getLayer()->Visible = imageLayer->IsVisible();
    }

    for (int i = 0; i < tmx_map->GetNumTileLayers(); i++) {
      const Tmx::TileLayer *tileLayer = tmx_map->GetTileLayer(i);

      if (!tileLayer->IsVisible())
        continue;

      opacity = tileLayer->GetOpacity();

      bool h_flipped       = false;
      bool v_flipped       = false;
      current_layer_zorder = tileLayer->GetZOrder() - first_layer_zorder;
      add(NULL, current_layer_zorder);
      for (int x = 0; x < tileLayer->GetWidth(); x++) {
        for (int y = 0; y < tileLayer->GetHeight(); y++) {
          int tileset_idx = tileLayer->GetTileTilesetIndex(x, y);
          if (tileset_idx == -1)
            continue;
          else {

            int                 tile_id       = tileLayer->GetTileId(x, y);
            int                 tileset_index = tileLayer->GetTileTilesetIndex(x, y);
            const Tmx::Tileset *tileset       = tmx_map->GetTileset(tileset_index);

            int image_width  = tileset->GetImage()->GetWidth();
            int image_height = tileset->GetImage()->GetHeight();

            int tile_margin  = tileset->GetMargin();
            int tile_spacing = tileset->GetSpacing();

            int tile_width  = tileset->GetTileWidth();
            int tile_height = tileset->GetTileHeight();

            int total_columns = image_width / tile_width;
            int total_rows    = image_height / tile_height;

            int tile_x_pos = tile_id % total_columns;
            int tile_y_pos = tile_id / total_columns;

            string tile_image_path = directory + "/" + tileset->GetImage()->GetSource();

            if (tileLayer->IsTileFlippedHorizontally(x, y)) {
              h_flipped = true;
            }

            if (tileLayer->IsTileFlippedVertically(x, y)) {
              v_flipped = true;
            }

            Sprite *         tileImage = new Sprite((char *)tile_image_path.c_str(), tile_width, tile_height);
            const Tmx::Tile *tmx_tile  = tileset->GetTile(tile_id);

            if (tmx_tile) {
              std::map<std::string, std::string> propertyList = tmx_tile->GetProperties().GetList();
              for (std::map<std::string, std::string>::iterator i = propertyList.begin(); i != propertyList.end(); ++i) {
                tileImage->setProperty(i->first.c_str(), i->second.c_str());
              }
            }

            tileImage->setProperty("TILE_X", std::to_string(x).c_str());
            tileImage->setProperty("TILE_Y", std::to_string(y).c_str());

            Animation *defaultAnimation = tileImage->newAnimation("default");

            if (tmx_tile && tmx_tile->IsAnimated()) {
              std::vector<Tmx::AnimationFrame> frames = tmx_tile->GetFrames();
              for (std::vector<Tmx::AnimationFrame>::iterator f = frames.begin(); f != frames.end(); ++f) {

                tile_x_pos = f->GetTileID() % total_columns;
                tile_y_pos = f->GetTileID() / total_columns;

                defaultAnimation->addFrame(tile_margin + (tile_x_pos * (tile_width + tile_spacing)), tile_margin + (tile_y_pos * (tile_height + tile_spacing)), f->GetDuration());
              }
            }
            else {
              defaultAnimation->addFrame(tile_margin + (tile_x_pos * (tile_width + tile_spacing)), tile_margin + (tile_y_pos * (tile_height + tile_spacing)), 100);
            }

            defaultAnimation->Loop = true;
            tileImage->setFlipped(h_flipped);
            tileImage->setVerticalFlipped(v_flipped);
            tileImage->getPlane()->setColorBalance(1, 1, 1, opacity);
            tileImage->Transform.position.set(x * tile_width, y * tile_height);
            add(tileImage, current_layer_zorder);
          }
        }
      }
      _layers.find(current_layer_zorder)->second->setProperty("Name", tileLayer->GetName().c_str());
    }


    // Iterate through all of the object groups.
    for (int i = 0; i < tmx_map->GetNumObjectGroups(); i++) {
      const Tmx::ObjectGroup *objectGroup = tmx_map->GetObjectGroup(i);
      current_layer_zorder                = objectGroup->GetZOrder() - first_layer_zorder;
      add(NULL, current_layer_zorder);
      // Iterate through all objects in the object group.
      for (int j = 0; j < objectGroup->GetNumObjects(); ++j) {
        // Get an object.
        const Tmx::Object *tmx_object = objectGroup->GetObject(j);
        GameObject *       object     = new GameObject();

        std::map<std::string, std::string> propertyList = objectGroup->GetProperties().GetList();
        for (std::map<std::string, std::string>::iterator i = propertyList.begin(); i != propertyList.end(); ++i) {
          object->setProperty(i->first.c_str(), i->second.c_str());
        }

        propertyList = tmx_object->GetProperties().GetList();
        for (std::map<std::string, std::string>::iterator i = propertyList.begin(); i != propertyList.end(); ++i) {
          object->setProperty(i->first.c_str(), i->second.c_str());
        }

        object->setProperty("Name", tmx_object->GetName().c_str());
        PointList2D point_list;

        const Tmx::Polygon *polygon = tmx_object->GetPolygon();
        if (polygon != NULL) {
          Sensor *tmx_sensor = new Sensor();
          for (int i = 0; i < polygon->GetNumPoints(); i++) {
            const Tmx::Point &point = polygon->GetPoint(i);
            point_list.add(point.x, point.y);
          }
          tmx_sensor->createFixture(point_list);
          object->addGameObject(tmx_sensor);
        }

        const Tmx::Ellipse *ellipse = tmx_object->GetEllipse();
        if (ellipse != NULL) {
          Sensor *tmx_sensor = new Sensor();
          int     radius     = max(ellipse->GetRadiusX(), ellipse->GetRadiusY());
          tmx_sensor->createFixture(radius);
          object->addGameObject(tmx_sensor);
          object->Transform.position.set(radius, radius);
        }
        // If there is no polygon or ellipse geometry, creates a rectangular sensor
        if (polygon == NULL && ellipse == NULL) {
          Sensor *tmx_sensor = new Sensor();
          tmx_sensor->createFixture(tmx_object->GetWidth(), tmx_object->GetHeight());
          object->addGameObject(tmx_sensor);
        }
        object->Transform.position.add(tmx_object->GetX(), tmx_object->GetY());
        object->Transform.rotation = tmx_object->GetRot();

        add(object, current_layer_zorder);
      }
      _layers.find(current_layer_zorder)->second->setProperty("Name", objectGroup->GetName().c_str());
    }

    delete tmx_map;
  }

  void GameStateController::setClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
  {
    _clearColor = glm::vec4(r, g, b, a);
  }
  void GameStateController::load()
  {
    if (!_amLoaded) {

#ifdef _DEBUG
      setClearColor(0.5f, 0.5f, 0.5f, 1.0f);
#else
      setClearColor(0.0f, 0.0f, 0.0f, 1.0f);
#endif
      __physicsUpdateAccumulator = 0.0f;
      _amLoaded                  = true;
      createPhysicalWorld();
      createMouseSensor();
      GameEngine::getInstance()->beginLoadGameState(this);
      _defaultCamera = new Camera();
      _activeCamera  = _defaultCamera;

      parseTMX();


      EventDispatcher::doOnLoad(this);
      GameEngine::getInstance()->endLoadGameState(this);
    }
  }

  void GameStateController::createMouseSensor()
  {
    b2BodyDef bodydef;
    bodydef.type       = b2BodyType::b2_kinematicBody;
    bodydef.allowSleep = false;
    bodydef.position.x = 0;
    bodydef.position.y = 0;
    _mouseBody         = _world->CreateBody(&bodydef);
    b2CircleShape circle;
    circle.m_radius = 0.01f;
    circle.m_p.x    = 0;
    circle.m_p.y    = 0;
    _mouseFixture   = _mouseBody->CreateFixture(&circle, 0);
    b2Filter filter;
    filter.categoryBits = ContactFilter::FilterFlags::Mouse;
    filter.maskBits     = ContactFilter::FilterFlags::Sensor | ContactFilter::FilterFlags::Text;
    _mouseFixture->SetSensor(true);
    _mouseFixture->SetFilterData(filter);
    _mouseBody->SetBullet(true);
    _mouseBody->SetUserData(new GameObject());
  }

  void GameStateController::destroyMouseSensor()
  {
    if (_mouseBody != NULL) {
      GameObject *mouseObject = (GameObject *)_mouseBody->GetUserData();
      if (mouseObject)
        delete mouseObject;
      _world->DestroyBody(_mouseBody);
      _mouseBody = NULL;
    }
  }

  void GameStateController::createPhysicalWorld()
  {
    b2Vec2 b;
    b.x = 0;
    b.y = 0;

    _debugDraw = new DebugDraw();
    _debugDraw->SetFlags(DebugDraw::e_shapeBit);
    _debugDraw->Create();
    _contactFilter = new ContactFilter();

    _world = new b2World(b);
    _world->SetDebugDraw(_debugDraw);
    _world->SetContactFilter(_contactFilter);

    _solver = new ContactSolver();
    _world->SetContactListener(_solver);
  }

  void GameStateController::destroyPhysicalWorld()
  {
    if (_world) {
      delete _world;
      _world = NULL;
    }

    if (_solver) {
      delete _solver;
      _solver = NULL;
    }

    if (_debugDraw) {
      _debugDraw->Destroy();
      delete _debugDraw;
      _debugDraw = NULL;
    }
  }

  void GameStateController::unload()
  {
    if (_tmx_path != NULL) {
      free(_tmx_path);
      _tmx_path = NULL;
    }

    destroyMouseSensor();
    delete _defaultCamera;
    for (multimap<int, GameObject *>::iterator i = _layers.begin(); i != _layers.end(); ++i) {
      delete i->second;
    }

    _layers.clear();

    EventDispatcher::doOnUnload(this);

    destroyPhysicalWorld();
    _amLoaded = false;
  }

  void GameStateController::draw()
  {
    for (multimap<int, GameObject *>::iterator i = _layers.begin(); i != _layers.end(); ++i) {
      i->second->draw();
    }
  }

  void GameStateController::step()
  {


    if (_activeCamera->getParent() == NULL) {
      _activeCamera->updateTransforms();
    }

    _mouseBody->SetTransform(b2Vec2(GameEngine::getInstance()->getMouse()->getPosX() / Config::PHYSICS_PIXELS_METERS_RATIO,
                                    GameEngine::getInstance()->getMouse()->getPosY() / Config::PHYSICS_PIXELS_METERS_RATIO),
                             0);

    OnUpdate();

    for (multimap<int, GameObject *>::iterator i = _layers.begin(); i != _layers.end(); ++i) {
      i->second->step();
    }
    updatePhysics();
    //CefDoMessageLoopWork();
  }

  GameObject *GameStateController::getLayer(unsigned int layer_id)
  {
    multimap<int, GameObject *>::iterator i = _layers.find(layer_id);
    // layer does not exists, so create it
    GameObject *layer = NULL;

    if (i != _layers.end())
      layer = i->second;
    return layer;
  }

  GameObject *GameStateController::add(GameObject *object)
  {
    return add(object, 0);
  }

  GameObject *GameStateController::add(GameObject *object, unsigned int layer_id)
  {

    GameObject *layer = getLayer(layer_id);

    if (layer == NULL) {
      layer = new GameObject();
      layer->setLayerID(layer_id);
      _layers.insert(pair<int, GameObject *>(layer_id, layer));
    }

    layer->addGameObject(object);

    return object;
  }

  void GameStateController::removeLayerReference(unsigned int layer_id)
  {
    multimap<int, GameObject *>::iterator i = _layers.find(layer_id);

    // layer does not exists, so can't remove it's reference
    if (i != _layers.end())
      _layers.erase(i);
  }

  GameObject *GameStateController::remove(GameObject *object, unsigned int layer_id)
  {
    if (object == NULL) {
      return NULL;
    }
    multimap<int, GameObject *>::iterator i = _layers.find(layer_id);

    // layer does not exists, so can't remove the object
    if (i == _layers.end()) {
      return NULL;
    }

    GameObject *layer = _layers.find(layer_id)->second;

    if (object->getParent() == layer) {
      object->setParent(NULL);
    }

    return object;
  }

  GameObject *GameStateController::addOverlay(GameObject *object)
  {
    return add(object, OVERLAY);
  }

  GameObject *GameStateController::removeOverlay(GameObject *object)
  {
    return remove(object, OVERLAY);
  }

  GameObject *GameStateController::addBackDrops(GameObject *object)
  {
    return add(object, BACKDROPS);
  }

  GameObject *GameStateController::removeBackDrops(GameObject *object)
  {
    return remove(object, BACKDROPS);
  }


  GameObject *GameStateController::addTile(GameObject *object)
  {
    return add(object, TILE);
  }

  GameObject *GameStateController::removeTile(GameObject *object)
  {
    return remove(object, TILE);
  }

  void GameStateController::stop()
  {
    EventDispatcher::doOnStop(this);
  }

  void GameStateController::start()
  {
    load();
    GameEngine::getInstance()->getGameCanvas()->setClearColor(_clearColor.r, _clearColor.g, _clearColor.b, _clearColor.a);

    EventDispatcher::doOnStart(this);
  }

  b2World *GameStateController::getWorld()
  {
    return _world;
  }

  void GameStateController::setActiveCamera(Camera *camera)
  {
    if (camera == NULL) {
      _activeCamera = _defaultCamera;
    }
    else {
      _activeCamera->Enabled = false;
      _activeCamera->getBody()->SetActive(false);
      _activeCamera = camera;
    }
    _activeCamera->Enabled = true;
    _activeCamera->getBody()->SetActive(true);
  }

  Camera *GameStateController::getActiveCamera()
  {
    return _activeCamera;
  }

  EventHandler GameStateController::OnLoad()
  {
    lua_getglobal(GameEngine::LUA_STATE, "EventDispatcher");
    lua_getfield(GameEngine::LUA_STATE, -1, "OnLoad");
    tolua_pushusertype(GameEngine::LUA_STATE, this, "GameStateController");

    if (lua_pcall(GameEngine::LUA_STATE, 1, 0, 0) != 0) {
      lua_State *L = GameEngine::LUA_STATE;
      GameEngine::getInstance()->registerError("LUA: %s - <%s [%d]>", lua_tostring(GameEngine::LUA_STATE, -1), __FILE__, __LINE__);
    }

    lua_pop(GameEngine::LUA_STATE, 1);
  }

  EventHandler GameStateController::OnUnload()
  {
    lua_getglobal(GameEngine::LUA_STATE, "EventDispatcher");
    lua_getfield(GameEngine::LUA_STATE, -1, "OnUnload");
    tolua_pushusertype(GameEngine::LUA_STATE, this, "GameStateController");

    if (lua_pcall(GameEngine::LUA_STATE, 1, 0, 0) != 0) {
      GameEngine::getInstance()->registerError("LUA: %s - <%s [%d]>", lua_tostring(GameEngine::LUA_STATE, -1), __FILE__, __LINE__);
    }

    lua_pop(GameEngine::LUA_STATE, 1);
  }

  EventHandler GameStateController::OnStart()
  {
    lua_getglobal(GameEngine::LUA_STATE, "EventDispatcher");
    lua_getfield(GameEngine::LUA_STATE, -1, "OnStart");
    tolua_pushusertype(GameEngine::LUA_STATE, this, "GameStateController");

    if (lua_pcall(GameEngine::LUA_STATE, 1, 0, 0) != 0) {
      GameEngine::getInstance()->registerError("LUA: %s - <%s [%d]>", lua_tostring(GameEngine::LUA_STATE, -1), __FILE__, __LINE__);
    }

    lua_pop(GameEngine::LUA_STATE, 1);
  }

  EventHandler GameStateController::OnStop()
  {
    lua_getglobal(GameEngine::LUA_STATE, "EventDispatcher");
    lua_getfield(GameEngine::LUA_STATE, -1, "OnStop");
    tolua_pushusertype(GameEngine::LUA_STATE, this, "GameStateController");

    if (lua_pcall(GameEngine::LUA_STATE, 1, 0, 0) != 0) {
      GameEngine::getInstance()->registerError("LUA: %s - <%s [%d]>", lua_tostring(GameEngine::LUA_STATE, -1), __FILE__, __LINE__);
    }

    lua_pop(GameEngine::LUA_STATE, 1);
  }

  EventHandler GameStateController::OnUpdate()
  {
    if (!(this->EventFlags & EventTypes::OnUpdate)) {
      return;
    }


    lua_getglobal(GameEngine::LUA_STATE, "EventDispatcher");
    lua_getfield(GameEngine::LUA_STATE, -1, "OnGameStateControllerUpdate");
    tolua_pushusertype(GameEngine::LUA_STATE, this, "GameStateController");

    if (lua_pcall(GameEngine::LUA_STATE, 1, 0, 0) != 0) {
      GameEngine::getInstance()->registerError("LUA: %s - <%s [%d]>", lua_tostring(GameEngine::LUA_STATE, -1), __FILE__, __LINE__);
    }

    lua_pop(GameEngine::LUA_STATE, 1);
  }

  EventHandler GameStateController::OnKeyDown(int keyCode)
  {
    lua_getglobal(GameEngine::LUA_STATE, "EventDispatcher");
    lua_getfield(GameEngine::LUA_STATE, -1, "OnKeyDown");
    tolua_pushusertype(GameEngine::LUA_STATE, this, "GameStateController");
    tolua_pushnumber(GameEngine::LUA_STATE, keyCode);

    if (lua_pcall(GameEngine::LUA_STATE, 2, 0, 0) != 0) {
      GameEngine::getInstance()->registerError("LUA: %s - <%s [%d]>", lua_tostring(GameEngine::LUA_STATE, -1), __FILE__, __LINE__);
    }

    lua_pop(GameEngine::LUA_STATE, 1);
  }
  EventHandler GameStateController::OnKeyUp(int keyCode)
  {
    lua_getglobal(GameEngine::LUA_STATE, "EventDispatcher");
    lua_getfield(GameEngine::LUA_STATE, -1, "OnKeyUp");
    tolua_pushusertype(GameEngine::LUA_STATE, this, "GameStateController");
    tolua_pushnumber(GameEngine::LUA_STATE, keyCode);

    if (lua_pcall(GameEngine::LUA_STATE, 2, 0, 0) != 0) {
      GameEngine::getInstance()->registerError("LUA: %s - <%s [%d]>", lua_tostring(GameEngine::LUA_STATE, -1), __FILE__, __LINE__);
    }

    lua_pop(GameEngine::LUA_STATE, 1);
  }

  EventHandler GameStateController::OnMouseDown(int button)
  {
    lua_getglobal(GameEngine::LUA_STATE, "EventDispatcher");
    lua_getfield(GameEngine::LUA_STATE, -1, "OnMouseDown");
    tolua_pushusertype(GameEngine::LUA_STATE, this, "GameStateController");
    tolua_pushnumber(GameEngine::LUA_STATE, button);
    if (lua_pcall(GameEngine::LUA_STATE, 2, 0, 0) != 0) {
      GameEngine::getInstance()->registerError("LUA: %s - <%s [%d]>", lua_tostring(GameEngine::LUA_STATE, -1), __FILE__, __LINE__);
    }

    lua_pop(GameEngine::LUA_STATE, 1);
  }

  EventHandler GameStateController::OnMouseMove()
  {
    lua_getglobal(GameEngine::LUA_STATE, "EventDispatcher");
    lua_getfield(GameEngine::LUA_STATE, -1, "OnGameStateControllerMouseMove");
    tolua_pushusertype(GameEngine::LUA_STATE, this, "GameStateController");
    tolua_pushusertype(GameEngine::LUA_STATE, GameEngine::getInstance()->getMouse(), "Mouse");

    if (lua_pcall(GameEngine::LUA_STATE, 2, 0, 0) != 0) {
      GameEngine::getInstance()->registerError("LUA ERROR: %s", lua_tostring(GameEngine::LUA_STATE, -1));
    }

    lua_pop(GameEngine::LUA_STATE, 1);
  }

  EventHandler GameStateController::OnMouseUp(int button)
  {
    lua_getglobal(GameEngine::LUA_STATE, "EventDispatcher");
    lua_getfield(GameEngine::LUA_STATE, -1, "OnMouseUp");
    tolua_pushusertype(GameEngine::LUA_STATE, this, "GameStateController");
    tolua_pushnumber(GameEngine::LUA_STATE, button);

    if (lua_pcall(GameEngine::LUA_STATE, 2, 0, 0) != 0) {
      GameEngine::getInstance()->registerError("LUA: %s - <%s [%d]>", lua_tostring(GameEngine::LUA_STATE, -1), __FILE__, __LINE__);
    }

    lua_pop(GameEngine::LUA_STATE, 1);
  }

  void GameStateController::updatePhysics()
  {
    /**
  if (__physicsUpdateAccumulator < 0.0f)
    __physicsUpdateAccumulator = 0.0f;
  /**/
    __physicsUpdateAccumulator += GameEngine::getInstance()->getElapsedTime();


    do {
      __physicsUpdateAccumulator -= Config::PHYSICS_TIME_STEP;
      _world->Step(Config::PHYSICS_TIME_STEP, Config::PHYSICS_VELOCITY_ITERATIONS, Config::PHYSICS_POSITION_ITERATIONS);
    } while (__physicsUpdateAccumulator >= Config::PHYSICS_TIME_STEP);
  }

  const char *GameStateController::setProperty(const char *property, const char *value)
  {
    return m_property_list.set(property, value);
  }

  const char *GameStateController::getProperty(const char *property)
  {
    return m_property_list.get(property);
  }

  void GameStateController::removeProperty(const char *property)
  {
    m_property_list.remove(property);
  }

  void GameStateController::clearProperties()
  {
    m_property_list.clear();
  }

  const char *GameStateController::propertyAt(unsigned int index)
  {
    return m_property_list.at(index);
  }

  const char *GameStateController::getPropertyName(unsigned int index)
  {
    return m_property_list.getName(index);
  }

  bool GameStateController::hasProperty(const char *property)
  {
    return m_property_list.has(property);
  }


  unsigned int GameStateController::getPropertyCount()
  {
    return m_property_list.getSize();
  }

  GameObjectList *GameStateController::queryProperty(const char *property)
  {
    return PropertyManager::getInstance()->query(this, property);
  }

  GameObjectList *GameStateController::queryProperty(const char *property, const char *value)
  {
    return PropertyManager::getInstance()->query(this, property, value);
  }

} // namespace Aztec
