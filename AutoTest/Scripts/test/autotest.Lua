if(autotest~=nil) then
	return autotest
end

autotest = GameObject:new()

dofile("scripts/test/testParams.Lua")


function autotest:wrapText(message)
	local newMessage=""
	local start = 1
	local count =0
	
	for i=1,string.len(message) do
		count = count + 1
		if(string.sub(message,i,i)=='\n') then
			newMessage = newMessage..string.sub(message,start,i)
			count=0	
			start=i+1
		else
			if(count > testParams.maxTextColumns) then
				count = 0
				newMessage = newMessage..string.sub(message,start,i).."\n"
				start=i+1
			end
		end
	end
	return newMessage
end

function autotest:Print(message)
	infoPanel.message = message
end
function autotest:Fail(message)
	message="Total running time: "..engine:getCurrentTime().."\n"..message.."\n"..debug.traceback()
	failScene.message=autotest:wrapText(message)
	engine:run(failScene)
end

function autotest:Success(message)	
	engine:run(successScene)
end


function autotest:OnUpdate(sender)
	if(engine:getCurrentTime()> testParams.timeToRun) then
		autotest:Success()
	end
end

return autotest
