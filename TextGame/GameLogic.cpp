#include "stdafx.h"
#include <iostream>
#include "GameLogic.h"
#include "System.h"
#include "World.h"
#include "Player.h"

GameLogic::GameLogic(World& world, Player& player, Player& player2)
	:m_world(world), m_player(player), m_player2(player2)
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
			m_player.moveUp(); break;
		case 's':
			m_player.moveDown(); break;
		case 'd':
			m_player.moveRight(); break;
		case 'a':
			m_player.moveLeft(); break;
		case '8':
			m_player2.moveUp(); break;
		case '2':
			m_player2.moveDown(); break;
		case '6':
			m_player2.moveRight(); break;
		case '4':
			m_player2.moveLeft(); break;
		case 27:
			//'Esc' key pressed. Exit the game
			return;
		}
	}
}

bool GameLogic::gameHasEnded()
{
	/*if ((m_world.pointsP1 + m_world.pointsP2) == m_world.numCoins) {
		return true;
	}*/
	return false;
}