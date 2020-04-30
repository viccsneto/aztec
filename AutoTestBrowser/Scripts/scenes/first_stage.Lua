if(firstStage~=nil) then
  return firstStage
end

local cos = math.cos
local sin = math.sin

firstStage = GameStateController:new()

firstStage.Speed = 17

function CreateBrowser(state)
  if (not state.browser) then
    state.browser = state:addOverlay(WebBrowser:new("https://www.youtube.com/watch?v=l15PDRSTn7s&feature=youtu.be&t=0", 800, 600, true))
    state.browser.speed = 5
    state.browser.x_dir = 1
    state.browser.y_dir = 1
    
    state.browser.x_min = 0
    state.browser.y_min = 0
    
    state.browser.x_max = 1024 - 800
    state.browser.y_max = 768 - 600

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
  end
end

function DestroyBrowser(state)
  if (state.browser) then
    state.browser:destroy()
    state.browser = nil
  end
end
   
function firstStage:OnLoad(state)
  --mouse:hideCursor()
  
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
  state.Music:setVolume(0.1)
  
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
  --state.Music:Play()
  CreateBrowser(state)
end

function firstStage:OnUpdate(state)
  if (keyboard:keyIsDown(Keyboard.KEY_ESCAPE)) then
    engine:run(editorScene)
  end
end

function firstStage:OnStop(state)
  DestroyBrowser(state)
end

return firstStage

