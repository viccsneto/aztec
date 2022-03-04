print (package.path)
print (package.cpath)


require("debugger")("localhost", 65535, "luaidekey")

-- Runs the main program, now with debugging support
dofile("scripts/main.Lua")

