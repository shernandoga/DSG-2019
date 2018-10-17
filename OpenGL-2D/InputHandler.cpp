#include "stdafx.h"
#include "InputHandler.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "Renderer.h"
#include "Player.h"

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
	Sprite * temp = (Sprite*)m_renderer.getDrawable("jugador");
	switch (key)
	{
		//TODO
	case 'w':
		//m_renderer.
			break;
	case 'a': 
		if (temp->getX() > -1)
			temp->setPosition(temp->getX()-0.01, temp->getY());
		break;

	case 's': break;
	case 'd': 
		if (temp->getX() <=1)
			temp->setPosition(temp->getX() + 0.01, temp->getY());
			
		
		break;

	case 27: exit(0);
	}
}

void InputHandler::__processKeyboard(unsigned char key, int x, int y)
{
	if (m_pInputHandler)
		m_pInputHandler->processKeyboard(key, x, y);
}