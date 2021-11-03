#pragma once
#include "Rooms.h"
#include "Creatures.h"
#include "Player.h"
#include <string>
using namespace std;

class MonsterRoom : public Rooms
{
public:
	MonsterRoom(string);

	Player Start(Player) override;
	

};

