local tmxScene = scene_controller:create('assets/maps/tmx/1000ad_cathedral_school_1f.tmx', '1000AD_CATHEDRAL_SCHOOL_1F')

function tmxScene:check_condition()
 
end



function tmxScene:SceneLoad(state)
  state.Nun = queryname("Nun")
  state.player_controller = maincharacter()
  state.lucca = queryname("local_lucca")
  function state.lucca:interact()
    dialog_controller:create("Lucca", "Viiish <:confused:>...", "[]", "center", function(self, opt)
          print("Answered "..opt.value..","..opt.index)
          state.player_controller:clean_action()
          state.player_controller:set_can_control(true)
          self:destroy()   
     end)
  end
  
  function state.Nun:interact()
       
    if (quest_controller:get_quest_status("find_princess")) then
      dofile("scripts/story/conclusion.lua")
      return
    elseif (quest_controller:get_quest_status("talk_to_the_king") ~= nil) then
      dialog_controller:create("Professora Freira", "Isso � tudo que eu sei... <:pensive:>", "[]", "center",           
        function(self, opt)
          print("Answered "..opt.value..","..opt.index)
          state.player_controller:clean_action()
          state.player_controller:set_can_control(true)
          self:destroy()    
        end
      )                  
      return
    end    
    
    local questions = {}
    local n_question = 5;
    local current_question = 1
    questions[1] = {question = "Ol�, eu sou N�d... cof cof... a nova Professora de voc�s, mas...", options = "[]"}
    questions[2] = {question = "Voc�s n�o est�o sabendo? Hoje n�o haver� aula...", options = "['Por qu�?', 'Vivaaa <:laughing:>!!!']", correct_index = 0}
    questions[3] = {question = "Nossa majestade, o Rei, decretou recesso em todo o reino de Tecgrafia at� que... at� que uma situa��o muito grave seja resolvida :/", options = "[]"}
    questions[4] = {question = "O mensageiro disse ser algo que pode afetar o destino de todos n�s, alguma coisa sobre monstros e cristais m�gicos que eu n�o entendi direito...<|br/|>Pap... cof, cof...<|br/|>Desculpem-me! O Rei as vezes n�o fala coisa com coisa, talvez voc�s possam descobrir algo no castelo.", options = "['E essa tosse a�?! Quer uma bala Halls?', 'Certo, vamos l� tentar descobrir o que se passa <:neutral_face:>']", correct_index = 1}
    questions[5] = {question = "Boa sorte! <:pensive:>", options="[]", position = "center"}
        
    dialog_controller:create("Freira", questions[current_question].question, questions[current_question].options, "north",
      function(self, opt)
        if (questions[current_question].options ~="[]" and opt.index ~= questions[current_question].correct_index) then      
          self:setup("Professora Freira", "Muito engra�adinho voc� <:unamused:>...<|br/|>"..questions[current_question].question, questions[current_question].options, "south", self.answered)
        else
          current_question = current_question + 1
          if (current_question <= n_question) then
            self:setup("Professora Freira", questions[current_question].question, questions[current_question].options, questions[current_question].position, self.answered)      
          else      
            quest_controller:set_quest_status("go_to_school", true)
            
            quest_controller:add_quest({key = "talk_to_the_king", text = "V� AT� O CASTELO FALAR COM O REI <|br/|> Descubra o que de t�o grave est� acontecendo e o porqu� de o Rei ter decretado recesso...", done = false})          
            state.player_controller:clean_action()
            state.player_controller:set_can_control(true)
            self:destroy()          
          end
        end         
      end
    )    
  end
end

function tmxScene:SceneStart(state)
    
end

return tmxScene