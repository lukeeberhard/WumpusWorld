#ifndef GAMEWORLD_H
#define GAMEWORLD_H
#include <iostream>
#include <ctime>

class GameWorld {
	private:
		char boardState[5][5];
		int playerPosX, playerPosY = 0;
	public:
		GameWorld(); // Constructor that creates the game with a random startup
		void displayEntireWorld(GameWorld); // Displays the game state to the screen
		void displayVisibleWorld(GameWorld); // Displays all squares one away from the player
		void moveForward(GameWorld); // Moves the player forward one square in the direction they are facing
		void turnLeft(GameWorld); // Turns the player 90 degrees to the left
		void turnRight(GameWorld); // Turns the player 90 degrees to the right
		bool haveIWon(); // Returns true or false depending on if the player has won
		bool amIAlive(); // Returns true or false depending on if player hit the wumpus or a pit
};

#endif