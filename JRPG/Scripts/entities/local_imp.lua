local imp_sprite

imp_sprite = Sprite:new("assets/image/enemies/chronotrigger_imp_sheet.png", 64 ,80);
imp_sprite:pivotOnCenter()

imp_sprite.idle_down_animation = imp_sprite:newAnimation("idle_down")
imp_sprite.idle_down_animation:addFrame(64 , 0,100)
imp_sprite.idle_down_animation:addFrame(128,0,50)
imp_sprite.idle_down_animation:addFrame(0,0,5000)

imp_sprite.idle_side_animation = imp_sprite:newAnimation("idle_side")
imp_sprite.idle_side_animation:addFrame(0, 80,2500)
imp_sprite.idle_side_animation:addFrame(64, 80,150)
imp_sprite.idle_side_animation:addFrame(128, 80,2500)

imp_sprite.idle_up_animation = imp_sprite:newAnimation("idle_up")
imp_sprite.idle_up_animation:addFrame(0, 160,10000)



imp_sprite.walk_down_animation = imp_sprite:newAnimation("walk_down")
imp_sprite.walk_down_animation:addHorizontalSequence(224, 0 ,6,150)

imp_sprite.walk_side_animation = imp_sprite:newAnimation("walk_side")
imp_sprite.walk_side_animation:addHorizontalSequence(224, 80,6,150)

imp_sprite.walk_up_animation = imp_sprite:newAnimation("walk_up")
imp_sprite.walk_up_animation:addHorizontalSequence(224,160,6,150)

imp_sprite.run_down_animation = imp_sprite:newAnimation("run_down")
imp_sprite.run_down_animation:addHorizontalSequence(640, 0, 6,100)

imp_sprite.run_side_animation = imp_sprite:newAnimation("run_side")
imp_sprite.run_side_animation:addHorizontalSequence(640, 80, 6, 100)


imp_sprite.run_up_animation = imp_sprite:newAnimation("run_up")
imp_sprite.run_up_animation:addHorizontalSequence(640, 160 ,6, 100)

imp_sprite.battle_start_animation = imp_sprite:newAnimation("battle_start")
imp_sprite.battle_start_animation:addHorizontalSequence(1056, 80 ,3, 150)
imp_sprite.battle_start_animation.Loop = false

imp_sprite.battle_idle_animation = imp_sprite:newAnimation("battle_idle")
imp_sprite.battle_idle_animation:addHorizontalSequence(1280, 80 ,4, 150)


imp_sprite.preparing_attack_animation = imp_sprite:newAnimation("preparing_attack")
imp_sprite.preparing_attack_animation:addHorizontalSequence(1056, 240 ,1, 150000)
imp_sprite.preparing_attack_animation.Loop = false

imp_sprite.battle_attack_animation = imp_sprite:newAnimation("battle_attack")
imp_sprite.battle_attack_animation:addHorizontalSequence(1568, 80 ,4, 150)
imp_sprite.battle_attack_animation.Loop = false


imp_sprite.battle_attacked_animation = imp_sprite:newAnimation("battle_attacked")
imp_sprite.battle_attacked_animation:addHorizontalSequence(1056, 160 ,2, 250)
imp_sprite.battle_attacked_animation.Loop = false


imp_sprite.battle_critical_attack_animation = imp_sprite:newAnimation("battle_critical_attack")
imp_sprite.battle_critical_attack_animation:addHorizontalSequence(1824, 80 ,3, 200)
imp_sprite.battle_critical_attack_animation:addHorizontalSequence(2064, 80 ,-3, 200)
imp_sprite.battle_critical_attack_animation.Loop = false

imp_sprite.weapon_read_sfx = Sound:new("assets/sfx/squeak2.wav")
imp_sprite.attack_sfx = Sound:new("assets/sfx/sword_hit.wav")
imp_sprite.attacked_sfx = Sound:new("assets/sfx/slice.wav")
imp_sprite.jump_sfx = Sound:new("assets/sfx/flyingobject.wav")
imp_sprite.critical_attack_sfx = Sound:new("assets/sfx/sword_critical_hit.wav")

function imp_sprite:OnAnimationStarted(sender, animation)
  if (animation == imp_sprite.battle_start_animation) then
    imp_sprite.weapon_read_sfx:Play()
  elseif (animation == imp_sprite.battle_attack_animation) then
    imp_sprite.attack_sfx:Play()
  elseif (animation == imp_sprite.preparing_attack_animation) then
    imp_sprite.jump_sfx:Play()
  elseif (animation == imp_sprite.battle_critical_attack_animation) then
    imp_sprite.critical_attack_sfx:Play()    
  elseif (animation == imp_sprite.battle_attacked_animation) then
    imp_sprite.attacked_sfx:Play()    
  end
end
  

function imp_sprite:OnAnimationFinished(sender, animation)
  local player_controller = self:getParent()  
  
  if (player_controller:get_in_battle()) then
    sender:setAnimation(imp_sprite.battle_idle_animation)
  end    
end


local local_imp_controller = character_controller:create ("Imp", imp_sprite, 20, 28)
local_imp_controller:setProperty("Name", "local_imp")
local_imp_controller:set_npc(true)

local_imp_controller:set_battle_name("imp")
local_imp_controller:set_max_hp(50)
local_imp_controller:set_current_hp(50)
local_imp_controller:set_max_mp(0)
local_imp_controller:set_current_mp(0)
local_imp_controller:set_battle_speed(20)
local_imp_controller:set_battle_attack(25)
local_imp_controller:set_battle_hit(50)
local_imp_controller:set_battle_defense(12)

return local_imp_controller
