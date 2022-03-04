local marle_sprite

marle_sprite = Sprite:new("assets/image/characters/chronotrigger_marle_sheet.png", 64 ,80);
marle_sprite:pivotOnCenter()

marle_sprite.idle_down_animation = marle_sprite:newAnimation("idle_down")
marle_sprite.idle_down_animation:addFrame(64 , 0,100)
marle_sprite.idle_down_animation:addFrame(128,0,50)
marle_sprite.idle_down_animation:addFrame(0,0,5000)

marle_sprite.idle_side_animation = marle_sprite:newAnimation("idle_side")
marle_sprite.idle_side_animation:addFrame(0, 80,2500)
marle_sprite.idle_side_animation:addFrame(64, 80,150)
marle_sprite.idle_side_animation:addFrame(128, 80,150)

marle_sprite.idle_up_animation = marle_sprite:newAnimation("idle_up")
marle_sprite.idle_up_animation:addFrame(0, 160,10000)



marle_sprite.walk_down_animation = marle_sprite:newAnimation("walk_down")
marle_sprite.walk_down_animation:addHorizontalSequence(224, 0 ,6,150)

marle_sprite.walk_side_animation = marle_sprite:newAnimation("walk_side")
marle_sprite.walk_side_animation:addHorizontalSequence(224, 80,6,150)

marle_sprite.walk_up_animation = marle_sprite:newAnimation("walk_up")
marle_sprite.walk_up_animation:addHorizontalSequence(224,160,6,150)

marle_sprite.run_down_animation = marle_sprite:newAnimation("run_down")
marle_sprite.run_down_animation:addHorizontalSequence(640, 0, 6,100)

marle_sprite.run_side_animation = marle_sprite:newAnimation("run_side")
marle_sprite.run_side_animation:addHorizontalSequence(640, 80, 6, 100)


marle_sprite.run_up_animation = marle_sprite:newAnimation("run_up")
marle_sprite.run_up_animation:addHorizontalSequence(640, 160 ,6, 100)


local local_marle_controller = character_controller:create ("Marle", marle_sprite, 20, 28)
local_marle_controller:setProperty("Name", "local_marle")
local_marle_controller:set_npc(true)
local_marle_controller:set_speed(100)

local_marle_controller:set_blocked(true)

local_marle_controller.Name = "Marle"
local_marle_controller.HP = 100
local_marle_controller.MP = 13
local_marle_controller.Gauge = 15

return local_marle_controller