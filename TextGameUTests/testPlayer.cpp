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
			World world("map.csv");
			Player player(world.getPlayer1COL(), world.getPlayer1ROW(), world);

			int posX = player.getX();
			int posY = player.getY();
			//Check move UP when is possible
			player.moveUp();
			Assert::AreEqual(posY, player.getY());
			
		}

	};
}