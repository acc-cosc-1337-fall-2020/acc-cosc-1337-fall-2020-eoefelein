#include "tic_tac_toe_manager.h"

using std::ostream;
using std::cout;

//cpp
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

ostream& operator << (ostream& output, const TicTacToeManager& m)
{
    for(auto& s: m.games)
    {
        output<<s;
        output<<"\n";
    }
    return output;
}

void TicTacToeManager::save_game(TicTacToe b)
{
    games.push_back(b);
    update_winner_count(b.get_winner());
}

void TicTacToeManager::get_winner_total()
{
    std::cout<<"Player X won "<<x_win<<" times, Player O won "<<o_win<<" times, and there were "<<ties<<" ties.\n";
}
