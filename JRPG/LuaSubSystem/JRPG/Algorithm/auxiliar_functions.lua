-----------------------------------------  
-- Auxiliar syntatic suggar functions --
-----------------------------------------

---
-- Returns the active GameStateController
-- @return #GameStateController
function gamestate()
  return engine:getCurrentGameState()
end  

---
-- Returns the GameObjects in the current GameStateController that has the desired property with the given value assigned
-- @param #string property The property name that will be queried
-- @param #string value The value that will be used as filter for the query
-- @return #GameObjectList
function query(property, value)  
  if (value == nil) then
    value = ""
  end
  return gamestate():queryProperty(property, value)
end

---
-- Returns the main character
-- @return #character
function maincharacter()  
  return query("main_character", "true"):next()
end

---
-- Returns the GameObjects in the current GameStateController that has the given name
-- @return #GameObject
function queryname(name)
  return query("Name", name):next()
end    

---
--Destroy the GameObjects in the current GameStateController that has the desired property with the given value assigned
-- @param #string property The property name that will be queried for destruction
-- @param #string value The value that will be used as filter for the destruction
-- @return #boolean Indicates if the function has destroyed some object
function destroy(property, value)
  local gamelist = query(property, value)
  
  if (gamelist:getSize() == 0) then
    return false 
  end
  
  while(gamelist:hasNext()) do
    local to_destroy = gamelist:next()
    to_destroy:destroy()
  end
  
  return true
end

---
-- Destroy the GameObjects in the current GameStateController that has the given name
-- @param #string name The name of the object to be destroyed
-- @return #boolean Indicates if the function has destroyed the object
function destroyname(name)
  return destroy("Name", name)
end

---
-- Destroy the GameObjectname if it is valid
-- @param #GameObject obj
-- @return #boolean Indicates if the function has destroyed the object
function destroyobj(obj)
  if (obj) then
    obj:destroy()  
    return true  
  end
  return false
end

---
-- Spawns entity (if it is not spawned already) of the given name to the nth(or default 1) layer of the current scene
-- @param #string name The name of the entity
-- @param #number layer_id The layer id where the entity will be instanced (implies zorder)
-- @return #character
function spawn(name, layer_id)
  
  if (type(layer_id) ~= "number") then    
    layer_id = 1
  end
     
  local entity = queryname(name)
  
  if (not entity) then    
    local source_name = name
    local separator_pos = string.find(source_name, "[.]")
    if (type(separator_pos) == "number") then
      source_name = string.sub(source_name, 1, separator_pos - 1)
    end
    entity = dofile("scripts/entities/"..source_name..".lua")
    entity:setProperty("Name", name)        
  end
  
  if (entity) then
    return gamestate():add(entity, layer_id)
  end
  
  return nil    
end

-----------------------------------------  
-- Mathematics 
-----------------------------------------

---
-- Rounds a value to it's nearest integer
-- @param #number value The value that will be rounded
-- @return #number The rounded value
function round(value)
  return math.floor(value + 0.5)
end

local default_threshold = 1

----
-- Considering a threshold, translates a value into -1, 0, 1
-- 
-- Considering a threshold, translates a value into the following representations
--    negative values: -1
--    non-zero positive values: 1
--    -threshold >= value <= threshold: 0
-- @param #number value The value that will be normalized
-- @param #number threshold The tolerance for normalizing a number   
-- @return #number A value among -1, 0, 1 
function normalize(value, threshold)
  if (type(threshold) ~= "number") then
    threshold = default_threshold
  end
  if (value >= threshold) then
    return 1
  elseif (value <= -threshold) then
    return -1
  end
  return 0
end

-- The following snippet allows for a better random behavior
-- source: http://lua-users.org/wiki/MathLibraryTutorial
-- Initialize the pseudo random number generator
math.randomseed( os.time() )
math.random(); math.random(); math.random()
-- done. :-)
-- improving the built-in pseudorandom generator
do
   local oldrandom = math.random
   local randomtable
   math.random = function ()
      if randomtable == nil then
         randomtable = {}
         for i = 1, 97 do
            randomtable[i] = oldrandom()
         end
      end
      local x = oldrandom()
      local i = 1 + math.floor(97*x)
      x, randomtable[i] = randomtable[i], x
      return x
   end
end
------------------------------------------------------------

function set_camera_position(x, y, limit)
  local camera = gamestate():getActiveCamera()
  local new_x = x
  local new_y = y
  
  if (limit) then           
    local scene_width =  tonumber(gamestate():getProperty("Width")) * 32
    local scene_height = tonumber(gamestate():getProperty("Height")) * 32
      
    local half_width = math.min(Config.SCREEN_WIDTH, scene_width) / 2
    local half_height = math.min(Config.SCREEN_HEIGHT, scene_height) / 2            
      
      
    if (new_x + half_width > scene_width ) then
      new_x = scene_width - half_width
    elseif (new_x - half_width < 0 ) then
      new_x = half_width
    end
      
    if (new_y + half_height > scene_height ) then
      new_y = scene_height - half_height                  
    elseif (new_y - half_height < 0 ) then
      new_y = half_height
    end     
  end
  
  camera.Transform.position:set(new_x, new_y)    
  
end