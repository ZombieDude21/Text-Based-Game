#pragma once
#include "Rooms.h"
#include <string>
class TreasureRoom : public Rooms
{
public:
    TreasureRoom(string);

    Player Start(Player) override;
};

