#include "stdafx.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "Sprite.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"



int main(int argc, char** argv)
{
	Renderer renderer;
	InputHandler inputHandler(renderer);
	
	renderer.initialize(argc, argv);
	inputHandler.initialize();


	//test objects
	Sprite sprite1;
	sprite1.setColor(255, 0, 0);
	sprite1.setPosition(0.75, 0.75);
	sprite1.setRotation(0.0);
	sprite1.setSize(0.2);
	renderer.addObject(&sprite1);
	Sprite sprite2;
	sprite2.setColor(0, 255, 0);
	sprite2.setPosition(0.25, 0.25);
	sprite2.setRotation(45.0);
	sprite2.setSize(0.2);
	renderer.addObject(&sprite2);


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