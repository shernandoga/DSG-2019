#include "stdafx.h"
#include <iostream>
#include <iostream>
#include <chrono>
#include <thread>
#include "GameLogic.h"
#include "System.h"
#include "World.h"
#include "Player.h"

GameLogic::GameLogic(World& world)
	:m_world(world)
{

}


GameLogic::~GameLogic()
{
}

void GameLogic::processInput()
{

	if (!System::keyHit())
		return; //no keyboard event to be processed


	while (System::keyHit())
	{
		char c = System::getNextKey();
		switch (c)
		{
		case 'w':
			World::getInstance()->getPlayer(1).moveUp(); break;
		case 's':
			World::getInstance()->getPlayer(1).moveDown(); break;
		case 'd':
			World::getInstance()->getPlayer(1).moveRight(); break;
		case 'a':
			World::getInstance()->getPlayer(1).moveLeft(); break;
		case '8':
			World::getInstance()->getPlayer(2).moveUp(); break;
		case '2':
			World::getInstance()->getPlayer(2).moveDown(); break;
		case '6':
			World::getInstance()->getPlayer(2).moveRight(); break;
		case '4':
			World::getInstance()->getPlayer(2).moveLeft(); break;
		case 27:
			//'Esc' key pressed. Exit the game
			exit(0);
		}
	}
}

bool GameLogic::gameHasEnded()
{
	if ((World::getInstance()->getPlayer(1).getScore() + World::getInstance()->getPlayer(2).getScore()) == World::getInstance()->getTotalCoins()) {
		World::getInstance()->draw();
		cout << "No quedan mas monedas. El juego se ha terminado" << endl;

		if (World::getInstance()->getPlayer(1).getScore() > World::getInstance()->getPlayer(2).getScore()) {
			cout << "El jugador 1 (o) ha ganado !!!" << endl;
		}
		else
			cout << "El jugador 2 (x) ha ganado !!!" << endl;
		std::this_thread::sleep_for(std::chrono::seconds(5));
		return true;
	}
	return false;
}