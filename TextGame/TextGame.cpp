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
#include <conio.h>


int main()
{
	//LOAD ALL THE SOUNDS
	cout << "Loading..";
	SoundManager soundManager;
	SoundManager* pSoundManager = SoundManager::getInstance();
	//pSoundManager->load("../snd/soundtrack-01.wav");
	pSoundManager->load("../snd/sonido.wav");
	//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	System::clear();
	cout << "Loading....";
	pSoundManager->load("../snd/moneda.wav");
	//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	System::clear();
	cout << "Loading........";
	pSoundManager->load("../snd/ko.wav");
	System::clear();
	cout << "LOADING COMPLETE";
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	System::clear();

	//MAIN MENU
	int choice = 0;
	do {
		cout << "\tMain Menu\n";
		cout << "Please make your selection\n";
		cout << "1 - Start game\n";
		cout << "2 - About\n";
		cout << "3 - Quit\n";
		cout << "Selection: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			//Starts the game, doesn´t do anything
			break;
		case 2:
			System::clear();
			cout << "This is a local 1V1 game in which you have to get all the coins before your opponent does.\n";
			cout << "PLAYER 1 --> W/A/S/D\n";
			cout << "PLAYER 1 --> 5/1/2/3\n";
			cout << "Game done in C++ in the subject -DESARROLLO DE SISTEMAS GRÁFICOS-\n";
			cout << "Copyright © 2000-2019 Interactive Programmers Community - Todos los derechos reservados\n";
			cout << "Press any key to continue";
			char ch;
			ch = _getch();
			System::clear();
			break;
		case 3:
			return 0;
			break;
		default:
			break;
		}
	} while (choice != 1);







	//PLAY THE GAME
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
		std::cout << "\t     KKKKKKKKK\n";
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
