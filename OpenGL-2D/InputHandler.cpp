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


void InputHandler::update() 
{
	//keyboard callback function
	Sprite* thePlayer = (Sprite*)m_renderer.getDrawable("jugador");
 
	if (leftPressed) {
		if (thePlayer->getX() > -1)
			thePlayer->setPosition(thePlayer->getX() - 0.01, thePlayer->getY());
	}
		

	if (rightPressed) {
		if (thePlayer->getX() <= 1)
			thePlayer->setPosition(thePlayer->getX() + 0.01, thePlayer->getY());		
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
			m_pInputHandler->leftPressed = true;
			break;
		case 'd':
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
		m_pInputHandler->leftPressed = false;
		break;
	case 'd':
		m_pInputHandler->rightPressed = false;
		break;
	}

}