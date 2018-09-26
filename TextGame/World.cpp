#include "stdafx.h"
#include "World.h"
#include "Player.h"
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
#include <vector>

void World::ReadFile(std::string filename)
{
	cout << "Reading config file: " << filename << "\n";
	ifstream inputFile;
	char c1, c2;
	inputFile.open(filename, fstream::in);
	if (inputFile.is_open())
	{
		char c = ' ';
		inputFile >> m_width >> c >> m_height >> c >> m_blank >> c >> m_coin >> c >> m_player1 >> c >> m_player2 >> c >> m_wall;
		
		string line;
		
		//load the maze into the vector;
		for (int x = 0; x < m_height; x++) {
			for (int y = 0; y < m_width; y++) {
				inputFile >> c;
				m_maze.push_back(c);
			}
			getline(inputFile, line);
		}

		inputFile.close();
	}
	else
		cout << "Couldn't create file: " << filename;
}

World::World(std::string nameFile)
{
	System::hideCursor();

	//initialize the timer. We want to display the time elapsed since the game began in draw()
	m_timer.start();

	//TODO: initalize everything else
	//...
	ReadFile(nameFile);
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
	//print the maze in the screen
	cout << '|';
	for (int x = 0; x < m_width; x++)
		cout << "-";

	cout << '|' << '\n' << '|';
	for (int x = 0; x < (m_height*m_width); x++) {
		//c = ;
		if (x%m_width == 0 && x != 0)
			cout << '|' << "\n" << '|';

		if (m_maze.at(x) == m_blank)
			cout << ' ';
		else
			cout << m_maze.at(x);
	}

	cout << '|' << "\n" << '|';
	for (int x = 0; x < m_width; x++)
		cout << "-";
	cout << '|' << "\n";

	//we sleep for a while
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

Player& World::getPlayer1()
{
	return m_player1;
}

Player& World::getPlayer2()
{
	return m_player2;
}