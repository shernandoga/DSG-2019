#include "stdafx.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "Sphere.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "Camera.h"
#include "ColladaModel.h"



int main(int argc, char** argv)
{
	Renderer renderer;
	InputHandler inputHandler(renderer);
	
	renderer.initialize(argc, argv);
	inputHandler.initialize();

	//init objects
	Camera camera;
	camera.setPosition(0, 0, 1);
	renderer.addCamera(&camera);

	ColladaModel* cm = new ColladaModel("Venom.dae");
	//ColladaModel* cm = new ColladaModel("EM208_heavy.dae");
	renderer.addObject(cm);

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