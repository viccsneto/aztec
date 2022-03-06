local tmxScene = scene_controller:create('assets/maps/tmx/melchior_hut_1f.tmx', 'MELCHIOR_HUT_1F')


function tmxScene:SceneStart(state)

end  

local function tell_about_sword_making()
  dofile("scripts/story/sword_making.lua")    
end

function tmxScene:go_down_stairs()
  dialog_controller:create("Melchior", "Hey, sua mãe não te deu educação?!<|br/|>Você não pode ir entrando assim pela casa dos outros <:rage:>...", "[]", "center", function(sender, opt)
      sender:destroy()                        
      maincharacter():addGameObject(sequence_controller:create({      
            maincharacter():move_action(7, 9, true, false),
            
            maincharacter():call_action(function()
                maincharacter():clean_action()
                maincharacter():set_ignore_blocked_places(false) 
                maincharacter():set_can_control(true) 
              end)
          }, 
          true, 
          false
        )
      )    
    end
  )
  
end
function tmxScene:SceneLoad(state)
  local melchior = queryname('melchior')
  
  function melchior:interact()
    tell_about_sword_making()
  end
  
  local lucca = queryname("local_lucca")
  lucca:face_direction(-1, 0)
  
  function lucca:interact()
    dialog_controller:create("Lucca", "Crono, vamos ouvir os conselhos de Melchior <:pensive:><|br/|>Precisamos agir rapidamente...", "[]", "center")
  end  

end

return tmxScene
 