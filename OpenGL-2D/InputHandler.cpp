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
}


void InputHandler::processKeyboard(unsigned char key, int x, int y) 
{
	//keyboard callback function
	Sprite* thePlayer = (Sprite*)m_renderer.getDrawable("jugador");
	std::cout << key;

	switch (key)
	{
		//TODO
	case 32: //ASCII KEY SPACE
		//m_renderer.
		((Player*)thePlayer)->shoot();
			break;
	case 'a': 
		if (thePlayer->getX() > -1)
			thePlayer->setPosition(thePlayer->getX()-0.01, thePlayer->getY());
		break;

	case 's': break;
	case 'd': 
		if (thePlayer->getX() <=1)
			thePlayer->setPosition(thePlayer->getX() + 0.01, thePlayer->getY());
			
		
		break;

	case 27: exit(0);
	}
}

void InputHandler::__processKeyboard(unsigned char key, int x, int y)
{
	if (m_pInputHandler)
		m_pInputHandler->processKeyboard(key, x, y);
}