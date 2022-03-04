function create_portal()
  local portal = Sprite:new("assets/image/misc/portal.png", 128, 128)
  
  portal.no_animation = portal:newAnimation("no")
  
  portal.closed_animation = portal:newAnimation("closed")
  portal.closed_animation:addHorizontalSequence(0, 0, 3, 75)
  portal.closed_animation.Loop = true
  
    
  portal.close_animation = portal:newAnimation("close")
  portal.close_animation:addHorizontalSequence(512, 128, -5, 75)
  portal.close_animation.Loop = false
  portal.close_animation.sfx = Sound:new("assets/sfx/portal.wav")
  portal.close_animation.next = portal.closed_animation
  
  portal.idle_animation = portal:newAnimation("idle")
  portal.idle_animation:addHorizontalSequence(0, 256, 5, 100)
  portal.idle_animation:addHorizontalSequence(0, 384, 5, 100)
  portal.idle_animation:addHorizontalSequence(0, 512, 5, 100)
  portal.idle_animation.Loop = true
  
  portal.open_animation = portal:newAnimation("open")
  portal.open_animation:addHorizontalSequence(0, 128, 5, 150)
  portal.open_animation.Loop = false
  portal.open_animation.sfx = Sound:new("assets/sfx/portal.wav")
  portal.open_animation.next = portal.idle_animation      
    
  
  function portal:no()
    self:setAnimation(self.no_animation)
    return self
  end
  
  function portal:idle()
    self:setAnimation(self.idle_animation)
    return self
  end
  
  function portal:open()
    self:setAnimation(self.open_animation)
    return self
  end
  
  function portal:close()
    self:setAnimation(self.close_animation)
    return self
  end
  
  function portal:closed()
    self:setAnimation(self.closed_animation)
    return self
  end   
  
  function portal:OnAnimationStarted(sender, animation)
    if (animation.sfx ~= nil) then
      animation.sfx:Play()
    end
  end
  
  function portal:OnAnimationFinished(sender, animation)
    if (animation.next ~= nil) then
      sender:setAnimation(animation.next)
    end
  end
  portal:pivotOnCenter()
  return portal
end  