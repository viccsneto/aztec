local nun_sprite
nun_sprite = Sprite:new("assets/image/npcs/nun.png", 50 , 72);

nun_sprite:pivotOnCenter()

nun_sprite.idle_down_animation = nun_sprite:newAnimation("idle_down")
nun_sprite.idle_down_animation:addFrame(0,0,10000)

nun_sprite.idle_up_animation = nun_sprite:newAnimation("idle_up")
nun_sprite.idle_up_animation:addFrame(100,0,10000)

nun_sprite.idle_side_animation = nun_sprite:newAnimation("idle_side")
nun_sprite.idle_side_animation:addFrame(50,0,10000)

nun_sprite.walk_down_animation = nun_sprite:newAnimation("walk_down")
nun_sprite.walk_down_animation:addVerticalSequence(0,72,4,150)

nun_sprite.walk_up_animation = nun_sprite:newAnimation("walk_up")
nun_sprite.walk_up_animation:addVerticalSequence(100,72,4,150)

nun_sprite.walk_side_animation = nun_sprite:newAnimation("walk_side")
nun_sprite.walk_side_animation:addVerticalSequence(50, 0,3,150)
nun_sprite.run_down_animation = nun_sprite:newAnimation("run_down")
nun_sprite.run_down_animation:addVerticalSequence(0,72,4,75)



nun_sprite.run_up_animation = nun_sprite:newAnimation("run_up")
nun_sprite.run_up_animation:addVerticalSequence(100, 72,4,75)

nun_sprite.run_side_animation = nun_sprite:newAnimation("run_side")
nun_sprite.run_side_animation:addVerticalSequence(50, 0,3,75)

local nun_controller = character_controller:create ("Nun", nun_sprite , 16, 16)
nun_controller:set_npc(true)
nun_controller:set_blocked(true)  
nun_controller:set_speed(120)
nun_controller:setProperty("Name", "Nun")

nun_controller:setProperty("Action", "queryname('Nun'):interact()")
return nun_controller