shaderCarrousel = dofile("scripts/tools/shaderCarrousel.Lua") 
firstScene = dofile("scripts/scenes/first_stage.Lua") 
editorScene = dofile("scripts/scenes/editor.Lua")

engine:run(editorScene)
shaderCarrousel:release()






