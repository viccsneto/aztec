local overworld_crono_sprite

overworld_crono_sprite = Sprite:new("assets/image/misc/overworld.png", 32,36);
overworld_crono_sprite:pivotOnCenter()
overworld_crono_sprite:createSensor()

overworld_crono_sprite.hasCollided = false
overworld_crono_sprite.idle_down_animation = overworld_crono_sprite:newAnimation("idle_down'")
overworld_crono_sprite.idle_down_animation:addFrame(0,336,10000)
overworld_crono_sprite.idle_down_animation:addHorizontalSequence(32,336,3,1000)
overworld_crono_sprite.idle_down_animation:addHorizontalSequence(32,336,3,1000)
overworld_crono_sprite.idle_down_animation:addHorizontalSequence(32,336,3,1000)
overworld_crono_sprite.idle_down_animation:addHorizontalSequence(32,336,3,1000)

overworld_crono_sprite.idle_up_animation = overworld_crono_sprite:newAnimation("idle_up'")
overworld_crono_sprite.idle_up_animation:addFrame(0,336,10000)
overworld_crono_sprite.idle_up_animation:addHorizontalSequence(32,336,3,1000)
overworld_crono_sprite.idle_up_animation:addHorizontalSequence(32,336,3,1000)
overworld_crono_sprite.idle_up_animation:addHorizontalSequence(32,336,3,1000)
overworld_crono_sprite.idle_up_animation:addHorizontalSequence(32,336,3,1000)

overworld_crono_sprite.idle_side_animation = overworld_crono_sprite:newAnimation("idle_side'")
overworld_crono_sprite.idle_side_animation:addFrame(0,336,10000)
overworld_crono_sprite.idle_side_animation:addHorizontalSequence(32,336,3,1000)
overworld_crono_sprite.idle_side_animation:addHorizontalSequence(32,336,3,1000)
overworld_crono_sprite.idle_side_animation:addHorizontalSequence(32,336,3,1000)
overworld_crono_sprite.idle_side_animation:addHorizontalSequence(32,336,3,1000)

overworld_crono_sprite.walk_down_animation = overworld_crono_sprite:newAnimation("walk_down")
overworld_crono_sprite.walk_down_animation:addHorizontalSequence(0,192,4,150)

overworld_crono_sprite.walk_up_animation = overworld_crono_sprite:newAnimation("walk_up")
overworld_crono_sprite.walk_up_animation:addHorizontalSequence(0,240,4,150)

overworld_crono_sprite.walk_side_animation = overworld_crono_sprite:newAnimation("walk_side")
overworld_crono_sprite.walk_side_animation:addHorizontalSequence(0,288,4,150)

overworld_crono_sprite.run_down_animation = overworld_crono_sprite.walk_down_animation
overworld_crono_sprite.run_side_animation = overworld_crono_sprite.walk_side_animation
overworld_crono_sprite.run_up_animation = overworld_crono_sprite.walk_up_animation

local overworld_crono = character_controller:create ("OverworldCrono", overworld_crono_sprite, 12, 8)
overworld_crono:setProperty("Name", "overworld_crono")
overworld_crono:set_maincharacter()
overworld_crono:set_speed(90)
return overworld_crono