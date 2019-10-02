#include "stdafx.h"
#include <iostream>
#include "GameLogic.h"
#include "System.h"
#include "World.h"

using namespace std;
GameLogic::GameLogic(Player& player1, Player& player2, World& world)
	: m_player1(player1), m_player2(player2), m_world(world)
{
	v = m_world.getVector();
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
			m_player1.moveLeft();
			break;
		case 's':
			m_player1.moveDown();
			break;
		case 'w':
			m_player1.moveUp();
			break;
		case 'd':
			m_player1.moveRight();
			break;
		case '1':
			m_player2.moveLeft();
			break;
		case '2':
			m_player2.moveDown();
			break;
		case '3':
			m_player2.moveRight();
			break;
		case '5':
			m_player2.moveUp();
			break;
		case 27:
			//'Esc' key pressed. Exit the game
			return;
			drawCoins();
		}
	}
}

bool GameLogic::gameHasEnded()
{
	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i] == '?') {
			ended = false;
		}
		else {
			ended = true;
		}
	}
	return ended;
}

void GameLogic::drawCoins()
{
	cout << "Player1 has: " << m_player1.getcoin() << ". \n";
	cout << "Player2 has: " << m_player2.getcoin() << ".";
}