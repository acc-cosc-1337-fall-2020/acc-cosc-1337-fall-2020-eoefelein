//cpp
#include "tic_tac_toe.h"
#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

TicTacToe game;
// {

// }

// // return check_board_full function return value
bool TicTacToe::game_over()
{
    return check_board_full();
}

// // 1) Mark vector w position -1 equal to player & 2) Call set_next_player private function
void TicTacToe::mark_board(int position)
{
//   if (position > 9 && position < 1)
//   {
//     throw Error("\nPosition must be 1 to 9.");
//   }
//   else if (next_player == "")
//   {
//     throw Error("\nMust start game first.");
//   }
//   else 
//   {
    slots[position-1] = next_player;
//   }
  set_next_player();
}

// // 1) First_player function argument value must be X or O
// // 2) In function set next player(private variable) to first_player function argument. 
// // 3) Call the clear_board function    
void TicTacToe::start_game(string first_player)
{
    // 1) First_player function argument value must be X or O
    // if(first_player != "O" || first_player != "X")
    // {
    //     throw Error("Player must be X or O.");
    // }
    // // 2) In function set next player(private variable) to first_player function argument. 
    // else
    // {
        next_player = first_player;
    // }
    // 3) Call the clear_board function 
    clear_board();
}

// // Iterate vector of strings pegs to & Display a tic tac toe board in 3x 3 format
void TicTacToe::display_board() const
{
   for (std::size_t i = 0; i < slots.size(); i += 3) 
   {
      cout << " " << slots.at(i) << "  |  " << slots.at(i + 1) << "  |  " << slots.at(i + 2) << " " << endl;
    //   if (i < 6) 
    //   {
    //     cout << "--|--|--" << endl;
    //   }
   }
   cout << endl;

   return;
}
        
// Set player. If private variable player X player is O else player is X
void TicTacToe::set_next_player()
{
  if(next_player == "X")
  {
    next_player = "O";
  }
  else
  {
    next_player = "X";
  }
}

// // 1) return false if vector of strings pegs has available slot by checking for a “ “(space)in each element. 
// // Otherwise return true
bool TicTacToe::check_board_full()const
{
    for (auto slot: slots)
    {
        if(slot != "X" && slot != "O") 
        {
        return false;
        }
    }
   return true;
}

// // 1) Set all 9 elements to a “ “ (space)
void TicTacToe::clear_board()
{
    const bool CLEAR_SCREEN = true;
    {
    cout << endl;

    if (CLEAR_SCREEN) {
        cout << "\033c";
    }

    cout << endl;
    }
}