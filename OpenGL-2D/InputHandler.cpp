#include "stdafx.h"
#include "InputHandler.h"
#include "World.h"
#include "Projectile.h"
#include "Renderer.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"

InputHandler* InputHandler::m_pInputHandler = nullptr;

InputHandler::InputHandler(Renderer& renderer): m_renderer(renderer)
{
	m_pInputHandler = this;
}


InputHandler::~InputHandler()
{
}

void InputHandler::initialize()
{
	glutKeyboardFunc(__processKeyboard);
}


void InputHandler::processKeyboard(unsigned char key, int x, int y)
{
	//keyboard callback function
	Renderer* renderer = (Renderer*)Renderer::get();
	Player* player2;
	Player* player1;
	player2 = (Player*)Renderer::get()->getObject("Player2");
	player1 = (Player*)Renderer::get()->getObject("Player1");


	switch (key)
	{
		//TODO
	case '8': 
		player2->moveUp(); break;
	case '2':
		player2->moveDown(); break;
	case '4': 
		renderer->addObject(new Projectile(player2->getX(), player2->getY(), false));
		break;

	case 'w':
		player1->moveUp(); break;
	case 's':
		player1->moveDown(); break;
	case 'd':
		renderer->addObject(new Projectile(player1->getX(), player1->getY(), true));
		break;
	case 27: exit(0);
	}
}

void InputHandler::__processKeyboard(unsigned char key, int x, int y)
{
	if (m_pInputHandler)
		m_pInputHandler->processKeyboard(key, x, y);
}