// TextGame.cpp : Main program entry point
//

#include "stdafx.h"
#include "World.h"
#include "GameLogic.h"


int main()
{
	World world("map.csv");
	Player player1(world.getPlayer1COL(), world.getPlayer1ROW(), world);
	Player player2(world.getPlayer2COL(), world.getPlayer2ROW(), world);
	GameLogic gameLogic(player1,player2,world);

	while (!gameLogic.gameHasEnded())
	{
		world.draw();

		gameLogic.processInput();
	}



    return 0;
}

