--[[
Este eh um modulo informativo que tem por objetivos exibir: 
	o tempo de execucao do sistema
	o quanto de memoria alocada pela camada Lua ainda nao foi recolhida pelo garbage collector
	o numero de objetos alocados
	o numero de frames por segundo com que o CppPlay esta executando
--]]

--Cria um objeto Texto
infoPanel = Text:new(255,255,255,"",22)

--Cria e posiciona o componente de informacoes de uso de memoria
infoPanel.memoryInfo = infoPanel:addGameObject(dofile("scripts/tools/memory_info.Lua"))
infoPanel.memoryInfo.Transform.position:set(0,60)

--Cria e reposiciona o componente de contagem de FPS
infoPanel.fpsInfo    = infoPanel:addGameObject(dofile("scripts/tools/fps_counter.Lua"))
infoPanel.fpsInfo.Transform.position:set(0,150)

--Cria e reposiciona a Label que informará qual o shader program em execução
infoPanel.lblShaderProgram = infoPanel:addGameObject(Text:new(155,155,155,"",20))
infoPanel.lblShaderProgram.Transform.position:set(0,260)

--Cria e reposiciona a Label de mensagem generica (utilizamos para SCORE)
infoPanel.message =""
infoPanel.lblMessage = infoPanel:addGameObject(Text:new(255,255,255,"",20))
infoPanel.lblMessage.Transform.position:set(0,320)


--A cada quadro atualiza a informacao de tempo de execucao e mensagem generica
function infoPanel:OnUpdate(sender,timeElapsed)			
	sender:setText("Running time:"..engine:getCurrentTime().."\nTrue Time:   "..engine:getTrueCurrentTime())	
	sender.lblMessage:setText(sender.message)
  sender.lblShaderProgram:setText("Shader Program: "..shaderCarrousel:getCurrentName())
end

return infoPanel