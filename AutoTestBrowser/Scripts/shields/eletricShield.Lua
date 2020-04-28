local newShield = Sprite:new("Assets/Image/shields.png",51,48,true)

newShield:createCircleSensor(26)
newShield:pivotOnCenter()
newShield.Transform.scale:set(1.38, 1.28)
newShield.sfx = Sound:new("Assets/SFX/shield.wav")

newShield.normal = newShield:newAnimation("normal")
newShield.normal:addHorizontalSequence(6,55,9,100)

newShield.hitted = newShield:newAnimation("hitted")
newShield.hitted:addHorizontalSequence(159,4,3,75)

newShield.hitted.Loop = false

function newShield:OnBeginContact(a,b)
	if(b.OBJECT_TYPE=="ENEMY_PROJECTILE") then	
		if(a:getCurrentAnimation()~=a.hitted) then
			a:setAnimation(a.hitted)							
		end
		--newShield.sfx:Play()
		
		b:destroy()
	end
end

function newShield:OnAnimationStart(sprite,animation)
	if(animation==sprite.hitted) then		
		sprite:setAnimation(sprite.normal)
	end
end
function newShield:OnAnimationFinished(sprite,animation)
	if(animation==sprite.hitted) then
		sprite:setAnimation(sprite.normal)
	end
end

return newShield


