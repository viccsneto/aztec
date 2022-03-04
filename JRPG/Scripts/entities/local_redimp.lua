local redimp_sprite

redimp_sprite = Sprite:new("assets/image/enemies/chronotrigger_redimp_sheet.png", 64 ,80);
redimp_sprite:pivotOnCenter()

redimp_sprite.idle_down_animation = redimp_sprite:newAnimation("idle_down")
--redimp_sprite.idle_down_animation:addFrame(64 , 0,100)
redimp_sprite.idle_down_animation:addFrame(128,0,50)
--redimp_sprite.idle_down_animation:addFrame(0,0,5000)

redimp_sprite.idle_side_animation = redimp_sprite:newAnimation("idle_side")
redimp_sprite.idle_side_animation:addFrame(0, 80,2500)
redimp_sprite.idle_side_animation:addFrame(64, 80,150)
redimp_sprite.idle_side_animation:addFrame(128, 80,2500)

redimp_sprite.idle_up_animation = redimp_sprite:newAnimation("idle_up")
redimp_sprite.idle_up_animation:addFrame(0, 160,10000)



redimp_sprite.walk_down_animation = redimp_sprite:newAnimation("walk_down")
redimp_sprite.walk_down_animation:addHorizontalSequence(224, 0 ,6,150)

redimp_sprite.walk_side_animation = redimp_sprite:newAnimation("walk_side")
redimp_sprite.walk_side_animation:addHorizontalSequence(224, 80,6,150)

redimp_sprite.walk_up_animation = redimp_sprite:newAnimation("walk_up")
redimp_sprite.walk_up_animation:addHorizontalSequence(224,160,6,150)

redimp_sprite.run_down_animation = redimp_sprite:newAnimation("run_down")
redimp_sprite.run_down_animation:addHorizontalSequence(640, 0, 6,100)

redimp_sprite.run_side_animation = redimp_sprite:newAnimation("run_side")
redimp_sprite.run_side_animation:addHorizontalSequence(640, 80, 6, 100)


redimp_sprite.run_up_animation = redimp_sprite:newAnimation("run_up")
redimp_sprite.run_up_animation:addHorizontalSequence(640, 160 ,6, 100)

redimp_sprite.battle_start_animation = redimp_sprite:newAnimation("battle_start")
redimp_sprite.battle_start_animation:addHorizontalSequence(1056, 80 ,3, 150)
redimp_sprite.battle_start_animation.Loop = false

redimp_sprite.battle_idle_animation = redimp_sprite:newAnimation("battle_idle")
redimp_sprite.battle_idle_animation:addHorizontalSequence(1280, 80 ,4, 150)


redimp_sprite.preparing_attack_animation = redimp_sprite:newAnimation("preparing_attack")
redimp_sprite.preparing_attack_animation:addHorizontalSequence(1056, 240 ,1, 150000)
redimp_sprite.preparing_attack_animation.Loop = false

redimp_sprite.battle_attack_animation = redimp_sprite:newAnimation("battle_attack")
redimp_sprite.battle_attack_animation:addHorizontalSequence(1568, 80 ,4, 150)
redimp_sprite.battle_attack_animation.Loop = false


redimp_sprite.battle_attacked_animation = redimp_sprite:newAnimation("battle_attacked")
redimp_sprite.battle_attacked_animation:addHorizontalSequence(1056, 160 ,2, 250)
redimp_sprite.battle_attacked_animation.Loop = false


redimp_sprite.battle_critical_attack_animation = redimp_sprite:newAnimation("battle_critical_attack")
redimp_sprite.battle_critical_attack_animation:addHorizontalSequence(1824, 80 ,3, 200)
redimp_sprite.battle_critical_attack_animation:addHorizontalSequence(2064, 80 ,-3, 200)
redimp_sprite.battle_critical_attack_animation.Loop = false

redimp_sprite.weapon_read_sfx = Sound:new("assets/sfx/squeak2.wav")
redimp_sprite.attack_sfx = Sound:new("assets/sfx/sword_hit.wav")
redimp_sprite.attacked_sfx = Sound:new("assets/sfx/slice.wav")
redimp_sprite.jump_sfx = Sound:new("assets/sfx/flyingobject.wav")
redimp_sprite.critical_attack_sfx = Sound:new("assets/sfx/sword_critical_hit.wav")

function redimp_sprite:OnAnimationStarted(sender, animation)
  if (animation == redimp_sprite.battle_start_animation) then
    redimp_sprite.weapon_read_sfx:Play()
  elseif (animation == redimp_sprite.battle_attack_animation) then
    redimp_sprite.attack_sfx:Play()
  elseif (animation == redimp_sprite.preparing_attack_animation) then
    redimp_sprite.jump_sfx:Play()
  elseif (animation == redimp_sprite.battle_critical_attack_animation) then
    redimp_sprite.critical_attack_sfx:Play()    
  elseif (animation == redimp_sprite.battle_attacked_animation) then
    redimp_sprite.attacked_sfx:Play()    
  end
end
  

function redimp_sprite:OnAnimationFinished(sender, animation)
  local player_controller = self:getParent()  
 
  if (player_controller:get_in_battle()) then
    sender:setAnimation(redimp_sprite.battle_idle_animation)
  end    
end


local local_redimp_controller = character_controller:create ("Redimp", redimp_sprite, 20, 28)
local_redimp_controller:setProperty("Name", "local_redimp")
local_redimp_controller:set_npc(true)

local_redimp_controller:set_battle_name("redimp")
local_redimp_controller:set_max_hp(60)
local_redimp_controller:set_current_hp(60)
local_redimp_controller:set_max_mp(0)
local_redimp_controller:set_current_mp(0)
local_redimp_controller:set_battle_speed(25)
local_redimp_controller:set_battle_attack(30)
local_redimp_controller:set_battle_hit(60)
local_redimp_controller:set_battle_defense(15)

return local_redimp_controller
