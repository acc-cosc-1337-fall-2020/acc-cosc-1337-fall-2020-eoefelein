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

// 1) first_player function argument value must be X or O
// 2) in function set next player(private variable) to first_player function argument
// 3) call the clear_board function    
void TicTacToe::start_game(string first_player)
{
  // 3) Call the clear_board function 
  clear_board();
  next_player = first_player;
}

// 1) Mark vector w position -1 equal to player & 2) Call set_next_player private function
void TicTacToe::mark_board(int position)
{
  slots[position-1] = next_player;
  TicTacToe::set_next_player();
}
        
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
bool TicTacToe::check_board_full()
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
    for(auto slot : slots)
    {
        slot = " ";
    }
}

// sets winner
void TicTacToe::set_winner()
{
  if(next_player == "X")
  {
    winner = "O";
  }
  else if(next_player == "O")
  { 
    winner = "X"; 
  }
  else
  {
    winner = "tie";
  }
}

// checks colum win
bool TicTacToe::check_column_win()
{
  return false;
}

// checks row win
bool TicTacToe::check_row_win()
{
  return false;
}

// checks diagonal win
bool TicTacToe::check_diagonal_win()
{
    return false;
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

string TicTacToe::get_player() const
{
	return next_player;
}

vector<string> TicTacToe::get_slots() const
{
	return slots;
}

// Error Class
string Error::get_message()
{
	return message;
}

// this is going to return an ostream obj, because cout is an obj of type ostream
std::ostream& operator << (std::ostream& output, const TicTacToe &game) // also returning a TicTacToe obj
{
  output << "\n";

  // display board for TicTacToe3
  if (game.slots.size() == 9) 
  {
  for (std::size_t i = 0; i < 9; i += 3) 
  {
		output << game.slots[i] << " | " << game.slots[i + 1] << " | " << game.slots[i + 2] << "\n";
	}
  }

  // display board for TicTacToe4
    if (game.slots.size() == 16) 
    {
        for (std::size_t i=0; i < 16; i += 4)
        {
            cout << game.slots[i] << " | " << game.slots[i + 1] << " | " <<  game.slots[i + 2] << " | " <<  game.slots[i + 3] << "\n";
        }
    }
  cout << endl;
  
	return output;
}

// modify the overloaded stream functions to work with TicTacToe 3 or 4
std::istream& operator >> (std::istream& input, TicTacToe& game) // also returning a TicTacToe obj
{
    int position;

    cout<<"\n\nPlayer "<<game.get_player()<<", make your move!\n";
	  
    if(game.slots.size() == 9)
    {
      cout << "Choose an empty slot by entering a number between 1 & 9 (inclusive): ";
    }

    if(game.slots.size() == 16)
    {
      cout << "Choose an empty slot by entering a number between 1 & 16 (inclusive): ";
    }

    input>>position;
    game.mark_board(position);

    return input;
}