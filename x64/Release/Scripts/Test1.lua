function dropItem()
    -- Initialize random seed
    math.randomseed(os.time())

    -- Define a table for fantasy items
    local items = {
        { name = "Mystic Sword", minCount = 1, maxCount = 3, dropChance = 5 },
        { name = "Ancient Helm", minCount = 1, maxCount = 2, dropChance = 10 },
        { name = "Dragon's Heart", minCount = 1, maxCount = 1, dropChance = 1 },
        { name = "Wizard's Scroll", minCount = 2, maxCount = 5, dropChance = 20 },
        { name = "Elixir of Life", minCount = 1, maxCount = 2, dropChance = 15 },
        { name = "Phoenix Feather", minCount = 1, maxCount = 1, dropChance = 3 },
        { name = "Shadow Cloak", minCount = 1, maxCount = 1, dropChance = 8 },
        { name = "Goblin's Coin", minCount = 5, maxCount = 10, dropChance = 25 },
        { name = "Knight's Shield", minCount = 1, maxCount = 2, dropChance = 12 },
        { name = "Orb of Power", minCount = 1, maxCount = 1, dropChance = 2 }
    }

    -- Function to determine if an item drops
    local function shouldDrop(dropChance)
        return math.random(100) <= dropChance
    end

    -- Function to select the count of an item to drop
    local function selectCount(minCount, maxCount)
        return math.random(minCount, maxCount)
    end

    -- Attempt to drop one item
    for _, item in ipairs(items) do
        if shouldDrop(item.dropChance) then
            local count = selectCount(item.minCount, item.maxCount)
            return item.name, count
        end
    end

    -- If no items are dropped
    return "No items dropped", 0
end

function OnMonsterDead()
    local itemName, itemCount = dropItem()
    if itemCount == 0 then
        return
    end
    print("Dropped: " .. itemName .. " x" .. itemCount)
end
