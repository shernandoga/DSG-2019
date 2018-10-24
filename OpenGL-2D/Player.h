#pragma once

#include <string>
#include "Sprite.h"

using namespace std;
class Player : public Sprite
{
public:
	Player();
	Player(string name, const char* texture);
	~Player();

	string m_name;
	void shoot();
	virtual void draw();
	
};
