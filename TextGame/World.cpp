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
	coinsP1 = 0;
	coinsP2 = 0;
	
	//We try to read the file
	char delimiter;
	ifstream inputFile(nameFile, fstream::in);
	if (inputFile.is_open())
	{
		inputFile >> m_heigth;
		inputFile >> delimiter;
		inputFile >> m_width;
		m_cells = vector<char>(m_heigth*m_width);
	

		for (int row = 0; row < m_heigth; row++)
		{		
			for (int col = 0; col < m_width; col++)
			{
				if (col < m_width - 1)
				{
					inputFile >> m_cells[row*m_width + col];
					inputFile >> delimiter;
				}		
				else
				{
					inputFile >> m_cells[row*m_width + col];
				}
			}
		
		}
		inputFile.close();
	}
}
World::World(vector<char> vectormap)
{
	m_cells = vector<char>(16);
	for (int i = 0; i < vectormap.size(); i++)
	{
		m_cells[i] = vectormap[i];
	}
	coinsP1 = 0;
	coinsP2 = 0;
	m_heigth = 4;
	m_width = 4;
}

World::~World()
{
}


void World::draw()
{
	drawMaze();

	//TODO: -write the time elapsed since the beginning
	//		-set the proper position/color
	
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
	std::cout << m_timer.getElapsedTime() << " milliseconds\n";
	std::cout << "Player 1 has: "<<coinsP1<<"coin(s)\n" ;
	std::cout <<  "Player 2 has: "<<coinsP2<<"coin(s)";
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
	int oldP = oldy * m_width + oldx;
	int newP = newy * m_width + newx;
	
	if(oldPosition=='1')
	{
		if(newPosition=='2'||newPosition=='#')
		{
			return "NO";
		}
		else if (newPosition=='?')
		{
			
			updateVector(oldPosition,oldP,newP);
			return "COIN";
		}
		else
		{
			
			updateVector(oldPosition,oldP,newP);
			return "YES";

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
			
			updateVector(oldPosition,oldP,newP);
			return "COIN";

		}
		else
		{
			updateVector(oldPosition,oldP,newP);
			return "YES";


		}
	}
}
void World::updateVector(char player,int oldposition,int newposition)
{

	m_cells[newposition] = player;
	m_cells[oldposition] = 'n';	
}

int World::getPlayer1ROW()
{
	int row = 0;
	int count = -1;
	for (int i = 0; i < m_cells.size(); i++) 
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
	for (int i = 0; i < m_cells.size(); i++)
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
	for (int i = 0; i < m_cells.size(); i++)
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
	for (int i = 0; i < m_cells.size(); i++)
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
vector <char> World::getCells()
{
	return m_cells;
}
void World::setCoins(int m_coinsP1, int m_coinsP2)
{
	coinsP1 = m_coinsP1;
	coinsP2 = m_coinsP2;

}
int World::getCoinsP1()
{
	return coinsP1;
}
int World::getCoinsP2()
{
	return coinsP2;
}

