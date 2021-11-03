#pragma once
#include "Rooms.h"
#include "Player.h"
#include <string>
using namespace std;
class EmptyRoom : public Rooms
{
public:
    EmptyRoom(string);
    Player Start(Player) override;
};

