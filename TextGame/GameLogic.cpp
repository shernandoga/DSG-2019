#include "stdafx.h"
#include <iostream>
#include "GameLogic.h"
#include "System.h"
#include "World.h"
#include "Player.h"

GameLogic::GameLogic(World& world)
	: m_world(world)
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
		case 'w':
			//Do whatever needs to be done when 's' is pressed
			//player1.moveup();
			break;
		case 'd':
			//Do whatever needs to be done when 's' is pressed
			break;

		case 'j':
			//Do whatever needs to be done when 's' is pressed
			break;
		case 'k':
			//Do whatever needs to be done when 's' is pressed
			break;
		case 'i':
			//Do whatever needs to be done when 's' is pressed
			break;
		case 'l':
			//Do whatever needs to be done when 's' is pressed
			break;

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