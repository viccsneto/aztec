-------------------------------------------
-- This module implements mechanisms to execute a sequence of actions 
--  Each action should have a start function and must have a step function
--  When the step function returns true, it indicates that the action was completed
--  then the sequence_controller will check if the sequence 
--    is finished
--    has more actions
--    or must be reversed (loop in the contrary order) 
-------------------------------------------


sequence_controller = {}


-- Creates a sequence of actions 
--    actions: a Lua table containing the actions implementations for this sequence
--    play: Sets if the sequence should start playing automatically
--    revert: Sets if the sequence will loop in the contrary order of execution 

function sequence_controller:create (actions, play, revert)

  -- Creates a GameObject that will represent the sequence (and be updated automatically by the engine)
  local sequence = GameObject:new()
  
  sequence.__private = {
    actions = actions
  }
  
  -- Sets the playing status of the sequence to true
  function sequence:play()
    self.__private.playing = true
  end
  
  -- Sets the playing status of the sequence to false, without restarting the sequence position
  function sequence:pause()  
    self.__private.playing = false
  end
  
  -- Stops the sequence execution and resets the sequence position
  function sequence:stop()
    self.__private.playing = false
    self:reset()
  end
  
  -- Sets the current action of the sequence
  function sequence:set_action(action)
    self.__private.current_action = action
  end
  
  -- Sets the revert status of the sequence
  function sequence:set_revert(revert)
    self.__private.revert = revert
  end
  
  -- Gets the revert status of the sequence
  function sequence:get_revert()
    return self.__private.revert
  end
  
  -- Indicates if the sequence is being played 
  function sequence:get_playing()
    return self.__private.playing 
  end
  
  -- Restart the sequence position
  function sequence:reset()
    self:set_action(1)
  end
  
  
  -- Event that occurs every frame and is responsible to update the sequence behavior     
  function sequence:OnUpdate(sender)
    
    -- If the sequence is not being played, abort
    if (not self.__private.playing) then
      return
    end
            
    -- If there are actions
    if (self.__private.actions) then
      -- Gets the current action index
      local current_action = self.__private.current_action
      
      -- If the index is within the actions domain
      if (self.__private.actions[current_action] ~= nil) then       
        
        -- If the action has not been started or is on a different direction (order of execution in a reversable sequence)
        if (self.__private.actions[current_action].has_started == nil or self.__private.actions[current_action].has_started ~= sender.__private.direction) then
           -- Updates the has_started flag with the current direction of the sequence
          self.__private.actions[current_action].has_started = sender.__private.direction
          if (self.__private.actions[current_action].started ~= nil) then
            -- Calls the started function of the action
            self.__private.actions[current_action]:started()
          end
        end
        -- Executes the current action step and gets its finished status 
        local action_finished = self.__private.actions[current_action]:step()
        
        -- If the current action has finished 
        if (action_finished) then
          -- Call its finished event, if there is one
          if (self.__private.actions[current_action].finished ~= nil) then            
            self.__private.actions[current_action]:finished()
          end
               
          -- Sets the action has_finished flag to the actual direction of the sequence
          self.__private.actions[current_action].has_finished = sender.__private.direction
          
          -- Move the sequence iterator index in the direction of the sequence          
          self.__private.current_action = sender.__private.current_action + sender.__private.direction
        end        
      else -- The sequence has finished the current direction 
        -- Call its finished event, if there is one 
        if (self.finished ~= nil) then
          self:finished()
        end
        -- If the sequence should execute in the inverted order
        if (self.__private.revert) then
          -- Changes the direction of the sequence execution
          self.__private.direction = self.__private.direction * -1
          
          -- Sets the new first action of the sequence
          local current_action = self.__private.current_action + self.__private.direction          
          self.__private.current_action = current_action
          return
        end
        -- If the sequence is not reversable, then destroys it
        self:destroy()
      end
    end    
  end
  
    -- Sets the initial sequence action position
  sequence:reset()
  
  sequence.__private.revert = revert
  sequence.__private.direction = 1
    
  -- Sets the sequence parameters based on the constructor arguments
  if play then sequence:play() end
    
  return sequence
end

