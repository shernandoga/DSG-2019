#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TextGame/World.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TextGameUTests
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethodMove)
		{
			//We create the world and we try to move from the start(3,1) to the left(2,1)
			//There is a coin so it should be able to move and the position on m_cells will be updated
			vector<char>m_cells;
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


			World world(m_cells);
			world.attemptMove(3,1,2,1);
			//m_cells is a vector which contains the map but keep in mind it has just 1 dimension
			//The position which the player will take is 6 and in the 7th position there should be an 'n'
			vector<char>cells=world.getCells();
			char player=cells[6];
			char blank =cells[7];
			Assert::AreEqual('1', player);
			Assert::AreEqual('n', blank);

		}

	};
}