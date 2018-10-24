#pragma once
#include "Player.h"

class Renderer;

class InputHandler
{
	static InputHandler* m_pInputHandler;
	Renderer& m_renderer;
	int SHOOT_TIME = 2;
	bool mvUp1 = false, mvUp2 = false, mvDwn1 = false, mvDwn2 = false;
	Player* player2;
	Player* player1;

public:
	InputHandler(Renderer& renderer);
	~InputHandler();
	
	void initialize();

	void processKeyboard(unsigned char key, int x, int y);
	static void __processKeyboard(unsigned char key, int x, int y);
	void retard(Player* player, Renderer* renderer, bool direction);

	void processUpKeyboard(unsigned char key, int x, int y);
	static void __processUpKeyboard(unsigned char key, int x, int y);

	void processEvents();
};

