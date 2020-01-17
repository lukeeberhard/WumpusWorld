#include "GameWorld.h"
#include <iostream>
#include <ctime>

using namespace std;

GameWorld::GameWorld() { // Constructor that creates the game with a random startup
	unsigned seed = time(0);
	srand(seed);
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			boardState[x][y] = ' ';
		}
	}
	int pitNum = ((rand() % 5) + 5);
	int x = 0;
	while (x < pitNum) {
		int pitGenX = (rand() % 4);
		int pitGenY = (rand() % 4);
		if (boardState[pitGenX][pitGenY] != 'O') {
			boardState[pitGenX][pitGenY] = 'O';
			x++;
		}
	}
	bool wumpusGen = false;
	while (wumpusGen == false) {
		int wumpusGenX = (rand() % 4);
		int wumpusGenY = (rand() % 4);
		if (boardState[wumpusGenX][wumpusGenY] != 'O') {
			boardState[wumpusGenX][wumpusGenY] = 'X';
			wumpusGen = true;
		}
	}
	bool playerGen = false;
	int playerDirection = (rand() % 3);
	while (playerGen == false) {
		int playerGenX = (rand() % 4);
		int playerGenY = (rand() % 4);
		if (boardState[playerGenX][playerGenY] != 'O' && boardState[playerGenX][playerGenY] != 'X') {
			if (playerDirection == 0)
				boardState[playerGenX][playerGenY] = 'N';
			else if (playerDirection == 1)
				boardState[playerGenX][playerGenY] = 'E';
			else if (playerDirection == 2)
				boardState[playerGenX][playerGenY] = 'S';
			else if (playerDirection == 3)
				boardState[playerGenX][playerGenY] = 'W';
			playerPosX = playerGenX;
			playerPosY = playerGenY;
			playerGen = true;
		}
	}
	bool goldGen = false;
	while (goldGen == false) {
		int goldGenX = (rand() % 4);
		int goldGenY = (rand() % 4);
		if (boardState[goldGenX][goldGenY] != 'O' && boardState[goldGenX][goldGenY] != 'X' && boardState[goldGenX][goldGenY] != 'N' && boardState[goldGenX][goldGenY] != 'E' && boardState[goldGenX][goldGenY] != 'S' && boardState[goldGenX][goldGenY] != 'W') {
			boardState[goldGenX][goldGenY] = 'G';
			goldGen = true;
		}
	}
}

void GameWorld::displayEntireWorld(GameWorld instance) { // Displays the game state to the screen
	cout << " __ __ __ __ __ " << endl;
	for (int x = 0; x < 5; x++) {
		cout << "|";
		for (int y = 0; y < 5; y++) {
			cout << boardState[x][y] << " |";
			if (y == 4)
				cout << endl;
		}
	}
	cout << " -- -- -- -- -- " << endl;
}

void GameWorld::displayVisibleWorld(GameWorld instance) { // Displays all squares one away from the player
	cout << " __ __ __ __ __ " << endl;
	for (int x = 0; x < 5; x++) {
		cout << "|";
		for (int y = 0; y < 5; y++) {
			if ((x == (playerPosX - 1) || x == playerPosX || x == (playerPosX + 1)) && (y == (playerPosY - 1) || y == playerPosY || y == (playerPosY + 1))) {
				cout << boardState[x][y] << " |";
				if (y == 4)
					cout << endl;
			}
			else {
				cout << "  |";
				if (y == 4)
					cout << endl;
			}
		}
	}
	cout << " -- -- -- -- -- " << endl;
}


void GameWorld::moveForward(GameWorld instance) { // Moves the player forward one square in the direction they are facing
	if ((playerPosX == 0 && boardState[playerPosX][playerPosY] == 'N') || (playerPosX == 4 && boardState[playerPosX][playerPosY] == 'S') || (playerPosY == 0 && boardState[playerPosX][playerPosY] == 'W') || (playerPosY == 4 && boardState[playerPosX][playerPosY] == 'E')) {
		cout << "You are facing a wall. You must turn before you can advance." << endl;
		return;
	}
	else if (boardState[playerPosX][playerPosY] == 'N') {
		boardState[playerPosX][playerPosY] = ' ';
		playerPosX--;
		if (boardState[playerPosX][playerPosY] == ' ' || boardState[playerPosX][playerPosY] == 'G')
			boardState[playerPosX][playerPosY] = 'N';
	}
	else if (boardState[playerPosX][playerPosY] == 'E') {
		boardState[playerPosX][playerPosY] = ' ';
		playerPosY++;
		if (boardState[playerPosX][playerPosY] == ' ' || boardState[playerPosX][playerPosY] == 'G')
			boardState[playerPosX][playerPosY] = 'E';
	}
	else if (boardState[playerPosX][playerPosY] == 'S') {
		boardState[playerPosX][playerPosY] = ' ';
		playerPosX++;
		if (boardState[playerPosX][playerPosY] == ' ' || boardState[playerPosX][playerPosY] == 'G')
			boardState[playerPosX][playerPosY] = 'S';
	}
	else if (boardState[playerPosX][playerPosY] == 'W') {
		boardState[playerPosX][playerPosY] = ' ';
		playerPosY--;
		if (boardState[playerPosX][playerPosY] == ' ' || boardState[playerPosX][playerPosY] == 'G')
			boardState[playerPosX][playerPosY] = 'W';
	}
}

void GameWorld::turnLeft(GameWorld instance) { // Turns the player 90 degrees to the left
	if (boardState[playerPosX][playerPosY] == 'N')
		boardState[playerPosX][playerPosY] = 'W';
	else if (boardState[playerPosX][playerPosY] == 'W')
		boardState[playerPosX][playerPosY] = 'S';
	else if (boardState[playerPosX][playerPosY] == 'S')
		boardState[playerPosX][playerPosY] = 'E';
	else if (boardState[playerPosX][playerPosY] == 'E')
		boardState[playerPosX][playerPosY] = 'N';
}

void GameWorld::turnRight(GameWorld instance) { // Turns the player 90 degrees to the right
	if (boardState[playerPosX][playerPosY] == 'N')
		boardState[playerPosX][playerPosY] = 'E';
	else if (boardState[playerPosX][playerPosY] == 'E')
		boardState[playerPosX][playerPosY] = 'S';
	else if (boardState[playerPosX][playerPosY] == 'S')
		boardState[playerPosX][playerPosY] = 'W';
	else if (boardState[playerPosX][playerPosY] == 'W')
		boardState[playerPosX][playerPosY] = 'N';
}

bool GameWorld::haveIWon() { // Returns true or false depending on if the player has won
	bool playerFound = false;
	bool goldFound = false;
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			if (boardState[x][y] == 'N' || boardState[x][y] == 'E' || boardState[x][y] == 'S' || boardState[x][y] == 'W')
				playerFound = true;
			else if (boardState[x][y] == 'G')
				goldFound = true;
		}
	}
	if (playerFound == true && goldFound == false)
		return true;
	else
		return false;
}

bool GameWorld::amIAlive() { // Returns true or false depending on if player hit the wumpus or a pit
	bool playerFound = false;
	bool goldFound = false;
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			if (boardState[x][y] == 'N' || boardState[x][y] == 'E' || boardState[x][y] == 'S' || boardState[x][y] == 'W')
				playerFound = true;
			else if (boardState[x][y] == 'G')
				goldFound = true;
		}
	}
	if (playerFound == false && goldFound == true)
		return false;
	else
		return true;
}
