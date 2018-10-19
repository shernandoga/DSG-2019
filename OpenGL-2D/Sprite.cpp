#include "stdafx.h"
#include "Sprite.h"


Sprite::Sprite()
{
}


Sprite::~Sprite()
{
}

void Sprite::setColor(float r, float g, float b)
{
	//When this method is called, we only store internally what this object's color will be
	//but, we need to pass the color to OpenGL every time the object is drawn
}

void Sprite::setPosition(double x, double y)
{
	//This method only updates internally the object's position. It still needs to be passed to OpenGL before drawing it
}

void Sprite::setDepth(double depth)
{
	//This method only updates internally the object's depth. It still needs to be passed to OpenGL before drawing it
}

void Sprite::setRotation(double angle)
{
	//This method only updates internally the object's rotation. It still needs to be passed to OpenGL before drawing it
}

void Sprite::setSize(double size)
{
	//This method only updates internally the object's size. It still needs to be passed to OpenGL before drawing it
	m_size = size;
}

void Sprite::draw()
{
	//TODO:

	//1. Pass the object's color to OpenGL

	//2. Save the current transformation matrix

	//3. Set the transformation matrix of the quad using position, size and angle

	//4. Draw the quad centered in [0,0] with coordinates: [-1,-1], [1,-1], [1,1] and [-1,1]
	
	//5. Restore the transformation matrix
}