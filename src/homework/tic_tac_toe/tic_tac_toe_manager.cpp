#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_data.h"

using std::ostream;
using std::cout;

//cpp
void TicTacToeManager::save_game(unique_ptr<TicTacToe> &game)
{
    // make sure update_winner_count is the first statement
    update_winner_count(game->get_winner());
    // add the move statement to game variable
    games.push_back(std::move(game));
}

// write constructor code to initialize private games vector
TicTacToeManager::TicTacToeManager(TicTacToeData& d)
{
    // by calling TicTacToeData get_games function
	games = d.get_games();
    // Iterate the games vector
	for (auto& game : games)
	{
		// call update winner function, pass winner for each game
        update_winner_count(game->get_winner());
	}
}

// void TicTacToeManager::save_game(unique_ptr<TicTacToe>& game)
// {
// 	update_winner(game->get_winner());
// 	games.push_back(std::move(game));
// 	data.save_games(games);
	
// }

void TicTacToeManager::update_winner_count(string winner)
{
    //if winner X increment x_win
    if(winner == "X")
    {
        x_win ++;
    }
    //if winner O increment o_win
    else if(winner == "O")
    {
        o_win ++;
    }
    //and else increment ties
    else
    {
        ties ++;
    }
}

// friend void ostream& operator<<(std::ostream& out, const tic_tac_toe& m)
// {
//     for(int x:m.pegs)
//     {
//         cout<< m;
//     }
// }

ostream& operator << (ostream &output, const TicTacToeManager &m)
{
    for(auto &game: m.games)
    {
        cout<< *game << "\n";
        cout<<"Winner: "<<game->get_winner()<<"\n\n";
    }

    return output;
}

void TicTacToeManager::get_winner_total(int& x, int& o, int& t)
{
    x = x_win;
	o = o_win;
	t = ties;
    std::cout<<"Player X won "<<x_win<<" times, Player O won "<<o_win<<" times, and there were "<<ties<<" ties.\n";
}

// Create a TicTacToeManager destructor-to save games to file
TicTacToeManager::~TicTacToeManager()
{
	// call the data class function save games
    data.save_games(games);
}