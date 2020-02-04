if(successScene~=nil) then
	return successScene
end

successScene = GameStateController:new()


function successScene:OnLoad(state)
		
	mouse:showCursor()
	state.Music = Music:new("Assets/Music/success.ogg")
	state.Music.Repeat = false
	state.Music:setVolume(10)
	
	state.background = state:addTile(Sprite:new("Assets/Image/success.png"))
    
	function state.background:OnUpdate(sender)
		if(keyboard:keyIsDown(Keyboard.KEY_ESCAPE)) then
			engine:requestShutdown()
		end
	end
  
	state.label = state:addOverlay(Text:new(255,255,0,"",26))
	state.label.Transform.position:set(220,300)
	state.label:setText("Test completed successfully!!! :)")
   
	state.infoPanel = state:addOverlay(dofile("scripts/tools/infoPanel.Lua"))
	state.infoPanel.Transform.position:set(530,20)
	state.infoPanel.Transform.scale:set(0.8,0.8)
	
  
  state.warrior = self:addOverlay(dofile("scripts/entities/Warrior.Lua"))
  state.warrior.destiny = {x=250,y=360}
	state.warrior.game_state = self
  
  function state.warrior:OnUpdate(sender)
    if (not sender.positioning) then
      sender.Transform.position:set(mouse:getPosX(),mouse:getPosY())
    end
    if (mouse:isLeftButtonPressed()) then
      sender:fire1()
    end
  end
	
end

function successScene:OnStart(state)	
	state.Music:Play()	
end

return successScene