---
-- This module implements a battle_controller
-- @type battle_controller
battle_controller = {
  __private = {
    width = Config.SCREEN_WIDTH ,
    height = Config.SCREEN_HEIGHT,
    players = {},
    enemies= {},
    last_update = 0,
    update_interval = 1.0 / 60,
    battle_ended = true,
    battle_ready = false
  }
}


function battle_controller.__private:play_music()
  if (self.Music == nil) then  
    self.Music = Music:new("assets/music/orchestra/battle.mp3")
  end

  if(not self.Music:isPlaying()) then
    if (gamestate().Music and gamestate().Music:isPlaying()) then
      self.Music:Play()
    end
  end
  
end

-- Resume the gamestate scene music theme
function battle_controller.__private:resume_music()
  if (self.Music ~= nil and self.Music:isPlaying()) then
    self.Music:Stop()
    gamestate():play_music()
  end    
end

 

---
-- Creates a battle with the given arguments
-- @param self The module itself
-- @param #table players table containing the player controlled entities
-- @param #table enemies table containing the NPCs entities
-- @return #battle The battle object
function battle_controller:create(players, enemies)
  
  ---
  -- @type battle    
  local battle = WebBrowser:new ("", battle_controller.__private.width, battle_controller.__private.height, true)
  
  
  battle:setProperty("Name", "battle")

  battle:Navigate("file:///scripts/JRPGEngine/UI/battle/battle.html");
  battle.__private = self.__private;
  battle.__private.players = players or {}
  battle.__private.enemies = enemies or {}
  battle.__private.queue = priority_queue:create()

  engine:getCurrentGameState():add(battle, 1000000)
  self.__private:play_music()
  
  function battle:get_battle_ready()
    return self.__private.battle_ready and not self:isLoading()
  end
  
  function battle:set_battle_ready(ready)
    self.__private.battle_ready = ready
    self.__private.last_update = engine:getCurrentTime()
   
  end
  
  
  function battle:get_target(entity)
    local target_party = entity:get_target_party()
    local target_id = entity:get_target_id()
    local target = target_party[target_id]
    
    if (target and target:get_current_hp() > 0) then
      return target
    else
      for i, target in ipairs(target_party) do        
        if (target:get_current_hp() > 0) then    
          entity:set_target_id(i)
          return target
        end 
      end
    end
    
    return nil    
  end
  
  function battle:get_queue()
    return self.__private.queue 
  end
  
  function battle:setup()
    self:set_battle_ready(false)
    self.__private.quests_visible = quest_controller:get_visibility()
    self.__private.battle_ended = false
    
    quest_controller:set_visibility(false)
    local player = maincharacter()
    player:set_camera_follow(false)
    
    for i, k in ipairs(self.__private.players) do            
      k:battle_start(i, self.__private.players, self.__private.enemies, self)       
    end

    for i, k in ipairs(self.__private.enemies) do            
      k:battle_start(i, self.__private.enemies, self.__private.players, self)
    end
    
  end

  battle:setup()

  function battle:terminate()    
    quest_controller:set_visibility(self.__private.quests_visible)
    battle_controller.__private:resume_music()
    local player = maincharacter()
    player:set_camera_follow(true)
    player:set_can_control(true)
    player:set_ignore_blocked_places(false)
    if (player.on_battle_finished ~= nil) then
      player:on_battle_finished()
    end
    for i, k in ipairs(self.__private.players) do                  
      if (k.on_battle_finished) then
        k:on_battle_finished()
      end 
    end
    self.__private.players = {}
    
    for i, k in ipairs(self.__private.enemies) do                  
      if (k.on_battle_finished) then
        k:on_battle_finished()
      end 
    end
        
    
    self.__private.enemies = {}
    self:destroy();
  end
  
   function battle:show_results()
    
    self.__private.battle_ended = true
    
    for i, k in ipairs(self.__private.players) do            
      k:battle_end()      
    end
            
    
    for i, k in ipairs(self.__private.enemies) do            
      k:battle_end()
    end
        
    
    self:ExecuteScript("show_results()")
    
  end

  function battle:battle_attacked(i)
    local player = maincharacter()
    player:battle_attacked(self.__private.enemies[i])
  end
  
  function battle:battle_attack(i)
    local player = self.__private.players[1]
    local enemy = self.__private.enemies[i]
    if (not player:get_koed()) then
      player:battle_attack(enemy)
    end
  end
  
  function battle:battle_miss(i)    
    local player = self.__private.players[i]
    if (not player:get_koed()) then
      player:battle_miss()
    end    
  end
    
  function battle:UpdateCameraPosition()
    local state  = engine:getCurrentGameState()
    local camera = state:getActiveCamera()

    local camera_point = {x = 0, y = 0}
    local entities_count = 0

    local speed = 500
    local threshold = 0.1

    for i, k in ipairs(self.__private.players) do
      local battle_position = k:get_battle_position()
      camera_point.x = camera_point.x + battle_position.x
      camera_point.y = camera_point.y + battle_position.y
      entities_count = entities_count + 1
    end

    for i, k in ipairs(self.__private.enemies) do
      local battle_position = k:get_battle_position()
      camera_point.x = camera_point.x + battle_position.x
      camera_point.y = camera_point.y + battle_position.y
      entities_count = entities_count + 1
    end

    if (entities_count == 0) then
      return
    end

    camera_point.x = camera_point.x / entities_count
    camera_point.y = camera_point.y / entities_count

    local movement =
      {
        x = normalize(camera_point.x - camera.Transform.position.x),
        y = normalize(camera_point.y - camera.Transform.position.y),
      }

    local elapsed = engine:getElapsedTime()


    --camera.Transform.position.x = camera.Transform.position.x + movement.x * elapsed * speed
    --camera.Transform.position.y = camera.Transform.position.y + movement.y * elapsed * speed
    set_camera_position(camera.Transform.position.x + movement.x * elapsed * speed, camera.Transform.position.y + movement.y * elapsed * speed, true)
    --self.Transform.position:set(camera.Transform.position.x - (Config.SCREEN_WIDTH / 2),camera.Transform.position.y - Config.SCREEN_HEIGHT / 2)

  end

  function battle:OnUpdate(sender)
    self:setAlwaysFocused(true)
    
    local current_time = engine:getCurrentTime()
    
    if (sender:get_battle_ready()) then
      if(sender.script_to_execute ~= nil) then
        sender:ExecuteScript(sender.script_to_execute)
        sender.script_to_execute = nil
      end
      if (not self.__private.battle_ended) then
        local elapsed_time = current_time - self.__private.last_update
        if (elapsed_time >= self.__private.update_interval) then
          local player_party_alive = false
          local enemy_party_alive = false
          self.__private.last_update = current_time
          for i, k in ipairs(self.__private.players) do               
            if (k:get_koed()) then
              self:get_queue():remove_entity_actions(k)
            else     
              if (not self:get_queue():entity_has_action(k)) then
                k:increment_battle_gauge(elapsed_time)
              end
              player_party_alive = true                      
            end
            local str_json = json.encode(k)
            
            sender:ExecuteScript("UpdatePlayer('"..str_json.."')")
            
          end
  
          for i, k in ipairs(self.__private.enemies) do
            if (not k:get_koed()) then  
              if (not self:get_queue():entity_has_action(k)) then
                k:increment_battle_gauge(elapsed_time * ((100 - math.random() * 35 + 1) / 100))
              end            
              enemy_party_alive = true                  
              if (k:get_battle_ready()) then
                local try_hit = round(math.random() * 100)
                local to_hit = k:get_battle_hit()   
                local success = (to_hit - try_hit  > 0)
                if (success) then                
                  print(engine:getCurrentTime().." hit:"..try_hit, to_hit)
                  k:battle_attack()
                else
                  print(engine:getCurrentTime().." missed:"..try_hit, to_hit)
                  k:battle_miss()
                end
              end
            end
            local str_json = json.encode(k)
            sender:ExecuteScript("UpdateEnemy('"..str_json.."')")
            if (k:get_koed()) then
              --table.remove(self.__private.enemies, i)
              self:get_queue():remove_entity_actions(k)
              --k:destroy()
            end
          end
          
          if (not player_party_alive or not enemy_party_alive and self:get_queue():empty()) then
            self:show_results()
          end
          
        end
        self:get_queue():update(elapsed_time)
        self:UpdateCameraPosition()
      end  
    end
  end

  return battle
end
