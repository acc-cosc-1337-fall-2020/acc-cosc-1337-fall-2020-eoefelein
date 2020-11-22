//h
#include "tic_tac_toe.h"
#include "tic_tac_toe_data.h"

// header guard
#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include <string>
#include <iostream>
#include <vector>
#include <memory>

using std::ostream;
using std::vector;
using std::unique_ptr;

class TicTacToeManager
{
    public:
        // Add constructor TicTacToeManager() = default;
        TicTacToeManager() = default;
        // Add a TicTacToeManager constructor with TicTacToeData reference param
        TicTacToeManager(TicTacToeData &data);
        // unique_ptr of TicTacToe reference
        void save_game(unique_ptr<TicTacToe> &game);
        friend ostream& operator << (std::ostream& output, const TicTacToeManager& m);
        void get_winner_total(int& x, int& o, int& t); //int& x, int& o, int& t
        // Create a TicTacToeManager destructor
        ~TicTacToeManager();
    private:
        // Add a TicTacToeData private variable name it data
        TicTacToeData data;
        // vector of reference wrapper TicTacToe
        vector<unique_ptr<TicTacToe>> games;
        void update_winner_count(string winner);
        int x_win = 0;
        int o_win = 0;
        int ties = 0;
};

#endif