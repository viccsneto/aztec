dofile("scripts/story/tell_story_table.lua")

local function generate_exponential_growth_latex(range_min, range_max )
  local exponential_growth_latex = "<%$$\\\\\\\\"
  for i = range_min, range_max do
    exponential_growth_latex = exponential_growth_latex .. "2^{"..i.."} = {"..(2^i).."} \\\\mbox{ camadas de aço} \\\\ldots "
    if (i < range_max) then
      exponential_growth_latex = exponential_growth_latex.."\\\\\\\\"
    end
  end

  exponential_growth_latex = exponential_growth_latex.."$$%>"
  return exponential_growth_latex
end  

local function give_sword_making_objectives()
  quest_controller:add_quest({key="find_carbon", text = "ENCONTRE CARBONO <|br/|> Segundo Melchior, você pode encontrar a quantidade necessária de carbono para produzir a espada samurai na seguinte localização geográfica: <%$ coordenadas = \\\\begin{cases} 2x - y = 27 \\\\\\\\ x + y = 75 \\\\end{cases} $%>", done = false})
  quest_controller:add_quest({key="find_silica", text = "ENCONTRE SÍLICA <|br/|> Você pode encontrar a quantidade necessária de sílica para produzir a espada samurai na seguinte localização geográfica: <%$ coordenadas = \\\\begin{cases} x + 2y = 133 \\\\\\\\ \\\\frac{x + y}{2} = 38,5 \\\\end{cases} $%>", done = false})  
  quest_controller:add_quest({key="find_copper", text = "ENCONTRE COBRE <|br/|> Você precisa de cobre para construir a Espada Samurai e lembra de ter visto uma grande quantidade de fios de cobre que sobraram da construção do chafariz próximo a sua casa: <%$ coordenadas = \\\\begin{cases} x = 24 \\\\\\\\ y = 18 \\\\end{cases} $%>", done = false})

end

local function  check_already_has_sword()
  return maincharacter():get_battle_attack() == 2^22
end

local function check_sword_making_objectives()
  if (quest_controller:get_quest_status("find_carbon") == nil) then
    return nil
  end
  
  return quest_controller:get_quest_status("find_carbon") and
    quest_controller:get_quest_status("find_silica") and
    quest_controller:get_quest_status("find_carbon") and
    quest_controller:get_quest_status("find_copper")
end

local function finish_sword_making_story()
  quest_controller:set_quest_status("talk_to_melchior", true)
  give_sword_making_objectives()
  maincharacter():clean_action()
  maincharacter():set_can_control(true)
end

local function continue_sword_making_story()
  tell_story_table({
       {
          actor = "Melchior",         
          text = "Perfeito!!! <:joy:>", 
          position = "center",
        },
        
        {
          actor = "Melchior",         
          text = "O segredo da espada é justamente a quantidade absurda de camadas de aço que conseguimos obter aplicando o processo. <:sunglasses:>", 
          position = "center",
        },
        {
          actor = "Melchior",         
          text = "Precisamos repetir a operação 22 vezes obtendo"..
            generate_exponential_growth_latex(19, 22)            
            , 
          position = "center 90% 250px",
        },
        {
          actor = "Melchior",         
          text = "Mais de QUATRO MILHÕES de camadas de aço com apenas 22 dobras <:joy:>", 
          position = "center",
        },
        {
          actor = "Melchior",         
          text = "Há apenas um problema <:pensive:>...<|br/|>Para construir uma Espada Samurai são precisos os seguintes ingredientes: carbono, manganês, sílica, fósforo e cobre...", 
          position = "center",
        },
        {
          actor = "Melchior",         
          text = "Com o recesso decretado pelo Rei, os fornecedores não realizaram entrega hoje... e eu só tenho manganês e fósforo no meu estoque. <:weary:>", 
          position = "center",
        },
        {
          actor = "Melchior",         
          text = "Preciso que vocês consigam o restante dos ingredientes, isto é, carbono, sílica e cobre.", 
          position = "center",
        },
        {
          actor = "Melchior",         
          text = "Tome esse pergaminho, ele contém pistas das localizações geográficas onde vocês podem encontrar os ítens necessários", 
          position = "center",
        },               
    },
    finish_sword_making_story)    
end

local function ask_about_the_pattern(complement)

  if(complement == nil) then
    complement = ""
  end
 dialog_controller:create("Melchior",
  complement.. 
    "Vocês conseguem enxergar o padrão? Trata-se de um crescimento exponencial:"..generate_exponential_growth_latex(1, 5).."<|br/|>"..
    "Qual seria o número de camadas de aço da lâmina se a dobrarmos mais uma vez, ou seja, quanto é <%`2^6`%> camadas de aço?",
  
  "['São 34 camadas de aço...','Acredito que sejam 36 camadas de aço', 'Tenho certeza que são 64 camadas de aço, isto é, o dobro da etapa anterior <:smirk:>']", 
  "center 90% 590px", 
  function(sender, opt)
    sender:destroy()     
    if (opt.index ~= 2) then 
      ask_about_the_pattern("Não, preste atenção...<|br/|>")
    else
      continue_sword_making_story()
    end                                     
  end)   
  
end

local function how_to_defeat_robot()
  local melchior = queryname("melchior")
  
  tell_story_table({
        {
          actor = "Melchior",
          text = "Ora, ora... há muito tempo não recebo visitantes <:relaxed:><|br/|>Que bons ventos os trazem aqui?",
          position = "north 90% 350px",
          options = "[\"Precisamos de uma magia bem poderosa para derrotar o Robô Guardião, Oh incrível Mago Melchior!!!\","..
            "\"Mago Melchior, o Chanceler nos mandou entregar esse documento e pedir ajuda para derrotar o Robô Guardião\"]"  
        },
        {
          actor = "Melchior",        
          text = "Mago?! Eu não sou mago... sou engenheiro <:smirk:>... ", 
          position = "north"  
        },
        {
          actor = "Melchior",        
          text = "As ciências são tão fascinantes quanto a magia e, por isso, os menos informados costumam confundir minha profissão <:joy:>", 
          position = "south",
          item_function = function()
            melchior:addGameObject(sequence_controller:create({
            
              melchior:move_action(5, 6, false, true ),
              melchior:move_action(6, 6, false, true ),              
              },          
              true,
              false
            ))
          end  
        },
        {
          actor = "Melchior",        
          text = "Mas, deixe-me ler esse documento <:scroll:>...<|br/|>Robô Guardião... indestrutível... Princesa Nádia, Masmorra do infi...<|br/|>Ahhhhhhh!!! <:grinning:>", 
          position = "north"  
        },
        {
          actor = "Melchior",         
          text = "Sim... eu sei de que tipo de que Robô Guardião estão falando... o que tem ele?", 
          position = "north",
          options = "[\"Precisamos derrotá-lo, oras... você não leu o documento? <:unamused:>!!!\","..
            "\"Como podemos destruir sua defesa? <:neutral_face:>\"]",
          item_function = function()
            melchior:addGameObject(sequence_controller:create({
            
              melchior:move_action(4.5, 6, false, false ),
              melchior:call_action(function() melchior:face_direction(0, 1) end)
              },          
              true,
              false
            ))
          end  
        },
        {
          actor = "Melchior",         
          text = "Ah, claro... vocês só precisam usar a arma mais poderosa que esse reino já viu...", 
          position = "north",
        },
        {
          actor = "Melchior",         
          text = "Construirei para vocês a lendáááária: <%<br/><center><h4>:jp::dolls: Espada Samurai Japonesa :dolls::jp:</h4></center>%> ", 
          position = "center",
        },
        {
          actor = "Melchior",         
          text = "Para construir tal espada, utilizaremos um incrível processo de origem japonesa que permite produzir uma lâmina com milhões de camadas de aço em poucas etapas.", 
          position = "north",
        },
        {
          actor = "Melchior",         
          text = "Começamos com uma única peça de aço, aquecemos-na até seu ponto de fusão e a dobramos no meio, obtendo 2 camadas de aço ao invés de 1.", 
          position = "north",
        },
        
        {
          actor = "Melchior",         
          text = "Repetimos este processo e obtemos 4 camadas ao invés de 2...", 
          position = "north",
        },
        
      },
      ask_about_the_pattern                 
      
  )
end
local function not_enough_ingredients()
  dialog_controller:create("Melchior", "Vocês ainda não coletaram todos os ingredientes que pedi... assim, fica difícil ajudar <:unamused:>...", "[]", "center")
end

local function motivation_talk()
  dialog_controller:create("Melchior", "Agora que você tem as espada...<%<br/><center><h4>ACABA COM ELE MEU GAROTO!!!</h4></center>%>", "[]", "center")
end
local function give_sword_to_crono()
  motivation_talk()
  maincharacter():set_battle_attack(2^22) 
  maincharacter():set_ignore_blocked_places(false)
end

local function make_the_sword()
  dialog_controller:create("Melchior", "Finalmente!!! Aguardem um pouco enquanto eu vou construir sua arma <:sunglasses:>", "[]", "center", function(sender, opt) 
    sender:destroy()   
    
    local melchior = queryname("melchior")    
    local character = maincharacter()     
    melchior:addGameObject(sequence_controller:create(
      {
        character:move_action(5, 8.5, true, false),
        character:move_action(5, 8, true, false),
        melchior:move_action(5, 9, true, false),
        melchior:move_action(8, 9, true, false),
        melchior:call_action(function() melchior.Visible = false end),
        melchior:wait_call_action(2, function() melchior.Visible = true end),       
        melchior:move_action(5, 9, true, false),
        melchior:move_action(5, 6.5, true, false),
        melchior:move_action(5, 7, true, false),
        melchior:call_action(function() give_sword_to_crono() end),
      },
      true,
      false)
    )
  end)
  
end

local function intro()
  if (check_already_has_sword()) then
    motivation_talk()
  elseif (check_sword_making_objectives() == nil) then
    how_to_defeat_robot()   
  elseif check_sword_making_objectives() then
    make_the_sword()
  else
    not_enough_ingredients()
  end

end  

intro()
