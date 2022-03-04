-------------------------------------------
-- This module implements a timer mechanism 
--  It is very useful to execute autonomous functions based on time 
-------------------------------------------

timer_controller = {}

-- Creates a timer
--  timeout: The amount of time in seconds (fractionable) until the execution
function timer_controller:create (interval)

  -- Creates a GameObject that will be updated automatically by the engine
  local timer = GameObject:new()
  timer.__private = {
    interval = interval
  }
         
  -- Resets the referential/start time of the timer (useful when you want the timer to be fired again)         
  function timer:reset()
    timer.__private.t0 = engine:getCurrentTime()
  end
  
  -- Event that occurs when the engine instantiates the timer
  function timer:OnCreate(sender)
    -- Resets the referential start time of the timer     
    timer:reset()
    -- Repasses the OnCreate event to the TimerCreate user implemented event, if there is one
    if (sender.oncreate ~= nil) then
      sender:oncreate(sender)
    end
  end

  -- Event that occurs every frame
  --  It is responsible to check if timeout has been reached and to fire the timeout event when needed       
  function timer:OnUpdate(sender)
    -- Repasses the OnUpdate event to the update user implemented event, if there is one
    if (sender.update ~= nil) then
      sender:update(sender)
    end
    -- Checks if the timer has reached its timeout
    if (engine:getCurrentTime() - sender.__private.t0 >= sender.__private.interval) then
      -- Calls the timeout event of the timer, if there is one (it is just a sanity check, there is no good reason to implement a timer without such event)
      if (sender.timeout ~= nil) then
        sender:timeout(sender)
      end
    end
  end
    
  return timer
end

