local chanceler_sprite
chanceler_sprite = Sprite:new("assets/image/npcs/chanceler.grid.png", 72 , 72);

chanceler_sprite:pivotOnCenter()

chanceler_sprite.idle_down_animation = chanceler_sprite:newAnimation("idle_down")
chanceler_sprite.idle_down_animation:addFrame(0,0,10000)

chanceler_sprite.idle_up_animation = chanceler_sprite:newAnimation("idle_up")
chanceler_sprite.idle_up_animation:addFrame(0,432,10000)

chanceler_sprite.idle_side_animation = chanceler_sprite:newAnimation("idle_side")
chanceler_sprite.idle_side_animation:addFrame(0,648,10000)

chanceler_sprite.walk_down_animation = chanceler_sprite:newAnimation("walk_down")
chanceler_sprite.walk_down_animation:addVerticalSequence(0,0,3,150)

chanceler_sprite.walk_up_animation = chanceler_sprite:newAnimation("walk_up")
chanceler_sprite.walk_up_animation:addVerticalSequence(0,432,3,150)

chanceler_sprite.walk_side_animation = chanceler_sprite:newAnimation("walk_side")
chanceler_sprite.walk_side_animation:addVerticalSequence(0,648,3,150)
chanceler_sprite.run_down_animation = chanceler_sprite:newAnimation("run_down")
chanceler_sprite.run_down_animation:addVerticalSequence(0,0,3,75)



chanceler_sprite.run_up_animation = chanceler_sprite:newAnimation("run_up")
chanceler_sprite.run_up_animation:addVerticalSequence(0,432,3,75)

chanceler_sprite.run_side_animation = chanceler_sprite:newAnimation("run_side")
chanceler_sprite.run_side_animation:addVerticalSequence(0,648,3,75)
chanceler_sprite.run_side_animation:addVerticalSequence(0,720,-2,75)


local chanceler_controller = character_controller:create ("Chanceler", chanceler_sprite , 16, 20)
chanceler_controller:set_npc(true)
chanceler_controller:set_blocked(true)  
chanceler_controller:set_speed(90)
chanceler_controller:setProperty("Name", "Chanceler")

return chanceler_controller