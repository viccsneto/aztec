local melchior_sprite
melchior_sprite = Sprite:new("assets/image/npcs/melchior.png", 50 , 72);

melchior_sprite:pivotOnCenter()

melchior_sprite.idle_down_animation = melchior_sprite:newAnimation("idle_down")
melchior_sprite.idle_down_animation:addFrame(0,0,10000)

melchior_sprite.idle_up_animation = melchior_sprite:newAnimation("idle_up")
melchior_sprite.idle_up_animation:addFrame(100,0,10000)

melchior_sprite.idle_side_animation = melchior_sprite:newAnimation("idle_side")
melchior_sprite.idle_side_animation:addFrame(50,0,10000)

melchior_sprite.walk_down_animation = melchior_sprite:newAnimation("walk_down")
melchior_sprite.walk_down_animation:addVerticalSequence(0, 0,3,150)

melchior_sprite.walk_up_animation = melchior_sprite:newAnimation("walk_up")
melchior_sprite.walk_up_animation:addVerticalSequence(100,0, 3, 150)

melchior_sprite.walk_side_animation = melchior_sprite:newAnimation("walk_side")
melchior_sprite.walk_side_animation:addVerticalSequence(50, 0, 3,150)
melchior_sprite.run_down_animation = melchior_sprite:newAnimation("run_down")
melchior_sprite.run_down_animation:addVerticalSequence(0, 0,3, 75)



melchior_sprite.run_up_animation = melchior_sprite:newAnimation("run_up")
melchior_sprite.run_up_animation:addVerticalSequence(100,0, 3, 75)

melchior_sprite.run_side_animation = melchior_sprite:newAnimation("run_side")
melchior_sprite.run_side_animation:addVerticalSequence(50, 0, 3, 75)

local melchior_controller = character_controller:create ("Melchior", melchior_sprite , 16, 28)
melchior_controller:set_npc(true)
melchior_controller:set_blocked(true)  
melchior_controller:set_speed(60)
melchior_controller:setProperty("Name", "melchior")

return melchior_controller