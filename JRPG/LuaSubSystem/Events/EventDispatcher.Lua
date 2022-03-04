EventDispatcher = {}
-------------------------------------------------------------------------------------------------

--GameObject events
-------------------------------------------------------------------------------------------------

function EventDispatcher.OnUpdate(sender)  
  if(sender.OnUpdate ~= nil) then
    sender:OnUpdate(sender)        
  else
    sender.EventFlags = Bitwise:AND(sender.EventFlags,Bitwise:NOT(EventTypes.OnUpdate))
  end
end

function EventDispatcher.Execute(sender, script_package)
  script_package = json.decode(script_package)
  return json.execute(script_package.script)
end

function EventDispatcher.ExecuteCallBackScript(sender, script)
    script_function = load("return function(sender, script) "..script.." end")
    script_function()(sender, script)
end

function EventDispatcher.OnCreate(sender)  
  __AztecBindedObjects.objects[sender] = sender
  __AztecBindedObjects.count = __AztecBindedObjects.count + 1
  if(sender.OnCreate ~= nil) then    
    sender:OnCreate(sender)    
  end  
end

function EventDispatcher.OnBeforeDraw(sender)  
  if(sender.OnBeforeDraw ~= nil) then    
    sender:OnBeforeDraw(sender)    
  else
    sender.EventFlags = Bitwise:AND(sender.EventFlags,Bitwise:NOT(EventTypes.OnBeforeDraw))
  end
end

function EventDispatcher.OnAfterDraw(sender)  
  if(sender.OnAfterDraw ~= nil) then    
    sender:OnAfterDraw(sender)    
  else
    sender.EventFlags = Bitwise:AND(sender.EventFlags,Bitwise:NOT(EventTypes.OnAfterDraw))
  end
end

function EventDispatcher.OnDestroy(sender)  
  __AztecBindedObjects.objects[sender] = nil
  __AztecBindedObjects.count = __AztecBindedObjects.count - 1
  if(sender.OnDestroy ~= nil) then    
    sender:OnDestroy(sender)    
  end  
end

function EventDispatcher.OnMouseMove(sender,mouse)  
  if(sender.OnMouseMove ~= nil) then
    if(sender:OnMouseMove(sender,mouse)) then  
      Mouse.hasMovement = false            
    end
  else
    sender.EventFlags = Bitwise:AND(sender.EventFlags,Bitwise:NOT(EventTypes.OnMouseMove))
  end
end

function EventDispatcher.OnClick(sender,mouse)  
  if(sender.OnClick ~= nil) then
    if(sender:OnClick(sender,mouse)) then          
      Mouse.hasClick = false          
    end    
  else
    sender.EventFlags = Bitwise:AND(sender.EventFlags,Bitwise:NOT(EventTypes.OnClick))
  end
end

function EventDispatcher.OnBeginContact(sender,b)  
  if(sender.OnBeginContact ~= nil) then
    sender:OnBeginContact(sender,b);
  else
    sender.EventFlags = Bitwise:AND(sender.EventFlags,Bitwise:NOT(EventTypes.OnBeginContact))    
  end
end

function EventDispatcher.OnEndContact(sender,b)  
  if(sender.OnEndContact ~= nil) then
    sender:OnEndContact(sender,b);
  else
    sender.EventFlags = Bitwise:AND(sender.EventFlags,Bitwise:NOT(EventTypes.OnEndContact))        
  end
end
-------------------------------------------------------------------------------------------------
-- Music Events
-------------------------------------------------------------------------------------------------
function EventDispatcher.OnMusicStarted(music)  
  if(music.OnMusicStarted ~= nil) then
    music:OnMusicStarted(music)          
  end  
end

function EventDispatcher.OnMusicFinished(music)  
  if(music.OnMusicFinished ~= nil) then
    music:OnMusicFinished(music)          
  end  
end

-------------------------------------------------------------------------------------------------
-- Sprite Events
-------------------------------------------------------------------------------------------------
function EventDispatcher.OnAnimationStarted(sprite,animation)  
  if(sprite.OnAnimationStarted ~= nil) then
    sprite:OnAnimationStarted(sprite,animation)
  else
    sprite.EventFlags = Bitwise:AND(sprite.EventFlags,Bitwise:NOT(EventTypes.OnAnimationStarted))      
  end  
end

function EventDispatcher.OnAnimationFinished(sprite,animation)  
  if(sprite.OnAnimationFinished ~= nil) then
    sprite:OnAnimationFinished(sprite,animation)  
  else
    sprite.EventFlags = Bitwise:AND(sprite.EventFlags,Bitwise:NOT(EventTypes.OnAnimationFinished))    
  end  
end


-------------------------------------------------------------------------------------------------
-- GameState Events
-------------------------------------------------------------------------------------------------

function EventDispatcher.OnLoad(state)    
  if(state.OnLoad ~= nil) then
    state:OnLoad(state)        
  end  
end

function EventDispatcher.OnStart(state)    
    if(state.OnStart ~= nil) then
    state:OnStart(state)        
  end  
end

function EventDispatcher.OnStop(state)    
  if(state.OnStop ~= nil) then
    state:OnStop(state)        
  end  
end

function EventDispatcher.OnUnload(state)
  if(state.OnUnload ~= nil) then
    state:OnUnload(state)        
  end  
end

function EventDispatcher.OnKeyDown(state,keycode)    
  if(state.OnKeyDown ~= nil) then
    state:OnKeyDown(state,keycode)  
  else
    state.EventFlags = Bitwise:AND(state.EventFlags,Bitwise:NOT(EventTypes.OnKeyDown))     
  end  
end

function EventDispatcher.OnKeyUp(state,keycode)    
  if(state.OnKeyUp ~= nil) then
    state:OnKeyUp(state,keycode)        
  else
    state.EventFlags = Bitwise:AND(state.EventFlags,Bitwise:NOT(EventTypes.OnKeyUp))    
  end  
end

function EventDispatcher.OnMouseDown(state,button)  
  if(state.OnMouseDown ~= nil) then
    state:OnMouseDown(state,button)
  else
    state.EventFlags = Bitwise:AND(state.EventFlags,Bitwise:NOT(EventTypes.OnMouseDown))    
  end  
end

function EventDispatcher.OnMouseUp(state,button)      
  if(state.OnMouseUp ~= nil) then
    state:OnMouseUp(state,button)
  else
    state.EventFlags = Bitwise:AND(state.EventFlags,Bitwise:NOT(EventTypes.OnMouseUp))    
  end  
end

function EventDispatcher.OnGameStateControllerMouseMove(state, mouse)    
  if(state.OnMouseMove ~= nil) then
    state:OnMouseMove(state, mouse  )
  else
    state.EventFlags = Bitwise:AND(state.EventFlags,Bitwise:NOT(EventTypes.OnMouseMove))    
  end  
end
function EventDispatcher.OnGameStateControllerUpdate(state)      
  if(state.OnUpdate ~= nil) then
    state:OnUpdate(state)
  else
    state.EventFlags = Bitwise:AND(state.EventFlags,Bitwise:NOT(EventTypes.OnUpdate))    
  end  
end