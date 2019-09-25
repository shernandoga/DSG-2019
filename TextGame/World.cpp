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


World::World(std::string nameFile)
{
	System::hideCursor();

	//initialize the timer. We want to display the time elapsed since the game began in draw()
	m_timer.start();

	//TODO: initalize everything else
	m_cells = vector<char>(0);


	//We randomly create a map to try the draw method
	m_cells.push_back('#');
	m_cells.push_back(' ');
	m_cells.push_back(' ');
	m_cells.push_back('?');
	m_cells.push_back('#');
	m_cells.push_back('#');
	m_cells.push_back(' ');
	m_cells.push_back('1');
	m_cells.push_back('#');
	m_cells.push_back(' ');
	m_cells.push_back('?');
	m_cells.push_back('2');
	m_cells.push_back('#');
	m_cells.push_back('?');
	m_cells.push_back(' ');
	m_cells.push_back(' ');
}


World::~World()
{
}


void World::draw()
{
	drawMaze();

	//TODO: -write the time elapsed since the beginning
	//		-set the proper position/color
	std::cout << m_timer.getElapsedTime() << "   ";
}


void World::drawMaze()
{
	System::clear();

	//TODO: -draw the maze: walls and each of the cells
	string map;
	for (int i = 0; i < 4; i++) //Height
	{
		for (int j = 0; j < 4; j++) //Width
		{
			map = map + m_cells[i*4+j];
		}
		map = map + "\n";
	}
	std::cout << map;

	//we sleep for a while
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

vector <char>& World::getVector()
{
	return m_cells;
}
string World::attemptMove(int oldx, int oldy, int newx, int newy)
{
	if (newy * 4 + newx > m_cells.size()||newy<0||newx<0) {
		return "NO";
	}
	char newPosition= m_cells[newy*4+newx];
	char oldPosition= m_cells[oldy*4+oldx];
	
	if(oldPosition=='1')
	{
		if(newPosition=='2'||newPosition=='#')
		{
			return "NO";
		}
		else if (newPosition=='?')
		{
			return "COIN";
			updateVector(oldPosition, newPosition);
		}
		else
		{
			return "YES";
			updateVector(oldPosition, newPosition);

		}
	}
	else
	{
		if (newPosition == '1' || newPosition == '#')
		{
			return "NO";
		}
		else if (newPosition=='?')
		{
			return "COIN";
			updateVector(oldPosition, newPosition);

		}
		else
		{
			return "YES";
			updateVector(oldPosition, newPosition);

		}
	}
}
void World::updateVector(char player, char newPosition)
{
	int playerint = player - '0';
	int newPositionint = newPosition - '0';
	m_cells[newPositionint] = player;
	m_cells[playerint] = ' ';

}
