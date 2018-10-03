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

World* World::m_pInstance = nullptr;
using namespace std;

#define NUM_POINTS 7

struct point2D {
	double x, y;
};

char c_empty, c_coin, c_player1, c_player2, c_wall, c_aux;


World::World(std::string nameFile){
	m_pInstance = this;

	System::hideCursor();

	//initialize the timer. We want to display the time elapsed since the game began in draw()
	m_timer.start();

	//TODO: initalize everything else
	point2D pointsForReading[NUM_POINTS];
	ReadFile("file.csv", pointsForReading, NUM_POINTS);

	pointsP1 = 0;
	pointsP2 = 0;
	numCoins = 15;
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

char World::checkbox(int x, int y){

	//y*msizex+x
	int k = (y*m_sizeX) + x;
	return m_maze[k];
}

bool World::iswall(char a) {

	return a == c_wall;
}; 
bool World::isplayer(char a) {
   
	return a == c_player1 || a == c_player2;
};
void World::updateworld(int xold,int yold ,int xnew,int ynew) {

	int posold = (yold*m_sizeX) + xold;
	int posnew = (ynew*m_sizeX) + xnew;
	char aux = m_maze[posold];
	m_maze[posold] = c_empty;
	m_maze[posnew] = aux;


}

Player& World::getPlayer(int p)
{
	if (p == 1)
		return player1;
	else if (p == 2)
		return player2;
}

bool World::isempty(char a) {

	return a == c_empty;
};
bool World::iscoin(char a) {

	return a == c_coin;
};

void World::drawMaze(){
	System::clear();

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

void World::ReadFile(const char* filename, point2D * points, int numPoints)
{
	ifstream inputFile;
	//char c_empty, c_coin, c_player1, c_player2, c_wall, c_aux;

	inputFile.open(filename, fstream::in);
	if (inputFile.is_open()) {
		//Reads the first row of the file
		inputFile >> m_sizeX >> c_aux >> m_sizeY >> c_aux >> c_empty >> c_aux >> c_coin >> c_aux >> c_player1 >> c_aux >> c_player2 >> c_aux >> c_wall;
		//Defines de vector
		m_maze = vector<char>(m_sizeX * m_sizeY);
		player1.setlimit(m_sizeX, m_sizeY);
		player2.setlimit(m_sizeX, m_sizeY);

		//Reads the rest of the files and saves it into the vector
		for (int i = 0; i < m_sizeX * m_sizeY; i++) {
			inputFile >> c_aux;
			m_maze[i] = c_aux;

			if (c_aux == c_player1) {
				player1.setcoord(i%m_sizeX, i / m_sizeX);					
			}
			if (c_aux == c_player2) {
				player2.setcoord(i%m_sizeX, i / m_sizeX);
			}


		}
		inputFile.close();
	}
	else
		cout << "Couldn't create the file: " << filename;
}



