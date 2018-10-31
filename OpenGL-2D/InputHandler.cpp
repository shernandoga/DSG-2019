#include "stdafx.h"
#include "InputHandler.h"
#include "World.h"
#include "Projectile.h"
#include "Renderer.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "AnimatedSprite.h"

InputHandler* InputHandler::m_pInputHandler = nullptr;
double secondsToDelay = 0.1;
clock_t startTimeP1 = clock();
clock_t startTimeP2 = clock();
double secondsPassed;

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
	//TODO glutKeyboardUpFunc deje de moverse cuando se suelte y que detecte cuando pulsado con booleans

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
		retard(player2, renderer, false);
		break;

	case 'w':
		player1->moveUp(); break;
	case 's':
		player1->moveDown(); break;
	case 'd':
		retard(player1, renderer, true);
		break;

	case 27: exit(0);
	}
}

void InputHandler::retard(Player* player, Renderer* renderer, bool direction) {
	clock_t startTimePl;
	if (direction) {
		startTimePl = startTimeP1;
	}else {
		startTimePl = startTimeP2;
	}
	secondsPassed = (clock() - startTimePl) / CLOCKS_PER_SEC;
	if (secondsPassed >= secondsToDelay)
	{
		renderer->addObject(new Projectile(player->getX(), player->getY(), direction, "img/fire-animation-2.png"));
		//AnimatedSprite * pAnimatedSprite = new AnimatedSprite("img/fire-animation-2.png", 5, 2, true);

		//pAnimatedSprite->setSize(0.12);
		//pAnimatedSprite->setPosition(player->getX(), player->getY());
		//pAnimatedSprite->setRotation(1);

		//pAnimatedSprite->draw();
		//renderer->addObject(pAnimatedSprite);
		if (direction) {
			startTimeP1 = clock();
		}
		else {
			startTimeP2 = clock();
		}
	}
}

void InputHandler::__processKeyboard(unsigned char key, int x, int y)
{
	if (m_pInputHandler)
		m_pInputHandler->processKeyboard(key, x, y);
}
