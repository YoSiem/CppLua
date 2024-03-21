function greeting(fromWho, toWho)
    print("Hello " .. toWho .. " from " .. fromWho)
end

function cppPrint(message)
    printMessage(message)
end

function add_test(a,b)
    local sum = addNumbers(a,b)
    printMessage("Sum: " .. sum)
end

function even_test(number)
    if isNumberEven(number) then
        printMessage("Number " .. number .. " is even")
    else
        printMessage("Number " .. number .. " is odd")
    end
end

function app_name_test()
    local appName = getAppName()
    printMessage("App name: " .. appName)
end

function random_test(min, max)
    local random = generateRandomNumber(min, max)
    printMessage("Random number: " .. random)
end