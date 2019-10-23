// TextGame.cpp : Main program entry point
//

#include "stdafx.h"
#include "World.h"
#include "GameLogic.h"
#include "System.h"
#include "iostream"
#include <chrono>
#include <thread>
#include "../SoundManager/SoundManager.h" //relative path to the main header



int main()
{
	SoundManager soundManager;
	SoundManager* pSoundManager = SoundManager::getInstance();
	pSoundManager->load("../snd/sonido.wav");
	pSoundManager->load("../snd/moneda.wav");
	World world("map.csv");
	Player player1(world.getPlayer1COL(), world.getPlayer1ROW(), world);
	Player player2(world.getPlayer2COL(), world.getPlayer2ROW(), world);
	GameLogic gameLogic(player1,player2,world);
	pSoundManager->play("../snd/sonido.wav", 0.6, 0, 0, 0, 0, 0, 0);

	while (!gameLogic.gameHasEnded())
	{
		world.draw();
		gameLogic.processInput();
	}
	System::clear();
	if (player1.getcoin() > player2.getcoin())
	{
		std::cout << "\n";
		std::cout << "\t     KKKKKKK\n";
		std::cout << "\t K  K ::::::: K  K\n";
		std::cout << "\t K  K ::::::: K  K\n";
		std::cout << "\t K  K ::::::: K  K\n";
		std::cout << "\t K  K ::::::: K K\n";
		std::cout << "\t   KK ::::::: KK\n";
		std::cout << "\t      K:::::K\n";
		std::cout << "\t       K:::K\n";
		std::cout << "\t       K:::K\n";
		std::cout << "\t       K:::K\n";
		std::cout << "\t       K:::K\n";
		std::cout << "\t      K:::::K\n";
		std::cout << "\t     KKKKKKKKKK\n";
		std::cout << "\n";
		std::cout << "   YOU HAVE WON PLAYER 1... CONGRATULATIONS!!";
	}
	else if (player1.getcoin() < player2.getcoin())
	{
		std::cout << "\n";
		std::cout << "\t     KKKKKKK\n";
		std::cout << "\t K  K ::::::: K  K\n";
		std::cout << "\t K  K ::::::: K  K\n";
		std::cout << "\t K  K ::::::: K  K\n";
		std::cout << "\t K  K ::::::: K K\n";
		std::cout << "\t   KK ::::::: KK\n";
		std::cout << "\t      K:::::K\n";
		std::cout << "\t       K:::K\n";
		std::cout << "\t       K:::K\n";
		std::cout << "\t       K:::K\n";
		std::cout << "\t       K:::K\n";
		std::cout << "\t      K:::::K\n";
		std::cout << "\t     KKKKKKKKKK\n";
		std::cout << "\n";
		std::cout << "   YOU HAVE WON PLAYER 2... CONGRATULATIONS!!";

	}
	else
	{
		std::cout << "DRAW";

	}
	
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    return 0;
}
