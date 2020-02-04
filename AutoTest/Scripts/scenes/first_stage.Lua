if(firstStage~=nil) then
	return firstStage
end

local cos = math.cos
local sin = math.sin

firstStage = GameStateController:new()

firstStage.Speed = 17

function firstStage:OnLoad(state)
	mouse:hideCursor()
	
	--Creates automatic test module
	state.autotest = state:addOverlay(dofile("scripts/test/autotest.Lua"))
	
  --Adds info panel
	state.infoPanel = state:addOverlay(dofile("scripts/tools/infoPanel.Lua"))
	state.infoPanel.Transform.position:set(530,20)
	state.infoPanel.Transform.scale:set(0.8,0.8)
	
	--Adds background
	state.background = state:addTile(dofile("scripts/entities/background.Lua"))
	
	--Creates Sound Track
	state.Music = Music:new("Assets/Music/music.ogg")
  state.Music:setVolume(40)
	
	--Adds our hero warrior
	state.warrior = self:addOverlay(dofile("scripts/entities/Warrior.Lua"))
  state.warrior.destiny = {x=250,y=360}
	state.warrior.game_state = self
	
  --Adds enemy
	state.enemy = dofile("scripts/entities/enemy.Lua")
	state.enemy.game_state = self
	state.enemy.Transform.position:set(550, 450)
		
	self:addOverlay(state.enemy)
end

function firstStage:OnStart(state)
	state.Music:Play()
end

return firstStage

