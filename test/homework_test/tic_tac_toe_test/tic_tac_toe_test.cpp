#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify game ends when board is full") 
{	
	TicTacToe game;
	game.start_game("X");

	game.mark_board(1);

	REQUIRE(game.game_over() == false);
	game.mark_board(2);

	REQUIRE(game.game_over() == false);
	game.mark_board(3);

	REQUIRE(game.game_over() == false);
	game.mark_board(4);
	
	REQUIRE(game.game_over() == false);
	game.mark_board(5);

	REQUIRE(game.game_over() == false);
	game.mark_board(7);

	REQUIRE(game.game_over() == false);
	game.mark_board(6);

	REQUIRE(game.game_over() == false);
	game.mark_board(9);

	REQUIRE(game.game_over() == false);
	game.mark_board(8);

	REQUIRE(game.game_over() == true);

	REQUIRE(game.get_winner() == "C");
}

// First Column test case
TEST_CASE("Test win by first column: ")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(1);
	REQUIRE(game.game_over() == false);

	game.mark_board(2);
	REQUIRE(game.game_over() == false);

	game.mark_board(4);
	REQUIRE(game.game_over() == false);

	game.mark_board(5);
	REQUIRE(game.game_over() == false);

	game.mark_board(7);
	REQUIRE(game.game_over() == true);

	REQUIRE(game.get_winner() == "X");
}

//Second Column test case
TEST_CASE("Test win by second column: ")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(2);
	REQUIRE(game.game_over() == false);

	game.mark_board(1);
	REQUIRE(game.game_over() == false);

	game.mark_board(5);
	REQUIRE(game.game_over() == false);

	game.mark_board(4);
	REQUIRE(game.game_over() == false);

	game.mark_board(8);
	REQUIRE(game.game_over() == true);
	
	REQUIRE(game.get_winner() == "X");
}

//Third Column test case
TEST_CASE("Test win by third column: ")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(3);
	REQUIRE(game.game_over() == false);

	game.mark_board(2);
	REQUIRE(game.game_over() == false);

	game.mark_board(6);
	REQUIRE(game.game_over() == false);

	game.mark_board(4);
	REQUIRE(game.game_over() == false);

	game.mark_board(9);
	REQUIRE(game.game_over() == true);
	
	REQUIRE(game.get_winner() == "X");
}

//First Row test case
TEST_CASE("Test win by first row: ")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(1);
	REQUIRE(game.game_over() == false);

	game.mark_board(4);
	REQUIRE(game.game_over() == false);

	game.mark_board(2);
	REQUIRE(game.game_over() == false);

	game.mark_board(5);
	REQUIRE(game.game_over() == false);

	game.mark_board(3);
	REQUIRE(game.game_over() == true);
	
	REQUIRE(game.get_winner() == "X");
}

//Second Row test case
TEST_CASE("Test win by second row: ")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(4);
	REQUIRE(game.game_over() == false);

	game.mark_board(1);
	REQUIRE(game.game_over() == false);

	game.mark_board(5);
	REQUIRE(game.game_over() == false);

	game.mark_board(2);
	REQUIRE(game.game_over() == false);

	game.mark_board(6);
	REQUIRE(game.game_over() == true);
	
	REQUIRE(game.get_winner() == "X");
}

//Third Row test case
TEST_CASE("Test win by third row: ")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(7);
	REQUIRE(game.game_over() == false);

	game.mark_board(1);
	REQUIRE(game.game_over() == false);

	game.mark_board(8);
	REQUIRE(game.game_over() == false);

	game.mark_board(5);
	REQUIRE(game.game_over() == false);

	game.mark_board(9);
	REQUIRE(game.game_over() == true);

	REQUIRE(game.get_winner() == "X");
}

//Top Left Diagonal test case
TEST_CASE("Test win diagonally from top left: ")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(1);
	REQUIRE(game.game_over() == false);

	game.mark_board(4);
	REQUIRE(game.game_over() == false);

	game.mark_board(5);
	REQUIRE(game.game_over() == false);

	game.mark_board(6);
	REQUIRE(game.game_over() == false);

	game.mark_board(9);
	REQUIRE(game.game_over() == true);
	
	REQUIRE(game.get_winner() == "X");
}

//Bottom left diagonal test case
TEST_CASE("Test win diagonally from bottom left: ")
{
	TicTacToe game;
	game.start_game("X");

	game.mark_board(7);
	REQUIRE(game.game_over() == false);

	game.mark_board(4);
	REQUIRE(game.game_over() == false);

	game.mark_board(5);
	REQUIRE(game.game_over() == false);

	game.mark_board(6);
	REQUIRE(game.game_over() == false);

	game.mark_board(3);
	REQUIRE(game.game_over() == true);
	
	REQUIRE(game.get_winner() == "X");
}
