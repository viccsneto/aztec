dofile("scripts/story/tell_story_table.lua")
dofile("scripts/story/portal.lua")


local function finish_story()
  scene_controller:run("1000AD_THE_END", "Entrance", 0,  -1)
end

local function fade_in_nadia()
  local nadia = queryname("local_marle")
  nadia:get_sprite():getPlane():setColorBalance(1, 1, 1, 0)
  local timer = timer_controller:create(0.005)
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
    nadia:get_sprite():getPlane():setColorBalance(balance_value, balance_value, balance_value, balance_value)    
  end
end

local function the_truth_about_nadia()
  local nun = queryname("Nun")
  local lucca = queryname("local_lucca")
  local character = maincharacter()
  local true_name = "<%N&#225;draž&#237; Veleslav&#237;n%>"
  
   
  local function open_portal()
    local nadia = spawn("local_marle")
    local music = Music:new("assets/music/conclusion2.ogg")
    music:Play()
    
    local portal_position = queryname("portal_position")
    local portal = gamestate():add(create_portal():open(), portal_position:getLayerID())
    
    portal.Transform.position:assign(portal_position.Transform.position)
    
    nadia.Transform.position:assign(portal_position.Transform.position)
    nadia:face_direction(0, 1)
    fade_in_nadia()
          
    
  end
  
  local function run_to_the_hills()
    local nadia = queryname("local_marle")
    nadia:set_speed(character:get_speed())
    nun:set_speed(character:get_speed())
    lucca:set_speed(character:get_speed())
    
    nadia:addGameObject(
    sequence_controller:create({      
      nadia:move_action(8, 13, true, false),
      nadia:move_action(8, 64, true, false),
    },
    true,
    false)
    )
    --[[
    nun:addGameObject(
    sequence_controller:create({
      nun:wait_call_action(1),            
      nun:move_action(8, 64, true, false),
    },                   
    true,
    false)
    )--]]
    
    lucca:addGameObject(
    sequence_controller:create({
      lucca:wait_call_action(2.5),            
      lucca:move_action(8, 64, true, false),
    },
    true,
    false)
    )
              
    character:addGameObject(
    sequence_controller:create({
      character:wait_call_action(3),            
      character:move_action(8, 64, true, false),
      character:call_action(finish_story),
    },                   
    true,
    false)
    )
              
  end
  
  local function show_dialog()
    tell_story_table({
          {
            actor = "Lucca",
            text = "Sabemos quem você é, Professora <:smirk:>...",
            position = "center",          
          },
          {
            actor = "Professora Freira",
            text = "Eu... Não entendi... <:pensive:>",
            position = "center",   
            options = "[\"Quando você se apresentou, quase disse que seu nome era Nád... conte-nos, seu nome <:unamused:>\"]"       
          },            
          {
            actor = "Professora Freira",
            text = "Meu nome é... por que isso é importante? <:pensive:>",
            position = "center",   
            options = "[\"Aposto que seu nome é Nádia ou, melhor dizendo, Princesa Nádia!!!\"]",
            item_function = function()
               nun:addGameObject(
                 sequence_controller:create({
                  nun:move_action(8, 8, false, true),
                  },
                  true,
                  false)
              )
            end       
          },
          {
            actor = "Professora Freira",
            text = "Não... vocês estão enganados <:neutral_face:>...",
            position = "center",                      
          }, 
          {
            actor = "Professora Freira",
            text = "Meu nome é... na verdade... eu odeio ter de explicar...",
            position = "center",                      
          },
          {
            actor = "Professora Freira",
            text = "Mas... eu me chamo "..true_name.."...",
            position = "center",                      
          },
          {
            actor = true_name,
            text = "Por causa da estação de metrô onde eu nasci... em Praga <:pensive:>...",
            position = "center",  
            options = "[\"O quê?! Como assim?!?! <:confounded:>\"]",
            item_function = function()               
               nun:addGameObject(
                 sequence_controller:create({
                  nun:move_action(8, 8.5, false, true),
                  },
                  true,
                  false)
              )
            end                      
          },
          {
            actor = "Lucca",
            text = "Então onde está a princesa?! O Robô disse que ela estava aqui <:triumph:>...",
            item_function = function() gamestate():stop_music() end,
            position = "north",                                  
          },
          {
            actor = "Nádia",
            text = "Eu estou aqui...",
            position = "center",
            item_function = open_portal,                                   
          },
          {
            actor = "Nádia",
            text = "RUUUUUUN!!!",
            position = "center",
            item_function = run_to_the_hills                                  
          },
        }                     
    )
  end

  
  character:addGameObject(
    sequence_controller:create({
      character:move_action(5.5, 11, false, false),
      character:move_action(6, 11, false, false),
    },
    true,
    false)
  )
  
  lucca:addGameObject(
    sequence_controller:create({
      lucca:move_action(8, 22, false, false),            
      lucca:move_action(8, 12, false, false),      
      lucca:move_action(9 , 12, false, false), 
      lucca:call_action(function() show_dialog() end),     
      lucca:move_action(10.5, 11, false, false),
      lucca:move_action(10, 11, false, false),
    },
    true,
    false)
  )
  
  
end

local function intro()
  the_truth_about_nadia()
end  

intro()
