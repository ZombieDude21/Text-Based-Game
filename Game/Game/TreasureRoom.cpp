#include "TreasureRoom.h"
#include <fstream>

TreasureRoom::TreasureRoom(string name)
{
	SetName(name);
}
Player TreasureRoom::Start(Player monk)
{
	ofstream logfile;
	logfile.open("Last Game log.txt", ios::app);


	system("CLS");
	cout << "-------------------------------------" << endl;
	cout << "You have entered Treasure Room" << endl;
	cout << "You have gained 500 score" << endl;
	monk.AddScore(500);
	cout << "Your current score is: " << monk.GetScore() << endl;

	logfile << "-------------------------------------" << endl;
	logfile << "You have entered Treasure Room" << endl;
	logfile << "You have gained 500 score" << endl;
	logfile << "Your current score is: " << monk.GetScore() << endl;

	logfile.close();


	system("pause");
	return monk;
}