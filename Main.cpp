#include "GameWorld.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {

	cout << "Welcome to Wumpus World! Try to navigate your player (represented by an N, E, S, or W based on which direction you're facing)\n";
	cout << "past the pits (represented by O's) and the fearsome Wumpus (represented by an X) and over the bag of gold (represented by a G)! Good luck; you'll need it.\n";

	char cont = 'Y';
	bool cheatFlag2 = false;

	do {

		GameWorld instance;
		char input;


		bool won = false;
		bool alive = true;
		bool cheat = false;
		bool cheatFlag = false;


		while (won != true && alive == true) {

				if (cheat == true) {
					instance.displayEntireWorld(instance);
				}
				else {
					instance.displayVisibleWorld(instance);
				}

				cout << "What do you do?" << endl;
				cout << "W - Move forward" << endl;
				cout << "A - Turn left" << endl;
				cout << "D - Turn right" << endl;
				cout << "C - Cheat (toggle full map view)" << endl;
				cout << "Q - Quit" << endl;
				cin >> input;

				if (input == 'W' || input == 'w')
					instance.moveForward(instance);
				else if (input == 'A' || input == 'a')
					instance.turnLeft(instance);
				else if (input == 'D' || input == 'd')
					instance.turnRight(instance);
				else if (input == 'C' || input == 'c') {
					if (cheat == true) {
						cheat = false;
					}
					else {
						cheat = true;
						cheatFlag = true;
					}
				}
				else if (input == 'Q' || input == 'q') {
					cout << "Goodbye!" << endl;
					exit(0);
				}
				else
					cout << "Invalid input. Please try again." << endl;

				won = instance.haveIWon();
				alive = instance.amIAlive();

		}

		if (won == true && alive == true && cheatFlag == false) {
			cout << "You found the gold! Congratulations!" << endl;
			cout << "Enter Y to play again or any other character to exit." << endl;
			cin >> cont;
		}
		else if (won == true && alive == true && cheatFlag == true && cheatFlag2 == false) {
			cout << "Would you look at that: the cheater found the gold! What a surprise." << endl;
			cout << "Enter Y to play again or any other character to exit." << endl;
			cout << "If you do play again, try to refrain from taking the easy way out this time." << endl;
			cout << "Trust me; I'll know if you do." << endl;
			cheat = false;
			cheatFlag = false;
			cheatFlag2 = true;
			cin >> cont;
		}
		else if (won == true && alive == true && cheatFlag == true && cheatFlag2 == true) {
			cout << "I told you I would find out. I knew I couldn't trust you from the beginning." << endl;
			cout << "Great job living up to my expectations." << endl;
			cout << "I think we're done here. Bye." << endl;
			exit(0);
		}
		else if (won != true && alive != true) {
			cout << "You have died." << endl;
			cout << "Enter Y to play again or any other character to exit." << endl;
			cin >> cont;
		}

	} while (cont == 'Y' || cont == 'y');
	
	cout << "Goodbye!" << endl;

	return 0;

}
