#include <bits/stdc++.h>

enum class MonsterType
{
    ogre,
    dragon,
    orc,
    giantSpider,
    slime,
};

struct Monster
{
    MonsterType type {};
    std::string_view name {};
    int health {};
};

constexpr std::string_view typeReturn(const MonsterType& type)
{
    using enum MonsterType;
    using namespace std::string_view_literals;

    switch (type)
    {
        case ogre: return "Ogre"sv;
        case dragon: return "Dragon"sv;
        case orc: return "Orc"sv;
        case giantSpider: return "Giant Spider"sv;
        case slime: return "Slime"sv;

        default: return "???"sv;
    }

}

void printMonster(const Monster& monster)
{
    std::cout << "This " << typeReturn(monster.type) << " is named " << monster.name << " and has " << monster.health << " health.\n";
}

int main()
{
    using enum MonsterType;
    using namespace std::string_view_literals;

    Monster monster1 {ogre, "Torg"sv, 145};
    Monster monster2 {slime, "Blurp"sv, 23};

    printMonster(monster1);
    printMonster(monster2);

    return 0;
}
