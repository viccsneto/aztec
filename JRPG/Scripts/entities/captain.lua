local captain_sprite
captain_sprite = Sprite:new("assets/image/npcs/captain.png", 50 , 72);

captain_sprite:pivotOnCenter()

captain_sprite.idle_down_animation = captain_sprite:newAnimation("idle_down")
captain_sprite.idle_down_animation:addFrame(0,0,10000)

captain_sprite.idle_up_animation = captain_sprite:newAnimation("idle_up")
captain_sprite.idle_up_animation:addFrame(100,0,10000)

captain_sprite.idle_side_animation = captain_sprite:newAnimation("idle_side")
captain_sprite.idle_side_animation:addFrame(50,0,10000)

captain_sprite.walk_down_animation = captain_sprite:newAnimation("walk_down")
captain_sprite.walk_down_animation:addVerticalSequence(0,72,4,150)

captain_sprite.walk_up_animation = captain_sprite:newAnimation("walk_up")
captain_sprite.walk_up_animation:addVerticalSequence(100,72,4,150)

captain_sprite.walk_side_animation = captain_sprite:newAnimation("walk_side")
captain_sprite.walk_side_animation:addVerticalSequence(50, 0, 2,150)
captain_sprite.walk_side_animation:addFrame(50, 0,150)
captain_sprite.walk_side_animation:addFrame(50, 144,150)

captain_sprite.run_down_animation = captain_sprite:newAnimation("run_down")
captain_sprite.run_down_animation:addVerticalSequence(0,72,4,75)

captain_sprite.run_up_animation = captain_sprite:newAnimation("run_up")
captain_sprite.run_up_animation:addVerticalSequence(100, 72,4,75)

captain_sprite.run_side_animation = captain_sprite:newAnimation("run_side")
captain_sprite.run_side_animation:addVerticalSequence(50, 0, 2,75)
captain_sprite.run_side_animation:addFrame(50, 0,75)
captain_sprite.run_side_animation:addFrame(50, 144,75)

local captain_controller = character_controller:create ("Captain", captain_sprite , 32, 16)
captain_controller:set_npc(true)
captain_controller:set_blocked(true)  
captain_controller:set_speed(120)
captain_controller:setProperty("Name", "Captain")

return captain_controller