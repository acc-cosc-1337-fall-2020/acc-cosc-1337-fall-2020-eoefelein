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
	char choice;
	string winner;

	do{

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
		}while (game.game_over() == false);

		if (game.get_winner() == "C")
		{
			cout<<"\nThe match is a Draw\n";
		}
		else
		{cout<<"\nThe Winner of the game is: "<<game.get_winner()<<"\n";}
		
		cout<<"\nIf you want to continue playing, enter Y or y.\n";
		cout<<"Otherwise, enter any key to exit.\n";
		cin>>choice;
	}while(choice == 'Y' || choice == 'y');
	
	cout<<"\nGame over!";
	return 0;
	
}