--- 
-- This module implements a priority_queue
-- @type priority_queue
priority_queue = {
  __private = {
    max_speed = 255
  }
}

priority_queue.__index = priority_queue

---
-- Creates a priority_queue with a possible maximum size (objects in the lowest part of the priority_queue will be discarded when needed)
-- @return #priority_queue
function priority_queue.create()    
  
  local new_queue = {
    __private = {
      queue = {},
      current = nil
      }
  }
  setmetatable(new_queue, priority_queue)
  return new_queue
end

---
-- pushes an action to the priority_queue
-- @param self
-- @param action
-- @return #nil
function priority_queue:add(action)
  if (action) then
    for i = 1, #self.__private.queue do
      if self.__private.queue[i].priority > action.priority then
        table.insert(self.__private.queue, i, action)
        return 
      end
    end
    table.insert(self.__private.queue, action)
  end
end

---
-- Verifies if an entity has a action waiting in the priority_queue
-- @param self
-- @param entity
-- @return #boolean
function priority_queue:entity_has_action(entity)
  local current = self.__private.current or {}
  if current.owner == entity then
    return true
  end
  for k, v in ipairs(self.__private.queue) do
    if v.owner == entity then
      return true
    end
  end
  return false
end

---
-- removes actions from a determined entity
-- @param self
-- @param entity
-- @return #nil
function priority_queue:remove_entity_actions(entity)
  local current = self.__private.current or {}
  if current.owner == entity then
    self.__private.current = nil
  end
  for i = #self.__private.queue, 1, -1 do
    local v = self.__private.queue[i]
    if v.owner == entity then
      table.remove(self.__private.queue, i)
    end
  end  
end

---
-- Sets the current action
-- @param self
-- @param current
-- @return #nil 
function priority_queue:set_current(current)
  self.__private.current = current
end

-- Gets the current action 
function priority_queue:get_current()
  return self.__private.current
end

-- clear
function priority_queue:clear()
    self:set_current(nil)
    self.__private.queue = {}
end

---
-- returns the number of elements in the priority_queue
function priority_queue:size()
  return #self.__private.queue 
end

---
-- returns a boolean indicating if the priority_queue has 0 elements
function priority_queue:empty()
  return self:size() == 0 and self:get_current() == nil
end

---
-- updates the priority_queue
function priority_queue:update(elapsed_time)
  local current = self:get_current()
  if (current ~= nil) then   
    if (current:step()) then
      current.owner:set_battle_gauge(0)
      self:set_current(nil)
    else
      return
    end
  end
  
  if (not self:empty()) then   
    -- Need to chose an action
    local front = table.remove(self.__private.queue, 1)
    front:execute(self)
    self:set_current(front)
  
    local aux_queue = self.__private.queue
    self.__private.queue = {}
    for _, v in ipairs(aux_queue) do    
      v:decrement_priority(elapsed_time)
      self:add(v)    
    end
  end   
end

---
-- creates a default action
function priority_queue:create_action(owner, priority)
  
  if (type(priority) ~= "number") then
    priority = 0
  end
  
  local action =  {
    owner = owner,
    priority = (priority_queue.__private.max_speed - owner:get_battle_speed()) + priority            
  }
      
  function action:decrement_priority(elapsed_time)
    local decrement = 1;
    if (self.owner) then
      decrement = self.owner:get_speed()
    end
    self.priority = math.max(0, self.priority - decrement * elapsed_time)     
  end  
  
  function action:execute(queue)
    self.queue = queue     
  end  
  
  function action:step()
    return true    
  end  
  
  return action
  
end