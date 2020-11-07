#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

#include <iostream>
#include <string>

using std::cout; 
using std::cin;
using std::string;

int main()
{
	TicTacToe game;
	TicTacToeManager manager; 

	string first_player;
	char choice;
	string winner;

	do
	{

	cout<<"Hope you're ready to play some tictactoe! \nPlease enter the first player, \"X\" or \"O\": ";
	cin>>first_player;

	while (!(first_player == "X" || first_player == "O"))
		{
			cout<< "Invalid input. Please enter X or O: \n";
			cin>> first_player;
		}

	game.start_game(first_player);
	cout<<game;
	
	while(game.game_over() == false)
	{
		cin>>game;
		cout<<game;
	}

	if(game.get_winner() == "C")
	{
		cout<<"\nThe match is a Draw\n";
		cout<<game<<"\n";
	}
	else
	{
		cout<<"\nThe Winner of the game is: "<<game.get_winner()<<"\n";
		cout<<game<<"\n";
	}
		
	manager.save_game(game);
	manager.get_winner_total();

	cout<<"\nIf you want to continue playing, enter Y or y.\n";
	cout<<"Otherwise, enter any key to exit.\n";
	cin>>choice;

	}while(choice == 'Y' || choice == 'y');

	cout<<manager;

	cout<<"\nGame over!";
	return 0;
	
}