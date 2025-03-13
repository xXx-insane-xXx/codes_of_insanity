--[[

    Reverse string program with only using string.sub() library function

]]--


local text = io.read("*l")
local print("Original text: " ..text)
local len = #text
local i = len
local tmp = ""
local new_text = ""

-- Method 1
while (true) do
    -- Extract a character from end
    char = string.sub(text, i, i)

    -- Check if char is a space
    if char == " " or i == 0 then

        i = i - 1
        -- Loop from back to front to ensure correct word order
        for j = #tmp, 0, -1 do
            new_text = new_text .. string.sub(tmp, j, j)
        end

        -- Add the extra space detected
        new_text = new_text .. " "
        -- Reset tmp
        tmp = ""
        
        -- <= since i is reducing to -1 inside this if condition when i = 0
        if (i <= 0) then break end

    else
        -- If no space was detected
        tmp = tmp .. char
        i = i - 1
    end
end

print(new_text)


-- Method 2
new_text = ""
tmp = ""
i = len
while (true) do

    char = string.sub(text, i, i)
    if char == " " or i == 0 then
        i = i - 1
        new_text = new_text .. tmp
        new_text = new_text .. " "
        tmp = ""
        -- <= since i is reducing to -1 inside this if condition when i = 0
        if (i <= 0) then break end
    else
        -- Ensures correct order
        tmp = char .. tmp
        i = i - 1
    end

end

print(new_text)

