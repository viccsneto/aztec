local lucca_sprite

lucca_sprite = Sprite:new("assets/image/characters/chronotrigger_lucca_sheet.png", 64 ,80);
lucca_sprite:pivotOnCenter()

lucca_sprite.idle_down_animation = lucca_sprite:newAnimation("idle_down")
lucca_sprite.idle_down_animation:addFrame(0,0,5000)
lucca_sprite.idle_down_animation:addFrame(64 , 0,1500)
lucca_sprite.idle_down_animation:addFrame(0,0, 3000)
lucca_sprite.idle_down_animation:addFrame(128,0, 1500)
lucca_sprite.idle_down_animation:addFrame(0,0,5000)

lucca_sprite.idle_side_animation = lucca_sprite:newAnimation("idle_side")
lucca_sprite.idle_side_animation:addFrame(0, 80,5000)
lucca_sprite.idle_side_animation:addFrame(128, 80,500)
lucca_sprite.idle_side_animation:addFrame(64, 80,200)
lucca_sprite.idle_side_animation:addFrame(128, 80,200)
lucca_sprite.idle_side_animation:addFrame(64, 80,200)
lucca_sprite.idle_side_animation:addFrame(128, 80,100)


lucca_sprite.idle_up_animation = lucca_sprite:newAnimation("idle_up")
lucca_sprite.idle_up_animation:addFrame(0, 160,10000)



lucca_sprite.walk_down_animation = lucca_sprite:newAnimation("walk_down")
lucca_sprite.walk_down_animation:addHorizontalSequence(224, 0 ,6,150)

lucca_sprite.walk_side_animation = lucca_sprite:newAnimation("walk_side")
lucca_sprite.walk_side_animation:addHorizontalSequence(224, 80,6,150)

lucca_sprite.walk_up_animation = lucca_sprite:newAnimation("walk_up")
lucca_sprite.walk_up_animation:addHorizontalSequence(224,160,6,150)

lucca_sprite.run_down_animation = lucca_sprite:newAnimation("run_down")
lucca_sprite.run_down_animation:addHorizontalSequence(640, 0, 6,100)

lucca_sprite.run_side_animation = lucca_sprite:newAnimation("run_side")
lucca_sprite.run_side_animation:addHorizontalSequence(640, 80, 6, 100)


lucca_sprite.run_up_animation = lucca_sprite:newAnimation("run_up")
lucca_sprite.run_up_animation:addHorizontalSequence(640, 160 ,6, 100)


local local_lucca_controller = character_controller:create ("Lucca", lucca_sprite, 20, 28)
local_lucca_controller:setProperty("Name", "local_lucca")
local_lucca_controller:set_npc(true)
local_lucca_controller:set_blocked(true)

local_lucca_controller.Name = "Lucca"
local_lucca_controller.HP = 100
local_lucca_controller.MP = 13
local_lucca_controller.Gauge = 15
local_lucca_controller:setProperty("Action", "queryname('local_lucca'):interact()")
return local_lucca_controller