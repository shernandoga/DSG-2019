#pragma once
#include "Sprite.h"
class AnimatedSprite :
	public Sprite
{

public:
	AnimatedSprite(const char* textureFilename, int numImagesX, int numImagesY, bool loop);
	virtual ~AnimatedSprite();

	virtual void draw();
};

