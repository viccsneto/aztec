local tmxScene = scene_controller:create('assets/maps/tmx/infinite_dungeon.tmx', 'INFINITE_DUNGEON')

tmxScene.__private = {
  current_level = 0,
  max_level = 6,
  show_answer_for = {},
  right_answers = {
    'B',
    'A',
    'B',
    'C',
    'E',
    'THERE_IS_NO_RIGHT_ANSWER'
  },

  monsters = {        
    'local_imp',
    'local_imp',
    'local_imp',
    'local_redimp',
    'local_redimp',
    'local_robo'
  }
}

function tmxScene:choose_letter(letter)
  local current_level = self.__private.current_level 
  if (current_level == 0 or self.__private.right_answers[current_level] == letter) then
    current_level = current_level + 1
  elseif (current_level == self.__private.max_level and queryname("local_monster"):get_current_hp() == 0) then  
    scene_controller:run("1000AD_OVERWORLD", "Castle", 0,1)
    return
  else
    current_level = current_level - 1
    local damage = maincharacter():get_battle_defense()
    if (maincharacter():get_current_hp() > 10) then
      damage = damage + 10
    else
      damage = damage + maincharacter():get_current_hp() - 1
    end
    maincharacter():battle_attacked(damage)
  end
  
  if (current_level < 1) then
    current_level = 1
  elseif (current_level > self.__private.max_level) then
    current_level =  self.__private.max_level
  end

  self.__private.current_level = current_level

  scene_controller:run("INFINITE_DUNGEON", "Entrance", 0,1)
end

function tmxScene:battle()
  local challenge = queryname("challenge")
  challenge:embed("")
  
  local crono = maincharacter()
  local enemy = queryname("local_monster")
  
  if (enemy:get_current_hp() == 0) then
    if (self.__private.current_level == self.__private.max_level) then
      dialog_controller:create("Robô Guardião", "Falha no sist :capital_abcd: :warning: :interrobang: :top: :top: :top: subject not found :bangbang: <|br/|>Princesa Nádia não se encontra no castel :clock1130: Localização estim :o: ad :a: : (x = 19, y = 36)<|br/|>Localização estimada: (x = 19, y = 36) <|br/|>Kernel Panic!","[]", "center")
      quest_controller:set_quest_status("defeat_guardian_robot", true)      
      quest_controller:add_quest({key="find_princess", text = "ENCONTRE A PRINCESA<|br/|> Após derrotar o Robô Guardião, você descobriu que a localização estimada da Princesa Nádia é (x = 19, y = 36), nem precisa calcular...", done = true})
    end          
    return
  end           

  if (crono:get_current_hp() > 0) then
    if (self.__private.current_level == self.__private.max_level) then
      if (not quest_controller:get_quest_status("defeat_guardian_robot")) then
        quest_controller:add_quest({key="defeat_guardian_robot", text = "DERROTE O ROBÔ GUARDIÃO<|br/|> Ao que tudo indica, para resgatar a princesa vocês precisarão derrotar o poderoso Robô Guardião da Masmorra Infinita...", false})
      end
    end
    local crono_actions = {
      crono:move_action(10,13, true, false),
      crono:face_direction_action(1, 0),
      crono:call_action(function () battle_controller:create({crono},{enemy}) end),
    }
    tmxScene:add(sequence_controller:create(crono_actions, true, false))
  end
end

function fade_maincharacter()
  local lucca = spawn("local_lucca")

  function lucca:interact()
    local tablet = gamestate():add(WebBrowser:new("file:///assets/html/challenges/tablet.html",1024, 768, true), 1000000000)
    tablet:setAlwaysFocused(true)
    function tablet:embed(question_id, answer_id)
      self.question_id = question_id
      self.answer_id = answer_id
    end


    function tablet:OnUpdate(sender)
      if (sender.question_id ~= nil) then
        if (not sender:isLoading()) then
          sender:ExecuteScript('embed("'..sender.question_id..'","'..sender.answer_id..'")')
          sender.question_id = nil
        end
      end
    end
    local state = gamestate()
    local current_level = state.__private.current_level
    if (current_level == 0) then
      tablet:embed("images/intro.png", "")
    elseif (current_level == state.__private.max_level ) then
      tablet:embed("images/final.png", "")
    else
      if (state.__private.show_answer_for[current_level]) then
        tablet:embed("images/question"..current_level..".png", "images/question"..current_level.."_answer.png")
      else
        tablet:embed("images/question"..current_level..".png", "")
      end
    end

    function tablet:close()
      self:destroy()
    end

    function tablet:OnDestroy(sender)
      maincharacter():set_can_control(true)
    end

    maincharacter():clean_action()
    maincharacter():set_can_control(false)

  end
  lucca:to_place("Entrance")
  local action = {
    __private = {
      count = 0,
      max = 50,
      last_update = 0,
      interval = 0.01 ,
    }
  }

  function action:started()
    local sfx = Sound:new("assets/sfx/Sealeddooropening.wav")
    sfx:Play()
    self.__private.count = 0
    self.__private.last_update = engine:getCurrentTime()
  end

  function action:step()
    local character = maincharacter()
    local current_time = engine:getCurrentTime()
    if (current_time - self.__private.last_update > self.__private.interval) then
      self.__private.count = self.__private.count + 1
      self.__private.last_update = current_time
      if (self.__private.count > self.__private.max) then
        gamestate():add(sequence_controller:create({lucca:move_action(9.5, 15.0 ,false,true),lucca:move_action(10, 15.0 ,false,true)}, true, false))
        return true
      end
      local balance = self.__private.count / self.__private.max
      character:get_sprite():getPlane():setColorBalance(1,1,1, balance)
      lucca:get_sprite():getPlane():setColorBalance(1,1,1, balance)

    end
    return false
  end

  gamestate():add(sequence_controller:create({action},true,false))
end

function tmxScene:show_current_challenge()
  local challenge = queryname("challenge")
  if (self.__private.current_level == 0) then
    challenge:embed("movies/intro.webm")
  elseif (self.__private.current_level == self.__private.max_level) then 
    challenge:embed("movies/final.webm")
  else
    challenge:embed("movies/level"..self.__private.current_level..".webm")
  end
end
function tmxScene:SceneStart(state)

  fade_maincharacter()
  self:spawn_monster()
  
  self:show_current_challenge()
end

function tmxScene:OnStop(state)
  state.Music:setVolume(1.0)
  local challenge = queryname("challenge")
  if (challenge) then
    challenge:embed("")
  end
end

function tmxScene:spawn_monster()
  

  local monster = queryname("local_monster")
  if (monster) then
    monster:destroy()
  end
  
  if (self.__private.current_level == 0) then
    monster = spawn("local_imp", maincharacter():getLayerID())
    
    function monster:interact()
      dialog_controller:create("Lacaio", "Você não precisa me derrotar no nível introdutório, calouro... Escolha logo uma porta e vaze daqui <:unamused:>.<|br/|> Ou então... atice as chamas e vamos aprender algo novo (eu adoro a do Donald) <:joy:>", "[]", "center")    
    end
  else
    local monster_name = self.__private.monsters[self.__private.current_level]
    
    monster = spawn(monster_name, maincharacter():getLayerID())
    
  
    function monster:on_battle_finished()
      if (self:get_current_hp() == 0 ) then
        if (self.__private.current_level == self.__private.max_level) then
          quest_controller:set_quest_status("defeat_guardian_robot", true)
          monster:interact()
        end
        tmxScene.__private.show_answer_for[tmxScene.__private.current_level] = true
      end
    end
  
    function monster:interact()
      tmxScene:battle()    
    end
  end
  
  monster:setProperty("Name", "local_monster")
  monster:setProperty("Action", "queryname('local_monster'):interact()")
  monster:apply_cure(monster:get_max_hp())
  monster:set_blocked(true)
  monster:set_position(23, 13)
  monster:face_direction(-1, 0)
  
end

function tmxScene:SceneLoad(state)

  local challenge = queryname("challenge")
  if (not challenge) then
    challenge = WebBrowser:new("file:///assets/html/challenges/viewer.html",640 * 0.6, 360 * 0.6, true)
    challenge.Transform.position:set(320,246)
    challenge:setProperty("Name","challenge")
    state:add(challenge, 4)
  end

  function challenge:embed(video_url)
    self.video_url = video_url
  end
  
  function challenge:embed_youtube(youtube_id)
    self.youtube_id = youtube_id
  end

  function challenge:OnUpdate(sender)
    if (not sender:isLoading()) then
      if (sender.video_url ~= nil) then      
        print("embedding video: "..sender.video_url)
        sender:ExecuteScript('embed("'..sender.video_url..'")')
        sender.video_url = nil            
      elseif (sender.youtube_id ~= nil) then      
        print("embedding video from youtube: "..sender.youtube_id)
        sender:ExecuteScript('embed_youtube("'..sender.youtube_id..'")')
        sender.youtube_id = nil
      end
    end
  end
end

local volume = 1

function tmxScene:OnKeyDown(state, keycode)
  if (keycode == keyboard.KEY_KP_PLUS) then
    volume = volume + 0.01
  elseif (keycode == keyboard.KEY_KP_MINUS) then
    volume = volume - 0.01
  end

  if (volume < 0) then
    volume = 0
  elseif (volume > 1) then
    volume = 1
  end

  if (state.Music) then
    if (state.Music:isPlaying()) then
      state.Music:setVolume(volume)
    end
  end
end

return tmxScene


 