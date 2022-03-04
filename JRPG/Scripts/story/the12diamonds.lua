dofile("scripts/story/tell_story_table.lua")

local function generate_latex_division(heirs)
  
  local latex = "<%$$ \\\\frac{12 \\\\mbox{ diamantes}}{"..tostring(#heirs)
  if (#heirs == 1) then
    latex = latex.." \\\\mbox{ herdeiro}} = "
  else
    latex = latex.." \\\\mbox{ herdeiros}} = "
  end
  latex = latex.."\\\\begin{cases} "
  
  if (#heirs == 0 ) then
    latex = latex.."??? \\\\mbox{ diamantes para ???} \\\\\\\\ "
  else
    local diamonds_per_heir = 12 / #heirs                
  
    for i = 1, #heirs do
      latex = latex..tostring(diamonds_per_heir).." \\\\mbox{ diamantes para "..heirs[i].."} \\\\\\\\ "
    end      
  end
                            
  latex = latex.."\\\\end{cases}$$%>"
  
  return latex
              
end

local function fade_in_scenery()
  local background = query("BackgroundImage"):next()
  local overlay = query("OverlayImage"):next()
  local effects = queryname("Effects")


  local objects_layer = queryname("Objects")

  local chanceler = queryname("chanceler")

  objects_layer:addGameObject(chanceler)
  objects_layer.Visible = true
  local timer = timer_controller:create(0.01)
  local state = gamestate()

  timer.step = 0
  timer.max = 100

  state:add(timer,0)

  function timer:timeout(sender)
    sender.step = sender.step + 1
    if (sender.step < state.timer.max ) then
      sender:reset()
    else
      objects_layer.Visible = true
      effects.Visible = true
      sender:destroy()
    end
  end

  function timer:update(sender)
    local balance_value = (sender.step / sender.max)
    background:getPlane():setColorBalance(balance_value, balance_value, balance_value, balance_value)
    overlay:getPlane():setColorBalance(balance_value, balance_value, balance_value, balance_value)
  end
end

local function fade_out_scenery()
  local background = query("BackgroundImage"):next()
  local overlay = query("OverlayImage"):next()
  local effects = queryname("Effects")
  effects.Visible = false

  local objects_layer = queryname("Objects")
  objects_layer.Visible = false

  local story_layer = queryname("StoryLayer")

  local chanceler = queryname("chanceler")
  
  story_layer:addGameObject(chanceler)
  
  local timer = timer_controller:create(0.01)
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
    local balance_value = 1.0 - (sender.step / sender.max)
    background:getPlane():setColorBalance(balance_value, balance_value, balance_value,  balance_value)
    overlay:getPlane():setColorBalance(balance_value, balance_value, balance_value,  balance_value)
  end
end

local function destroy_story_image()
  local sprite = queryname("story_image")
  if (sprite) then
    sprite:destroy()
  end
end

local function destroy_second_story_image()
  local sprite = queryname("second_story_image")
  if (sprite) then
    sprite:destroy()
  end
end

local function show_story_image(path)
  destroy_story_image()
  local sprite = queryname("StoryLayer"):addGameObject(Sprite:new(path))
  sprite:setProperty("Name", "story_image")
  sprite:setZOrder(-2)
  sprite:pivotOnCenter()
  local camera = gamestate():getActiveCamera()
  sprite.Transform.position:set(camera.Transform.position.x, camera.Transform.position.y - 90)
  
  sprite:getPlane():setColorBalance( 1, 1, 1, 0)
  sprite.timer = sprite:addGameObject(timer_controller:create(0.005))  

  sprite.timer.step = 0
  sprite.timer.max = 100

  function sprite.timer:timeout(sender)
    sender.step = sender.step + 1
    if (sender.step < sender.max ) then
      sender:reset()
    else
      sender:destroy()
    end
  end

  function sprite.timer:update(sender)
    local balance_value = (sender.step / sender.max)
    sprite:getPlane():setColorBalance(1, 1, 1, balance_value)
  end  
end

local function show_second_story_image(path)
  destroy_second_story_image()
  local sprite = queryname("StoryLayer"):addGameObject(Sprite:new(path))
  sprite:setProperty("Name", "second_story_image")
  sprite:setZOrder(-1)
  sprite:pivotOnCenter()
  local camera = gamestate():getActiveCamera()
  sprite.Transform.position:set(camera.Transform.position.x, camera.Transform.position.y - 90)
  
  sprite:getPlane():setColorBalance( 1, 1, 1, 0)
  sprite.timer = sprite:addGameObject(timer_controller:create(0.005))  

  sprite.timer.step = 0
  sprite.timer.max = 100

  function sprite.timer:timeout(sender)
    sender.step = sender.step + 1
    if (sender.step < sender.max ) then
      sender:reset()
    else
      sender:destroy()
    end
  end

  function sprite.timer:update(sender)
    local balance_value = (sender.step / sender.max)
    sprite:getPlane():setColorBalance(1, 1, 1, balance_value)
  end  
end

local function king_return_scene()
  local king = queryname("king")
  king:addGameObject(
    sequence_controller:create({
      king:move_action(22.5, 26, true, false),
      king:move_action(22.5, 26.5, true, false),         
    },
    true,
    false)
  )
end

local function finish_story()
    
  local chanceler = queryname("chanceler")
  local character = maincharacter()  
  
  quest_controller:set_quest_status("talk_to_the_king", true)
  quest_controller:add_quest({key="rescue_the_princess", text = "RESGATE A PRINCESA<br/> Vocês precisam resgatar a Princesa Nádia e salvar o futuro do Reino. Nádia é a única herdeira dos diamantes que ainda pode estar viva...", false})
            
  chanceler:addGameObject(
    sequence_controller:create({
      character:call_action(function()
        character:clean_action()
        character:set_can_control(true)
        character:set_ignore_blocked_places(false)
        destroy_story_image()
        destroy_second_story_image()
        fade_in_scenery()
        king_return_scene()              
      end),
      chanceler:move_action(24.5, 52,  true, false),
      chanceler:move_action(42.5,  52, true, false),
      chanceler:move_action(42.5,  39, true, false),      
      chanceler:move_action(45.5,  39, true, false),
      chanceler:move_action(45,  39, true, false),
      
    },
    true,
    false)
  )
  
  
end



local function new_hope()

 tell_story_table(
    {
      {
        actor = "Chanceler",
        text = "Exatamente! A situação estava indefinida e ficamos desesperados quanto ao futuro de nosso reino.",
        position = "south"  
      },
      {
        actor = "Chanceler",        
        text = "Até que, quando traduzimos o antigo pergaminho que Willian III segurava durante seu faniquito, descobrimos que havia alguma esperança.", 
        position = "south"  
      },
      {
        actor = "Chanceler",
        text = "O pergaminho havia sido escrito pelos antigos construtores desse castelo e revelava que havia a possibilidade de sair com vida da masmorra maldita...",        
        position = "south"  
      },
      {
        actor = "Chanceler",
        text = "Mas apenas os mais inteligentes estariam aptos a desafiar a <%"..
          "<br/><center><h4>Masmorra Infinita</h4></center>%>", 
        position = "south"  
      },      
      {
        actor = "Chanceler",
        text = "Muito bem, vocês são os mais inteligentes e a sua sua missão é resgatar a princesa."..
          generate_latex_division({"Nádia"}), 
        position = "north 90% 150px",
        item_function = function()
            local sprite = queryname("story_image")
            sprite.death_nadia.Transform.position.y = sprite.death_nadia.Transform.position.y - 64             
            sprite.death_nadia:life()
            --[[
            local chanceler = queryname("chanceler")
            chanceler:addGameObject(sequence_controller:create({                        
                chanceler:move_action(27.5, 28, true, false),
                chanceler:move_action(27, 28, true, false),
              },
              true,
              false)
            )
            --]]            
        end,          
      },
      {
        actor = "Chanceler",
        text = "Vocês estão preparados?",
        options = "[\"Sim!!!\", \"Com certeza!!!\"]", 
        position = "center"  
      },
      {
        actor = "Chanceler",
        text = "Sigam-me!",
        position = "center",         
      },                      
    },
    finish_story
  )   
end

local function willian_III_dies()
  tell_story_table(
    {
      {
        actor = "Chanceler",
        text = "Willian III não parecia triste pela perda de seus irmãos, ele seria agora não só o próximo Rei, mas também o único herdeiro dos poderosos diamantes mágicos. ",
        position = "south"  
      },
      {
        actor = "Chanceler",
        text = "Mas... Hoje pela manhã, ouvimos um quebra-quebra vindo da biblioteca... Willian III gritava ensandecido:<|br/|>Não pode ser!!! Arrrrrrrrrrgh!!!", 
        position = "south"  
      },
      {
        actor = "Chanceler",
        text = "Quando chegamos, Willian III já estava morto... *infartou* segurando um pergaminho..." ,        
        position = "south"  
      },
      {
        actor = "Chanceler",
        text = "Dizem que ele foi assombrado por seus irmãos <:ghost:>...<|br/|> tipo aquela sombra de Game of Thrones <:joy:>... enfim.", 
        position = "south"  
      },      
      {
        actor = "Chanceler",
        text = "Agora que não havia nenhum herdeiro vivo... quem ficaria com os diamantes protetores do reino?<|br/|>"..
          generate_latex_division({}), 
        position = "north 90% 350px",
        options = "[\"Não sei... :pensive:\", \"Não há como saber!!!\"]",
        item_function = function()
            local sprite = queryname("story_image")
            sprite.death_willianIII = sprite:addGameObject(create_magic():death())
            sprite.death_willianIII.Transform.position:set(198 - 512, 392 - 280)                         
        end,
          
      },                 
    },
    new_hope
  ) 
end

local function james_dies()
  tell_story_table(
    {
      {
        actor = "Chanceler",
        text = "Não bastasse tanta desgraça, quando o Rei ordenou que pendurassem a cabeça do monstro na parede, em memória da princesa Nádia, descobriu-se que "..
          "o monstro na verdade era o príncipe James.",
        position = "south"  
      },
      {
        actor = "Chanceler",
        text = "James havia retornado de uma festa a fantasia e estava apenas fazendo uma brincadeira de mau gosto com a sua irmã... pediu pra morrer.",        
        position = "south"  
      },
      {
        actor = "Chanceler",
        text = "Assim, restava apenas Willian III:<|br/|>"..
          generate_latex_division({"Willian III"}), 
        position = "north 90% 150px",
        item_function = function()
            destroy_second_story_image()
            local sprite = queryname("story_image")
            sprite.death_james = sprite:addGameObject(create_magic():death())
            sprite.death_james.Transform.position:set(828 - 512, 392 - 280)                         
        end,   
      },      
    },
    willian_III_dies
  )
    
end





local function nadia_dies()
  tell_story_table(
      {
        {
          actor = "Chanceler",
          text  = "Algumas semanas depois, ouvimos os gritos da princesa Nádia e a avistamos sendo perseguida por um monstro que urrava:<|br/|><|br/|>"..
            "Eu vou te fazer CÓóÓóÓócegas !!!",
          position = "south",
          item_function = function() show_second_story_image("assets/image/story/nadia_tickles.png") end
        },
        {
          actor = "Chanceler",
          text  = "A princesa, que é muito cosquenta e não consegue se controlar com tal ameaça, correu desesperadamente "..
            "para a masmorra maldita... de onde ninguém jamais retornou :( ...",
          position = "south",                
        },
        {
          actor = "Chanceler",
          text  = "O príncipe Willian III bravamente matou o monstro fazedor de cócegas com suas próprias mãos...",
          item_function = function() show_second_story_image("assets/image/story/willianIII_kills_monster.png") end,
          position = "south",
        },                 
        {
          actor = "Chanceler",
          text  = "Mas era tarde demais...",          
          position = "south",
        },
        {
          actor = "Chanceler",
          text  = "Com a morte de Nádia, a divisão dos diamantes passaria então a ser:<|br/|>"..
            generate_latex_division({"Willian III", "James"}), 
          item_function = function()    
            destroy_second_story_image()            
            local sprite = queryname("story_image")
            sprite.death_nadia = sprite:addGameObject(create_magic():death())
            sprite.death_nadia.Transform.position:set(706 - 512, 392 - 280) 
          end,
          position = "north 90% 150px",
        },
      },
      james_dies
    )   
end


local function henry_dies()
  tell_story_table(
      {
        {
          actor = "Chanceler",
          text  = "Mas, para a surpresa de todos, essa tragédia não foi um evento isolado...",
          position = "south",
        },
        {
          actor = "Chanceler",
          text  = "O príncipe Henry achou absurda a forma como seus irmãos supostamente morreram e resolveu provar que era impossível sofrer um acidente de lancha no deserto do Sahara...",
          position = "south",
        },
        {
          actor = "Chanceler",
          text  = "Mostrou a todos que era uma atividade não só segura, mas extremamente divertida...",
          position = "south",
        },
        
        {
          actor = "Chanceler",
          text  = "Errou, no entanto, ao ofender os simpáticos Tuaregs rebeldes separatistas que lhe pediram para dar um passeio :(",
          position = "south",
        },        
        {
          actor = "Chanceler",
          text  = "Assim, a divisão dos diamantes ficaria da seguinte forma:<|br/|>"..
            generate_latex_division({"Willian III", "Nádia", "James"}),
          position = "north 90% 150px",
          item_function = function()
            local sprite = queryname("story_image")
            sprite.death_henry = sprite:addGameObject(create_magic():death())
            sprite.death_henry.Transform.position:set(580 - 512, 392 - 280)                         
          end,
        },
      },
      nadia_dies
    )       
end

local function charles_and_bartholomew_dies()

 tell_story_table(
      {
        {
          actor = "Chanceler",
          text  = "Porém, nos últimos meses uma maldição parece ter caído sobre a família real e bem...",
          item_function = function() show_story_image("assets/image/story/heirs.png") end,
          position = "south",
        },
        {
          actor = "Chanceler",
          text  = "os primeiros a morrerem foram Charles e Bartholomew, que sofreram um acidente de lancha no deserto do Sahara.",
          position = "south",
        },
        
        {
          actor = "Chanceler",
          text  = "Com isso, a divisão dos diamantes seria:<|br/|>"..
            generate_latex_division({"Willian III", "Henry", "Nádia", "James"}),
          position = "north 90% 180px",
          item_function = function()
            local sprite = queryname("story_image")
            sprite.death_charles = sprite:addGameObject(create_magic():death())
            sprite.death_charles.Transform.position:set(324 - 512, 392 - 280)  
            
            sprite.death_bartholomew = sprite:addGameObject(create_magic():death())
            sprite.death_bartholomew.Transform.position:set(452 - 512, 392 - 280)
          end,
        },
      },
      henry_dies
    )     
  
end




local function tell_about_the_inheritance()
   
  local chanceler = queryname("chanceler")

  local function show_dialog()
    tell_story_table(
      {
        {
          actor = "Chanceler",
          text  = "Muito bem... Eis o problema:<|br/|>"..
            "as leis que regem estes diamantes exigem que eles sejam passados de geração em geração, divididos igualmente entre os filhos do Rei...",
            item_function = function() show_story_image("assets/image/story/heirs.png") end,
          position = "south",
        },
        {
          actor = "Chanceler",
          text  = "Até aí tudo muito fácil, pois o número 12 é bastante generoso em termos de divisão exata...",
          position = "south",
        },
        {
          actor = "Chanceler",
          text  = "A divisão dos 12 diamantes pelos 6 herdeiros ocorreria da seguinte forma:"..
          generate_latex_division({"Willian III", "Charles", "Bartholomew", "Henry", "Nadia", "James"}),
          position = "center 90% 250px",
        },
      },
      charles_and_bartholomew_dies
    )
  end
  
  
  chanceler:addGameObject(
    sequence_controller:create({                
      chanceler:move_action(24.5, 39, true, false),                                                           
      chanceler:move_action(24.5, 38.5, true, false),        
      chanceler:call_action(show_dialog),
    },
    true,
    false)
  )
end

local function tell_about_green_diamonds()

  local chanceler = queryname("chanceler")

  local function show_dialog()
    local story_image = queryname("story_image") 
    story_image.apple = story_image:addGameObject(create_magic())
    story_image.apple:apple()
    story_image.apple.Transform.position:set(806 - 512, 95 - 280)
    dialog_controller:create(
      "Chanceler",
      "Por fim, temos 3 diamantes verdes que possuem o incrível sabor de maçã verde <:yum:><|br/|>IN...FI...NI...TO...",
      "[]",
      "center",
      function(sender, opt)
        sender:destroy()
        tell_about_the_inheritance()
      end
    )

  end

  chanceler:addGameObject(
    sequence_controller:create({
      chanceler:move_action(33.5, 28, false, false),
      chanceler:call_action(show_dialog),
      chanceler:move_action(33.5, 27, true, false),
    },
    true,
    false)
  )
end

local function tell_about_yellow_diamonds()


  local chanceler = queryname("chanceler")

  local function show_dialog()
    local story_image = queryname("story_image") 
    story_image.wind = story_image:addGameObject(create_magic())
    story_image.wind:wind()
    story_image.wind.Transform.position:set(655 - 512, 100 - 280)
    dialog_controller:create(
      "Rei Willian II",
      "3 diamantes amarelos controlam o vento: movimentam nossos barcos à vela, previnem furacões, alimentam as pás de nossos moinhos e de nossos geradores de energia elétrica...",
      "[]",
      "center",
      function(sender, opt)
        sender:destroy()
        tell_about_green_diamonds()
      end
    )
  end

  chanceler:addGameObject(
    sequence_controller:create({
      chanceler:move_action(28.5, 28, true, false),
      chanceler:call_action(show_dialog),
      chanceler:move_action(28.5, 27, true, false),
    },
    true,
    false)
  )
end

local function tell_about_blue_diamonds()
  local chanceler = queryname("chanceler")

  local function show_dialog()
    local story_image = queryname("story_image") 
    story_image.water = story_image:addGameObject(create_magic())
    story_image.water:water()
    story_image.water.Transform.position:set(365 - 512, 95 - 280)
    dialog_controller:create(
      "Chanceler",
      "Outros 3 diamantes, azuis como o oceano, são capazes de controlar a água: apagar incêndios, prevenir enchentes, hidratar as lavouras e matar a sede da população com água da mais pura qualidade...",
      "[]",
      "center",
      function(sender, opt)
        sender:destroy()
        tell_about_yellow_diamonds()
      end
    )

  end

  chanceler:addGameObject(
    sequence_controller:create({
      chanceler:move_action(19.5, 28, false, false),
      chanceler:call_action(show_dialog),
      chanceler:move_action(19.5, 27, true, false),
    },
    true,
    false)
  )
end

local function tell_about_red_diamonds()
  local chanceler = queryname("chanceler")

  local function show_dialog()
    local story_image = queryname("story_image") 
    story_image.fire = story_image:addGameObject(create_magic())
    story_image.fire:fire()
    story_image.fire.Transform.position:set(229 - 512, 79 - 280)
    
    dialog_controller:create(
      "Chanceler",
      "Temos 3 diamantes vermelhos que, incandecentes como ferro em brasa, são capazes de controlar o fogo: incendiar as tropas inimigas, possibilitar a forja dos metais mais resistentes e nos aquecer no inverno que está chegando :wolf:...",
      "[]",
      "center",
      function(sender, opt)
        sender:destroy()
        tell_about_blue_diamonds()
      end
    )
  end
    
  chanceler:addGameObject(
    sequence_controller:create({
      chanceler:move_action(15.5, 28, true, false),
      chanceler:call_action(show_dialog),
      chanceler:move_action(15.5, 27, true, false),
    },
    true,
    false)
  )


end

local function tell_about_diamonds()
  show_story_image("assets/image/story/the12diamonds.png")
  dialog_controller:create(
    "Chanceler",
    "Há muitas gerações o reino prospera e é protegido pelo nosso mais importante tesouro:<|br/|>"..
    "<%<center><h4>12 poderosos diamantes mágicos secretos!!!</h4></center>%>",
    "[]",
    "center",
    function(sender, opt)
      sender:destroy()
      tell_about_red_diamonds()
    end
  )
end

local function chanceler_assumes()
  local trial_music = Music:new("assets/music/orchestra/trial.ogg")
  trial_music:Play()
  fade_out_scenery()
  
  local chanceler = queryname("chanceler")
  local character = maincharacter()
  chanceler:addGameObject(
    sequence_controller:create({
      chanceler:move_action(24.5, 27, false, true),
      chanceler:move_action(24.5, 28, false, true),      
      chanceler:call_action(function() tell_about_diamonds() end),
    },
    true,
    false)
  )
end

local function king_exit_scene()
  local king = queryname("king")
  king:addGameObject(
    sequence_controller:create({
      king:move_action(22.5, 33, false, false),
      king:move_action(24.5, 38, false, false),
      king:call_action(function() chanceler_assumes() end),
      --[[      
      king:move_action(24.5, 52, false, false),      
      king:move_action(42.5, 52, false, false),
      king:move_action(42.5, 39, false, false),
      king:move_action(45, 39, false, false),
      king:move_action(44, 39, false, false),
      --]]
    },
    true,
    false)
  )
end




local function intro()
  dofile("scripts/story/magic.lua")
  
  local function tell_intro()
    tell_story_table(
      {
        {
          actor = "Rei Willian II",
          text  = "Obrigado por virem meus fiéis súditos...",
          position = "center"
        },
        {
          actor = "Rei Willian II",
          text  = "Quando a Professora Freira disse que enviaria as pessoas mais inteligentes da Catedral Escola eu não podia imaginar que seriam tão jovens...",
          position = "center"
        },
        {
          actor = "Rei Willian II",
          text  = "Mas tenho certeza que vocês serão de fundamental ajuda neste momento tão difícil <:pensive:>",
          position = "center"
        },
        {
          actor = "Rei Willian II",
          text  = "Prontos para ouvir a história?",
          position = "center",
          options = "['Pessoas mais inteligentes da Catedral Escola? Nós?! :laughing:', 'Claro, Majestade! Por favor, prossiga :no_mouth:']",
        },
        {
          actor = "Rei Willian II",
          text  = "Era uma vez um pato <:hatching_chick:>...",
          position = "center",
        },
        {
          actor = "Rei Willian II",
          text  = "Que na verdade era um cisne feio...",
          position = "center",
        },
        {
          actor = "Rei Willian II",
          text  = "Não, pera...<|br/|>isso que dá não ensaiar a apresentação <:confounded:>...",
          position = "center",
        },
        {
          actor = "Rei Willian II",
          text  = "Chanceler, você que sabe contar história como ninguém...<|br/|>Assuma por gentileza.",
          position = "center",
        },
      },
      king_exit_scene
    )
  end
  local character = maincharacter()
  
  character:addGameObject(
    sequence_controller:create({
      character:move_action(24.5, 33.5, false, false),
      character:move_action(24.5, 33, false, false),
      character:call_action(function() tell_intro() end)
    },
    true,
    false)
  )
  

end

intro()
