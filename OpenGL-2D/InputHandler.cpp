   #include "stdafx.h"
#include "InputHandler.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "Renderer.h"
#include "Player.h"
#include <iostream>

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
	glutKeyboardUpFunc(__processKeyboardUp);
}

#define PLAYER_MOVE_SPEED 0.15

void InputHandler::update(double dt) 
{
	//keyboard callback function
	Sprite* thePlayer = (Sprite*)m_renderer.getDrawable("jugador");
 
	if (leftPressed) {
		if (thePlayer->getX() > -1)
			thePlayer->setPosition(thePlayer->getX() - PLAYER_MOVE_SPEED *dt, thePlayer->getY());
	}
		

	if (rightPressed) {
		if (thePlayer->getX() <= 1)
			thePlayer->setPosition(thePlayer->getX() + PLAYER_MOVE_SPEED *dt, thePlayer->getY());
	}
		
		

}

void InputHandler::__processKeyboard(unsigned char key, int x, int y)
{
	Sprite* thePlayer;
	if (m_pInputHandler)
	{
		switch (key)
		{
		case 32: //ASCII KEY SPACE
			thePlayer= (Sprite*)Renderer::get()->getDrawable("jugador");
			((Player*)thePlayer)->shoot();
			break;
		case 'a':
		case 'A':
			m_pInputHandler->leftPressed = true;
			break;
		case 'd':
		case 'D':
			m_pInputHandler->rightPressed = true;
			break;
		case 27:
			exit(0);
		}

	}
	
}


void InputHandler::__processKeyboardUp(unsigned char key, int x, int y)
{
	
	switch (key)
	{
	case 'a':
	case 'A':
		m_pInputHandler->leftPressed = false;
		break;
	case 'd':
	case 'D':
		m_pInputHandler->rightPressed = false;
		break;
	}

}