-----------------------------------------
-- This modules implements a minimap component (GPS like, somewhat) to be shown at the overworld scene
-- It is concepted to help the player know in what cartesian coordinate of the map he actually is
-- With this functionality, it is easy to make mathematical challenges whose the correct solution corresponds to
-- a geografic point of interest
-- @type  minimap_controller  
-------------------------------------------
minimap_controller = {
  __private = {
    last_coords = {x = 0, y= 0},
    tile_size = 32,
    width = 375,
    height = 255
  }
}

---
-- Creates the minimap and places it at the bottom right side of the screen
-- @return #minimap
function minimap_controller:create()
  
  ---
  -- Uses a chromium instance to render and control the dialog (implemented with web technologies)
  -- @type minimap
  local minimap = WebBrowser:new ("", minimap_controller.__private.width, minimap_controller.__private.height, true)
  minimap:setProperty("Name", "minimap")  
  minimap:Navigate("file:///LuaSubSystem/JRPG/UI/minimap/minimap.html");
  --[[
  local grayscale = Shader:createFromFiles(nil, 'shaders/grayscale.fs')
  minimap:setShader(grayscale)
  --]]
  
  
  minimap.__private = minimap_controller.__private;
  
  -- Puts the web render component in the actual scene in an unusually very high layer order. This way it will almost certainly be shown in front of all other components
  engine:getCurrentGameState():add(minimap, 1000000)
  
  -- Offers an API to update the current player position in the map
  function minimap:setup(x, y)
    x = string.format("%.1f", x / minimap.__private.tile_size)
    y = string.format("%.1f", y / minimap.__private.tile_size)
    
    -- check if the minimap is not updated already
    if (minimap.__private.last_coords.x ~= x or minimap.__private.last_coords.y ~= y) then    
      minimap.script_to_execute = "setPosition("..x..","..y..")"
      minimap.__private.last_coords.x = x 
      minimap.__private.last_coords.y = y
    end              
  end
          
  -- Controls the minimap execution
  function minimap:OnUpdate(sender)    
    local state  = engine:getCurrentGameState()
    local camera = state:getActiveCamera()
    
    local player = maincharacter()
    if (player ~= nil) then
      minimap:setup(player.Transform.position.x, player.Transform.position.y)
    end
    
    if (not sender:isLoading() and sender.script_to_execute ~= nil) then     
      sender:ExecuteScript(sender.script_to_execute)
      sender.script_to_execute = nil
    end
    
    sender.Transform.position:set(camera.Transform.position.x + (Config.SCREEN_WIDTH / 2) - self.__private.width - 5  ,camera.Transform.position.y + Config.SCREEN_HEIGHT / 2 - self.__private.height - 5)    
  end
      
  return minimap
end