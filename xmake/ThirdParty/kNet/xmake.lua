

local name = "kNet"

local prefixInclude = "../../../include/ThirdParty/" .. name
local prefixSrc = "../../../src/ThirdParty/" .. name



-- add headers
add_headers(prefixInclude .. "/*.h")
add_headers(prefixInclude .. "/" .. name .. "*.h")
add_headers(prefixInclude .. "/" .. name .. "*.inl")

if is_plat("windows") then
	add_headers(prefixInclude .. "/" .. name .. "/win32/*.h")
else
	add_headers(prefixInclude .. "/" .. name .. "/unix/*.h")
end

	
-- add files
add_files(prefixSrc .. "/*.cpp")
if is_plat("windows") then
	add_files(prefixSrc .. "/win32/*.cpp")
else
	add_files(prefixSrc .. "/unix/*.cpp")
end



	

