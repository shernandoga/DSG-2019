// TextGame.cpp : Main program entry point
//

#include "stdafx.h"
#include "World.h"
#include "GameLogic.h"
#include <iostream>
#include <windows.h>

int main()
{
	World world("file.csv");
	GameLogic gameLogic(world);

	while (!gameLogic.gameHasEnded())
	{
		world.draw();

		gameLogic.processInput();
	}
	if(world.getPlayer1().getcoin() < world.getPlayer2().getcoin())
	{
		// player 2 wins
		std::cout << "PLAYER 2 WINS !";
	}
	else {
		// player 1 wins
		std::cout << "PLAYER 1 WINS !";
	}



	Sleep(5*1000);

    return 0;
}

