#include "stdafx.h"
#include "World.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <chrono>
#include <thread>
#include <fstream>
#include "System.h"
#include "stdafx.h"
#include <stdio.h>
#include <istream>
#include <fstream>
using namespace std;

#define NUM_POINTS 7

struct point2D {
	double x, y;
};

World::World(std::string nameFile)
{
	System::hideCursor();

	//initialize the timer. We want to display the time elapsed since the game began in draw()
	m_timer.start();

	//TODO: initalize everything else
	point2D pointsForReading[NUM_POINTS];
	ReadFile("file.csv", pointsForReading, NUM_POINTS);
	PrintPoints(pointsForReading, NUM_POINTS);

}


World::~World()
{
}


void World::draw()
{
	drawMaze();

	//TODO: -write the points each player has
	

	//TODO: -write the time elapsed since the beginning
	//		-set the proper position/color
	std::cout << m_timer.getElapsedTime() << "   ";
}


void World::drawMaze()
{
	System::clear();

	//TODO: -draw the maze: walls and each of the cells


	//we sleep for a while
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void World::ReadFile(const char* filename, point2D * points, int numPoints)
{
	ifstream inputFile;
	char c1, c2;
	inputFile.open(filename, fstream::in);
	if (inputFile.is_open())
	{
		for (int i=0; i < numPoints; i++) 
		{
			inputFile >> points[i].x >> c1 >> points[i].y >> c2;
		}
		inputFile.close();
	}
	else
		cout << "Couldn't create the file: " << filename;
}

void World::PrintPoints(point2D * points, int numPoints)
{
	for (int i=0; i < numPoints; i++) {
		cout << points[i].x << "," << points[i].y;
	}
}

