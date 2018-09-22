#pragma once
#include "Timer.h"
#include <string>
using namespace std;

class World
{
	Timer m_timer;

	struct point2D {
		double x, y;
	};

   #define NUM_POINTS 2

	void drawMaze();
	void ReadFile(const char* filename, point2D* points, int numPoints);
	void PrintPoints(point2D* points, int numPoints);

public:
	World(string nameFile);
	~World();

	void draw();
};