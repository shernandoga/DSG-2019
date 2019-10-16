#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TextGame/GameLogic.h"
#include <vector>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			vector<char> v;
			v.push_back('#');
			v.push_back('n');
			v.push_back('n');
			v.push_back('n');
			v.push_back('#');
			v.push_back('#');
			v.push_back('n');
			v.push_back('1');
			v.push_back('#');
			v.push_back('n');
			v.push_back('n');
			v.push_back('2');
			v.push_back('#');
			v.push_back('n');
			v.push_back('n');
			v.push_back('n');
			World world(v);
			Player player1(world.getPlayer1COL(), world.getPlayer1ROW(), world);
			Player player2(world.getPlayer2COL(), world.getPlayer2ROW(), world);
			GameLogic gL(player1, player2, world);
			Assert::IsTrue(gL.gameHasEnded());
		}
	};
