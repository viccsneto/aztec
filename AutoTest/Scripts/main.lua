shaderCarrousel = dofile("scripts/tools/shaderCarrousel.Lua") 
firstScene = dofile("scripts/scenes/first_stage.Lua") 
failScene    = dofile("scripts/scenes/fail.Lua")
successScene = dofile("scripts/scenes/Success.Lua")

engine:run(successScene)
shaderCarrousel:release()






