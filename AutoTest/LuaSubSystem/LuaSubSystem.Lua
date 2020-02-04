--Prevents stdout buffering (Eclipse console output do not promptly prints output otherwise) 
io.stdout:setvbuf('no')

--Creates a table to hold every GameObject that is instantiated
__AztecBindedObjects =
{
	count = 0,
	objects={}
}

--Initializes event subsystem
dofile("LuaSubSystem/Events/Events.Lua")

-- Simplifies access to common componentes
function __Aztec__InitializeCommonComponents() 
  engine   = GameEngine:getInstance()
  mouse    = engine:getMouse()
  keyboard = engine:getKeyboard()
end