// TextGame.cpp : Main program entry point
//

#include "stdafx.h"
#include "World.h"
#include "GameLogic.h"


int main()
{
	World world("file.csv");

	GameLogic gameLogic(world);

	do {
		world.draw();

		gameLogic.processInput();
	}
	while (!gameLogic.gameHasEnded());

    return 0;
}

