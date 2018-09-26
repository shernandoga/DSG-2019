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


World::World(std::string nameFile){
	System::hideCursor();

	//initialize the timer. We want to display the time elapsed since the game began in draw()
	m_timer.start();

	//TODO: initalize everything else
	//...
}


World::~World(){
}


void World::draw(){
	drawMaze();

	//TODO: -write the points each player has
	

	//TODO: -write the time elapsed since the beginning
	//		-set the proper position/color
	std::cout << m_timer.getElapsedTime() << "   ";
}


void World::drawMaze(){
	System::clear();
	for (int i = 0; i < 400; i++) {
		m_maze.push_back(i);
	}
	//TODO: -draw the maze: walls and each of the cells
	int posi=0;
	for (int i = 0; i < m_sizeY; i++){
		for ( int j = 0; j < m_sizeX; j++){
			//std::string auxString << m_maze[posi];
			std::cout << m_maze[posi];
			posi++;
		}
		//std::cout << auxString;
		//change line
		std::cout << "\n";
	}

	//we sleep for a while
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}