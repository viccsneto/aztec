if(successScene~=nil) then
	return successScene
end

successScene = GameStateController:new()


function successScene:OnLoad(state)
		
	mouse:showCursor()
	state.Music = Music:new("Assets/Music/success.ogg")
	state.Music.Repeat = false
	state.Music:setVolume(0.0)
	
	state.background = state:addTile(Sprite:new("Assets/Image/success.png"))
      
	function state.background:OnUpdate(sender)
		if(keyboard:keyIsDown(Keyboard.KEY_ESCAPE)) then
			engine:requestShutdown()
		end
	end
  
  --state.browser = state:addOverlay(WebBrowser:new("https://www.youtube.com/watch?v=SImHi16cwqc&feature=youtu.be&t=0", 800, 600, true))
  state.browser = state:addOverlay(WebBrowser:new("https://www.youtube.com/watch?v=l15PDRSTn7s&feature=youtu.be&t=0", 800, 600, true))
  
  --state.browser:getPlane():setColorBalance(1,1,1,0.9)
  state.browser.speed = 5
  state.browser.x_dir = 1
  state.browser.y_dir = 1
  
  state.browser.x_min = 0
  state.browser.y_min = 0
  
  state.browser.x_max = 1024 - 800
  state.browser.y_max = 768 - 600
  
  ---[[
  function state.browser:OnUpdate(sender)    
		self.Transform.position.x = self.Transform.position.x + self.x_dir * self.speed * engine:getElapsedTime()
    self.Transform.position.y = self.Transform.position.y + self.y_dir * self.speed * engine:getElapsedTime()
    if (self.Transform.position.x < self.x_min) then
      self.Transform.position.x = self.x_min
      self.x_dir = 1
    elseif (self.Transform.position.x > self.x_max) then
      self.Transform.position.x = self.x_max
      self.x_dir = -1
    end
    
    if (self.Transform.position.y < self.y_min) then
      self.Transform.position.y = self.y_min
      self.y_dir = 1
    elseif (self.Transform.position.y > self.y_max) then
      self.Transform.position.y = self.y_max
      self.y_dir = -1
    end
	end
  --]]
  
  --[[
	state.label = state:addOverlay(Text:new(255,255,0,"",26))
	state.label.Transform.position:set(220,300)
	state.label:setText("Test completed successfully!!! :)")
   
	state.infoPanel = state:addOverlay(dofile("scripts/tools/infoPanel.Lua"))
	state.infoPanel.Transform.position:set(530,20)
	state.infoPanel.Transform.scale:set(0.8,0.8)
	--]]
  
  state.warrior = self:addOverlay(dofile("scripts/entities/Warrior.Lua"))
  state.warrior.destiny = {x=250,y=360}
	state.warrior.game_state = self
  
  function state.warrior:OnUpdate(sender)
    if (not sender.positioning) then
      sender.Transform.position:set(mouse:getPosX(),mouse:getPosY())
    end
    if (mouse:isLeftButtonPressed()) then
      --sender:fire1()
    end
  end
	
end

function successScene:OnStart(state)	
	state.Music:Play()	
end

return successScene