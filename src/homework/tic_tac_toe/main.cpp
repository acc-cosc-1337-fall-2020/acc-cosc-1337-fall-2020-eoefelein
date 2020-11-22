#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"

#include <iostream>
#include <string>
#include <functional>
#include <memory>

using std::cout; 
using std::cin;
using std::string;
using std::unique_ptr;
using std::make_unique;

int main()
{
	int size;
	string first_player;
	char choice;
	unique_ptr<TicTacToeManager> manager{ new TicTacToeManager() };
	
	// Create a  TicTacToeData data instance
	TicTacToeData data;
	// int x = 0;
	// int o = 0;
	// int tie = 0;

	do
	{
	unique_ptr<TicTacToe> game;
	// allow users to choose between a tic tac toe 3 or 4 game
	cout<<"Hope you're ready to play some tictactoe! \nPlease choose TicTacToe3 or TicTacToe4 (3 or 4): \n";
    cin >> size;

    // create an instance (make_unique) of TicTacToe3 or 4 
	if (size == 3) 
	{
		game = make_unique<TicTacToe3>();
    }
        
    if (size == 4) 
	{
		game = make_unique<TicTacToe4>();
    }

	cout<<"Great! Thanks for selcting your board size. Now please enter the first player, \"X\" or \"O\": ";
	cin>>first_player;

	while (!(first_player == "X" || first_player == "O"))
		{
			cout<< "Invalid input. Please enter X or O: \n";
			cin>> first_player;
		}

	game->start_game(first_player);
	cout<<*game;
	
	do
	{
		cin>>*game;
		cout<<*game;
	} while(game->game_over() == false);

	if(game->get_winner() == "C")
	{
		cout<<"\nThe match is a Draw\n";
	}
	else
	{
		cout<<"\nThe Winner of the game is: "<<game->get_winner()<<"\n";
	}

	//  modify the TicTacToe manager save game function call to manager.save_game
	manager -> save_game(game);

	cout<<"\nIf you want to continue playing, enter Y or y.\n";
	cout<<"Otherwise, enter any key to exit.\n";
	cin>>choice;

	}while(choice == 'Y' || choice == 'y');

	cout<<*manager;
	cout<<"\nGame over!";
	return 0;
	
}