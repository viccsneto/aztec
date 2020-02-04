local newEnemy =  SpriteSensor:new("Assets/Image/enemy.png",126,73,true)

newEnemy.hp =30

local function createShield()
	local newShield = Sprite:new("Assets/Image/enemy.png",209,209,true)
	newShield.animation = newShield:newAnimation("shielding")
	newShield.animation:addHorizontalSequence(301,0,1,100)
	newShield:createCircleSensor(104.5)
	newShield.hit_count = 0
	
	function newShield:OnBeginContact(a,b) 
   
		if(b.OBJECT_TYPE=="PROJECTILE") then
			a.hit_count = a.hit_count+1
			infoPanel.message="Score: 0 (shield enabled)"
			if(a.hit_count>6) then
				infoPanel.message="Score: 0 (GO!!!)"
				a:destroy()
				newEnemy.shield = nil
			end			
			b:destroy()
			
		end    
	end
		
	return newShield
end

local function createCannon(flipped, x, y)

	local newCannon = Sprite:new("Assets/Image/enemy.png",139,40,true)
	newCannon.animation = newCannon:newAnimation("stand")
	newCannon.animation:addFrame(8,163,1000)
	newCannon.animation.Loop = false
	newCannon.lastShot = 0
	newCannon.laser_fire_rate = 5
	newCannon.laserSpeed = 275
	newCannon.laserCount = 0
	
	if(flipped) then
		newCannon:setVerticalFlipped(true)
	end	
	
	newCannon.Transform.position:set(x,y)
	newCannon.originalY = y
	
	
	function newCannon:fire()
		local laser = SpriteSensor:new("Assets/Image/enemy.png",32,8)
		--local laser = Sensor:new(32,3)
		laser.OBJECT_TYPE="ENEMY_PROJECTILE"
		laser:newAnimation("flying"):addFrame(173,139,1000).Loop = false		
		laser.Transform.position = self:getGlobalTransform().position
		local xScale = self.ownerShip.Transform.scale.x
		local yScale = self.ownerShip.Transform.scale.y
		
		if(self.originalY > 0) then
			laser.Transform.position:sub(75*xScale,-13* yScale)
		else
			laser.Transform.position:sub(75*xScale,13* yScale)
		end
		
		laser.launchPosition = laser.Transform.position.x
		laser.range = 750
		laser.speed = self.laserSpeed
    
		function laser:OnUpdate(sender)
			sender.Transform.position.x = sender.Transform.position.x - self.speed * engine:getElapsedTime()
			if(sender.launchPosition -sender.Transform.position.x>sender.range) then
				sender:destroy()
			end

		end
		
		

		self.lastShot = engine:getCurrentTime()
		self.ownerShip.game_state:addOverlay(laser)
		laser.Transform.scale = self.ownerShip.Transform.scale
	end
	
	function newCannon:OnUpdate(sender)
		local currentTime = engine:getCurrentTime()	
		local yScale= self.ownerShip.Transform.scale.y
		if(sender.originalY > 0) then
			sender.Transform.position.y = (sender.originalY +  math.cos(currentTime)*5) * yScale
		else
			sender.Transform.position.y = (sender.originalY -  math.cos(currentTime)*5) * yScale		
		end
		if((currentTime - sender.lastShot)>=1/sender.laser_fire_rate) then
			sender:fire()
		end
	end	
	
	
	return newCannon
end
newEnemy.OBJECT_TYPE = "ENEMY"
newEnemy.Transform.zorder = 1
newEnemy.Transform.position:set(50,50)

newEnemy.vspeed = 95
newEnemy.hspeed = 95

newEnemy.flying = newEnemy:newAnimation("flying")
newEnemy.flying:addFrame(3,41,1000)
newEnemy.flying.Loop = false

newEnemy.rightCannon  = newEnemy:addGameObject(createCannon(false,5,-31))
newEnemy.rightCannon.ownerShip = newEnemy
newEnemy.leftCannon   = newEnemy:addGameObject(createCannon(true,5,31))
newEnemy.leftCannon.ownerShip = newEnemy

newEnemy.shield = newEnemy:addGameObject(createShield())

function newEnemy:OnBeginContact(a,b)
	if(b.OBJECT_TYPE=="PROJECTILE") then
		b:destroy()
		self.game_state.warrior.score = self.game_state.warrior.score + 10
		infoPanel.message="Score: "..self.game_state.warrior.score
  end
end


function newEnemy:OnUpdate(sender)
	
	newEnemy:setShader(shaderCarrousel:update())
	if(newEnemy.shield~=nil) then
		newEnemy.shield:setShader(shaderCarrousel:update())
	end
	newEnemy.leftCannon:setShader(shaderCarrousel:update())
	newEnemy.rightCannon:setShader(shaderCarrousel:update())
	
	if((sender.Transform.position.x >= 850) or (sender.Transform.position.x <= 250)) then
		sender.hspeed=-sender.hspeed
	end
	
	if((sender.Transform.position.y >= 600) or (sender.Transform.position.y <= 50)) then
		sender.vspeed=-sender.vspeed
	end	
	local elapsedTime = engine:getElapsedTime()
	local hMovement = sender.hspeed * elapsedTime 
	local vMovement = sender.vspeed * elapsedTime 

	sender.Transform.position:set(sender.Transform.position.x + hMovement , sender.Transform.position.y + vMovement)			
end


newEnemy.Transform.scale:set(1.5,1.5)

return newEnemy
