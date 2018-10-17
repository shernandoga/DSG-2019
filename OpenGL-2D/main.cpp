#include "stdafx.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Text.h"
#include "Projectile.h"
#include "Text.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"



int main(int argc, char** argv)
{
	Renderer renderer;
	InputHandler inputHandler(renderer);
	
	renderer.initialize(argc, argv);
	inputHandler.initialize();

	//Projectile *pProj1 = new Projectile(0.25, 0.25, true);
	Text2D *texto1 = new Text2D("PLAYER 1: 10", -0.75, 0.75, 1);
	Text2D *texto2 = new Text2D("PLAYER 2: 10", 0.40, 0.75, 1);

	renderer.addObject(texto1);
	renderer.addObject(texto2);
	texto1->updateScore(1);
	texto2->updateScore(0);
	
	/*
	//test objects
	Sprite *pSprite1= new Sprite();
	pSprite1->setColor(255, 0, 0);
	pSprite1->setPosition(0.25, 0.25);
	pSprite1->setRotation(0.0);
	pSprite1->setSize(0.2);
	pSprite1->setDepth(1.5);
	renderer.addObject(pSprite1);

	Sprite *pSprite2= new Sprite();
	pSprite2->setColor(0, 255, 0);
	pSprite2->setPosition(0.5, 0.5);
	pSprite2->setRotation(45.0);
	pSprite2->setSize(0.2);
	pSprite2->setDepth(1.3);
	renderer.addObject(pSprite2);
	*/

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