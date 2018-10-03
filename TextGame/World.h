#pragma once
#include "Timer.h"
#include <string>
#include <vector>
#include "Player.h"
using namespace std;

class World
{
	static World* m_pInstance;


	char c_empty, c_coin, c_player1, c_player2, c_wall, c_aux;
	Timer m_timer;
	vector<char> m_maze;
	int m_sizeX, m_sizeY, pointsP1, pointsP2, numCoins;
	Player player1, player2;

	struct point2D {
		double x, y;
	};

   #define NUM_POINTS 7

	void drawMaze();
	void ReadFile(const char* filename, point2D* points, int numPoints);
	void PrintPoints(point2D* points, int numPoints);
	


public:
	World(string nameFile);
	~World();
	char checkbox(int x, int y);
	bool iswall(char a);
	bool isempty(char a);
	bool iscoin(char a);
	void updateworld(int xold, int yold, int xnew, int ynew);

	bool isplayer(char a);
	void draw();

	Player& getPlayer(int p);

	static World* getInstance() { return m_pInstance; }
};