local king_sprite

king_sprite = Sprite:new("assets/image/npcs/king.grid.png", 72 , 72);
king_sprite:pivotOnCenter()

king_sprite.idle_down_animation = king_sprite:newAnimation("idle_down")
king_sprite.idle_down_animation:addFrame(0,72,3000)
--king_sprite.idle_down_animation:addFrame(0,0,3000)



king_sprite.idle_up_animation = king_sprite:newAnimation("idle_up")
king_sprite.idle_up_animation:addFrame(0,504,10000)

king_sprite.idle_side_animation = king_sprite:newAnimation("idle_side")
king_sprite.idle_side_animation:addFrame(0,360,10000)

king_sprite.walk_down_animation = king_sprite:newAnimation("walk_down")
king_sprite.walk_down_animation:addVerticalSequence(0,792,2,300)

king_sprite.walk_up_animation = king_sprite:newAnimation("walk_up")
king_sprite.walk_up_animation:addVerticalSequence(0,504,2,300)

king_sprite.walk_side_animation = king_sprite:newAnimation("walk_side")
king_sprite.walk_side_animation:addVerticalSequence(0,360,2,300)
king_sprite.run_down_animation = king_sprite:newAnimation("run_down")
king_sprite.run_down_animation:addVerticalSequence(0,792,2,75)



king_sprite.run_up_animation = king_sprite:newAnimation("run_up")
king_sprite.run_up_animation:addVerticalSequence(0,504,2,200)

king_sprite.run_side_animation = king_sprite:newAnimation("run_side")
king_sprite.run_side_animation:addVerticalSequence(0,360,2,200)


local king_controller = character_controller:create ("King", king_sprite , 16, 32)
king_controller:set_npc(true)
king_controller:set_blocked(true)  
king_controller:setProperty("Name", "King")
king_controller:set_speed(80)

return king_controller