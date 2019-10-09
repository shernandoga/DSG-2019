// TextGame.cpp : Main program entry point
//

#include "stdafx.h"
#include "World.h"
#include "GameLogic.h"
#include "System.h"
#include "iostream"
#include <chrono>
#include <thread>

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
	System::clear();
	if (player1.getcoin() > player2.getcoin())
	{
		std::cout << "U HAVE GUON PLAIER JUAN";
	}
	else if (player1.getcoin() < player2.getcoin())
	{
		std::cout << "U JAF WON PLAI ER TXU";

	}
	else
	{
		std::cout << "DRAW";

	}
	
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    return 0;
}

