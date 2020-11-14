//h

// header guard
#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include "tic_tac_toe.h"

using std::ostream;
using std::vector;
using std::unique_ptr;

class TicTacToeManager
{
    public:
        //TicTacToeManager() = default;
        // unique_ptr of TicTacToe reference
        void save_game(unique_ptr<TicTacToe> &game);
        friend ostream& operator << (std::ostream& output, const TicTacToeManager& m);
        void get_winner_total();
    private:
        // vector of reference wrapper TicTacToe
        vector<unique_ptr<TicTacToe> > games;
        int x_win = 0;
        int o_win = 0;
        int ties = 0;
        void update_winner_count(string winner);
};

#endif