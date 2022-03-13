-------------------------------------------
-- This module implements mechanisms to control the GameStates execution and transitions 
-------------------------------------------

scene_controller = {
  scenes = {
  }
}

-- Creates a scene 
--    tmx_path: Path to a TMX(Tiled Map) resource
--    scene_name: A string representing the scene name
function scene_controller:create (tmx_path, scene_name)

  -- Creates a GameStateController based on the TMX resource Path
  local state = GameStateController:new(tmx_path)
  
  -- Sets its name
  state.scene_name = scene_name
  
  -- Puts the new scene to the list of controlled scenes
  scene_controller.scenes[scene_name] = state
  
  -- Event that occurs when a GameStateController is loaded     
  function state:OnLoad(state)
    
    -- Get the list of spawner objects        
    local spawner_list = state:queryProperty("Spawn")
    
    -- Replaces each spawner of the list with the corresponding object 
    while (spawner_list:hasNext()) do
      local spawner = spawner_list:next()           
      local entity_name = spawner:getProperty("Name")
      spawner:setProperty("Name", entity_name.."_old_spawner")
      local layer_id = spawner:getLayerID()
      local spawned = spawn(entity_name, layer_id)      
      
      for i = 1, spawner:getPropertyCount() do
        local property_name = spawner:getPropertyName(i-1)
        if (property_name ~= "Spawn" and property_name ~= "Name") then
          local property_value = spawner:propertyAt(i-1)
          spawned:setProperty(property_name, property_value)    
        end 
      end
      
      spawned.Transform.position:set(spawner.Transform.position.x, spawner.Transform.position.y)
      spawner:destroy()            
    end   
    
    -- Gets the list of Label objects
    local label_list = state:queryProperty("Label")    
    
    -- Creates a Text GameObject with the corresponding Label and associates it with the Label object  
    while (label_list:hasNext()) do
      local object = label_list:next()
      local label_text = object:getProperty("Label")  
      object.label_object = object:addGameObject(Text:new(255,255,255,"fonts/default.ttf", 18))      
      object.label_object.Transform.position:set(-(string.len(label_text) / 2) * 10 , -50)      
      object.label_object:setZOrder(100)
      object.label_object:setText(label_text)            
      object.label_object.Visible = false
    end  
    
    -- Tries to get the Music property of the map
    local music_path = state:getProperty("Music")
    
    -- if there is a Music property
      if (music_path ~= nil) then  
        -- Intantiates the Music resource and associates it with the state         
        state.Music = Music:new("assets/music/"..music_path)
        state.Music:setVolume(0.25)
      end
    -- creates the quest lists window
    state:add(quest_controller:create(), 1000000)
    -- Repasses the OnLoad event to an user defined SceneLoad event, if there is one
    if (state.SceneLoad ~= nil) then
      state:SceneLoad(state)
    end
  end
  
  -- Plays the state Music
  function state:play_music()
    if (state.Music ~= nil) then
      if(not state.Music:isPlaying()) then
        state.Music:Play()
      end
    end
  end
  
    -- Stops the state Music
  function state:stop_music()
    if (state.Music ~= nil) then
      if(state.Music:isPlaying()) then
        state.Music:Stop()
      end
    end
  end
    
    
  -- Fade in Effect
  function state:fade_in()
  
    state:getActiveCamera():setColorBalance(0, 0, 0, 1.0)
    state.timer = timer_controller:create(0.0001)
    
    function state.timer:oncreate()    
      state.player = maincharacter()
       
    
      if (state.player ~= nil) then        
        state.player:set_can_control(false)
      end
    end      
     
    
    state:add(state.timer,0)    
    state.timer.step = 0    
    state.timer.max = 100
    
    
    function state.timer:timeout(sender)
      sender.step = sender.step + 1            
      if (sender.step < state.timer.max ) then
        sender:reset()
      else
        state.player = maincharacter()
        if (state.player ~= nil) then        
          state.player:set_can_control(true)
        end
        sender:destroy()
      end
    end
    
    function state.timer:update(sender)
      local balance_value = (sender.step / sender.max)
      state:getActiveCamera():setColorBalance(balance_value, balance_value, balance_value, 1.0)
    end
  end
  
  -- Fade out Effect
  
  function state:fade_out(scene)
    local state = self
    
    state:getActiveCamera():setColorBalance(1,1,1,1)

    state.timer = state:add(timer_controller:create(0.005),0)
    state.timer.step = 0
    state.timer.max = 25
      
    state.player = maincharacter() 
    
    if (state.player ~= nil) then        
      state.player:set_can_control(false)
    end
    
    function state.timer:update(sender)
      state:getActiveCamera():setColorBalance(1,1,1,1 - (sender.step / sender.max))
    end
    
    function state.timer:timeout(sender)
      sender.step = sender.step + 1            
      if (sender.step < state.timer.max ) then
        sender:reset()
      else
        state.player = maincharacter()
        if (state.player ~= nil) then
          state.player:set_can_control(true)
        end
        sender:destroy()
        engine:run(scene)
      end
    end
  end
  
  -- Event that occurs when the state starts to run 
  function state:OnStart(state)
    state.player = maincharacter()
    if (state.player) then
      set_camera_position(state.player.Transform.position.x, state.player.Transform.position.y,true)
      
      -- Tries to get a startup_object from the map
      local place_obj = queryname(state.startup_object_name)
      
      -- If there is such place_obj
      if (place_obj ~= nil) then      
        -- Moves the main player to the place_obj position
        
        if (state.player ~= nil) then
          state.player:to_place(place_obj)
          state.player:face_direction(state.startup_face_direction.x,state.startup_face_direction.y)               
        end
      else
        print(state.startup_object_name.." not found...")      
      end
    end
    -- Executes a FadeIn effect to indicate the transition
    state:fade_in()  
        
    -- Starts playing the state theme music    
    state:play_music()    
    
    -- Cleans the keyboard buffer (prevents unwanted interaction)
    keyboard:cleanBuffer()
    
    --Cleans any action that might be associated with the player 
    if (state.player ~=nil) then
      state.player:clean_action()
    end    
    
    -- Repasses the OnStart event to an user defined SceneStart event, if there is one
    if (state.SceneStart ~= nil) then
      state:SceneStart(state)
    end
  end
  
  -- Executes the scene
  function state:run()
    scene_controller:run(state.scene_name)
  end
    
  return state
end

-- Executes a scene and sets the place and initial facing direction of the main character
function scene_controller:run (scene_name, place, face_x, face_y)
  
  local scene = scene_controller.scenes[scene_name]
  
  if (scene == nil) then
    error("There is no scene named "..scene_name.." in the scene controller")
    return
  else
    
    if (place ~= nil) then 
      scene.startup_object_name =  place
      scene.startup_face_direction =  {x = face_x, y = face_y}           
    end
    
    -- Gets the active scene
    local current_state = engine:getCurrentGameState()
    
    -- If there is one, then Fades out to the new active scene    
    if (current_state ~= nil) then
      current_state:fade_out(scene)
    else -- otherwise just executes the new scene
      engine:run(scene)
    end   
  end
end