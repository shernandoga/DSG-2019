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
	
	//We try to read the file
	char delimiter;
	ifstream inputFile(nameFile, fstream::in);
	if (inputFile.is_open())
	{
		inputFile >> m_heigth;
		inputFile >> delimiter;
		inputFile >> m_width;
		inputFile >> delimiter;
		inputFile >> delimiter;

		for (int row = 0; row < m_heigth; row++)
		{		
			for (int col = 0; col < m_width; col++)
			{
				inputFile >> m_cells[row*m_width+col];
				inputFile >> delimiter;
			}
			inputFile >> delimiter;
			inputFile >> delimiter;			
		}
		inputFile.close();
	}
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
	for (int i = 0; i < m_heigth; i++) //Height
	{
		for (int j = 0; j < m_width; j++) //Width
		{
			map = map + m_cells[i*m_width+j];
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
	if (newy * m_width + newx > m_cells.size()||newy<0||newx<0) {
		return "NO";
	}
	char newPosition= m_cells[newy*m_width+newx];
	char oldPosition= m_cells[oldy*m_width +oldx];
	
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
	draw();
}

int World::getPlayer1ROW()
{
	int row = 0;
	int count = -1;
	for (int i = 0; i < m_cells.size; i++) 
	{
		count++;
		if (count > m_width - 1)
		{
			count = 0;
			row++;
		}
		if (m_cells[i]=='1')
		{
			return row;
		}
	}
}

int World::getPlayer2ROW()
{
	int row = 0;
	int count = -1;
	for (int i = 0; i < m_cells.size; i++)
	{
		count++;
		if (count > m_width - 1)
		{
			count = 0;
			row++;
		}
		if (m_cells[i] == '2')
		{
			return row;
		}
	}
}

int World::getPlayer1COL()
{
	int row = 0;
	int count = -1;
	for (int i = 0; i < m_cells.size; i++)
	{
		count++;
		if (count > m_width - 1)
		{
			count = 0;
			row++;
		}
		if (m_cells[i] == '1')
		{
			return count;
		}
	}
}

int World::getPlayer2COL()
{
	int row = 0;
	int count = -1;
	for (int i = 0; i < m_cells.size; i++)
	{
		count++;
		if (count > m_width-1)
		{
			count = 0;
			row++;
		}
		if (m_cells[i] == '2')
		{
			return count;
		}
	}
}
