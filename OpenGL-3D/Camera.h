#pragma once
#include "GraphicObject3D.h"

class Camera: public GraphicObject3D
{
public:
	Camera();
	~Camera();

	virtual void draw() {} //we do nothing
};

