--- 
-- This module implements a stack data structure in Lua
-- @type stack 

stack = {}
stack.__index = stack
---
-- Creates a stack with a possible maximum size (objects in the lowest part of the stack will be discarded when needed)
-- @param #number stack_max Maximum size of the stack
-- @return #stack
function stack.create(stack_max)  
  if (type(stack_max) ~= "number" or stack_max < 0) then
    stack_max = 0
  end
  local new_stack = {__private = {space = {}, max = stack_max,first = 0,  last = 0}}
  setmetatable(new_stack, stack)
  return new_stack;
end

---
-- pushes a value to the stack
-- 
function stack:push(value)
  if (value) then
    self.__private.last = self.__private.last + 1
    self.__private.space[self.__private.last] = value
    
    if (self.__private.max > 0 and (self:size() > self.__private.max)) then
      local deallocate_count = self:size()  - self.__private.max
      local start = self.__private.first
      for i = start + 1, start + deallocate_count do
        self.__private.space[i] = nil 
      end  
      self.__private.first = self.__private.first + deallocate_count
    end
  end
end

-- pops a value from the stack
function stack:pop()
  if self:empty() then return nil end
  local value = self.__private.space[self.__private.last]
  self.__private.space[self.__private.last] = nil
  self.__private.last = self.__private.last - 1
  return value
end

-- pops n values from the stack and return the last one 
function stack:popn(n)
  while (n > 1) do
    self:pop()
    n = n - 1
  end
  return self:top()
end

-- returns (top - n)th value from the stack 
function stack:top(n)
  local minus_offset = 0
  if (type(n) == "number" and n < 0) then
    minus_offset = n
  end
  if self:empty() then return nil end
  local value = self.__private.space[self.__private.last + minus_offset]
  return value
end

-- returns the number of elements in the stack
function stack:size()
  return self.__private.last - self.__private.first
end

-- returns a boolean indicating if the stack has 0 elements
function stack:empty()
  return self:size() == 0
end