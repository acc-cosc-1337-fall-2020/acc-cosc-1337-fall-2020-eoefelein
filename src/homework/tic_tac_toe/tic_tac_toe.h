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
      void display_board() const;
      string get_player() const { return next_player; };

      // new functions
      string get_winner () { return winner; }

    private:
      void set_next_player();
      bool check_board_full() const;
      void clear_board();
      // private variables
      string next_player;
      vector <string> slots{9, " "};
      string winner;

      // new functions
      bool check_column_win();
      bool check_row_win();
      bool check_diagonal_win();
      void set_winner();

};

class Error

{

public:

  //Constructor: initialized private variable message with function parameter msg

  Error(string msg) : message{ msg } {};

   

  //Returns the message private variable

  string get_message()const { return message; }


private:

  //Class member variable

  string message;

};

#endif