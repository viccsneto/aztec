local robo_sprite

robo_sprite = Sprite:new("assets/image/characters/chronotrigger_robo_sheet.png", 64 ,80);
robo_sprite:pivotOnCenter()

robo_sprite.idle_down_animation = robo_sprite:newAnimation("idle_down")
robo_sprite.idle_down_animation:addFrame(64 , 0,100)
robo_sprite.idle_down_animation:addFrame(128,0,50)
robo_sprite.idle_down_animation:addFrame(0,0,5000)

robo_sprite.idle_side_animation = robo_sprite:newAnimation("idle_side")
robo_sprite.idle_side_animation:addFrame(0, 80,2500)
robo_sprite.idle_side_animation:addFrame(64, 80,150)
robo_sprite.idle_side_animation:addFrame(128, 80,2500)

robo_sprite.idle_up_animation = robo_sprite:newAnimation("idle_up")
robo_sprite.idle_up_animation:addFrame(0, 160,10000)



robo_sprite.walk_down_animation = robo_sprite:newAnimation("walk_down")
robo_sprite.walk_down_animation:addHorizontalSequence(224, 0 ,6,150)

robo_sprite.walk_side_animation = robo_sprite:newAnimation("walk_side")
robo_sprite.walk_side_animation:addHorizontalSequence(224, 80,6,150)

robo_sprite.walk_up_animation = robo_sprite:newAnimation("walk_up")
robo_sprite.walk_up_animation:addHorizontalSequence(224,160,6,150)

robo_sprite.run_down_animation = robo_sprite:newAnimation("run_down")
robo_sprite.run_down_animation:addHorizontalSequence(640, 0, 6,100)

robo_sprite.run_side_animation = robo_sprite:newAnimation("run_side")
robo_sprite.run_side_animation:addHorizontalSequence(640, 80, 6, 100)


robo_sprite.run_up_animation = robo_sprite:newAnimation("run_up")
robo_sprite.run_up_animation:addHorizontalSequence(640, 160 ,6, 100)

robo_sprite.battle_start_animation = robo_sprite:newAnimation("battle_start")
robo_sprite.battle_start_animation:addHorizontalSequence(1056, 80 ,3, 250)
robo_sprite.battle_start_animation.Loop = false

robo_sprite.battle_idle_animation = robo_sprite:newAnimation("battle_idle")
robo_sprite.battle_idle_animation:addHorizontalSequence(1280, 80 ,2, 550)
robo_sprite.battle_idle_animation:addHorizontalSequence(1440, 80 ,-2, 550)


robo_sprite.preparing_attack_animation = robo_sprite:newAnimation("preparing_attack")
robo_sprite.preparing_attack_animation:addHorizontalSequence(1056, 240 ,1, 150000)
robo_sprite.preparing_attack_animation.Loop = false

robo_sprite.battle_attack_animation = robo_sprite:newAnimation("battle_attack")
robo_sprite.battle_attack_animation:addHorizontalSequence(1568, 80 ,4, 150)
robo_sprite.battle_attack_animation.Loop = false


robo_sprite.battle_attacked_animation = robo_sprite:newAnimation("battle_attacked")
robo_sprite.battle_attacked_animation:addHorizontalSequence(1056, 160 ,2, 250)
robo_sprite.battle_attacked_animation.Loop = false


robo_sprite.battle_critical_attack_animation = robo_sprite:newAnimation("battle_critical_attack")
robo_sprite.battle_critical_attack_animation:addHorizontalSequence(1824, 80 ,4, 200)
robo_sprite.battle_critical_attack_animation:addHorizontalSequence(2064, 80 ,-3, 200)
robo_sprite.battle_critical_attack_animation.Loop = false

robo_sprite.weapon_read_sfx = Sound:new("assets/sfx/Robotcomputing2.wav")
robo_sprite.attack_sfx = Sound:new("assets/sfx/Robotnoise2.wav")
robo_sprite.attacked_sfx = Sound:new("assets/sfx/slice.wav")
robo_sprite.jump_sfx = Sound:new("assets/sfx/flyingobject.wav")
robo_sprite.critical_attack_sfx = Sound:new("assets/sfx/MetalGong2.wav")

function robo_sprite:OnAnimationStarted(sender, animation)
  if (animation == robo_sprite.battle_start_animation) then
    robo_sprite.weapon_read_sfx:Play()
  elseif (animation == robo_sprite.battle_attack_animation) then
    robo_sprite.attack_sfx:Play()
  elseif (animation == robo_sprite.preparing_attack_animation) then
    robo_sprite.jump_sfx:Play()
  elseif (animation == robo_sprite.battle_critical_attack_animation) then
    robo_sprite.critical_attack_sfx:Play()    
  elseif (animation == robo_sprite.battle_attacked_animation) then
    robo_sprite.attacked_sfx:Play()    
  end
end
  

function robo_sprite:OnAnimationFinished(sender, animation)
  local player_controller = self:getParent()  

  if (player_controller:get_in_battle()) then
    sender:setAnimation(robo_sprite.battle_idle_animation)
  end    
end


local local_robo_controller = character_controller:create ("Robo", robo_sprite, 20, 28)
local_robo_controller:setProperty("Name", "local_robo")
local_robo_controller:set_npc(true)

local_robo_controller:set_battle_name("Robô Guardião")
local_robo_controller:set_max_hp(100)
local_robo_controller:set_current_hp(100)
local_robo_controller:set_max_mp(0)
local_robo_controller:set_current_mp(0)
local_robo_controller:set_battle_speed(15)
local_robo_controller:set_battle_attack(40)
local_robo_controller:set_battle_hit(100)
local_robo_controller:set_battle_defense(1024)

return local_robo_controller
