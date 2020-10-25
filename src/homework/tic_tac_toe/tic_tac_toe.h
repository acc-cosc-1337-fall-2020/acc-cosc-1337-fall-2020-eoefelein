//header
#include <string>
#include <iostream>
#include <vector>

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
      // return next_player val
      string get_player() const { return next_player; };

    private:
      void set_next_player();
      bool check_board_full() const;
      void clear_board();
      string next_player;
      vector <string> slots{9, " "};

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