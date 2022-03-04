if (tell_story_table == nil) then
  function tell_story_table(table, transition_function)
    local current_item = 1
    local max_item = #table
  
    if (table[current_item].item_function) then
      table[current_item].item_function()
    end
  
    dialog_controller:create(
      table[current_item].actor,
      table[current_item].text,
      table[current_item].options and table[current_item].options or "[]",
      table[current_item].position,
      function(sender, opt)
        if (current_item < max_item) then
          current_item = current_item + 1
          if (table[current_item].item_function) then
            table[current_item].item_function()
          end
          sender:setup(
            table[current_item].actor,
            table[current_item].text,
            table[current_item].options and table[current_item].options or "[]",
            table[current_item].position,
            sender.answered
          )
        else
          sender:destroy()
          if (transition_function) then
            transition_function()
          end
        end
      end
    )
  end
end