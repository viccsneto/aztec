--------------------------------------------
-- This modules implements a quest component
-- 
-- It works like a todo list, giving a direction to the player of which tasks(or quests) has been completed and which are pendent 
--A quest is a table with the following format:
--   {
--     key  = "unique_identifying_key",
--     text = "What the player must do! Allows html tags, such as <br/> emoji and mathjax syntax ($ inline latex $ $$ latex $$ and ` asciimath `)",
--     done = false -- or true, depending if the task is pendent or already done 
--   }
--   
-- A list of quests is represented by a table with n quest elements
-- {
--    {
--      key  = "unique_identifying_key",    
--      text = "What the player must do! Allows html tags, such as <br/> emoji and mathjax syntax ($ inline latex $ $$ latex $$ and ` asciimath `)",
--      done = false -- or true, depending if the task is pendent or already done 
--    },
--    {
--     key  = "another_unique_identifying_key",    
--      text = "What the player must do also! Allows html tags, such as <br/> emoji and mathjax syntax ($ inline latex $ $$ latex $$ and ` asciimath `)",
--      done = false -- or true, depending if the task is pendent or already done 
--    }
--    ,
--    ... more quests ...
--  }
--
-- @type quest_controller
quest_controller = {
  __private = {  
  width = 1024,
  height = 230,
  visible = false,  
  quests = {},
  quest_update_id = 0,
  update_time = 0,
  update_show_interval = 5
  }
}




-- gets the quest version identification (so we know if the quest_list is updated)
function quest_controller.__private:get_quest_update_id()
  return self.quest_update_id;
end

-- increments the quest version identification (so we know that the list must passed to the quest_list webbrowser component)
function quest_controller.__private:increment_quest_update_id()
  self.quest_update_id = self.quest_update_id + 1;
  self.update_time = engine:getCurrentTime()
  return self:get_quest_update_id()
end

---
-- Returns the list of quests    
function quest_controller:get_quests()
  return self.__private.quests;
end

---
-- Returns the quest status by key    
function quest_controller:get_quest_status(key)
  for i = 1, #self.__private.quests do
    if (self.__private.quests[i].key == key) then
      return self.__private.quests[i].done and self.__private.quests[i].done or false
    end
  end
  return nil
end

---
-- Sets the quest status by key    
function quest_controller:set_quest_status(key, done)
  for i = 1, #self.__private.quests do
    if (self.__private.quests[i].key == key and self.__private.quests[i].done ~= done) then
      self.__private.quests[i].done = done      
      self.__private.quests[i].id = self.__private:increment_quest_update_id()
    end
  end
end

---
--Adds a quest to the quest_list 
function quest_controller:add_quest(quest)
  for i = 1, #self.__private.quests do
    if (self.__private.quests[i].key == quest.key) then
      self.__private.quests[i].done = quest.done
      if (quest.text ~= nil) then
        self.__private.quests[i].text = quest.text
      end
      self.__private.quests[i].id = self.__private:increment_quest_update_id()
      return 
    end
  end
  quest.id = self.__private:increment_quest_update_id()
  table.insert(self.__private.quests, quest)
   
end

---
-- Removes a quest from the list (if exists)  
function quest_controller:remove_quest(quest)
  for i = 1, #self.__private.quests do
    if (self.__private.quests[i].key == quest.key) then
      table.remove(self.__private.quests, i)
      self.__private:increment_quest_update_id()
    end
  end 
end

---
-- Assigns a list of quests   
function quest_controller:set_quests(quests)
  self.__private.quests = quests;
  if (#self.__private.quests > 0) then  
    for i = 1, #self.__private.quests do
      self.__private.quests[i].id = self.__private:increment_quest_update_id()
    end   
  else
    -- even if we are cleaning quests the id must be updated
    self.__private:increment_quest_update_id()
  end
end

---
-- Toggle visibility of the component (i.e., make it visible if not visible and vice-versa)
function quest_controller:toggle_visibility()
  local visible = not self:must_show()
  if (not visible) then
    self.__private.update_time = 0
  end
  self:set_visibility(visible)
end

---
-- Gets the visibility status of the component
function quest_controller:get_visibility()
  return self.__private.visible
end

---
-- Sets the visibility status of the component
function quest_controller:set_visibility(visible)
  self.__private.visible = visible  
end

function quest_controller:must_show()
  
  if (not quest_controller:get_visibility()) then
    
    if (quest_controller.__private:get_quest_update_id() == 0) then
      return false
    end
    
    local current_time = engine:getCurrentTime()
    if (current_time - quest_controller.__private.update_time > quest_controller.__private.update_show_interval) then        
        return false
    end 
  end
  
  return true
end
---
-- Creates the quest and places it at the bottom right side of the screen
function quest_controller:create()
 
  -- if questlist already instanced, return it
  local questlist =  (queryname("questlist"))
  if (questlist ~= nil) then
    return questlist
  end
  -- Uses a chromium instance to render and control the dialog (implemented with web technologies)
  local questlist = WebBrowser:new ("file:///LuaSubSystem/JRPG/UI/quest/quest.html", self.__private.width, self.__private.height, true)
  questlist:setProperty("Name", "questlist")    
  
  questlist.__private = {
    quest_update_id = 0;
  };
  
  -- Puts the web render component in the actual scene in an unusually very high layer order. This way it will almost certainly be shown in front of all other components
  engine:getCurrentGameState():add(questlist, 1000000)
  
  -- Offers an API to update the current player position in the map
  function questlist.__private:Setup(quests)    
    local str_json = json.encode(quests, true)
    self.script_to_execute = "Setup('"..str_json.."')"
  end
               
  -- Controls the quest execution
  function questlist:OnUpdate(sender)    
    local state  = engine:getCurrentGameState()
    local camera = state:getActiveCamera()
    
    sender.Transform.position:set(camera.Transform.position.x - (Config.SCREEN_WIDTH / 2) - 5,camera.Transform.position.y - (Config.SCREEN_HEIGHT / 2) + 5)
    
    if (not quest_controller:must_show()) then
      sender.Visible = false
      return
    end
    
    sender.Visible = true
    
        
    if (not sender:isLoading()) then
      if(sender.__private.script_to_execute ~= nil) then
        sender:WindowExecuteScript(sender.__private.script_to_execute)
        sender.__private.script_to_execute = nil      
      end
      
      local last_update_id = quest_controller.__private:get_quest_update_id()
      if (self.__private.quest_update_id ~= last_update_id) then
        self.__private:Setup(quest_controller:get_quests())
        self.__private.quest_update_id = last_update_id
      end
   end
        
  end
      
  return questlist
end