#include <iostream>
#include <vector>
#include <cassert>

namespace Items
{
    enum Type
    {
        healthPotions,
        torches,
        arrows,

        maxItems
    };
}

std::string_view getItemNamePlural(Items::Type type)
{
    switch (type)
    {
        case Items::healthPotions:  return "health potions";
        case Items::torches:        return "torches";
        case Items::arrows:         return "arrows";

        default:                    return "???";
    }
}

std::string_view getItemNameSingular(Items::Type type)
{
    switch (type)
    {
        case Items::healthPotions:  return "health potion";
        case Items::torches:        return "torch";
        case Items::arrows:         return "arrow";

        default:                    return "???";
    }
}

void printInventoryName (const std::vector<int>& inventory, Items::Type type)
{
    bool plural {inventory[type] != 1};
    
    std::cout << "You have " << inventory[type] << ' ' << (plural ? getItemNamePlural(type) : getItemNameSingular(type)) << '\n';
}
int countTotalItems(const std::vector<int>& inventory)
{
    int count {0};
    for (int e : inventory)
    {
        count += e;
    }
    return count;
}

int main()
{
    std::vector<int> inventory {1, 5, 10};
    assert(inventory.size() == Items::maxItems );

    for (int i=0; i < Items::maxItems; ++i)
    {
        auto item { static_cast<Items::Type>(i) };
        printInventoryName(inventory, item);
    }
    std::cout << "You have " << countTotalItems(inventory) << " total items";

    return 0;
}
