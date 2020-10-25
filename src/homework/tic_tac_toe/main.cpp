#include "tic_tac_toe.h"
#include <iostream>
#include <string>

using std::cout; 
using std::cin;
using std::string;

int main()
{
	TicTacToe game;
	string first_player;

	cout<<"Hope you're ready to play some tictactoe! \nPlease enter first player, \"X\" or \"O\": ";
	cin>>first_player;

	game.start_game(first_player);
	
	do
	{
		cout<<"Enter a number from 1-9 to make your move: ";
		int position;
		cin>>position;
		
		game.mark_board(position);
		game.display_board();
	} while(game.game_over() == false);
	
	cout<<"Game over!";
	return 0;
	
}