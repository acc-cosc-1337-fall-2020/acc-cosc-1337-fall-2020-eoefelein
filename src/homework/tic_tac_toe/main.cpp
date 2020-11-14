#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"

#include <iostream>
#include <string>

using std::cout; 
using std::cin;
using std::string;
using std::unique_ptr;
using std::make_unique;

int main()
{
	unique_ptr<TicTacToe> game;
	int size;
	string first_player;
	char choice;
	
	TicTacToeManager manager;

	do
	{
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
	
	while(game->game_over() == false)
	{
		cin>>*game;
		cout<<*game;
	}

	if(game->get_winner() == "C")
	{
		cout<<"\nThe match is a Draw\n";
	}
	else
	{
		cout<<"\nThe Winner of the game is: "<<game->get_winner()<<"\n";
	}

	//  modify the TicTacToe manager save game function call to manager.save_game
	manager.save_game(game);
	cout<<manager;
	manager.get_winner_total();

	cout<<"\nIf you want to continue playing, enter Y or y.\n";
	cout<<"Otherwise, enter any key to exit.\n";
	cin>>choice;

	}while(choice == 'Y' || choice == 'y');

	cout<<"\nGame over!";
	return 0;
	
}