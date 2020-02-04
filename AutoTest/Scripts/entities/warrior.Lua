local point_list = PointList2D:new()
point_list:add(-30 , 0)
point_list:add(30, 0)
point_list:add(30, 30)
point_list:add(0 , 40)
point_list:add(-30 , 30)

local newWarrior =  GameObject:new()

newWarrior.OBJECT_TYPE = "PLAYER"
newWarrior:setPivot(50,29)

newWarrior:addGameObject(Sensor:new(0,0,12))
newWarrior.sprite = newWarrior:addGameObject(Sprite:new("Assets/Image/warrior.png",76,58,true))

newWarrior.Visible =true
newWarrior.speed   = 225
newWarrior.score = 0
newWarrior.Transform.position:set(600,0)
newWarrior.accumulator = 0;

function TransformToStr(name, obj)
  return name.." Transform {x = "..obj.Transform.position.x.." y = "..obj.Transform.position.y.."}"
end
function newWarrior:OnBeginContact(a,b)
	if(b.OBJECT_TYPE=="ENEMY_PROJECTILE") then
		autotest:Fail("\n\tWarrior's shield isn't working:\n\n\t\tWhat have you done to the physics subsystem?!\n\t"..TransformToStr("a = ",a).."\n\t"..TransformToStr("b = ",b).."\n")
	end
end

newWarrior.Transform.zorder = 1
newWarrior.flying = newWarrior.sprite:newAnimation("flying")
newWarrior.flying:addHorizontalSequence(310,10,4,33)
newWarrior.projectile = dofile("scripts/projectiles/smallProjectile.Lua")
newWarrior.shield = newWarrior:addGameObject(dofile("scripts/shields/eletricShield.Lua"))

-- The following line will make the physics test fail on purpose
--newWarrior.shield.Transform.position.x = newWarrior.shield.Transform.position.x + 50

newWarrior.Transform.scale:set(1.5,1.5)

function newWarrior:fire1()	
	self.projectile:fire(newWarrior)
end


function newWarrior:OnUpdate(sender)
	newWarrior.sprite:setShader(shaderCarrousel:update())
	local elapsedTime = engine:getElapsedTime()
	shaderCarrousel:getCurrent():SetUniform('lightPos',newWarrior.Transform.position.x,newWarrior.Transform.position.y,0.0)
	
	sender.accumulator = sender.accumulator + engine:getElapsedTime()
	self.Transform.position:set(self.game_state.enemy.Transform.position.x+math.cos(sender.accumulator)*270, self.game_state.enemy.Transform.position.y+math.sin(sender.accumulator)*270)
	
	camera =  engine:getCurrentGameState():getActiveCamera()
	if(keyboard:keyIsDown(Keyboard.KEY_RIGHT)) then
		camera.Transform.position.x = camera.Transform.position.x + self.speed * elapsedTime
    elseif(keyboard:keyIsDown(Keyboard.KEY_LEFT)) then
		camera.Transform.position.x = camera.Transform.position.x - self.speed * elapsedTime
	end
	
	if(keyboard:keyIsDown(Keyboard.KEY_UP )) then
		camera.Transform.position.y = camera.Transform.position.y- self.speed * elapsedTime
	elseif(keyboard:keyIsDown(Keyboard.KEY_DOWN)) then
		camera.Transform.position.y = camera.Transform.position.y + self.speed * elapsedTime
	end
	
	if(self.Transform.position.x < self.game_state.enemy.Transform.position.x) then
		if(math.abs(self.Transform.position.y-self.game_state.enemy.Transform.position.y)<=30) then
			self:fire1()	
		end
	end
	
end


return newWarrior
--]]