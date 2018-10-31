#include "stdafx.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Player.h"
#include "World.h"
#include "Text.h"
#include "Projectile.h"
#include "Text.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "AnimatedSprite.h"


int main(int argc, char** argv)
{
	Renderer renderer;
	InputHandler inputHandler(renderer);
	renderer.initialize(argc, argv);
	inputHandler.initialize();

	Text2D *texto1 = new Text2D("PLAYER 1: ", -0.75, 0.75, 1);
	Text2D *texto2 = new Text2D("PLAYER 2: ", 0.40, 0.75, 1);

	renderer.addObject(texto1);
	renderer.addObject(texto2);
	texto1->setName("text1");
	texto2->setName("text2");
	texto1->updateScore(0);
	texto2->updateScore(0);
	
	
	//test objects
	Player *pPlayer1= new Player("img/fighter-01.png");
	//Player1->setColor(255, 0, 0);
	pPlayer1->setPosition(-0.75, 0.0);
	pPlayer1->setRotation(270.0);
	pPlayer1->setSize(0.2);
	pPlayer1->setDepth(1.5);
	pPlayer1->setName("Player1");
	renderer.addObject(pPlayer1);

	Player *pPlayer2 = new Player("img/fighter-02.png");
	//pPlayer2->setColor(0, 255, 0);
	pPlayer2->setPosition(0.75, 0.0);
	pPlayer2->setRotation(90.0);
	pPlayer2->setSize(0.2);
	pPlayer2->setDepth(1.3);
	pPlayer2->setName("Player2");
	renderer.addObject(pPlayer2);
	//AnimatedSprite * pAnimatedSprite = new AnimatedSprite("img/fire-animation-2.png", 5, 2, true);
	//pAnimatedSprite->setSize(0.25);
	//renderer.addObject(pAnimatedSprite);

	while (1)
	{
		//UPDATE////////////////////
		////////////////////////////
		//process queued events
		glutMainLoopEvent();


		//RENDER////////////////////
		////////////////////////////
		glutPostRedisplay();
		glutSwapBuffers();
	}
   
	return 0;
	
}
