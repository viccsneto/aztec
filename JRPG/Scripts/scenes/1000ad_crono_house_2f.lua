local tmxScene = scene_controller:create('assets/maps/tmx/crono_house_2f.tmx', 'CRONO_HOUSE_2F')

function tmxScene:SceneLoad(state) 
  if (not quest_controller:get_quest_status("go_to_school")) then
    quest_controller:add_quest({key = "go_to_school", text = "PROVA ORAL DE MATEMÁTICA :cry: <br/> Vá para Catedral Escola (que fica na parte Sul do continente logo após a ponte) e se apresente para a prova oral..."})
  end
  self.curtains_sfx = Sound:new('assets/sfx/curtains.wav')   
end

function tmxScene:lucca_exit_scene()
  maincharacter():clean_action()
  maincharacter():set_can_control(false)
  local lucca = queryname("local_lucca")
  if (lucca) then
    lucca:addGameObject(sequence_controller:create({
        lucca:move_action(6 , 6, true, false),
        lucca:move_action(1.5, 6, true, false),
        lucca:move_action(1.5, 10, true, false),
        lucca:move_action(2.5, 10, true, false),
        lucca:call_action(function()
          lucca:destroy()
          maincharacter():clean_action()
          maincharacter():set_can_control(true)  
       end),
      },
      true,
      false)
    )
  end  
end

function tmxScene:lucca_suggest_talk_to_the_king()
  
  local lucca = queryname("local_lucca")
  
  if (lucca) then
    lucca:destroy()
  end
  
  lucca = spawn("local_lucca")
  lucca:to_place("Entrance")
  maincharacter():clean_action()
  maincharacter():set_can_control(false)
  lucca:addGameObject(sequence_controller:create({
      lucca:move_action(1.5, 6, false, false),
      lucca:move_action(6, 6, false, false),
      lucca:move_action(6, 4, false, false),
      lucca:call_action(function()
        self:toggle_curtains()
        dialog_controller:create("Lucca","Crono, precisamos de uma estratégia para vencer esse Robô Guardião. Ele tem uma defesa muito forte <:pensive:>...<|br/|>Venha, vamos falar com o Rei!!!","[]", "center", function (sender, opt)
                 
          tmxScene:lucca_exit_scene()
          sender:destroy()
        end)
      end)
    },
    true,
    false)
  )
end

function tmxScene:SceneStart(state)

  -- Restores Crono Energy
  local crono = maincharacter()
  local cure_amount = crono:get_max_hp() - crono:get_current_hp()

  if (crono.Transform.position.x == queryname("Bed").Transform.position.x) then   
    if (cure_amount > 0) then
      self:sleep()
    else      
      if (quest_controller:get_quest_status("defeat_guardian_robot") ~= nil) then
        if (not quest_controller:get_quest_status("talk_to_melchior")) then
          self:lucca_suggest_talk_to_the_king()
        end
      end
    end    
  end    
end


function tmxScene:sleep()
  local curtains = queryname("open_curtains")
  if (curtains.Visible) then
    self:toggle_curtains()
  end
  self:stop_music()    
  
  
  local crono = maincharacter()
  local cure_amount = crono:get_max_hp() - crono:get_current_hp()
  if (cure_amount > 0) then
    crono:apply_cure(cure_amount)
  end
  
  crono:clean_action()
    
  scene_controller:run("CRONO_HOUSE_2F", "Bed", -1, 0)
  
end

function tmxScene:toggle_curtains()
  local curtains = queryname("open_curtains")
  curtains.Visible = not curtains.Visible   
  self.curtains_sfx:Play()  
  maincharacter():face_direction(0, -1)
end

return tmxScene
 