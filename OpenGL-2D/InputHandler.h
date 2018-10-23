#pragma once
#include "Player.h"

class Renderer;

class InputHandler
{
	static InputHandler* m_pInputHandler;
	Renderer& m_renderer;
	int SHOOT_TIME = 2;
public:
	InputHandler(Renderer& renderer);
	~InputHandler();
	
	void initialize();

	void processKeyboard(unsigned char key, int x, int y);
	static void __processKeyboard(unsigned char key, int x, int y);
	void retard(Player* player, Renderer* renderer, bool direction);
};

