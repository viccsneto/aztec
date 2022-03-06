local tmxScene = scene_controller:create('assets/maps/tmx/crono_house_1f.tmx', 'CRONO_HOUSE_1F')


function tmxScene:lucca_prevents_exit()
  if (not quest_controller:get_quest_status("multiplying_table")) then
    quest_controller:add_quest({key = "multiplying_table", text = "PRATIQUE A TABUADA <|br/|> Lucca e voc� combinaram de praticar um pouco de tabuada antes da prova oral de matem�tica."})
  end
  dialog_controller:create("Lucca", "Aonde voc� pensa que vai? N�o se esque�a que hoje vai ter prova oral e que n�s combinamos de treinar a tabuada antes de ir para escola...<|br/|>Voc� faltou a P1 e se for mal nessa vai ser transferido para a AMAE (Associa��o dos Moleques Analfabetos Exclu�dos) <:cry:>", "[]", "north",
        function (self, opt)
          self:destroy()      
          
          local crono_actions = {
            maincharacter():move_action(21,15, false, true),
            maincharacter():move_action(17.5,15, true, false),
            maincharacter():move_action(17.5, 10.5, false, false),
            maincharacter():move_action(16.5 ,10, false, false),
            maincharacter():cancontrol_action(),
          }
          
          tmxScene:add(sequence_controller:create(crono_actions, true))
        end
      )  
   maincharacter():face_direction(0, -1)
end

function tmxScene:lucca_exits()
  local lucca = queryname("local_lucca") 
   local lucca_actions = {
      
      lucca:move_action(17.5,10, false, false),
      lucca:move_action(17.5,12, false, false),
      lucca:move_action(17.5,15, true, false),
      lucca:move_action(21,15, true, false),
      lucca:move_action(21,17, true, false),
      lucca:call_action ( function() lucca:destroy() end)
    }
  
    self:add(sequence_controller:create(lucca_actions, true, false))
end

function tmxScene:lucca_enters()

  if (queryname("local_lucca") == nil) then      
    local lucca = spawn("local_lucca")
    lucca:to_place("Outside")
    
    lucca:face_direction(0, 1)
    maincharacter():set_can_control(false)
    
    local lucca_actions = {
      lucca:move_action(21,15, false, false),
      lucca:move_action(17.5,15, false, false),
      lucca:move_action(17.5,10, false, false),
      lucca:move_action(16, 10, false, false),
      lucca:face_direction_action(1, 0),
      lucca:call_action ( function() self:lucca_prevents_exit() end)
    }
  
    self:add(sequence_controller:create(lucca_actions, true, false))
    
    lucca:setProperty("Action", "queryname('local_lucca'):interact()")   

    function lucca:interact()
      if (quest_controller:get_quest_status("multiplying_table")) then
        dialog_controller:create("Lucca", "Muito bem, senhor apressadinho!!!<|br/|>Podemos ir para escola agora <:smile:>", "[]", "center",
          function(self, opt)
            print("Answered "..opt.value..","..opt.index)
            maincharacter():clean_action()
            maincharacter():set_can_control(true)
            self:destroy()
            tmxScene:lucca_exits()
          end
        )
        return
      end

      local questions = {}
      local n_question = 6;
      local current_question = 1
      questions[1] = {question = "De cor e saltiado hein?!<|br/|>Quanto � 2 x 2?", options = "['2', '6', '4', 'N�o sei...']", correct_index = 2}
      questions[2] = {question = "Quanto � 2 x 5?", options = "['10', '2', '5', '25']", correct_index = 0}
      questions[3] = {question = "Vamos l�, 5 x 7?", options = "['57', '75', '35', 'Posso usar a calculadora?']", correct_index = 2}  
      questions[4] = {question = "Hmmm, 7 x 5?", options = "['57', '75', '35, como na anterior <:unamused:> ...', '53']", correct_index = 2}
      questions[5] = {question = "Certo, 8 x 8?", options = "['88', '64', '16', 'Vish... nenhuma das anteriores?']", correct_index = 1}
      questions[6] = {question = "Hahahaha voc� est� arrasando, Crono <%:joy::clap::clap:<br/>%> Quanto � <%`sum_(n=1)^(2^64) ((n(n+1))/2)^2 ?`%>", options="['42', 'Ah, voc� s� pode estar brincando... isso n�o � tabuada <:rage:>']", correct_index = 1}
  
      dialog_controller:create("Lucca", questions[current_question].question, questions[current_question].options, "north",
        function(self, opt)
          if (opt.index ~= questions[current_question].correct_index) then
            self:setup("Lucca", "N�o, pense mais um pouco...<|br/|>"..questions[current_question].question, questions[current_question].options, "south", self.answered)
          else
            current_question = current_question + 1
            if (current_question <= n_question) then
              self:setup("Lucca", questions[current_question].question, questions[current_question].options, "north", self.answered)
            else
              quest_controller:set_quest_status("multiplying_table", true)
              maincharacter():clean_action()
              maincharacter():set_can_control(true)
              self:destroy()
              queryname("local_lucca"):interact()
            end            
          end
        end)
      end
    else
    self:lucca_prevents_exit()
   end
end

function tmxScene:check_condition()
  if(quest_controller:get_quest_status("multiplying_table")) then    
    scene_controller:run("1000AD_OVERWORLD", "Crono_House", 0, 1)
  else
    self:lucca_enters()
  end
end

function tmxScene:SceneStart(state)
--state:add(dofile("Scripts/dialogs/lucca_tabuada.lua"))
end

function tmxScene:SceneLoad(state)


end

return tmxScene

 