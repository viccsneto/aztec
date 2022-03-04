function create_magic()
  local magic = Sprite:new("assets/image/misc/magic.png", 96, 96)
  
  magic.no_animation = magic:newAnimation("no")
  
  magic.wind_animation = magic:newAnimation("wind")
  magic.wind_animation:addHorizontalSequence(0, 0, 5, 175)
  magic.wind_animation.sfx = Sound:new("assets/sfx/wind.wav")
  
  
  magic.fire_animation = magic:newAnimation("fire")
  magic.fire_animation:addHorizontalSequence(0, 96, 3, 175)
  magic.fire_animation.sfx = Sound:new("assets/sfx/fire.wav")
  
  magic.water_animation = magic:newAnimation("water")
  magic.water_animation:addHorizontalSequence(0, 192, 3, 275)
  magic.water_animation.sfx = Sound:new("assets/sfx/water.wav")
  
  magic.apple_animation = magic:newAnimation("green_apple")
  magic.apple_animation:addHorizontalSequence(0, 288, 4, 275)
  magic.apple_animation.sfx = Sound:new("assets/sfx/apple.wav")
  
  magic.death_animation = magic:newAnimation("death")
  magic.death_animation:addHorizontalSequence(0, 384, 5, 275)
  magic.death_animation.Loop = false
  magic.death_animation.sfx = Sound:new("assets/sfx/death.wav")
  
  magic.life_animation = magic:newAnimation("life")
  magic.life_animation:addHorizontalSequence(0, 480, 5, 275)
  --[[
  magic.life_animation:addHorizontalSequence(0, 480, 5, 275)
  magic.life_animation:addHorizontalSequence(0, 480, 6, 275)
  magic.life_animation.Loop = false
  --]]
  
  magic.life_animation.sfx = Sound:new("assets/sfx/life.wav")
  
  
  function magic:no()
    self:setAnimation(self.no_animation)
    return self
  end
  
  function magic:fire()
    self:setAnimation(self.fire_animation)
    return self
  end
  
  function magic:water()
    self:setAnimation(self.water_animation)
    return self
  end
  
  function magic:wind()
    self:setAnimation(self.wind_animation)
    return self
  end
  
  function magic:apple()
    self:setAnimation(self.apple_animation)
    return self
  end
  
  function magic:life()
    self:setAnimation(self.life_animation)
    return self
  end
  
  function magic:death()
    self:setAnimation(self.death_animation)
    return self
  end
  
  function magic:OnAnimationStarted(sender, animation)
    if (animation.sfx ~= nil) then
      animation.sfx:Play()
    end
  end
  magic:pivotOnCenter()
  return magic
end  