// TextGame.cpp : Main program entry point
//

#include "stdafx.h"
#include "World.h"
#include "GameLogic.h"


int main()
{
	World world("file.csv");
	Player player1(world.getPlayer1ROW(), world.getPlayer1COL(), world);
	Player player2(world.getPlayer2ROW(), world.getPlayer2COL(), world);
	GameLogic gameLogic(player1,player2,world);

	while (!gameLogic.gameHasEnded())
	{
		world.draw();

		gameLogic.processInput();
	}

    return 0;
}

