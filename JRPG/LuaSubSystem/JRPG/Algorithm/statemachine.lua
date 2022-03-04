---
-- This module implements a Finite State Machine with automatic transition execution and stack
-- @type statemachine
statemachine = {}

statemachine.__index = statemachine

-- Syntax suggar to call a function passing un unpacked table as arguments  
local function call_handler(handler, params)
  if handler then
    return handler(unpack(params))
  end
end

---
-- Creates a transition function based on State Names
--  
--This function will call corresponding states of the transitions such as:
--       
--    onbeforeNEW_STATE_NAME   -- Cancel the transition when returning false
--    onleaveACTUAL_STATE_NAME -- Cancel the transition when returning false
--    
--    onenterNEW_STATE_NAME    -- Occurs when the transition is executed
--    onafterOLD_STATE_NAME    -- Occurs when the old state is left
--    
--    onstatechange            -- Occurs everytime a state changes
--
local function create_transition(name)
  return function(self, ...)
    local current = self:current()
    local to = name
    local from = current and current.name or "none"
    local params = { self, from, to, ... }
    
    local state = self:find_state(name)
    if (not state) then
      return false
    end
    
    call_handler(self["beforestatechange"], params)
    
    if (call_handler(self["onbefore" .. name], params) == false or call_handler(self["onleave" .. from], params) == false) then
      return false
    end
    
    state.has_executed = true
    
    if (self.__private.stack:top() ~= state) then
      self.__private.stack:push(state)
    end
    
    call_handler(self["onenter" .. to] or self["on" .. to], params)
    call_handler(self["onafter" .. from], params)
    call_handler(self["onstatechange"], params)

    return true
  end
end

---
-- Searches a state in the Statestatemachine
-- 
function statemachine:find_state(name)
  local lookup_state = nil
  for _, state in ipairs(self.__private.options.states or {}) do
    if (state.name == name) then
      lookup_state = state;
      break;
    end
  end
  return lookup_state
end

---
-- Creates a FiniteStatestatemachine with the given options
-- @return #statemachine
function statemachine.create(options)
  assert(options.states)

  local fsm = {__private = {}}
  setmetatable(fsm, statemachine)

  fsm.__private.options = options
  fsm.__private.stack = stack.create(5)  
  fsm.__private.states = {}
  fsm.__private.conditions = {}
  fsm.__private.variables = {}

  for _, state in ipairs(options.states or {}) do
    local name = state.name
    fsm[name] = fsm[name] or create_transition(name)
    fsm.__private.states[name] = fsm.__private.states[name] or {has_executed = false}
    fsm.__private.checks = {} 
        
  end
  
  for name, callback in pairs(options.callbacks or {}) do
    fsm[name] = callback
  end

  fsm.__private.stack:push(fsm:find_state(options.initial or 'none'))
    
  return fsm
end

---
-- Returns the current state of the FiniteStatestatemachine
function statemachine:current()
  return self.__private.stack:top() 
end

---
-- Returns true if the current state is of the speficied name 
function statemachine:is(name)
  return self:current() and self:current().name == name
end

---
-- Pops to the last state in the transition history
function statemachine:pop()
  if (self.__private.stack:size() > 1) then
    local current = self.__private.stack:popn(2)
    current.has_executed = false
    return self:current()
  end
  return nil  
end  

---
-- Gets a value from the FiniteStatestatemachine "global" variables
function statemachine:get(variable)
  return self.__private.variables[variable]
end

---
-- Sets a value to the FiniteStatestatemachine "global" variables
function statemachine:set(variable, value)
  self.__private.variables[variable] = value;
  return self.__private.variables[variable]
end

---
-- Gets a value from the FiniteStatestatemachine (statename or actual) state variables
function statemachine:stateget(variable, statename)
  local state = self:current()
  if (statename ~= nil) then
    state = self:find_state(statename)
    if (state == nil) then
      return nil
    end 
  end
    
  
  state.__private = state.__private or {variables = {}}  
  return state.__private.variables[variable]
end

---
-- Sets a value to the FiniteStatestatemachine (statename or actual) state variables
function statemachine:stateset(variable, value, statename)
  local state = self:current()
  if (statename ~= nil) then
    state = self:find_state(statename)
    if (state == nil) then
      return nil
    end 
  end
  
  state.__private = state.__private or {variables = {}}  
  state.__private.variables[variable] = value
  return state.__private.variables[variable]
end

---
-- Returns true if the FiniteStatestatemachine "global" variable has the specified value
function statemachine:test(variable, value)  
  return self:get(variable) == value
end

---
-- Returns true if the FiniteStatestatemachine actual state has the specified value
function statemachine:statetest(variable, value)  
  return self:stateget(variable) == value
end

---
-- Executes an iteration of the FiniteStatestatemachine
function statemachine:update()
  local current =  self:current()
  
  if (current == nil) then
    return
  end
  
  if (not current.has_executed) then
    self[current.name](self)
    return
  end
  
  call_handler(self["update" .. current.name], {})
  
  if(self.__private.checks ~=nil and self.__private.checks[current.name]) then  
    for i, v in ipairs(self.__private.checks[current.name].always_functions._handlers) do
      if (type(v) == "function") then
        v()
      end
    end
    
    for i, v in ipairs(self.__private.checks[current.name].once_functions._handlers) do
      if (type(v) == "function") then
        v()
        self.__private.checks[current.name].once_functions._handlers[i] = ""
      end
    end
    
    for i, v in ipairs(self.__private.checks[current.name].oncecase_functions._handlers) do
      if (type(v) == "function") then
        if v() then 
          self.__private.checks[current.name].oncecase_functions._handlers[i] = ""
          return
        end
      end
    end
    
    for i, v in ipairs(self.__private.checks[current.name].case_functions._handlers) do
      if (type(v) == "function") then
        if v() then return end
      end
    end
    
    for i, v in ipairs(self.__private.checks[current.name].default_functions._handlers) do
      if (type(v) == "function") then
        v() 
      end
    end
  end
end

---
-- Creates a state_action(an action may be a function, a transition name or none)  given a condition
function statemachine:create_state_action(condition, from, action)
  local state_action = function()
    local condition_function = function() return false end
    local action_function = nil
    
    if (type(condition) == "function") then
      condition_function = function() return function(self) return condition end end
    elseif (type(condition) == "boolean") then
      condition_function = function() return function(self) return condition end end 
    elseif (type(condition) == "string") then
      condition_function = loadstring("return function(self) return "..condition.." end")
    end        
    
    if (type(action) == "function") then
      action_function = function() return action end
    elseif (type(action) == "string" and action ~= "") then    
      local state = self:find_state(action)
      if (state) then
        action_function = function() return function(self) self[state.name](self) end end                
      else 
        action_function = loadstring("return function(self) "..action.." end")         
      end
    end
    if (action_function == nil) then action_function = function() return function(self)  end end end
    if (condition_function()(self)) then
      if(type(action_function) == "function" ) then
        action_function()(self)       
        return true;
      end
    end
    return false  
  end
  return state_action
end

---
-- Create space for the action function handlers 
function statemachine:create_function_handlers()
  return 
  {
    case_functions = {
      _count = 0, 
      _handlers = {}
    }, 
    
    once_functions = {
      _count = 0, 
      _handlers = {}
    },
    
    oncecase_functions = {
      _count = 0, 
      _handlers = {}
    },
    
    always_functions = {
      _count = 0, _handlers = {}
    },
     
    default_functions = {
      _count = 0, _handlers = {}
    }
  }
end  

---
-- When a case action condition is satisfied, besides executing its own action, prevents the iteration from executing other checks/actions (similar to a switch/case+break operation in C)
function statemachine:case(condition, from, action)
   
  local state_action = self:create_state_action(condition, from, action)
  
  self.__private.checks[from] = self.__private.checks[from] or self:create_function_handlers()
  self.__private.checks[from].case_functions._count = self.__private.checks[from].case_functions._count + 1
  self.__private.checks[from].case_functions._handlers[self.__private.checks[from].case_functions._count] = state_action
  return state_action
end

---
-- When an once action condition is satisfied, it executes its own action(only once) without preventing the iteration from executing posterior checks/actions 
function statemachine:once(condition, from, action)
   
  local state_action = self:create_state_action(condition, from, action)
  
  self.__private.checks[from] = self.__private.checks[from] or self:create_function_handlers()
  self.__private.checks[from].once_functions._count = self.__private.checks[from].once_functions._count + 1
  self.__private.checks[from].once_functions._handlers[self.__private.checks[from].once_functions._count] = state_action
  return state_action
end

---
-- When an oncecase action condition is satisfied, it executes its own action(only once) and prevents the iteration from executing posterior checks/actions (similar to a switch/case+break operation in C) 
function statemachine:oncecase(condition, from, action)
   
  local state_action = self:create_state_action(condition, from, action)
  
  self.__private.checks[from] = self.__private.checks[from]  or self:create_function_handlers()
  self.__private.checks[from].oncecase_functions._count = self.__private.checks[from].oncecase_functions._count + 1
  self.__private.checks[from].oncecase_functions._handlers[self.__private.checks[from].oncecase_functions._count] = state_action
  return state_action
end

---
-- default action is executed when no previous case or oncecase condition is satisfied
function statemachine:default(from, action)
   
  local state_action = self:create_state_action(true, from, action)
  
  self.__private.checks[from] = self.__private.checks[from] or self:create_function_handlers()
  self.__private.checks[from].default_functions._count = self.__private.checks[from].default_functions._count + 1
  self.__private.checks[from].default_functions._handlers[self.__private.checks[from].default_functions._count] = state_action
  return state_action
end

---
-- Always actions will always be executed, before the case/oncecase iteration begins 
function statemachine:always(from, action)
   
  local state_action = self:create_state_action(true, from, action)
  
  self.__private.checks[from] = self.__private.checks[from] or self:create_function_handlers()
  self.__private.checks[from].always_functions._count = self.__private.checks[from].always_functions._count + 1
  self.__private.checks[from].always_functions._handlers[self.__private.checks[from].always_functions._count] = state_action
  return state_action
end