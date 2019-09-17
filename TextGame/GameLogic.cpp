#include "stdafx.h"
#include <iostream>
#include "GameLogic.h"
#include "System.h"
#include "World.h"

GameLogic::GameLogic(Player& player1, Player& player2, World& world)
	: m_player1(player1), m_player2(player2), m_world(world)
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

		case 'a':
			//Do whatever needs to be done when 'a' is pressed

			break;
		case 's':
			//Do whatever needs to be done when 's' is pressed
			break;
		//...
		//...
		//...
		case 27:
			//'Esc' key pressed. Exit the game
			return;
		}
	}
}

bool GameLogic::gameHasEnded()
{
	//TODO: We need to check it the game has ended
	return false;
}