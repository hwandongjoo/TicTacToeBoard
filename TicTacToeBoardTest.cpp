/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};


//EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, toggleTurn)
{
	TicTacToeBoard obj;
	Piece output = obj.toggleTurn();// X -> O
	ASSERT_EQ(output,'O');
	//ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, placePiece)
{
	TicTacToeBoard obj;
	Piece output = obj.placePiece(0,0);//put X
	ASSERT_EQ(output,'X');
	//ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, placePiece_toggle)
{
	TicTacToeBoard obj;
	obj.placePiece(0,0);//put X and toggle
	Piece output = obj.placePiece(0,1);//O
	ASSERT_EQ(output,'O');
	//ASSERT_TRUE(true);
}
TEST(TicTacToeBoardTest, placePiece_Already)
{
	TicTacToeBoard obj;
	obj.placePiece(0,0);//put X and toggle
	Piece output = obj.placePiece(0,0);//Already X exist
	ASSERT_EQ(output,'X');
	//ASSERT_TRUE(true);
}
TEST(TicTacToeBoardTest, placePiece_Out_Row)
{
	TicTacToeBoard obj;
	Piece output = obj.placePiece(3,1);
	ASSERT_EQ(output,'?');
	//ASSERT_TRUE(true);
}
TEST(TicTacToeBoardTest, placePiece_Out_Col)
{
	TicTacToeBoard obj;
	Piece output = obj.placePiece(1,3);
	ASSERT_EQ(output,'?');
	//ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, getPiece)
{
	TicTacToeBoard obj;
	obj.placePiece(1,1);
	Piece output = obj.getPiece(1,1);
	ASSERT_EQ(output,'X');
	//ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, getPiece_Blank)
{
	TicTacToeBoard obj;
	obj.placePiece(1,1);
	Piece output = obj.getPiece(2,1);
	ASSERT_EQ(output,' ');
	//ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, getPiece_Invalid)
{
	TicTacToeBoard obj;
	obj.placePiece(1,1);
	Piece output = obj.getPiece(3,1);
	ASSERT_EQ(output,'?');
	//ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, getWinner_Invalid)
{
	TicTacToeBoard obj;
	obj.placePiece(1,1);
	Piece output = obj.getWinner();
	ASSERT_EQ(output,'?');
	//ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, getWinner_Win_Row)
{
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	obj.placePiece(1,0);
	obj.placePiece(0,1);
	obj.placePiece(1,1);
	obj.placePiece(0,2);
	obj.placePiece(2,0);
	obj.placePiece(1,2);
	obj.placePiece(2,2);
	obj.placePiece(2,1);
    /*
    xxx
    00x
    0x0
    */
	Piece output = obj.getWinner();
	ASSERT_EQ(output,'X');
	//ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, getWinner_Win_Column)
{
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	obj.placePiece(0,1);
	obj.placePiece(1,0);
	obj.placePiece(0,2);
	obj.placePiece(2,0);
	obj.placePiece(1,1);
	obj.placePiece(1,2);
	obj.placePiece(2,2);
	obj.placePiece(2,1);
    /*
	x00
	x0x
	xx0
    */
	Piece output = obj.getWinner();
	ASSERT_EQ(output,'X');
	//ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, getWinner_Win_Diagonol_LtoR)
{
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	obj.placePiece(0,1);
	obj.placePiece(1,1);
	obj.placePiece(0,2);
	obj.placePiece(2,0);
	obj.placePiece(1,0);
	obj.placePiece(1,2);
	obj.placePiece(2,1);
	obj.placePiece(2,2);
    /*
    X00
    0XX
    X0X
    */
	Piece output = obj.getWinner();
	ASSERT_EQ(output,'X');
	//ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, getWinner_Win_Diagonol_RtoL)
{
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	obj.placePiece(0,1);
	obj.placePiece(1,1);
	obj.placePiece(1,0);
	obj.placePiece(2,0);
	obj.placePiece(2,1);
	obj.placePiece(1,2);
	obj.placePiece(2,2);
	obj.placePiece(0,2);
    /*
    X0X
    0XX
    X00
    */
	Piece output = obj.getWinner();
	ASSERT_EQ(output,'X');
	//ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, getWinner_None)
{
	TicTacToeBoard obj;
	obj.placePiece(1,1);
	obj.placePiece(0,0);
	obj.placePiece(0,2);
	obj.placePiece(2,0);
	obj.placePiece(1,0);
	obj.placePiece(1,2);
	obj.placePiece(0,1);
	obj.placePiece(2,1);
	obj.placePiece(2,2);
	/*
	0XX
	XX0
	00X
	*/
	Piece output = obj.getWinner();
	ASSERT_EQ(output,' ');
	//ASSERT_TRUE(true);
}