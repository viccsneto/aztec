local newBackGround = GameObject:new();

local _private =
{
	Speed = 95
}

function _private:OnUpdate(sender)
	sender:setShader(shaderCarrousel:update())
	sender.Transform.position.x = sender.Transform.position.x - (_private.Speed * engine:getElapsedTime())

	if(sender.Transform.position.x<-2055) then
		sender.Transform.position.x=sender.other.Transform.position.x+2055
	end	
end

newBackGround.bg1 = newBackGround:addGameObject(Sprite:new("Assets/Image/background.jpg"))
newBackGround.bg1.OnUpdate = _private.OnUpdate

newBackGround.bg2 = newBackGround:addGameObject(Sprite:new("Assets/Image/background.jpg"))
newBackGround.bg2.Transform.position:set(2055,0)
newBackGround.bg2.OnUpdate = _private.OnUpdate

newBackGround.bg2.other = newBackGround.bg1
newBackGround.bg1.other = newBackGround.bg2


return newBackGround


