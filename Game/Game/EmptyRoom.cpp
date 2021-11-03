#include "EmptyRoom.h"
#include "Creatures.h"
#include "Player.h"
#include <string>
#include <fstream>
using namespace std;

EmptyRoom::EmptyRoom(string name)
{

	SetName(name);
}
Player EmptyRoom::Start(Player monk)
{

	ofstream logfile;
	logfile.open("Last Game log.txt", ios::app);


	system("CLS");
	cout << "-------------------------------------" << endl;
	cout << "You have entered Empty Room" << endl;
	cout << "You decied to pray" << endl;
	cout << "Your hp has been restored" << endl;

	logfile << "-------------------------------------" << endl;
	logfile << "You have entered Empty Room" << endl;
	logfile << "You decied to pray" << endl;
	logfile << "Your hp has been restored" << endl;
	
	logfile.close();
		

	monk.ResetHP();
	system("pause");
	return monk;
}
