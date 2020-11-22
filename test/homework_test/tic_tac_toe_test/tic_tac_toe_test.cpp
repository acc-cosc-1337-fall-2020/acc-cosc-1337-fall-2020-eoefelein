#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <functional>
#include <memory>
#include "../../../src/homework/tic_tac_toe/tic_tac_toe.h"
#include "../../../src/homework/tic_tac_toe/tic_tac_toe_3.h"
#include "../../../src/homework/tic_tac_toe/tic_tac_toe_4.h"
#include "../../../src/homework/tic_tac_toe/tic_tac_toe_manager.h"

using std::unique_ptr;
using std::make_unique;

TEST_CASE("Verify Test Configuration", "verification") 
{
	REQUIRE(true == true);
}

TEST_CASE("Test set first player to X3") 
{
    unique_ptr<TicTacToe> board{ new TicTacToe3() };
    board->start_game("X");

	REQUIRE(board->get_player() == "X");
}

TEST_CASE("Test set first player to O3") 
{
    unique_ptr<TicTacToe> board{ new TicTacToe3() };
    board->start_game("O");

    REQUIRE(board->get_player() == "O");
}

TEST_CASE("Test set first player to X4") 
{
    unique_ptr<TicTacToe> board{ new TicTacToe4() };
    board->start_game("X");

	REQUIRE(board->get_player() == "X");
}

TEST_CASE("Test set first player to O4") 
{
    unique_ptr<TicTacToe> board{ new TicTacToe4() };
    board->start_game("O");

    REQUIRE(board->get_player() == "O");
}

TEST_CASE("Verify start_game correctly sets first player to X3")
{
    unique_ptr<TicTacToe> board = make_unique<TicTacToe3>();
    board->start_game("X");
	REQUIRE(board->get_player() == "X");

    board->mark_board(4);
    REQUIRE(board->get_player() == "O");
}

TEST_CASE("Verify start_game correctly sets first player to X4")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    game->start_game("X");
	REQUIRE(game->get_player() == "X");

    game->mark_board(4);
    REQUIRE(game->get_player() == "O");
}

TEST_CASE("Verify start_game correctly sets first player to O3")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    game->start_game("O");
	string player = game->get_player();


    REQUIRE(game->get_player() == "O");
}

TEST_CASE("Verify start_game correctly sets first player to O4")
{
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
    game->start_game("O");
	string player = game->get_player();


    REQUIRE(game->get_player() == "O");
}

TEST_CASE("Test game over when board full. No Winner.") 
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToe3>();
	board->start_game("X");

	board->mark_board(1);
	REQUIRE(board->game_over() == false);

	board->mark_board(2);
	REQUIRE(board->game_over() == false);

	board->mark_board(3);
	REQUIRE(board->game_over() == false);

	board->mark_board(5);
	REQUIRE(board->game_over() == false);

	board->mark_board(4);
	REQUIRE(board->game_over() == false);

	board->mark_board(6);
	REQUIRE(board->game_over() == false);

	board->mark_board(8);
	REQUIRE(board->game_over() == false);

	board->mark_board(7);
	REQUIRE(board->game_over() == false);

	board->mark_board(9);
    
	REQUIRE(board->game_over() == true);
}

// First Column test case
TEST_CASE("3Test win by first column: ")
{
    unique_ptr<TicTacToe> board = make_unique<TicTacToe3>();
    board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(1);      
	REQUIRE(board->game_over() == false);
	board->mark_board(2);        
	REQUIRE(board->game_over() == false);
	board->mark_board(4);        
	REQUIRE(board->game_over() == false);
	board->mark_board(5);         
	REQUIRE(board->game_over() == false);
	board->mark_board(7);
	REQUIRE(board->game_over() == true);
}

TEST_CASE("4Test win by first column: ")
{
    unique_ptr<TicTacToe> board = make_unique<TicTacToe4>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(1);
	REQUIRE(board->game_over() == false);
	board->mark_board(2);
	REQUIRE(board->game_over() == false);
	board->mark_board(5);
	REQUIRE(board->game_over() == false);
	board->mark_board(6);
	REQUIRE(board->game_over() == false);
	board->mark_board(9);
	REQUIRE(board->game_over() == false);
	board->mark_board(3);
	REQUIRE(board->game_over() == false);
	board->mark_board(13);
	REQUIRE(board->game_over() == true);
}

//Second Column test case
TEST_CASE("3Test win by second column: ")
{
    unique_ptr<TicTacToe> board = make_unique<TicTacToe3>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(2);
	REQUIRE(board->game_over() == false);
	board->mark_board(1);
	REQUIRE(board->game_over() == false);
	board->mark_board(5);
	REQUIRE(board->game_over() == false);
	board->mark_board(9);
	REQUIRE(board->game_over() == false);
	board->mark_board(8);
	REQUIRE(board->game_over() == true);
}

TEST_CASE("4Test win by second column: ")
{
    unique_ptr<TicTacToe> board = make_unique<TicTacToe4>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(2);
	REQUIRE(board->game_over() == false);
	board->mark_board(1);
	REQUIRE(board->game_over() == false);
	board->mark_board(6);
	REQUIRE(board->game_over() == false);
	board->mark_board(9);
	REQUIRE(board->game_over() == false);
	board->mark_board(10);
	REQUIRE(board->game_over() == false);
	board->mark_board(5);
	REQUIRE(board->game_over() == false);
	board->mark_board(14);
	REQUIRE(board->game_over() == true);
}

//Third Column test case
TEST_CASE("3Test win by third column: ")
{
    unique_ptr<TicTacToe> board = make_unique<TicTacToe3>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(3);
	REQUIRE(board->game_over() == false);
	board->mark_board(1);
	REQUIRE(board->game_over() == false);
	board->mark_board(6);
	REQUIRE(board->game_over() == false);
	board->mark_board(4);
	REQUIRE(board->game_over() == false);
	board->mark_board(9);
	REQUIRE(board->game_over() == true);
}

TEST_CASE("4Test win by fourth column: ")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToe4>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(4);
	REQUIRE(board->game_over() == false);
	board->mark_board(1);
	REQUIRE(board->game_over() == false);
	board->mark_board(8);
	REQUIRE(board->game_over() == false);
	board->mark_board(3);
	REQUIRE(board->game_over() == false);
	board->mark_board(12);
	REQUIRE(board->game_over() == false);
	board->mark_board(2);
	REQUIRE(board->game_over() == false);
	board->mark_board(16);
	REQUIRE(board->game_over() == true);
}

//First Row test case
TEST_CASE("3Test win by first row: ")
{
    unique_ptr<TicTacToe> board = make_unique<TicTacToe3>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(1);
	REQUIRE(board->game_over() == false);
	board->mark_board(4);
	REQUIRE(board->game_over() == false);
	board->mark_board(2);
	REQUIRE(board->game_over() == false);
	board->mark_board(5);
	REQUIRE(board->game_over() == false);
	board->mark_board(3);
	REQUIRE(board->game_over() == true);
}

TEST_CASE("4Test win by first row: ")
{
    unique_ptr<TicTacToe> board = make_unique<TicTacToe4>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(1);
	REQUIRE(board->game_over() == false);
	board->mark_board(12);
	REQUIRE(board->game_over() == false);
	board->mark_board(2);
	REQUIRE(board->game_over() == false);
	board->mark_board(5);
	REQUIRE(board->game_over() == false);
	board->mark_board(3);
	REQUIRE(board->game_over() == false);
	board->mark_board(11);
	REQUIRE(board->game_over() == false);
	board->mark_board(4);
	REQUIRE(board->game_over() == true);
}

//Second Row test case
TEST_CASE("3Test win by second row: ")
{
    unique_ptr<TicTacToe> board = make_unique<TicTacToe3>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(1);
	REQUIRE(board->game_over() == false);
	board->mark_board(4);
	REQUIRE(board->game_over() == false);
	board->mark_board(2);
	REQUIRE(board->game_over() == false);
	board->mark_board(5);
	REQUIRE(board->game_over() == false);
	board->mark_board(3);
	REQUIRE(board->game_over() == true);
}

TEST_CASE("4Test win by second row: ")
{
    unique_ptr<TicTacToe> board = make_unique<TicTacToe4>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(5);
	REQUIRE(board->game_over() == false);
	board->mark_board(2);
	REQUIRE(board->game_over() == false);
	board->mark_board(6);
	REQUIRE(board->game_over() == false);
	board->mark_board(9);
	REQUIRE(board->game_over() == false);
	board->mark_board(7);
	REQUIRE(board->game_over() == false);
	board->mark_board(11);
	REQUIRE(board->game_over() == false);
	board->mark_board(8);
	REQUIRE(board->game_over() == true);
}

//Third Row test case
TEST_CASE("3Test win by third row: ")
{
    unique_ptr<TicTacToe> board = make_unique<TicTacToe3>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(7);
	REQUIRE(board->game_over() == false);
	board->mark_board(2);
	REQUIRE(board->game_over() == false);
	board->mark_board(8);
	REQUIRE(board->game_over() == false);
	board->mark_board(6);
	REQUIRE(board->game_over() == false);
	board->mark_board(9);
	REQUIRE(board->game_over() == true);
}

TEST_CASE("4Test win by third row: ")
{
    unique_ptr<TicTacToe> board = make_unique<TicTacToe4>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(9);
	REQUIRE(board->game_over() == false);
	board->mark_board(3);
	REQUIRE(board->game_over() == false);
	board->mark_board(10);
	REQUIRE(board->game_over() == false);
	board->mark_board(5);
	REQUIRE(board->game_over() == false);
	board->mark_board(11);
	REQUIRE(board->game_over() == false);
	board->mark_board(1);
	REQUIRE(board->game_over() == false);
	board->mark_board(12);
	REQUIRE(board->game_over() == true);
}

//Top Left Diagonal test case
TEST_CASE("3Test win diagonally from top left: ")
{
    unique_ptr<TicTacToe> board = make_unique<TicTacToe3>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(1);
	REQUIRE(board->game_over() == false);
	board->mark_board(2);
	REQUIRE(board->game_over() == false);
	board->mark_board(5);
	REQUIRE(board->game_over() == false);
	board->mark_board(6);
	REQUIRE(board->game_over() == false);
	board->mark_board(9);
	REQUIRE(board->game_over() == true);
}

TEST_CASE("4Test win diagonally from top left: ")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToe4>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(1);
	REQUIRE(board->game_over() == false);
	board->mark_board(2);
	REQUIRE(board->game_over() == false);
	board->mark_board(6);
	REQUIRE(board->game_over() == false);
	board->mark_board(9);
	REQUIRE(board->game_over() == false);
	board->mark_board(11);
	REQUIRE(board->game_over() == false);
	board->mark_board(3);
	REQUIRE(board->game_over() == false);
	board->mark_board(16);
	REQUIRE(board->game_over() == true);
}

//Bottom left diagonal test case
TEST_CASE("3Test win diagonally from top right: ")
{
    unique_ptr<TicTacToe> board = make_unique<TicTacToe3>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(7);
	REQUIRE(board->game_over() == false);
	board->mark_board(2);
	REQUIRE(board->game_over() == false);
	board->mark_board(5);
	REQUIRE(board->game_over() == false);
	board->mark_board(6);
	REQUIRE(board->game_over() == false);
	board->mark_board(3);
	REQUIRE(board->game_over() == true);
}

TEST_CASE("4Test win diagonally from top right: ")
{
	unique_ptr<TicTacToe> board = make_unique<TicTacToe4>();
	board->start_game("X");
	REQUIRE(board->game_over() == false);
	board->mark_board(13);
	REQUIRE(board->game_over() == false);
	board->mark_board(2);
	REQUIRE(board->game_over() == false);
	board->mark_board(10);
	REQUIRE(board->game_over() == false);
	board->mark_board(6);
	REQUIRE(board->game_over() == false);
	board->mark_board(7);
	REQUIRE(board->game_over() == false);
	board->mark_board(8);
	REQUIRE(board->game_over() == false);
	board->mark_board(4);
	REQUIRE(board->game_over() == true);
}