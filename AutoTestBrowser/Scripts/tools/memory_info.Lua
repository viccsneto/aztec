local memoryInfo = Text:new(255,255,0,"",20)

local function gcinfo()
  return collectgarbage("count")
end

local memoryCount = gcinfo()
--Este modulo acompanha a utilizacao de memoria por Lua e pelo CppPlay

--a funcao gcinfo() de Lua disponibiliza informacoes sobre o garbage collector
--Enquanto o LuaSubSystem disponibiliza o numero de objetos alocados no CppPlay pela camada Lua


--Variaveis locais para exibir o range de utilizacao de memoria
local memoryFloor = memoryCount
local memoryPeak  = memoryCount
local bindedCount = __AztecBindedObjects.count
local bindedFloor = bindedCount
local bindedPeak  = bindedCount

--Evento executado a cada frame (Sempre exibe as informacoes atuais do uso)
function memoryInfo:OnUpdate(sender)

	memoryCount = gcinfo()
	
	if(memoryCount < memoryFloor) then
		memoryFloor = memoryCount
	end
	
	if(memoryCount > memoryPeak) then
		memoryPeak = memoryCount
	end
	
	bindedCount = __AztecBindedObjects.count
	if(bindedCount < bindedFloor) then
		bindedFloor = bindedCount
	end
	
	if(bindedCount > bindedPeak) then
		bindedPeak = bindedCount
	end
		
	memoryInfo:setText("GCInfo:"..memoryCount.."\n   ["..memoryFloor.."<="..memoryCount.."<="..memoryPeak.."]\nObjects:"..bindedCount.."\n   ["..bindedFloor.."<="..bindedCount.."<="..bindedPeak.."]\n")	
	
end

return memoryInfo