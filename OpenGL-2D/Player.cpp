#include "Player.h"
#include "stdafx.h"

Player::Player(string name) {
	setPosition(0, -0.5);
	setSize(0.2);
	setDepth(1.25);
	setColor(255, 0, 0);
	setName(name);
}

void Player::draw() {
	//1. Pass the object's color to OpenGL
	
	//2. Save the current transformation matrix
	glPushMatrix();
	//3. Set the transformation matrix of the quad using position, size and angle
	glColor3f(255,0,0);
	glTranslated(getX(), getY(), 0);	
	glScalef(0.1, 0.1, 1);
	//4. Draw the quad centered in [0,0] with coordinates: [-1,-1], [1,-1], [1,1] and [-1,1]
	glBegin(GL_QUADS);
	
	glVertex3f(-1, -1, -getDepth());
	glVertex3f(1, -1, -getDepth());
	glVertex3f(1, 1, -getDepth());
	glVertex3f(-1, 1, -getDepth());
	glEnd();

	//5. Restore the transformation matrix
	glPopMatrix();

}