#include "stdafx.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Player.h"
#include "World.h"
#include "Text.h"
#include "Projectile.h"
#include "Text.h"
#include <iostream>
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "AnimatedSprite.h"
#include "../3rd-party/SoundManager/SoundManager.h" //relative path to the main header
using namespace std;


int main(int argc, char** argv)
{
	int cont = 0;

	//Sound
	clock_t startSoundtrack = clock();
	double secondsPassed;
	SoundManager soundManager;
	SoundManager* pSoundManager = SoundManager::getInstance();
	pSoundManager->setVerbose(true);
	pSoundManager->createAudioObject("snd/soundtrack-01.wav");
	pSoundManager->createAudioObject("snd/cannon.wav");

	int audioObj1 = pSoundManager->getAudioObjectId("snd/soundtrack-01.wav");
	pSoundManager->play(audioObj1, 1.f);
	int audioObj2 = pSoundManager->getAudioObjectId("snd/cannon.wav");

	Renderer renderer;
	InputHandler inputHandler(renderer);
	renderer.initialize(argc, argv);
	inputHandler.initialize();
	bool play = true;
	/*while (!play) {
		if (inputHandler.doPlay()) {
			play = true;
		}
		glutMainLoopEvent();
		glutPostRedisplay();
		glutSwapBuffers();
	}*/
	Text2D *texto1 = new Text2D("PLAYER 1: 10", -0.75, 0.75, 1);
	Text2D *texto2 = new Text2D("PLAYER 2: 10", 0.40, 0.75, 1);
	Text2D *textWinner = new Text2D("GANADOR", -0.25, 0.5, 1);

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
		if (inputHandler.doPlay() == true) {

			secondsPassed = (clock() - startSoundtrack) / CLOCKS_PER_SEC;
			if (secondsPassed > 80) {
				startSoundtrack = clock();
				pSoundManager->play(audioObj1, 1.f);
			}
			//UPDATE////////////////////
			////////////////////////////
			//process queued events
			inputHandler.processEvents(pSoundManager, audioObj2);
			glutMainLoopEvent();

			//RENDER////////////////////
			////////////////////////////
			glutPostRedisplay();
			glutSwapBuffers();
		}

		if (pPlayer1->getScore() == 10) {
			renderer.addObject(textWinner);
			textWinner->setText("El jugador 1 ha ganado !!!");
			inputHandler.stopPlaying();

			inputHandler.processEvents(pSoundManager, audioObj2);
			glutMainLoopEvent();

			glutPostRedisplay();
			glutSwapBuffers();
		}
		else if (pPlayer2->getScore() == 10)
		{
			renderer.addObject(textWinner);
			textWinner->setText("El jugador 2 ha ganado !!!");
			inputHandler.stopPlaying();

			inputHandler.processEvents(pSoundManager, audioObj2);
			glutMainLoopEvent();

			glutPostRedisplay();
			glutSwapBuffers();
		}

	}
   
	return 0;
	
}
