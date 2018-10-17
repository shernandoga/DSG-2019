#include "stdafx.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Player.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "Text.h"
#include "Timer.h"




int main(int argc, char** argv)
{
	Renderer renderer;
	InputHandler inputHandler(renderer);
	
	renderer.initialize(argc, argv);
	inputHandler.initialize();


	//test objects
	Player* jugador = new Player("jugador", "../OpenGL-2D/img/fighter-01.png");
	renderer.addObject(jugador);
	
	Sprite *pSprite1= new Sprite("../OpenGL-2D/img/alien-01.png");
	pSprite1->setColor(255, 0, 0);
	pSprite1->setPosition(0.25, 0.25);
	pSprite1->setRotation(0.0);
	pSprite1->setSize(0.2);
	pSprite1->setDepth(1.5);
	renderer.addObject(pSprite1);

	Sprite *pSprite2= new Sprite("../OpenGL-2D/img/alien-02.png");
//	pSprite2->setColor(0, 255, 0);
	pSprite2->setPosition(-0.25, 0.25);
	pSprite2->setRotation(0.0);
	pSprite2->setSize(0.2);
	pSprite2->setDepth(1.5);
	renderer.addObject(pSprite2);

	Sprite *pSprite3 = new Sprite("../OpenGL-2D/img/alien-01.png");
	pSprite3->setPosition(0.75, 0.25);
	pSprite3->setRotation(0.0);
	pSprite3->setSize(0.2);
	pSprite3->setDepth(1.5);
	renderer.addObject(pSprite3);

	Sprite *pSprite4 = new Sprite("../OpenGL-2D/img/alien-02.png");
	//	pSprite2->setColor(0, 255, 0);
	pSprite4->setPosition(-0.75, 0.25);
	pSprite4->setRotation(0.0);
	pSprite4->setSize(0.2);
	pSprite4->setDepth(1.5);
	renderer.addObject(pSprite4);

	Sprite *pSprite5 = new Sprite("../OpenGL-2D/img/alien-01.png");
	pSprite5->setPosition(0.25, 0.25);
	pSprite5->setRotation(0.0);
	pSprite5->setSize(0.2);
	pSprite5->setDepth(1.5);
	renderer.addObject(pSprite5);


	Text2D *Text2D11 = new Text2D("Player1textName",-0.125,0.8,1.5);
	Text2D11->setColor(13, 120, 254);
	renderer.addObject(Text2D11);
	int i = 0;
	Timer time;
	time.start();

	Text2D *Text2D12 = new Text2D("TimerP", 0.5, 0.8, 1.5);
	Text2D12->setColor(13, 120, 254);
	renderer.addObject(Text2D12);
	


	while (1)
	{

		Text2D11->setText("Player 1 Points: "+to_string(i++));
		Text2D12->setText("Time: " + to_string(time.getElapsedTime()));
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
