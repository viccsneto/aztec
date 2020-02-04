#include "Sensor.h"
#include "Config.h"
#include "ContactFilter.h"
#include "GameEngine.h"
namespace Aztec {
  void Sensor::init(float x, float y)
  {
    _className.assign("Sensor");
    Transform.position.set(x, y);
    _width   = 0.0f;
    _height  = 0.0f;
    _radius  = 0.0f;
    _fixture = NULL;
    _pointlist.clear();
    _body->SetUserData(this);
  }

  Sensor::Sensor(float x, float y, float w, float h) : GameObject()
  {
    init(x, y);
    _width  = w;
    _height = h;
    setPivot(_width / 2, _height / 2);
    createFixture(w, h);
  }

  Sensor::Sensor(float w, float h) : GameObject()
  {
    init(0, 0);
    _width  = w;
    _height = h;
    setPivot(_width / 2, _height / 2);
    createFixture(w, h);
  }

  Sensor::Sensor(float radius) : GameObject()
  {
    init(0, 0);
    _radius = radius;
    createFixture(radius);
  }

  Sensor::Sensor(void) : GameObject()
  {
    init(0, 0);
  }

  Sensor::Sensor(float x, float y, float radius) : GameObject()
  {
    init(x, y);
    _radius = radius;
    createFixture(radius);
  }

  Sensor::Sensor(PointList2D point_list)
  {
    init(0, 0);
    _pointlist = point_list;
    createFixture(point_list);
  }

  GameObject *Sensor::getTarget()
  {
    if (_parent != NULL) {
      return _parent;
    }
    return this;
  }

  void Sensor::createFixture(float radius)
  {
    _width  = 0.0f;
    _height = 0.0f;

    if (_fixture != NULL) {
      _body->DestroyFixture(_fixture);
      _fixture = NULL;
    }

    if (radius == 0) {
      return;
    }

    b2CircleShape circle;
    circle.m_p.Set(0, 0);
    circle.m_radius = (radius * (Transform.scale.x + Transform.scale.y) / 2) / Config::PHYSICS_PIXELS_METERS_RATIO;

    _fixture = _body->CreateFixture(&circle, 0);

    _fixture->SetSensor(true);
    setFilterData();
  }

  void Sensor::createFixture(float w, float h)
  {
    if (_fixture != NULL) {
      _body->DestroyFixture(_fixture);
      _fixture = NULL;
    }

    _radius = 0;
    _width  = w;
    _height = h;

    if ((w == 0) || (h == 0)) {
      return;
    }

    b2Vec2 vertices[4];

    float x1, x2;
    float y1, y2;

    x1 = 0;
    y1 = 0;

    x2 = ((_width * Transform.scale.x) / Config::PHYSICS_PIXELS_METERS_RATIO);
    y2 = ((_height * Transform.scale.y) / Config::PHYSICS_PIXELS_METERS_RATIO);

    x1 -= ((_pivot.x * Transform.scale.x) / Config::PHYSICS_PIXELS_METERS_RATIO);
    y1 -= ((_pivot.y * Transform.scale.y) / Config::PHYSICS_PIXELS_METERS_RATIO);

    x2 -= ((_pivot.x * Transform.scale.x) / Config::PHYSICS_PIXELS_METERS_RATIO);
    y2 -= ((_pivot.y * Transform.scale.y) / Config::PHYSICS_PIXELS_METERS_RATIO);

    vertices[0].Set(x1, y1);
    vertices[1].Set(x2, y1);
    vertices[2].Set(x2, y2);
    vertices[3].Set(x1, y2);

    b2PolygonShape rect;
    rect.Set(vertices, 4);

    _fixture = _body->CreateFixture(&rect, 0);

    _fixture->SetSensor(true);
    setFilterData();
    _body->SetUserData(this);
  }

  void Sensor::createFixture(PointList2D point_list)
  {
    vector<Vector2> list_of_vertices = point_list.getList();
    int             total_vertices   = list_of_vertices.size();

    if (total_vertices < 3) {
      GameEngine::getInstance()->registerWarning("Tried to create a polygon fixture with less than 3 vertices\n");
      return;
    }

    if (_fixture != NULL) {
      _body->DestroyFixture(_fixture);
      _fixture = NULL;
      _body->ResetMassData();
    }


    b2Vec2 *vertices = new b2Vec2[total_vertices];


    for (int i = 0; i < total_vertices; i++) {
      float x = list_of_vertices[i].x;
      float y = -list_of_vertices[i].y;

      x = (x * Transform.scale.x) / Config::PHYSICS_PIXELS_METERS_RATIO;
      y = (y * Transform.scale.y) / Config::PHYSICS_PIXELS_METERS_RATIO;
      x -= ((_pivot.x * Transform.scale.x) / Config::PHYSICS_PIXELS_METERS_RATIO);
      y -= ((_pivot.y * Transform.scale.y) / Config::PHYSICS_PIXELS_METERS_RATIO);
      vertices[i].Set(x, y);
    }


    b2PolygonShape poly;
    poly.Set(vertices, total_vertices);

    delete[] vertices;

    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &poly;

    _fixture = _body->CreateFixture(&myFixtureDef);

    _fixture->SetSensor(true);
    setFilterData();
    _body->SetUserData(this);
  }

  void Sensor::setFilterData()
  {
    setFilterData(ContactFilter::FilterFlags::Sensor, ContactFilter::FilterFlags::Mouse | ContactFilter::FilterFlags::Sensor);
  }
  void Sensor::setFilterData(int category_bits, int mask_bits)
  {
    b2Filter filter;
    filter.categoryBits = category_bits;
    filter.maskBits     = mask_bits;

    _fixture->SetFilterData(filter);
  }

  void Sensor::reScale()
  {
    GameObject::reScale();

    if (_width != 0 && _height != 0) {
      createFixture(_width, _height);
    }
    else if (_radius) {
      createFixture(_radius);
    }
    else if (_pointlist.getList().size() >= 3) {
      createFixture(_pointlist);
    }
    updateTransforms();
  }

  Sensor::~Sensor()
  {
  }

} // namespace Aztec