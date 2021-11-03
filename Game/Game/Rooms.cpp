#include "Rooms.h"
#include "Player.h"
#include <string>
using namespace std;

Rooms::Rooms()
{}

void Rooms::SetName(string name)
{
	Name = name;
}
string Rooms::GetName()
{
	return Name;
}

Player Rooms::Start(Player monk)
{
	return monk;
}
