#include "stdafx.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Player.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "AnimatedSprite.h"
#include "Text.h"
#include "Timer.h"



int main(int argc, char** argv)
{
	Renderer renderer;
	InputHandler inputHandler(renderer);
	
	renderer.initialize(argc, argv);
	inputHandler.initialize();


	//test objects
	Player* jugador = new Player("jugador", "img/fighter-01.png");
	renderer.addObject(jugador);
	
	/*AnimatedSprite * pAnimatedSprite = new AnimatedSprite("img/fire-animation-2.png", 5, 2, true);
	pAnimatedSprite->setSize(0.25);
	renderer.addObject(pAnimatedSprite);
	*/

	//Number of enemies
	double E = 8.00;

	//Start position of X
	const double xmin = -0.7;
	double x = xmin;
	//Start position of Y
	double y = 0.25;

	//Separation between enemies
	double r = ((-x)*2)/(E-1);

	double t = 0.15;

	//number of columns
	double c = 4.00;

	for (int k=0;k<c;k++) {
		for (int l=0; l < E; l++) {

			Sprite *pSprite;
			if (k%2==0) {
				pSprite = new Sprite("img/alien-01.png");
			}
			else {
				pSprite = new Sprite("img/alien-02.png");
			}
			pSprite->setColor(255, 0, 0);
			pSprite->setPosition(x, y);
			pSprite->setRotation(0.0);
			pSprite->setSize(0.1);
			pSprite->setDepth(1.5);
			pSprite->setName((string)(k+""+l));
			renderer.addObject(pSprite);
			x = x + r;
		}
		y = y + t;
		x = xmin;
	}

	Text2D *Text2D11 = new Text2D("Player1textName",-0.125,-0.8,1.5);
	Text2D11->setColor(13, 120, 254);
	renderer.addObject(Text2D11);
	int i = 0;
	Timer time;
	time.start();

	Text2D *Text2D12 = new Text2D("TimerP", 0.5, -0.8, 1.5);
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
		inputHandler.update();


/*		for (int k = 0; k<c; k++) {
			for (int l = 0; l < E; l++) {
				Sprite* theEnemy = (Sprite*)renderer.getDrawable((string)(k + "" + l));
				theEnemy->setPosition(theEnemy->getX(), theEnemy->getY()-0.1);
				
			}
		}  */

		//RENDER////////////////////
		////////////////////////////
		glutPostRedisplay();
		glutSwapBuffers();
	}
   
	return 0;

}
