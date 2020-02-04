local novoCursorMouse = Sprite:new("assets/image/cursor.png")
novoCursorMouse.TIPO_CURSOR_MOUSE = true
novoCursorMouse.Transform.zorder = 1000

function novoCursorMouse:OnUpdate(sender,timeElapsed)
	novoCursorMouse.Transform.position:set(mouse:getPosX(),mouse:getPosY())
end

function novoCursorMouse:OnDestroy()
	mouse:showCursor()
end

return novoCursorMouse
