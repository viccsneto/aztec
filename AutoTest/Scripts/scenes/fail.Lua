if(failScene~=nil) then
	return failScene
end

failScene = GameStateController:new()

function failScene:OnLoad(state)
	mouse:showCursor()
  
	state.Music = Music:new("Assets/Music/fail.ogg")
	state.Music.Repeat = false
  
	state.background = state:addTile(Sprite:new("Assets/Image/fail.png"))
  
	state.label = state:addOverlay(Text:new(255,255,0,"",18))
	state.label.Transform.scale:set(0.7,0.7)
	state.label.Transform.position:set(20,20)		
end

function failScene:OnStart(state)		
	state.Music:Play()
  if (state.message) then
    state.label:setText(state.message)
  end
end

return failScene

