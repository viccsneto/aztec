---
-- This module implements a JRPG style dialog controller
-- @type dialog_controller
dialog_controller = {
  __private = {
    margin = {
      left = 0,
      top =  0,
    }   
  }
}

---
-- Creates a dialog window with the given options and shows it
-- @param self The module itself
-- @param #string title The title of the dialog
-- @param #string text The text of the dialog
-- @param #string options A string describing an array of options
-- @param #string position A string describing the position of the dialog ("center", "north", "northeast"...) 
-- @param #function callback A callback function which will receive a table with the user selected option 
-- @return #dialog The dialog object
function dialog_controller:create(title, text, options, position, callback)

  
  ---
  -- @type dialog
  local dialog = WebBrowser:new ("file:///LuaSubSystem/JRPG/UI/Dialog/dialog.html", Config.SCREEN_WIDTH , Config.SCREEN_HEIGHT, true) 
  --local dialog = WebBrowser:new ("file:///LuaSubSystem/JRPG/UI/Dialog/dialog2.html", Config.SCREEN_WIDTH , Config.SCREEN_HEIGHT, true)
  
  
  dialog:setAlwaysFocused(true)  
  dialog.__private = self.__private;
  
   
  -- Puts the web render component in the actual scene in an unusually very high layer order. This way it will almost certainly be shown in front of all other components
  engine:getCurrentGameState():add(dialog, 2000000)
  
  function dialog:OnDestroy(sender)    
    if (dialog_controller.__private.quest_visibility) then
      quest_controller:set_visibility(true)
      dialog_controller.__private.quest_visibility = nil
    end
  end
  ---
  -- Offers an API to setup the current dialog presentation and behaviour
  -- @param self The dialog itself 
  -- @param #string title The title of the dialog
  -- @param #string text The text of the dialog
  -- @param #string options A string describing an array of options
  -- @param #string position A string describing the position of the dialog ("center", "north", "northeast"...)
  -- @param #function callback A callback function which will receive a table with the user selected option 
  function dialog:setup(title, text, options, position, callback)
    keyboard:reset()
    self:setAlwaysFocused(true)
    dialog_controller.__private.quest_visibility = dialog_controller.__private.quest_visibility and dialog_controller.__private.quest_visibility or quest_controller:get_visibility()        
    quest_controller:set_visibility(false)
    
    if (position == nil) then
      position = "north"
    end

    if (type(callback) == "function") then
      dialog.answered = callback
    else
      dialog.answered = function(self, opt)
        self:destroy()
        maincharacter():clean_action()
        maincharacter():set_can_control(true)
        
      end
    end

    dialog.script_to_execute = "Setup('"..title.."','"..text.."',"..options..",'"..position.."')"
  end

  -- Setup the new dialog component with the constructor argument options
  dialog:setup(title, text, options, position, callback)

  -- Controls the dialog execution
  function dialog:OnUpdate(sender)
    local camera = gamestate():getActiveCamera()
        
    sender.Transform.position:set(camera.Transform.position.x - (Config.SCREEN_WIDTH / 2) + self.__private.margin.left ,camera.Transform.position.y - (Config.SCREEN_HEIGHT / 2) + self.__private.margin.top)
    
    local player = maincharacter()
    player:set_can_control(false)    
    if (not sender:isLoading() and sender.script_to_execute ~= nil) then
      print(sender.script_to_execute)
      sender:ExecuteScript(sender.script_to_execute)
      sender.script_to_execute = nil      
    end
  end

  return dialog
end
