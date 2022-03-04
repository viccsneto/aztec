local tmxScene = scene_controller:create('assets/maps/tmx/1000ad_tecgrafia_castle_1f.tmx', '1000AD_TECGRAFIA_CASTLE_1F')


function tmxScene:check_condition()
 
end

function tmxScene:SceneLoad(state)
  state.captain = queryname('captain.walking')
     
   local captain_actions = {
    state.captain:call_action(function()  state.captain.message = "Cadê o Skinner para me render? Preciso ir ao banheiro <:fearful:>" end),    
    state.captain:move_action(6.5, 52, false, false),  
    state.captain:move_action(6.5 ,40, false, false),
    state.captain:move_action(6.5, 52, false, false),
    state.captain:move_action(42.5, 52, false, false),
    state.captain:move_action(42.5, 40, false, false),
    state.captain:move_action(42.5, 52, false, false),
    state.captain:call_action(function()  state.captain.message = "Cadê o Skinner para me render? Preciso ir ao banheiro <:fearful:>" end),
    
    state.captain:call_action(function()  state.captain.message = "Ai, ai... Vou-me já que está pingando <:cold_sweat:>" end),
        
    state.captain:move_action(6.5, 52, true, false),  
    state.captain:move_action(6.5 ,40, true, false),
    state.captain:move_action(6.5, 52, true, false),
    state.captain:move_action(42.5, 52, true, false),
    state.captain:move_action(42.5, 40, true, false), 
    state.captain:move_action(42.5, 52, true, false),
    state.captain:call_action(function()  state.captain.message = "Ai, ai... Vou-me já que está pingando <:cold_sweat:>" end),
    
    state.captain:call_action(function()  state.captain.message = "Talvez... se eu andar... bem devagarzinho <:sweat:>..." end),     
    state.captain:move_action(6.5, 52, false, true),  
    state.captain:move_action(6.5 ,40, false, true),
    state.captain:move_action(6.5, 52, false, true),
    state.captain:move_action(42.5, 52, false, true),
    state.captain:move_action(42.5, 40, false, true),
    state.captain:move_action(42.5, 52, false, true),
    state.captain:call_action(function()  state.captain.message = "Talvez... se eu andar... bem devagarzinho <:sweat:>..." end),
         
  }
      
  state.captain.sequence = state:add(sequence_controller:create(captain_actions, true, true))
    
   local chanceler = queryname("chanceler")
    if (chanceler ~= nil) then
      chanceler:face_direction(-1, 0)      
      chanceler:setProperty("Action", "queryname('chanceler'):interact()")
    end
    
  function chanceler:interact()  
    if (quest_controller:get_quest_status("defeat_guardian_robot") ~= nil) then
      tell_about_melchior()
    elseif (quest_controller:get_quest_status("rescue_the_princess") ~= nil) then
      dialog_controller:create("Chanceler", "Eis a Masmorra do Infinito!!! Contamos com vocês para salvarem a princesa Nádia e o futuro do reino.", "[]", "center")
    else
      dialog_controller:create("Chanceler", "Oh meu Deus, o que será de nós sem a princesa??? <:scream:>", "[]", "center")
    end
  end
  
  local king = queryname("king")
  
  function king:interact()
    if (not quest_controller:get_quest_status("talk_to_the_king")) then
      dofile("scripts/story/the12diamonds.lua")
    elseif (quest_controller:get_quest_status("defeat_guardian_robot") ~= nil and quest_controller:get_quest_status("talk_to_melchior") == nil) then
      dialog_controller:create("Rei Willian II", "O quê? Um inimigo muito forte?! Comuniquem já o Chanceler... <:scream:>", "[]", "center")
    else
      dialog_controller:create("Rei Willian II", "Nádia... Por favor, tragam-na de volta <:pensive:>", "[]", "center")         
    end
  end
end



function tmxScene:check_unblock_dungeon_entrance()
  if (quest_controller:get_quest_status("talk_to_the_king")) then
    local soldier_left = queryname("soldier.blocking_dungeon_left")
    local soldier_right = queryname("soldier.blocking_dungeon_right")
    if (not soldier_left.has_unblocked_path) then
      soldier_left.has_unblocked_path = true
      soldier_left.sequence = soldier_left:addGameObject(
        sequence_controller:create({
          soldier_left:move_action(42, 37.5, true, false),
          soldier_left:move_action(40, 37.5, true, false),
          soldier_left:move_action(40.5, 37.5, true, false),
        },
        true,
        false)
      )
      
      soldier_right.sequence = soldier_right:addGameObject(
        sequence_controller:create({
          soldier_right:move_action(43, 37.5, true, false),
          soldier_right:move_action(45, 37.5, true, false),
          soldier_right:move_action(44.5 , 37.5, true, false),
        },
        true,
        false)
      )
    end      
  end
end

function tmxScene:infinite_dungeon_soldier_warning()
  local text = "Vocês não estão autorizados a passar... além disso, eu não entraria aí nem que me pagassem..."
  
  if (quest_controller:get_quest_status("talk_to_the_king")) then
    text = "Boa sorte, heróis!!! Tragam a princesa de volta ou estaremos perdidos <:pensive:>..."
  end
  
  dialog_controller:create("Soldado", text, "[]", "center")
end

function tmxScene:block_dungeon_entrance()
   local soldier_left = queryname("soldier.blocking_dungeon_left")   
   local soldier_right = queryname("soldier.blocking_dungeon_right")
   soldier_left.has_unblocked_path = false
   
   soldier_left.Transform.position:set(1337, 1171)
   soldier_left:face_direction(0, 1)
   
   soldier_right.Transform.position:set(1376, 1171)     
   soldier_right:face_direction(0, 1)
   
   
   
    
end

function tmxScene:teleport_to_dungeon()    
  scene_controller:run("INFINITE_DUNGEON", "Entrance", 0,  -1)
end

function tmxScene:SceneStart(state)    
  self:block_dungeon_entrance()
  --dofile("scripts/story/the12diamonds.lua")
end

function tmxScene:unblock_main_passage()

  local soldier_left = queryname("soldier.blocking_left")    
  soldier_left:addGameObject(sequence_controller:create(
    {
      soldier_left:move_action(24, 28.5, true, false),      
      soldier_left:move_action(19, 28.5, true, false),
      soldier_left:move_action(20, 28.5, true, false),
    },
    true,false))

  local soldier_right = queryname("soldier.blocking_right")    
  soldier_right:addGameObject(sequence_controller:create(
    {
      soldier_right:move_action(25, 28.5, true, false),
      soldier_right:move_action(30, 28.5, true, false) ,
      soldier_right:move_action(29, 28.5, true, false),
    },
    true,false)) 
    
  
  local captain_blocking = queryname("captain.blocking")
  captain_blocking:removeProperty("Action")
  
  captain_blocking:addGameObject(sequence_controller:create(
  {
    captain_blocking:move_action(24.5, 28, false, false),
    captain_blocking:move_action(24.5, 24, false, false),
    captain_blocking:move_action(24.5, 24.5, false, false),
  },
  true,false))             
end


function tell_about_melchior()
  dialog_controller:create("Chanceler","Se esse inimigo é mesmo tão poderoso, somente uma pessoa poderá nos ajudar... O Mago Melchior!!! Procurem-no em sua ilha, entreguem este documento e informem que o reino precisa de sua ajuda...","['Pode deixar com a gente! :sunglasses:']","center", function(sender, opt)
    sender:destroy()      
    if (not quest_controller:get_quest_status("talk_to_melchior")) then 
      quest_controller:add_quest({key="talk_to_melchior", text = "FALE COM O MAGO MELCHIOR<br/> O Chanceler disse que apenas o Mago Melchior saberá como derrotar o poderoso Robô Guardião. Encontrem-no!!!", false})
    end   
    maincharacter():clean_action()
    maincharacter():set_can_control(true)
  end)    
end

function tmxScene:check_gone_school()
    --quest_controller:add_quest({key = "talk_to_the_king", text = "VÁ ATÉ O CASTELO FALAR COM O REI <|br/|> Descubra o que de tão grave está acontecendo e o porquê de o Rei ter decretado recesso...", done = true})
  if (quest_controller:get_quest_status("talk_to_the_king") ~= nil) then    
    dialog_controller:create("Capitão","Então vocês são os heróis que a Professora Freira prometeu nos enviar? <:no_mouth:><|br/|>O Rei está esperando por vocês <:scream:>","[]","center", function(sender, opt)
      sender:destroy()            
      self:unblock_main_passage()
      maincharacter():clean_action()
      maincharacter():set_can_control(true)
    end)    
  else
    dialog_controller:create("Capitão","Vão embora, o Rei mandou dizer que não está... <:trollface:>","[]","center")    
  end  
end


function tmxScene:captain_walking_interact()
  local walking_captain = queryname("captain.walking") 
  dialog_controller:create("Capitão", walking_captain.message, "[]", "north", function(sender, opt)
    sender:destroy() 
    maincharacter():clean_action()
    maincharacter():set_can_control(true)
  end)
  
end  
return tmxScene
 