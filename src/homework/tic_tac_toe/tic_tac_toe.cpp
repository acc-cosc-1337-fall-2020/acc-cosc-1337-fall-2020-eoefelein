//cpp
#include "tic_tac_toe.h"
#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::ostream;
using std::cin;
using std::istream;
using std::endl;

TicTacToe game;

// 1) Mark vector w position -1 equal to player & 2) Call set_next_player private function
void TicTacToe::mark_board(int position)
{
  slots[position-1] = next_player;
  TicTacToe::set_next_player();
}

// 1) first_player function argument value must be X or O
// 2) in function set next player(private variable) to first_player function argument
// 3) call the clear_board function    
void TicTacToe::start_game(string first_player)
{
    next_player = first_player;
    // 3) Call the clear_board function 
    clear_board();
}

// iterate vector of strings slots to display tic tac toe board
/*
void TicTacToe::display_board() const
{
   for (std::size_t i = 0; i < slots.size(); i += 3) 
   {
      cout << " " << slots.at(i) << "  |  " << slots.at(i + 1) << "  |  " << slots.at(i + 2) << " " << endl;
   }
   cout << endl;

   return;
}
*/
        
// set player. if private variable player X player is O else player is X
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

// 1) return false if vector of string slots has available slot by checking for a space
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

// 1) set all 9 elements to a space
void TicTacToe::clear_board()
{
    for(std::size_t i=0; i < slots.size(); i++)
    {
        slots[i] = " ";
    }
}

// determines game over
bool TicTacToe::game_over()
{   
    if(check_column_win()||check_row_win()||check_diagonal_win()) 
    {
        set_winner();
        return true;
    }
    else if(check_board_full())
    {
        winner = "C";
        return true;
    }
    else
    {
        return false;
    }
}

// checks colum win
bool TicTacToe::check_column_win()
{
  for(std::size_t i = 0; i < 3; ++ i)
  if((slots[i] == slots[i+3] && slots[i+3] == slots[i+6]) && (slots[i] != " "))
  {
    return true;
  }
  return false;
}

// checks row win
bool TicTacToe::check_row_win()
{
  for(std::size_t i = 0; i < 7; i += 3)
  if((slots[i] == slots[i+1] && slots[i+1] == slots[i+2]) && (slots[i] != " "))
  {
    return true;
  }
  return false;
}

// checks diagonal win
bool TicTacToe::check_diagonal_win()
{
    if(slots[0] == slots[4] && slots[4] == slots[8])
    {
        if(slots[4] != " ")
        {
            return true;
        }
    }
    else if(slots[2] == slots[4] && slots[4] == slots[6])
    {
       if(slots[4] != " ")
        {
            return true;
        }
    }
    return false;
}

// sets winner
void TicTacToe::set_winner()
{
  if(next_player == "X")
  {
    winner = "O";
  }
  else
  { 
    winner = "X"; 
  }
}

std::istream& operator >> (std::istream& input, TicTacToe& game) // also returning a TicTacToe obj
{
    int position;

    cout<<"\n\nPlayer "<<game.get_player()<<", make your move! Choose an empty slot by entering a number between 1 & 9:\n";
	  input>>position;
	  while(position < 1 || position > 9)
    {
		cout<<"\nYour entry is invalid. Please choose an empty slot by entering a number between 1 & 9: \n";
		input>>position;
    }
    
    game.mark_board(position);

    return input;
}

// this is going to return an ostream obj, because cout is an obj of type ostream
std::ostream& operator << (std::ostream& output, const TicTacToe game) // also returning a TicTacToe obj
{
  for (std::size_t i = 0; i < game.slots.size(); i += 3) 
  {
    output << " " << game.slots.at(i) << "  |  " << game.slots.at(i + 1) << "  |  " << game.slots.at(i + 2) << " " << endl;
  }
  cout << endl;

  return output;
}

