--Initializes JRPG subsystem
dofile("scripts/JRPGEngine/JRPGEngine.Lua")

-- Pre Load All Scenes
dofile("scripts/scenes/1000ad_overworld.lua")
dofile("scripts/scenes/1000ad_crono_house_1f.lua")
dofile("scripts/scenes/1000ad_crono_house_2f.lua")
dofile("scripts/scenes/1000ad_tecgrafia_castle_1f.lua")
dofile("scripts/scenes/1000ad_cathedral_school_1f.lua")
dofile("scripts/scenes/1000ad_melchior_hut_1f.lua")
dofile("scripts/scenes/infinite_dungeon.lua")
dofile("scripts/scenes/the_end.lua")

--scene_controller:run("CRONO_HOUSE_2F", "Bed", -1, 0)

scene_controller:run("CRONO_HOUSE_1F", "Entrance", 0, -1)
--scene_controller:run("1000AD_OVERWORLD", "Crono_House", 0, 0)
--scene_controller:run("1000AD_CATHEDRAL_SCHOOL_1F", "Entrance", 0,  -1)
--scene_controller:run("1000AD_TECGRAFIA_CASTLE_1F", "Entrance", 0, -1)
--scene_controller:run("INFINITE_DUNGEON", "Entrance", 0,  -1)
--scene_controller:run("MELCHIOR_HUT_1F", "Entrance", 0, -1)
--scene_controller:run("1000AD_THE_END", "Entrance", 0,  -1)
