//header
#include <string>
#include <iostream>
#include <vector>

// header guard
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

using std::string;
using std::vector;

class TicTacToe
{
    public:
      bool game_over();
      void mark_board(int position);
      void start_game(string first_player);
      //void display_board() const;
      string get_player() const { return next_player; };

      // homework 7
      string get_winner () { return winner; }
      // friend functions
      friend std::ostream& operator << (std::ostream& output, const TicTacToe game);
      friend std::istream& operator >> (std::istream& input, TicTacToe &ngame);

    private:
      void set_next_player();
      bool check_board_full() const;
      void clear_board();

      // private variables
      string next_player;
      vector<string> slots{9, " "};
      string winner;

      // additional functionality
      bool check_column_win();
      bool check_row_win();
      bool check_diagonal_win();

      // homework 7
      void set_winner();
};

#endif