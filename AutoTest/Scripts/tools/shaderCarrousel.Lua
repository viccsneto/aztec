if(shaderCarrousel~=nil) then
	return shaderCarrousel
end

local shaderCarrousel = {}

shaderCarrousel.lastTime = 0
shaderCarrousel.interval = 5
shaderCarrousel.current  = 1
shaderCarrousel.count    = 5

shaderCarrousel.names = 
	{
		'default shader',
		'shaders/colorcrazyness.fs',
		'shaders/dynamicLight.fs',
		'shaders/grayScale.fs',
		'shaders/oneminus.fs',
	}
shaderCarrousel.list = 
	{
		Shader:createFromFiles(nil,nil),
		Shader:createFromFiles(nil,shaderCarrousel.names[2]),
		Shader:createFromFiles(nil,shaderCarrousel.names[3]),
		Shader:createFromFiles(nil,shaderCarrousel.names[4]),
		Shader:createFromFiles(nil,shaderCarrousel.names[5])
	}

function shaderCarrousel:getCurrentName()	
	return shaderCarrousel.names[shaderCarrousel.current]
end
function shaderCarrousel:getCurrent()	
	return shaderCarrousel.list[shaderCarrousel.current]
end

function shaderCarrousel:update()
	local currentTime = engine:getCurrentTime()
	if ((currentTime - shaderCarrousel.lastTime) > shaderCarrousel.interval) then
		shaderCarrousel.lastTime = currentTime
		shaderCarrousel.current = shaderCarrousel.current + 1
		if(shaderCarrousel.current > shaderCarrousel.count) then	
			shaderCarrousel.current = 1
		end
	end
	return self:getCurrent()
end

function shaderCarrousel:release()
	for i=2,shaderCarrousel.count do
		return shaderCarrousel.list[i]:delete()
	end
end
	
return shaderCarrousel