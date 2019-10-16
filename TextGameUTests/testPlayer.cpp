#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TextGame/Player.h"
#include "../TextGame/World.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TextGameUTests
{
	TEST_CLASS(testPlayer)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			
			World world(buildMap());
			Player player(world.getPlayer1COL(), world.getPlayer1ROW(), world);

			int posX = player.getX();
			int posY = player.getY();
			//Check move UP when is possible
			player.moveUp();
			Assert::AreEqual(posY-1, player.getY());
			//Check move UP when is impossible
			player.moveUp();
			Assert::AreEqual(posY - 1, player.getY());
			//Check move DOWN when is possible
			player.moveDown();
			Assert::AreEqual(posY, player.getY());
		}

		TEST_METHOD(TestMethod2)
		{

			World world(buildMap());
			Player player(world.getPlayer1COL(), world.getPlayer1ROW(), world);

			int posX = player.getX();
			int posY = player.getY();
			//Check move RIGHT derecha when is impossible
			player.moveRight();
			Assert::AreEqual(posX, player.getX());
			//Check move LEFT when is possible
			player.moveLeft();
			Assert::AreEqual(posX - 1, player.getX());
			//Check move RIGHT derecha when is possible
			player.moveRight();
			Assert::AreEqual(posX, player.getX());
			//Check move LEFT when is impossible
			player.moveLeft();
			player.moveLeft();
			Assert::AreEqual(2, player.getX());
		}

		TEST_METHOD(TestMethod3)
		{

			World world(buildMap2());
			Player player(world.getPlayer1COL(), world.getPlayer1ROW(), world);

			int posX = player.getX();
			int posY = player.getY();
			
			//Check move DOWN when is impossible
			player.moveDown();
			Assert::AreEqual(posY, player.getY());	
		}

		vector<char> testPlayer::buildMap()
		{
			vector<char> m_cells;
			m_cells.push_back('#');
			m_cells.push_back('n');
			m_cells.push_back('n');
			m_cells.push_back('?');
			m_cells.push_back('#');
			m_cells.push_back('#');
			m_cells.push_back('?');
			m_cells.push_back('1');
			m_cells.push_back('#');
			m_cells.push_back('n');
			m_cells.push_back('?');
			m_cells.push_back('2');
			m_cells.push_back('#');
			m_cells.push_back('?');
			m_cells.push_back('n');
			m_cells.push_back('n');
			return m_cells;
		}

		vector<char> testPlayer::buildMap2()
		{
			vector<char> m_cells;
			m_cells.push_back('#');
			m_cells.push_back('n');
			m_cells.push_back('n');
			m_cells.push_back('?');
			m_cells.push_back('#');
			m_cells.push_back('#');
			m_cells.push_back('?');
			m_cells.push_back('n');
			m_cells.push_back('#');
			m_cells.push_back('n');
			m_cells.push_back('?');
			m_cells.push_back('2');
			m_cells.push_back('#');
			m_cells.push_back('?');
			m_cells.push_back('n');
			m_cells.push_back('1');
			return m_cells;
		}
	};
}