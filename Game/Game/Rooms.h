#pragma once
#include <string>
#include <iostream>
#include "Player.h"

using namespace std;
class Rooms
{
private:
	string Name;
public:
	Rooms();
	void SetName(string);

	string GetName();

	virtual Player Start(Player);
};

