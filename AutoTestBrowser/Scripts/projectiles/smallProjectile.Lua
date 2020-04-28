if(Small_missile~=nil) then
	return Small_missile
end


local _private =  
{
	CLASS_TYPE = "PROJECTILE",
	speed = 450,
	range = 1280,
	fire_rate = 15,
	last_time = 0,
	x0 = 46,
	y0 = 0,
	soundfx = Sound:new("Assets/SFX/Laser.wav")
}


function _private:OnUpdate(sender)
	sender.Transform.position.x = sender.Transform.position.x + _private.speed * engine:getElapsedTime()
	if(sender.Transform.position.x > sender.launchPosition.x + _private.range) then
		sender:destroy()
	end
	
end

function _private:OnCreate(sender)
	--_private.soundfx:Play()
	
end

local Small_missile =  {}


function Small_missile:fire(warrior)
	if((engine:getCurrentTime() - _private.last_time) >= (1/_private.fire_rate)) then
		_private.last_time = engine:getCurrentTime()
		local projectile = Sprite:new("Assets/Image/warrior.png",10,10,true)
		projectile:createCircleSensor(5)
		projectile.OnCreate = _private.OnCreate
		warrior.game_state:addBackDrops(projectile)
		projectile.OBJECT_TYPE = _private.CLASS_TYPE
		projectile:newAnimation("forward"):addFrame(297,468,100)
		projectile.OnUpdate = _private.OnUpdate
		
		projectile.Transform.position:set(warrior.Transform.position.x+_private.x0,warrior.Transform.position.y+_private.y0)
		projectile.launchPosition={x=projectile.Transform.position.x,y=projectile.Transform.position.y}				
	end
end

return Small_missile
