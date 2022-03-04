local tmxScene = scene_controller:create('assets/maps/tmx/1000AD_the_end.tmx', '1000AD_THE_END')

local function finish()
  engine:requestShutdown()
end

function tmxScene:fade_in_background()
  local background = queryname("BackgroundImage")
  background:getPlane():setColorBalance(1, 1, 1, 0)
  local timer = timer_controller:create(0.03)
  local state = gamestate()

  timer.step = 0
  timer.max = 100

  state:add(timer,0)

  function timer:timeout(sender)
    sender.step = sender.step + 1
    if (sender.step < state.timer.max ) then
      sender:reset()
    else      
      sender:destroy()
    end
  end

  function timer:update(sender)
    local balance_value = (sender.step / sender.max)
    background:getPlane():setColorBalance(balance_value, balance_value, balance_value, balance_value)
    
  end
end

function tmxScene:SceneStart(state)
  local music = state.Music
  music.Loop = false
  function music:OnMusicFinished(music)
    finish()  
  end
  
  self:fade_in_background()
end

function tmxScene:SceneLoad(state)
  
  local background = Sprite:new("assets/maps/tilesets/the_end.png")
  background:setProperty("Name", "BackgroundImage")
  state:add(background, 0)
  
end    


function tmxScene:OnKeyUp(state,keycode)    
  if (keycode == keyboard.KEY_ESCAPE) then
    finish()
  end 
end

return tmxScene