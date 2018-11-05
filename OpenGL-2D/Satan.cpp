#include "Satan.h"
#include "Sprite.h"
#include "Renderer.h"



Satan* Satan::m_pInstance= nullptr;

Satan::Satan()
{
	m_pInstance = this;
}


Satan::~Satan()
{
}

void Satan::createEnemies() {
	r = ((-x) * 2) / (E - 1);
	int numEnemies = 0;
	for (int k = 0; k<c; k++) {
		for (int l = 0; l < E; l++) {

			Sprite *pSprite;
			if (k % 2 == 0) {
				pSprite = new Sprite("img/alien-01.png");
			}
			else {
				pSprite = new Sprite("img/alien-02.png");
			}
			pSprite->setColor(255, 0, 0);
			pSprite->setPosition(x, y);
			pSprite->setRotation(0.0);
			pSprite->setSize(0.1);
			pSprite->setDepth(1.5);
			pSprite->setName(string("enemy") + to_string(numEnemies));
			Renderer::get()->addObject(pSprite);
			x = x + r;
			numEnemies++;
		}
		y = y + t;
		x = xmin;
	}
	setNumEnemies(numEnemies);
}

#define ENEMY_SPEED 0.01

bool Satan::updateEnemies(double dt)
{
	for (int id = 0; id < getNumEnemies(); id++)
	{
		Sprite* theEnemy = (Sprite*)Renderer::get()->getDrawable(string("enemy") + to_string(id));
		if (theEnemy != nullptr)
		{
			if (theEnemy->getY() >= -0.5) 
			{
				theEnemy->setPosition(theEnemy->getX(), theEnemy->getY() - ENEMY_SPEED* dt);
			}
			else
			{
				Sprite* gameover = new Sprite("img/game-over.png");
				gameover->setDepth(1.01);
				Renderer::get()->addObject(gameover);
				return true;
			}
		}
	}
	return false;
}