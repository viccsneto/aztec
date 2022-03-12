-------------------------------------------
-- This module implements mechanisms to control player-characters and NPCs( non-player-characters)
-- states and actions
-- @type character_controller

local MOVE_THRESHOLD = 2
local ATTACK_THRESHOLD = 5
local SENSOR_SIDE_MARGIN = 5

character_controller = {
  __global_stats = {}  
}

---
-- Creates a character controller
-- @param self 
-- @param #string entity_name The name of the entity
-- @param #Sprite entity_sprite The sprite gameobject, usually an animated sprite that represents visually the character in the scene
-- @param #number  sensor_side_length The length of the side of the character rectangular sensor (used to detect collision and interaction)
-- @param #number  sensor_y_offset The vertical offset position of the sensor in relation to the sprite body (usually it should be at its feet)
-- @param #boolean   npc determines if the character is not really a character but a non-player-character (NPC) controlled by the computer
-- @return #character The character instance
function character_controller:create (entity_name, entity_sprite, sensor_side_length, sensor_y_offset, npc)

  ---
  -- @type  character       
  local character = GameObject:new()

     
  character.blocked_sensor = character:addGameObject(AutoSensor:new(sensor_side_length, sensor_side_length))
  character.blocked_sensor.Transform.position:set(0, sensor_y_offset)
  character.sensor = character:addGameObject(Sensor:new(sensor_side_length + SENSOR_SIDE_MARGIN, sensor_side_length + SENSOR_SIDE_MARGIN))
  character.sensor.Transform.position:set(0, sensor_y_offset)

  -- Private fields
  character.__private = {
    entity_name = entity_name,
    last_action_command = 0,
    last_toggle_minimap = 0,
    last_toggle_questlist = 0,
    action_script = nil,
    auto_action_script = nil,
    sprite = nil,
    has_collided = false,
    z_order = 0,
    can_control = true,
    speed = 140,
    run_factor = 1.7,
    alignment = 16,
    tile_size = 32,
    action_interval = 0.25,
    ignore_blocked_places = false,
    last_direction = {
      x = 0,
      y = 0,
    },
    last_position = {
      x = 0,
      y = 0,
    },
    sensor_y_offset = sensor_y_offset,
    is_npc = npc,
    camera_follow = not npc,

    -- Battle stats
    party_id = 1,
    target_id = 1,

    party = nil,
    target_party = nil,
   
    battle_controller = nil

  }
  
   
  
  character_controller.__global_stats[entity_name] = character_controller.__global_stats[entity_name] and character_controller.__global_stats[entity_name] or
  { 
    max_hp = 100,
    current_hp = 100,
    max_mp = 20,
    current_mp = 20,
    battle_speed   =  1,
    battle_attack  =  1,
    battle_defense =  1,
    battle_hit     =  80,
    battle_gauge = 0,
  } 
  
  function character:get_last_position()
    return self.__private.last_position
  end
  
  function character:set_last_position(x, y)
    self.__private.last_position = {x = x, y = y};
  end
  
  function character:get_battle_position()
    return self.__private.battle_position
  end
  
  function character:set_battle_position(x, y)
    self.__private.battle_position = {x = x, y = y};
  end
  
  -- makes this the main sprite
  function character:set_maincharacter()
    local old_maincharacter = maincharacter()
    if (old_maincharacter) then
      old_maincharacter:removeProperty("main_character")
      old_maincharacter:set_npc(true)
    end
    self:setProperty("main_character", "true")
    self:set_npc(false)
  end
  
  

  -- Toggles the minimap visibility
  function character:toggle_minimap()
    local current_time = engine:getCurrentTime()
    if (current_time - character.__private.last_toggle_minimap < character.__private.action_interval) then
      return
    end
    character.__private.last_toggle_minimap = current_time

    local minimap = queryname("minimap")
    if (minimap ~= nil) then
      minimap.Visible = not minimap.Visible
    end
  end

  -- Toggles questlist visibility
  function character:toggle_questlist()
    local current_time = engine:getCurrentTime()
    if (current_time - character.__private.last_toggle_questlist < character.__private.action_interval) then
      return
    end
    character.__private.last_toggle_questlist = current_time
    
    quest_controller:toggle_visibility()
    
  end

  -- Changes the facing direction of the sprite based on the given coordinates:
  --  x: negative values make the sprite face left, positive values make the sprite face right (it is overridden when y is different of 0)
  --  y: negative values make the sprite face up, positive values make the sprite face down
  function character:face_direction(x, y)
    character.__private.last_direction.x = x
    character.__private.last_direction.y = y
    character:move(0, 0, false, false)
  end

  -- Changes the NPC(Non-Player-Character) status of a character
  --  npc: true indicates that the character cannot be controlled by user input. (probably it will be controlled by the computer)
  --       false indicates that the character input will control the entity
  function character:set_npc(npc)
    character.__private.is_npc = npc
    character:set_ignore_blocked_places(npc)
    character:set_camera_follow(not npc)
    character:set_can_control(not npc)
  end

  -- Indicates if the entity is a Non character sprite (controlled by the computer)
  function character:get_npc()
    return character.__private.is_npc
  end

  -- Places the entity in the given object location (position and layer)
  function character:to_place(place_obj)
    if (type(place_obj) == "string") then
      place_obj = queryname(place_obj)
    end
    
    if (place_obj ~= nil) then      
      character.Transform.position:set(place_obj.Transform.position.x, place_obj.Transform.position.y - character.__private.sensor_y_offset)
      place_obj:getLayer():addGameObject(character)
    end
  end


  -- Gets the sprite component of the entity
  function character:get_sprite()
    return character.__private.sprite
  end

  -- Sets the sprite component of the entity
  function character:set_sprite(sprite)
    if (character.__private.sprite ~= nil) then
      removeGameObject(character.__private.sprite)
      character.__private.sprite = nil
    end

    character.__private.sprite = sprite

    if (character.__private.sprite ~= nil) then
      character.__private.sprite.Transform.position:set(0, 0)
      character:addGameObject(character.__private.sprite)
    end
  end

  -- Gets the entity base moving speed (in pixels per second)
  function character:get_speed()
    return character.__private.speed
  end

  -- Sets the entity base moving speed (in pixels per second)
  function character:set_speed(speed)
    character.__private.speed = speed
  end

  
  -- Gets the entity battle_name
  function character:get_battle_name()
    return character.__private.battle_name and character.__private.battle_name or character:getProperty("Name")
  end

  -- Sets the entity battle name
  function character:set_battle_name(battle_name)
    character.__private.battle_name = battle_name
  end

  
  -- Sets the entity party
  function character:set_party(party)
    character.__private.party = party
  end

  -- Gets the entity party
  function character:get_party()
    return character.__private.party
  end

  -- Sets the entity party id
  function character:set_party_id(party_id)
    character.__private.party_id = party_id
  end

  -- Gets the entity party id
  function character:get_party_id()
    return character.__private.party_id
  end


  -- Sets the entity target party
  function character:set_target_party(target_party)
    character.__private.target_party = target_party
  end

  -- Gets the entity target party
  function character:get_target_party()
    return character.__private.target_party
  end

  -- Sets the entity target id
  function character:set_target_id(target_id)
    character.__private.target_id = target_id
  end

  -- Gets the entity target id
  function character:get_target_id()
    return character.__private.target_id
  end

  -- Gets the entity battle_gauge
  function character:get_battle_ready()
    return self:get_battle_gauge() == 100 and not self:get_battle_controller():get_queue():entity_has_action(self)
  end

  -- Sets the entity battle_gauge
  function character:set_battle_gauge(battle_gauge)    
    character_controller.__global_stats[self.__private.entity_name].battle_gauge = battle_gauge
  end

  -- Gets the entity battle_gauge
  function character:get_battle_gauge()
    return character_controller.__global_stats[self.__private.entity_name].battle_gauge
  end

  -- Gets the entity base battle speed
  function character:get_battle_speed()
    return character_controller.__global_stats[self.__private.entity_name].battle_speed
  end

  -- Sets the entity base battle speed
  function character:set_battle_speed(battle_speed)
    character_controller.__global_stats[self.__private.entity_name].battle_speed = round(battle_speed)
  end


  -- Gets the entity inflinged damage
  function character:calculate_damage()                                               
    local damage = round((self:get_battle_attack() * ((100 - math.random() * 15) / 100)))
    return damage
  end

  -- Gets the entity base battle attack
  function character:get_battle_attack()
    return character_controller.__global_stats[self.__private.entity_name].battle_attack
  end

  -- Sets the entity base battle attack
  function character:set_battle_attack(battle_attack)
    character_controller.__global_stats[self.__private.entity_name].battle_attack = round(battle_attack)
  end
  
    -- Gets the entity base battle hit chance
  function character:get_battle_hit()
    return character_controller.__global_stats[self.__private.entity_name].battle_hit
  end

  -- Sets the entity base battle hit chance
  function character:set_battle_hit(battle_hit)
    character_controller.__global_stats[self.__private.entity_name].battle_hit = round(battle_hit)
  end
  

  -- Gets the entity base battle defense
  function character:get_battle_defense()
    return character_controller.__global_stats[self.__private.entity_name].battle_defense
  end

  -- Sets the entity base battle defense
  function character:set_battle_defense(battle_defense)
    character_controller.__global_stats[self.__private.entity_name].battle_defense = round(battle_defense)
  end

  -- Gets the entity max_hp
  function character:get_max_hp()
    return character_controller.__global_stats[self.__private.entity_name].max_hp
  end

  -- Sets the entity base max_hp
  function character:set_max_hp(max_hp)
    character_controller.__global_stats[self.__private.entity_name].max_hp = round(max_hp)
  end


  -- Gets the entity max_mp
  function character:get_max_mp()
    return character_controller.__global_stats[self.__private.entity_name].max_mp
  end

  -- Sets the entity max_mp
  function character:set_max_mp(max_mp)
    character_controller.__global_stats[self.__private.entity_name].max_mp = round(max_mp)
  end

  -- Gets the entity current_hp
  function character:get_current_hp()
    return character_controller.__global_stats[self.__private.entity_name].current_hp
  end

  -- Sets the entity current_hp
  function character:set_current_hp(current_hp)
    character_controller.__global_stats[self.__private.entity_name].current_hp = math.max(0, math.min(current_hp , self:get_max_hp()))
  end

  -- Applies Damage
  function character:apply_damage(damage)    
    self:set_current_hp(self:get_current_hp() - damage)    
    print(self:get_battle_name().. " suffers "..damage.. " damage and now has "..self:get_current_hp().."hp")
  end
  
   -- Gets the entity KOed status
  function character:get_koed()
    return self:get_current_hp() == 0
  end
    
  -- Gets the entity current_mp
  function character:get_current_mp()
    return character_controller.__global_stats[self.__private.entity_name].current_mp
  end

  -- Sets the entity current_mp
  function character:set_current_mp(current_mp)
    character_controller.__global_stats[self.__private.entity_name].current_mp = round(current_mp)
  end
  
  function character:show_label(text, color, interval)
    if (type(interval) ~= "number") then
      interval = 1
    end    
    timer = self:get_sprite():addGameObject(timer_controller:create(interval))
    
    timer.label = self:addGameObject(Text:new(color.r, color.g, color.b, "fonts/default.ttf", 16 ))
    timer.label:setText(text)
    timer.label.Transform.position:set(-string.len(text) * 5, -30)
    
    function timer:update()
      local new_y = math.max(self.label.Transform.position.y - engine:getElapsedTime() * 25, -50);
      self.label.Transform.position.y = new_y
    end
    function timer:timeout()
      self.label:destroy()
      self:destroy()
    end     
  end
  
  function character:show_white_label(text, interval)    
      self:show_label(text, {r = 255, g = 255, b = 255}, interval)
  end

  function character:show_green_label(text, interval)    
      self:show_label(text, {r = 0, g = 255, b = 0}, interval)
  end
  
  function character:show_red_label(text, interval)    
      self:show_label(text, {r = 255, g = 0, b = 0}, interval)
  end

  -- Applies Cure
  function character:apply_cure(cure)
    self:show_green_label(cure, 1.5)
    print(self:get_battle_name().. " received "..cure.. " of HP")
    self:set_current_hp(self:get_current_hp() + cure)
  end

  -- Sets if the entity can be controlled by user input
  --    sometimes, even character sprites must be controlled by the computer or, at least, not controlled by user input temporarilly
  function character:set_can_control(can_control)
    self.__private.can_control = can_control
  end

  -- Indicates if the entity can be controlled by user input
  function character:get_can_control()
    return self.__private.can_control
  end

  -- Sets if the active camera must follow the entity (very handy for the map navigation)
  function character:set_camera_follow(follow)
    self.__private.camera_follow = follow
  end

  -- Indicates if the main camera must follow this entity
  function character:get_camera_follow()
    return self.__private.camera_follow
  end

  -- Moves the sprite in a direction
  --    x: The horizontal component of the direction
  --    y: The verticla component of the direction
  --    run: when true, the entity will run instead of walk
  --    walk: when true, the entity will walk slower than usual
  function character:move (x, y, run, calmly)

    local sprite = self.__private.sprite

    -- If there is no sprite to be controlled
    if (sprite == nil) then
      return false
    end

    -- Gets the base speed of the entity
    local speed = self.__private.speed

    -- If running, multiply the base speed by run_factor
    if (run) then
      speed = speed * self.__private.run_factor
    elseif (calmly) then -- If calmly, divide the base speed by run_factor
      speed = speed / self.__private.run_factor
    end


    -- Gets the current animation of the sprite
    local animation = sprite:getCurrentAnimation()

    --  If the entity is not moving, sets an idle animation
    if (x == 0 and y == 0) then
      -- If the is not in a battle
      if (not self:get_in_battle()) then
        if (character.__private.last_direction.y < 0 ) then -- character last movement was facing up
          animation = sprite.idle_up_animation
        elseif (self.__private.last_direction.y > 0 ) then -- character last movement was facing down
          animation = sprite.idle_down_animation
        else
          animation = sprite.idle_side_animation
          sprite:setFlipped(self.__private.last_direction.x < 0 ) -- if the last movement was facing left, then flips the sprite horizontally
        end

      end
    else -- The entity is moving

      -- Adjusts the destination position to match aligment (default to tile_size / 2)
      local destination_x =  (round(self.Transform.position.x / self.__private.alignment)) + x
      local destination_y =  (round(self.Transform.position.y / self.__private.alignment)) + y

      self.__private.last_direction.x = x
      self.__private.last_direction.y = y

      -- Choose animation and flip status of the sprite corresponding to the movement
      if (y < 0) then
        animation = run and sprite.run_up_animation or sprite.walk_up_animation
        sprite:setFlipped(false)
      elseif (y > 0) then
        animation = run and sprite.run_down_animation or sprite.walk_down_animation
        sprite:setFlipped(false)
      elseif (x < 0) then
        animation = run and sprite.run_side_animation or sprite.walk_side_animation
        sprite:setFlipped(true)
      elseif (x > 0) then
        animation = run and sprite.run_side_animation or sprite.walk_side_animation
        sprite:setFlipped(false)
      end

      -- Deslocate the entity based on the speed and elapsed time (the maximum elapsed time will be restricted to 1.0/60 seconds by the native engine)
      -- Basing the movement in the elapsed time prevents the movement to be clock dependent (i.e. faster in better computers, slower in worse computers)
      local elapsed = engine:getElapsedTime()
      self.Transform.position:set(self.Transform.position.x + x * speed * elapsed,self.Transform.position.y + y * speed * elapsed)
    end

    -- If the animation is different of the current one, then updates it
    if (animation ~= sprite:getCurrentAnimation()) then
      sprite:setAnimation(animation)
    end


    return true
  end

  -- Cleans the action script of the entity
  function character:clean_action(action_script)
    if (action_script == nil) then
      self.__private.action_script = nil
    elseif (self.__private.action_script == action_script) then
      self.__private.action_script = nil
    end
  end

  -- Executes an autoaction script
  function character:execute_autoaction()
    local action_script = self.__private.auto_action_script
    self.__private.auto_action_script = nil
    self:execute_action(action_script)
  end

  -- Executes an action script
  function character:execute_action(action_script)
    if (action_script ~= nil) then
      EventDispatcher.ExecuteCallBackScript(self, action_script)
    elseif (self.__private.action_script ~= nil) then
      local action_script = self.__private.action_script
      EventDispatcher.ExecuteCallBackScript(self, action_script)
    end
  end

  -- Updates the z-order of the entity
  --  when a sprite is in the same layer as other gameobject and it is at a higher y position, then it must appears behind the other gameobject
  --  otherwise it will look as floating
  function character:update_zorder()
    if (character.__private.z_order ~= character.Transform.position.y) then
      character.__private.z_order = character.Transform.position.y
      character:setZOrder(character.Transform.position.y);
    end
  end

  -- Sets if the entity should ignore phisically blocked places
  function character:set_ignore_blocked_places(ignore)
    character.__private.ignore_blocked_places = ignore
  end

  -- Indicates if the entity is ignoring phisically blocked places
  function character:get_ignore_blocked_places()
    return character.__private.ignore_blocked_places
  end

  -- Sets the pixel position of the entity based on the given tile coordinates
  function character:set_position(x,y)
    character.Transform.position:set(x * character.__private.tile_size, y * character.__private.tile_size)
  end

  -- Sets if the entity should be a physical obstacle (such as a blocked place)
  function character:set_blocked(blocked)
    if (blocked) then
      character.blocked_sensor:setProperty("Blocked", "Blocked")
    else
      character.blocked_sensor:removeProperty("Blocked")
    end
  end

  
  -- checks if enough time has passed since the last action command (prevents a command to be repeated by keyboard repeat interval)
  function character:check_action_command()
    
    local current_time = engine:getCurrentTime() 
    local elapsed = current_time - self.__private.last_action_command
    if (keyboard:keyIsDown(Keyboard.KEY_SPACE) and ( elapsed >= self.__private.action_interval)) then
      self.__private.last_action_command = current_time
      return true
    end
    return false
  end
  
  -- Event called by the engine every frame.
  --  Responsible for updating the entity behavior
  function character:OnUpdate (sender)
    
    local x = 0
    local y = 0

    -- If the entity is not ignoring blocked pplaces
    if (not character:get_ignore_blocked_places()) then
      -- Checks if the entity has collided and must be moved to the last valid position
      if (character.__private.has_collided) then
        character.Transform.position:set (character:get_last_position().x , character:get_last_position().y)
        character.__private.has_collided = false
        return
      end
    end

    -- If the entity must be followed by the camera
    if (character.__private.camera_follow) then
      set_camera_position(sender.Transform.position.x, sender.Transform.position.y, true)
      
    end

    -- Updates the last valid position
    character.__private.last_position.x =  sender.Transform.position.x
    character.__private.last_position.y =  sender.Transform.position.y
  
    -- If the entity is controlled by the user
    if (not character.__private.is_npc) then
      -- If the user is allowed to control the entity at this time
      if (character:get_can_control() and not character:get_in_battle()) then
        -- If there is a pendent automatic action script
        if (character.__private.auto_action_script ~= nil) then
          --Executes the automatic action script
          character:execute_autoaction()
          return
        end
        
        -- If the user pressed 1, toggle questlist visibility
        if (keyboard:keyIsDown(Keyboard.KEY_1)) then
          character:toggle_questlist()
        end
        
        -- If the user pressed 2, toggle minimap visibility
        if (keyboard:keyIsDown(Keyboard.KEY_2)) then
          character:toggle_minimap()
        end
        

        -- If the user pressed SPACE, executes possible action scripts (usually set by interactable objects)
        if (self:check_action_command()) then
          character:execute_action()
        end

        -- Horizontal Movement
        if (keyboard:keyIsDown(Keyboard.KEY_RIGHT)) then
          x = 1
        elseif (keyboard:keyIsDown(Keyboard.KEY_LEFT)) then
          x = -1
        end

        -- Vertical Movement
        if (keyboard:keyIsDown(Keyboard.KEY_UP)) then
          y = -1
        elseif (keyboard:keyIsDown(Keyboard.KEY_DOWN)) then
          y = 1
        end

        -- Checks if the entity should run
        local run = keyboard:keyIsDown(Keyboard.KEY_LSHIFT) or keyboard:keyIsDown(Keyboard.KEY_RSHIFT)

        -- Checks if the entity should move calmly
        local calmly = keyboard:keyIsDown(Keyboard.KEY_LCTRL) or keyboard:keyIsDown(Keyboard.KEY_RCTRL)

        -- Updates the entity movement
        sender:move(x, y, run, calmly)
      end
    end

    -- Updates the entity zorder based on the actual y position
    character:update_zorder()
  end


  -- Generates a sequence action that will set this entity control status to true
  function character:cancontrol_action()
    local action = {}

    function action:step()
      character:set_can_control(true)
      character:set_ignore_blocked_places(false)
      character:move(0,0, false, false)
      return true
    end
    return action
  end

  -- Generates a sequence action that will make this entity face the given direction
  function character:face_direction_action(face_x, face_y)
    local action = {}

    function action:step()
      character:face_direction(face_x, face_y)
      return true
    end
    return action
  end

  -- Generates a sequence action that will call a function
  function character:call_action(callback_function)
    local action = {
      callback_function = callback_function
    }

    function action:step()
      -- if the function returns false (which is different than returning nil), it means that the action is not finished yet
      if (self:callback_function() == false) then
        return false
      end
      return true
    end
    return action
  end

  -- Generates a animation action (if wait is specified then the action will wait the specified animation to be finished)
  function character:animation_action(animation, wait)
    local action = {
      sprite = self:get_sprite(),
      animation = animation,
      wait = wait
    }

    function action:started()
      self.sprite:setAnimation(self.animation)
    end

    function action:step()
      return (not self.wait) or self.animation.Finished
    end

    return action
  end

  -- Generates a animation finished action (that will wait the specified animation to be finished)
  function character:animation_finished_action(animation)
    local action = {
      animation = animation
    }

    function action:step()
      return self.animation.Finished
    end
    return action
  end



  -- Generates a sequence action that will call a function after the elapsed time
  function character:wait_call_action(interval, callback_function)
    local action = {
      interval = interval,
      callback_function = callback_function

    }

    function action:reset()
      self.t0 = engine:getCurrentTime()
    end

    function action:started()
      self:reset()
    end

    function action:step()
      -- if the timeout has been reached
      if (engine:getCurrentTime() - self.t0 >= self.interval) then
        -- of there is a callback function (sometimes we just want a timer)
        if (type(self.callback_function) == "function") then
          -- if the function returns false (which is different than returning nil), it means that the action is not finished yet
          -- and a new interval will get place
          if (self:callback_function() == false) then
            self:reset()
            return false
          end
        end
        -- this action has finished
        return true
      end
      -- timeout has not been reached yet
      return false
    end
    return action
  end


  -- Generates a move action that will be executed until the entity gets to the given tile position
  --    x: the x destination of the movement
  --    y: the y destination of the movement
  --    run: if the entity should run to the position
  --    calmly: if the entity should walk calmly to the position
  function character:move_action(x,y, run, calmly)
    local action = {}
    action.__private = {}
    action.__private.destination_x = x * character.__private.tile_size
    action.__private.destination_y = y * character.__private.tile_size
    action.__private.run = run
    action.__private.calmly = calmly

    function action:started()
      character:set_can_control(false)
      character:set_ignore_blocked_places(true)
    end

    function action:step()
      character:set_can_control(false)
      character:set_ignore_blocked_places(true)
      local move_x = 0
      local move_y = 0
      local current_x = math.floor(character.Transform.position.x)
      local current_y = math.floor(character.Transform.position.y)

      if(current_x  < self.__private.destination_x) then
        move_x = 1
      elseif(current_x > self.__private.destination_x) then
        move_x = -1
      end

      if(current_y < self.__private.destination_y) then
        move_y = 1
      elseif(current_y > self.__private.destination_y) then
        move_y = -1
      end
      
      if(math.abs(current_x - self.__private.destination_x) <= MOVE_THRESHOLD) then
        self.__private.destination_x = current_x
        move_x = 0
      end
      
      if(math.abs(current_y - self.__private.destination_y) <= MOVE_THRESHOLD) then
        self.__private.destination_y = current_y
        move_y = 0
      end

      character:move(move_x, move_y, run, calmly)

      if (move_x == 0 and move_y == 0) then
        return true
      end

      return false
    end

    return action
  end

  -- Generates a prepare_attack action that will be executed until the entity gets to target position
  --    x: the x destination of the movement
  --    y: the y destination of the movement
  --    run: if the entity should run to the position
  --    calmly: if the entity should walk calmly to the position
  function character:prepare_attack_action(target)
    local action = {}
    action.__private = {}
    action.__private.target = target


    function action:started()
      character.__private.target = self.__private.target
      character:get_sprite():setAnimation(character.__private.sprite.preparing_attack_animation)
    end

    function action:step()


      local current_x = round(character.Transform.position.x)
      local current_y = round(character.Transform.position.y)

      local target_x = round(target.Transform.position.x)
      local target_y = round(target.Transform.position.y)
      
      if (target_x < current_x) then
        target_x = target_x + character.__private.alignment
      elseif (target_x > current_x) then
        target_x = target_x - character.__private.alignment
      end
      


      local move_x = target_x - current_x

      if (math.abs(move_x) <= ATTACK_THRESHOLD) then
        character.Transform.position:set(target_x, target_y)
        return true
      else
        local elapsed_time = engine:getElapsedTime()

        move_x = normalize(move_x)
        move_x = ((move_x * Config.SCREEN_WIDTH * elapsed_time) / 1.5) 
      
        local new_x = character.Transform.position.x + move_x
  
        local p0_distance = math.abs(new_x - character:get_battle_position().x)
        local enemy_distance = math.abs(self.__private.target.Transform.position.x - new_x)
        local jump_height =    math.min(p0_distance, enemy_distance) / 2
        local new_y = character:get_battle_position().y - jump_height
  
        character.Transform.position:set(new_x, new_y)
        
        return false
      end      
    end

    return action
  end

  -- Event that occurs when the entity collide with another GameObject
  function character:OnBeginContact (sender, other)

    -- If other is an obstacle
    if (other:hasProperty("Blocked")) then
      -- Entity has collided (it will be placed to the last valid position in the next iteration if ignore_blocked_places is not set)
      character.__private.has_collided = true
    end

    -- If other is interactable
    if (other:hasProperty("Action")) then
      -- Sets the action_script based on the interactable Action property
      local action_script = other:getProperty("Action")
      character.__private.action_script = action_script
    end

    -- If other causes an instant action to occur
    if (other:hasProperty("AutoAction")) then
      -- Sets the auto_action_script based on the trigger "AutoAction" property
      local action_script = other:getProperty("AutoAction")
      character.__private.auto_action_script = action_script
    end

    -- If the other object has an associated Label,display it
    if (other.label_object ~= nil) then
      other.label_object.Visible = true
    end
  end

  -- Event that occurs when the entity stops colliding with another GameObject
  function character:OnEndContact (sender, other)
    -- If other was interactable, removes the corresponding Action script from the entity
    if (other:hasProperty("Action")) then
      local action_script = other:getProperty("Action")
       character:clean_action(action_script)
    end

    -- If other object has an associated Label, hide it
    if (other.label_object ~= nil) then
      other.label_object.Visible = false
    end
  end

  -- Serializes the entity to JSON
  function character:toJSON()
    return
      json.encode({
        Name  = self:get_battle_name(),
        HP    = self:get_current_hp(),
        MP    = self:get_current_mp(),
        Gauge = self:get_battle_gauge(),
        Ready = self:get_battle_ready()
      }, true)
  end


  -------------------------------------------------------------
  -- Battle Control
  -------------------------------------------------------------
  function character:increment_battle_gauge(elapsed_time)
    local current_gauge = self:get_battle_gauge()
    if (current_gauge < 100) then
      self:set_battle_gauge(math.min(current_gauge + self:get_battle_speed() * elapsed_time, 100))
      return (self:get_battle_gauge() == 100)
    end
    return true
  end


  function character:get_battle_controller()
    return self.__private.battle_controller
  end

  function character:set_battle_controller(battle_controller)
    self.__private.battle_controller = battle_controller
  end

  function character:get_in_battle()
    return self:get_battle_controller() ~= nil
  end

  
  function character:battle_start_animation()
    local sprite = self:get_sprite()
    if (sprite == nil or sprite.battle_start_animation == nil) then
      return false
    end
    sprite:setAnimation(sprite.battle_start_animation)
  end

  function character:battle_attack_animation()
    local sprite = self:get_sprite()
    if (sprite == nil or sprite.battle_attack_animation == nil) then
      return false
    end
    sprite:setAnimation(sprite.battle_attack_animation)
  end
  
  function character:idle_down_animation()
    local sprite = self:get_sprite()
    if (sprite == nil or sprite.idle_down_animation == nil) then
      return false
    end
    sprite:setAnimation(sprite.idle_down_animation)
  end
  
  function character:battle_win_animation()
    local sprite = self:get_sprite()
    if (sprite == nil or sprite.battle_win_animation == nil) then
      return false
    end
    sprite:setAnimation(sprite.battle_win_animation)    
  end

  function character:battle_start(id, party, enemy_party, battle_controller)

    self:set_battle_controller(battle_controller)
    self:set_party(party)
    self:set_can_control(false)
    self:set_party_id(id)
    self:set_target_party(enemy_party)
    self:set_target_id(1)
    self:set_battle_position(self:get_last_position().x,self:get_last_position().y)
    self:set_battle_gauge(0)
    self:battle_start_animation()

  end

  -- Default attack action, can be overridden by the entity specialization
  function character:get_attack_actions(critical)

    local target = self:get_battle_controller():get_target(self)

    local function step_in_direction()

      if (not target) then
        return 0
      end
      if (self:get_battle_position().x > target.Transform.position.x) then
        return 0.5
      else
        return -0.5
      end
    end

    if (critical) then
      return
        {
          self:prepare_attack_action(target),
          self:animation_action(self:get_sprite().battle_attack_animation, true),
          self:call_action(function() self.__private.target:battle_attacked(self:calculate_damage()) end),
          self:animation_action(self:get_sprite().battle_critical_attack_animation, true),
          self:call_action(function() self.__private.target:battle_attacked(self:calculate_damage()) end),
          self:move_action(math.floor(self:get_battle_position().x / self.__private.tile_size)+step_in_direction(), math.floor(self:get_battle_position().y / self.__private.tile_size), true, false),
          self:move_action(math.floor(self:get_battle_position().x / self.__private.tile_size), math.floor(self:get_battle_position().y / self.__private.tile_size), true, false),
          self:call_action(function() self:get_sprite():setAnimation(self:get_sprite().battle_idle_animation); self.battle_waiting = true end),          
        }
    else
      return
        {
          self:prepare_attack_action(target),
          self:animation_action(self:get_sprite().battle_attack_animation, true),
          self:call_action(function() self.__private.target:battle_attacked(self:calculate_damage()) end),
          self:move_action(math.floor(self:get_battle_position().x / self.__private.tile_size)+step_in_direction(), math.floor(self:get_battle_position().y / self.__private.tile_size), true, false),
          self:move_action(math.floor(self:get_battle_position().x / self.__private.tile_size), math.floor(self:get_battle_position().y / self.__private.tile_size), true, false),
          self:call_action(function() self:get_sprite():setAnimation(self:get_sprite().battle_idle_animation); self.battle_waiting = true end),          
        }
    end
  end
  
  function character:battle_miss()
    self:set_battle_gauge(0)
    self:battle_attack_animation()
    self:show_red_label("Miss", 1.5)
  end
  
  function character:battle_attack()

    local chance = math.floor(math.random() * 100 + 1)
    local critical_hit = chance >= 75
    local queue_action = self:get_battle_controller():get_queue():create_action(self)
    local attack_action = self:addGameObject(sequence_controller:create(self:get_attack_actions(critical_hit), false))
    attack_action.queue_action = queue_action

    function attack_action:finished()
      self.queue_action.attack_finished = true
    end

    queue_action.attack_action = attack_action

    function queue_action:execute(queue)
      self.attack_action:play()
    end

    function queue_action:step()
      if (self.attack_finished) then
        return true
      end
      return false
    end

    self:get_battle_controller():get_queue():add(queue_action)

  end

  function character:battle_attacked(damage)
    damage =  math.max(0, damage - self:get_battle_defense())

    local sprite = character.__private.sprite
    
    self:show_white_label(damage, 0.5)
    
    if (damage > 0) then
      self:apply_damage(damage)
      if (sprite == nil or sprite.battle_start_animation == nil) then
        return false
      end
      sprite:setAnimation(sprite.battle_attacked_animation)
    end
  end

  function character:battle_end()       
        
    if (self:get_current_hp() > 0) then
      self:battle_win_animation()
    else
      self:idle_down_animation()
    end
    
    local timer = self:addGameObject(timer_controller:create(3))
    timer.character_controller = self
    function timer:timeout(sender)
      sender.character_controller:clean_action()
      sender.character_controller:set_battle_controller(nil)
      sender:destroy()
    end
    
  end

  -- Sets the sprite passed to the constructor as the sprite component of the controller
  character:set_sprite(entity_sprite)

  return character
end
