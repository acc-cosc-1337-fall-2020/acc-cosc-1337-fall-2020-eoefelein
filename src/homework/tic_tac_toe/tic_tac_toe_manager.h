//h
#include <string>
#include <iostream>
#include <vector>

#include "tic_tac_toe.h"

// header guard
#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

using std::ostream;
using std::vector;

class TicTacToeManager
{
    public:
        void save_game(const TicTacToe b);
        friend ostream& operator << (std::ostream& output, const TicTacToeManager& m);
        void get_winner_total();
    private:
        vector <TicTacToe> games{};
        int x_win = 0;
        int o_win = 0;
        int ties = 0;
        void update_winner_count(string winner);
};

#endif