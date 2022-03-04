local crono_sprite

crono_sprite = Sprite:new("assets/image/characters/chronotrigger_crono_sheet.png", 64 ,80);
crono_sprite:pivotOnCenter()

crono_sprite.idle_down_animation = crono_sprite:newAnimation("idle_down")
crono_sprite.idle_down_animation:addFrame(64 , 0,100)
crono_sprite.idle_down_animation:addFrame(128,0,50)
crono_sprite.idle_down_animation:addFrame(0,0,5000)

crono_sprite.idle_side_animation = crono_sprite:newAnimation("idle_side")
crono_sprite.idle_side_animation:addFrame(0, 80,2500)
crono_sprite.idle_side_animation:addFrame(64, 80,150)
crono_sprite.idle_side_animation:addFrame(128, 80,150)

crono_sprite.idle_up_animation = crono_sprite:newAnimation("idle_up")
crono_sprite.idle_up_animation:addFrame(0, 160,10000)



crono_sprite.walk_down_animation = crono_sprite:newAnimation("walk_down")
crono_sprite.walk_down_animation:addHorizontalSequence(224, 0 ,6,150)

crono_sprite.walk_side_animation = crono_sprite:newAnimation("walk_side")
crono_sprite.walk_side_animation:addHorizontalSequence(224, 80,6,150)

crono_sprite.walk_up_animation = crono_sprite:newAnimation("walk_up")
crono_sprite.walk_up_animation:addHorizontalSequence(224,160,6,150)

crono_sprite.run_down_animation = crono_sprite:newAnimation("run_down")
crono_sprite.run_down_animation:addHorizontalSequence(640, 0, 6,100)

crono_sprite.run_side_animation = crono_sprite:newAnimation("run_side")
crono_sprite.run_side_animation:addHorizontalSequence(640, 80, 6, 100)


crono_sprite.run_up_animation = crono_sprite:newAnimation("run_up")
crono_sprite.run_up_animation:addHorizontalSequence(640, 160 ,6, 100)

crono_sprite.battle_start_animation = crono_sprite:newAnimation("battle_start")
crono_sprite.battle_start_animation:addHorizontalSequence(1056, 80 ,3, 250)
crono_sprite.battle_start_animation.Loop = false

crono_sprite.battle_idle_animation = crono_sprite:newAnimation("battle_idle")
crono_sprite.battle_idle_animation:addHorizontalSequence(1280, 80 ,2, 250)
crono_sprite.battle_idle_animation:addHorizontalSequence(1440, 80 ,-2, 250)


crono_sprite.preparing_attack_animation = crono_sprite:newAnimation("preparing_attack")
crono_sprite.preparing_attack_animation:addHorizontalSequence(1056, 240 ,1, 150000)
crono_sprite.preparing_attack_animation.Loop = false

crono_sprite.battle_attack_animation = crono_sprite:newAnimation("battle_attack")
crono_sprite.battle_attack_animation:addHorizontalSequence(1568, 80 ,4, 150)
crono_sprite.battle_attack_animation.Loop = false


crono_sprite.battle_attacked_animation = crono_sprite:newAnimation("battle_attacked")
crono_sprite.battle_attacked_animation:addHorizontalSequence(1056, 160 ,2, 250)
crono_sprite.battle_attacked_animation.Loop = false


crono_sprite.battle_critical_attack_animation = crono_sprite:newAnimation("battle_critical_attack")
crono_sprite.battle_critical_attack_animation:addHorizontalSequence(1824, 80 ,3, 200)
crono_sprite.battle_critical_attack_animation.Loop = false

crono_sprite.battle_win_animation = crono_sprite:newAnimation("battle_win_animation")
crono_sprite.battle_win_animation:addHorizontalSequence(1056, 0 ,2, 500)
crono_sprite.battle_win_animation.Loop = true

crono_sprite.weapon_read_sfx = Sound:new("assets/sfx/weaponreadied.wav")
crono_sprite.attack_sfx = Sound:new("assets/sfx/sword_hit.wav")
crono_sprite.attacked_sfx = Sound:new("assets/sfx/slice.wav")
crono_sprite.jump_sfx = Sound:new("assets/sfx/flyingobject.wav")
crono_sprite.critical_attack_sfx = Sound:new("assets/sfx/sword_critical_hit.wav")

function crono_sprite:OnAnimationStarted(sender, animation)
  if (animation == crono_sprite.battle_start_animation) then
    crono_sprite.weapon_read_sfx:Play()
  elseif (animation == crono_sprite.battle_attack_animation) then
    crono_sprite.attack_sfx:Play()
  elseif (animation == crono_sprite.preparing_attack_animation) then
    crono_sprite.jump_sfx:Play()
  elseif (animation == crono_sprite.battle_critical_attack_animation) then
    crono_sprite.critical_attack_sfx:Play()    
  elseif (animation == crono_sprite.battle_attacked_animation) then
    crono_sprite.attacked_sfx:Play()    
  end
end
  

function crono_sprite:OnAnimationFinished(sender, animation)
  local player_controller = self:getParent()  

  if (player_controller:get_in_battle()) then
    sender:setAnimation(crono_sprite.battle_idle_animation)
  end    
end


local local_crono_controller = character_controller:create ("Crono", crono_sprite, 20, 28)
local_crono_controller:setProperty("Name", "local_crono")
local_crono_controller:set_maincharacter()

local_crono_controller:set_battle_name("Crono")
local_crono_controller:set_max_hp(100)
--local_crono_controller:set_current_hp(10)
local_crono_controller:set_max_mp(30)
local_crono_controller:set_current_mp(13)
local_crono_controller:set_battle_speed(65)
local_crono_controller:set_battle_attack(30)
local_crono_controller:set_battle_defense(15)

function local_crono_controller:on_battle_finished()
  local current_hp = self:get_current_hp()
  print("Battle finished:"..current_hp)
  if (current_hp == 0) then
    scene_controller:run("CRONO_HOUSE_2F", "Bed", -1, 0)
  end
  
end

return local_crono_controller
