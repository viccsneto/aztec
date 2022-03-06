
local tmxScene = scene_controller:create('assets/maps/tmx/1000ad_overworld.tmx', "1000AD_OVERWORLD")

function tmxScene:SceneLoad(state)    
  minimap_controller:create()
end

function tmxScene:check_melchior_hut()

  if (quest_controller:get_quest_status("talk_to_melchior") ~= nil) then    
    scene_controller:run("MELCHIOR_HUT_1F", "Entrance", 0,-1)
  else
    dialog_controller:create("Lucca","Não parece ter gente em casa...","[]","center")
  end
end

function tmxScene:SceneStart(state)
  
end

function tmxScene:check_sword_making_objectives(objective)
  if (quest_controller:get_quest_status("find_carbon") == nil) then
    return
  end
  quest_controller:set_quest_status(objective, true)
  
  
  destroyname(objective)
  local found_carbon = quest_controller:get_quest_status("find_carbon")
  local found_silica = quest_controller:get_quest_status("find_silica")
  local found_copper = quest_controller:get_quest_status("find_copper") 
  
  if (found_carbon and found_silica and found_copper) then
    dialog_controller:create("Lucca","Viva Crono!!! Conseguimos todos os ingredientes <:joy:>... vamos falar com o Melchior...","[]","center")
  else
    local items = ""
    items = items .. (found_copper and "" or "cobre... ")    
    items = items .. (found_silica and "" or "sílica... ")
    items = items .. (found_carbon and "" or "carbono... ")
    
    
    
    dialog_controller:create("Lucca","Legal, Crono!!! Encontramos mais um ingrediente <:sunglasses:>, mas ainda precisamos conseguir: "..items,"[]","center")
  end
end
return tmxScene
 