--Este modulo define o missil lancado pelas naves inimigas

--Se o modulo ja foi criado nao precisa criar novamente
if(Enemy_missile~=nil) then
	return Enemy_missile
end

--Cria parametros privados para o modulo
local _private =  
{
	CLASS_TYPE = "MISSILE",
	speed = 0,
	range = 800,
	x0 = -29,
	y0 = -16,
	y0b = 18,
	soundfx = Sound:new("Assets/SFX/launch.wav")
}

--Este evente acontece a cada quadro e define a nova posicao do missil (que se move para a esquerda)
--Caso o missil tenha percorrido mais do que seu alcance maximo, entao eh destruido
function _private:OnUpdate(sender)
	sender.Transform.position.x = sender.Transform.position.x - _private.speed * engine:getElapsedTime()
	if(sender.Transform.position.x < sender.launchPosition.x - _private.range) then	
		sender:destroy()
	end
	
end

--Quando o missil eh criado, entao toca um som de disparo de missil(bem, mais ou menos... eh uma catapulta do war2 ><)
function _private:OnCreate(sender)
	_private.soundfx:Play()
end

--Cada inimigo so pode atirar um missil por vez. Assim, quando o missil for destruido notifica a nave lancadora de que pode lancar novos niveis
function _private:OnDestroy(sender)
	sender.enemy.canFire = true
end
--cria uma tabela Lua para representar o modulo
local Enemy_missile =  {}

--Dispara um par de misseis referentes a nave "enemy"
function Enemy_missile:fire(enemy)
	--Cria um sprite sensor para representar o missil (ele eh ao mesmo tempo um sprite e um sensor retangular de mesma dimensao do sprite)
	local projectile = SpriteSensor:new("Assets/Image/enemy_si.png",46,21,true)
	
	--proibe que a nave lancadora lance novos misseis ateh que estes tenham sido destruidos
	enemy.canFire = false
	
	--Faz os eventos do missel apontarem para as definicoes privadas aqui definidas
	projectile.OnCreate = _private.OnCreate
	projectile.OnDestroy = _private.OnDestroy
	projectile.OnUpdate = _private.OnUpdate
	
	--Adiciona o missil na layer BackDrops do gameState
	enemy.game_state:addBackDrops(projectile)
	
	--Seta a TAG do missil de acordo com as definicoes privadas(neste caso, MISSILE)
	projectile.OBJECT_TYPE = _private.CLASS_TYPE
	
	--Cria uma sequencia de animacao do missil voando
	projectile:newAnimation("forward"):addHorizontalSequence(27,586,4,100)
	
	--Define as posicoes iniciais e de lancamento do missil(usada para computar se a distancia maxima foi percorrida)
	projectile.Transform.position:set(enemy.Transform.position.x+_private.x0,enemy.Transform.position.y+_private.y0)
	projectile.launchPosition={x=projectile.Transform.position.x,y=projectile.Transform.position.y}	

	--Mais do mesmo, so que para o segundo missel (eh um par).
	--Poderia ser melhor modularizado... um pouco de colaboracao seria bem vinda: que tal?
	
	--Cria um sprite sensor para representar o missil b(ele eh ao mesmo tempo um sprite e um sensor retangular de mesma dimensao do sprite)
	local projectileb = SpriteSensor:new("Assets/Image/enemy_si.png",46,21,true)
	
	--Faz os eventos do missel b apontarem para as definicoes privadas aqui definidas
	projectileb.OnCreate = _private.OnCreate
	projectileb.OnDestroy = _private.OnDestroy
	projectileb.OnUpdate = _private.OnUpdate
	
	--Adiciona o missil na layer BackDrops do gameState
	enemy.game_state:addBackDrops(projectileb)
	
	--Seta a TAG do missil de acordo com as definicoes privadas(neste caso, MISSILE)
	projectileb.OBJECT_TYPE = _private.CLASS_TYPE
	
	--Cria uma sequencia de animacao do missil voando
	projectileb:newAnimation("forward"):addHorizontalSequence(27,586,4,100)
	
	--Define as posicoes iniciais e de lancamento do missil(usada para computar se a distancia maxima foi percorrida)
	projectileb.Transform.position:set(enemy.Transform.position.x+_private.x0,enemy.Transform.position.y+_private.y0b)
	projectileb.launchPosition={x=projectileb.Transform.position.x,y=projectileb.Transform.position.y}

	--Diz para cada missil quem foi a nave lancadora (para que ele notifique se pode ou nao atirar novamente)
	projectile.enemy = enemy
	projectileb.enemy = enemy
	
end

return Enemy_missile
