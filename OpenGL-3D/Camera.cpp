#include "Camera.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"


Camera::Camera()
{
}


Camera::~Camera()
{
}

void Camera::applyMatrix()
{
	//TODO: apply the inverse transformation
	//1. Set the perspective matrix

	//2. Reset the modelview matrix

	//3. Apply the camera's own transformation: translation/rotation

	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); 
	glRotatef(-m_roll, 0.0, 0.0, 1.0); //aplicamos el roll
	glRotatef(-m_yaw, 0.0, 1.0, 0.0); //aplicamos el yaw
	glRotatef(-m_pitch, 1.0, 0.0, 0.0); //aplicamos el pitch
	glTranslatef(-m_x, -m_y, -m_z); //aplicamos la translación
}