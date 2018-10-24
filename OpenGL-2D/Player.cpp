#include "Player.h"
#include "stdafx.h"
#include "Bullet.h"
#include "Renderer.h"

Player::Player(string name, const char* texture): Sprite(texture)
{
	setPosition(0, -0.5);
	setSize(0.2);
	setDepth(1.25);
	setColor(255, 0, 0);
	setName(name);
}

void Player::draw() {

	//0. Activate textures and give coords
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_textureId);

	//1. Pass the object's color to OpenGL
	
	//2. Save the current transformation matrix
	glPushMatrix();
	//3. Set the transformation matrix of the quad using position, size and angle
	//glColor3f(255,0,0);
	glTranslated(getX(), getY(), 0);	
	glScalef(0.1, 0.1, 1);
	//4. Draw the quad centered in [0,0] with coordinates: [-1,-1], [1,-1], [1,1] and [-1,1]

	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-1.0, -1.0, -m_depth);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, -1.0, -m_depth);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, 1.0, -m_depth);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-1.0, 1.0, -m_depth);

	glEnd();

	//5. Restore the transformation matrix
	glPopMatrix();

}


void Player::shoot()
{
	Sprite* pBullet = new Bullet(m_x, m_y, "../OpenGL-2D/img/alien-01.png");
	Renderer render;
	render.get()->addObject(pBullet);

}