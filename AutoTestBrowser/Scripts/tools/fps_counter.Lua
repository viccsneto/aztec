--[[
Este modulo eh responsavel pela contagem de FPS
Ele exibe o FPS atual bem como o FPS minimo e maximo atingidos
--]]

---[[
local fps_counter = Text:new(255,0,0,"",20)
local fps = 0
local fpsAvg = 0
local fpsCount = 0
local fpsFloor = 100000
local fpsAvgWeight = 0
local fpsPeak = fps
local lastFPSUpdate = 0
local elapsedFloor = 1000000
local elapsedPeak = 0
local lastFPSUpdate = 0
local currentTime = engine:getCurrentTime()

function fps_counter:OnCreate(sender)
	lastFPSUpdate = engine:getCurrentTime()
end

function fps_counter:OnUpdate(sender)
	currentTime = engine:getCurrentTime()
	local elapsedTime = engine:getTrueElapsedTime()
	if(currentTime-lastFPSUpdate >= 1) then
		fps = fpsCount
    
    fpsAvgWeight = fpsAvgWeight + 1
    
		if(fps < fpsFloor) then
			fpsFloor = fps
		end
		
		if(fps > fpsPeak) then
			fpsPeak = fps
		end
		
		lastFPSUpdate = engine:getCurrentTime()
		fpsAvg = ((fps + ((fpsAvgWeight-1) * fpsAvg)) / fpsAvgWeight)
		fpsCount = 0
	end

	fpsCount = fpsCount + 1
	
	if(elapsedTime < elapsedFloor) then
		elapsedFloor = elapsedTime
	end
	
	if(elapsedTime > elapsedPeak) then
		elapsedPeak = elapsedTime
	end
  
  local strElapsed = string.format("%.4f", elapsedTime)
  local strPeak = string.format("%.4f", elapsedPeak)
  local strFloor = string.format("%.4f", elapsedFloor)
  local strFpsAvg = string.format("%.4f", fpsAvg)
	fps_counter:setText("FPS:"..fps.."\n   ["..fpsFloor.."<="..strFpsAvg.."<="..fpsPeak.."]\nElapsed:"..strElapsed.."\n   ["..strFloor.."<="..strElapsed.."<="..strPeak.."]")
end

return fps_counter
--]]