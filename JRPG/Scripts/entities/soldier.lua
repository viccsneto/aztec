local soldier_sprite
soldier_sprite = Sprite:new("assets/image/npcs/soldier.png", 50 , 72);

soldier_sprite:pivotOnCenter()

soldier_sprite.idle_down_animation = soldier_sprite:newAnimation("idle_down")
soldier_sprite.idle_down_animation:addFrame(0,0,10000)

soldier_sprite.idle_up_animation = soldier_sprite:newAnimation("idle_up")
soldier_sprite.idle_up_animation:addFrame(100,0,10000)

soldier_sprite.idle_side_animation = soldier_sprite:newAnimation("idle_side")
soldier_sprite.idle_side_animation:addFrame(50,0,10000)

soldier_sprite.walk_down_animation = soldier_sprite:newAnimation("walk_down")
soldier_sprite.walk_down_animation:addVerticalSequence(0,72,4,150)

soldier_sprite.walk_up_animation = soldier_sprite:newAnimation("walk_up")
soldier_sprite.walk_up_animation:addVerticalSequence(100,72,4,150)

soldier_sprite.walk_side_animation = soldier_sprite:newAnimation("walk_side")
soldier_sprite.walk_side_animation:addVerticalSequence(50, 0,3,150)
soldier_sprite.run_down_animation = soldier_sprite:newAnimation("run_down")
soldier_sprite.run_down_animation:addVerticalSequence(0,72,4,75)



soldier_sprite.run_up_animation = soldier_sprite:newAnimation("run_up")
soldier_sprite.run_up_animation:addVerticalSequence(100, 72,4,75)

soldier_sprite.run_side_animation = soldier_sprite:newAnimation("run_side")
soldier_sprite.run_side_animation:addVerticalSequence(50, 0,3,75)

local soldier_controller = character_controller:create ("Soldier", soldier_sprite , 16, 32)
soldier_controller:set_npc(true)
soldier_controller:set_blocked(true)  
--soldier_controller:set_speed(120)
soldier_controller:setProperty("Name", "soldier")

function soldier_controller:interact()
  local could_control = maincharacter():get_can_control()
  dialog_controller:create("Soldado","...","[]", "center", function(sender, opt)
    sender:destroy()
    maincharacte():clean_action()
    maincharacter():set_can_control(could_control)
  end)
end

return soldier_controller