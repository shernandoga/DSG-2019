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
	//pSoundManager->load("../snd/soundtrack-01.wav");
	pSoundManager->load("../snd/sonido.wav");
	pSoundManager->load("../snd/moneda.wav");
	pSoundManager->load("../snd/ko.wav");
	World world("map.csv");
	Player player1(world.getPlayer1COL(), world.getPlayer1ROW(), world);
	Player player2(world.getPlayer2COL(), world.getPlayer2ROW(), world);
	GameLogic gameLogic(player1,player2,world);
	//pSoundManager->play("../snd/soundtrack-01.wav", 0.5, 0, 0, 0, 0, 0, 0);
	pSoundManager->play("../snd/sonido.wav", 0.6, 0, 0, 0, 0, 0, 0);

	while (!gameLogic.gameHasEnded())
	{
		world.draw();
		gameLogic.processInput();
	}
	System::clear();
	//pSoundManager->stop("../snd/sonido.wav");
	pSoundManager->play("../snd/ko.wav", 0.9, 0, 0, 0, 0, 0, 0);
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

