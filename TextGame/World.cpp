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

template<typename StringFunction>
void splitString(const std::string &str, char delimiter, StringFunction f) {
	std::size_t from = 0;
	for (std::size_t i = 0; i < str.size(); ++i) {
		if (str[i] == delimiter) {
			f(str, from, i);
			from = i + 1;
		}
	}
	if (from <= str.size())
		f(str, from, str.size());
}

//void ReadFile(const char* filename, const char* points, int numPoints)
void ReadFile(std::string filename)
{
	cout << "Reading config file: " << filename << "\n";
	ifstream inputFile;
	char c1, c2;
	inputFile.open(filename, fstream::in);
	if (inputFile.is_open())
	{
		std::string line;
		std::getline(inputFile, line);
		cout << line << "\n";
		//20,20,.,?,o,x,*
		//.o................x.
		
		int maze_width, maze_height;
		char blank, coin, player1, player2, wall;
		string maze_values;

		//source: https://stackoverflow.com/questions/1894886/parsing-a-comma-delimited-stdstring/48807276#48807276
		splitString(line, ',', [](const std::string &s, std::size_t from, std::size_t to) {
			std::cout << "`" << s.substr(from, to - from) << "`\n";
			/*if (maze_width == null)
				maze_width = s.substr(from, to - from);*/
		});

		std::cout << "dimensions: " << maze_width << " x " << maze_height;
		std::cout << "\n"; 
		std::cout << "BLANK: `" << blank << "` | ";
		std::cout << "COIN: `" << coin << "` | ";
		std::cout << "PLAYER1: `" << player1 << "` | ";
		std::cout << "PLAYER2: `" << player2 << "` | ";
		std::cout << "WALL: `" << wall << "`";
		std::cout << "\n";

		for (std::string line; getline(inputFile, line); )
		{
			std::cout << line << "\n";
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


	//we sleep for a while
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}