//header
#include <string>
#include <iostream>
#include <vector>

// header guard
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

using std::unique_ptr;
using std::make_unique;
using std::string;
using std::vector;
using std::cout;

class TicTacToe
{
    public:
      TicTacToe(vector<string> s, string win) : slots{s}, winner{win} {};
    // create a constructor with int param named size, 
    // use initializer list to initialize the vector to 9 or 16 elements
      TicTacToe(int size) : slots(size*size, " ") {};
      //TicTacToe(vector<string> s, string win) : slots{s}, winner{win} {};

      bool game_over();
      void mark_board(int position);
      void start_game(string first_player);
      string get_player() const;
      // homework 7
      string get_winner() { return winner; };
      vector<string> get_slots() const;
      // friend functions
      friend std::ostream& operator << (std::ostream& output, const TicTacToe& t);
      friend std::istream& operator >> (std::istream& input, TicTacToe& t);

    protected:
      // virtual functions
      virtual bool check_column_win() = 0;
      virtual bool check_row_win() = 0;
      virtual bool check_diagonal_win() = 0;
      string next_player;
      vector<string> slots;

    private:
      void set_winner();
      void set_next_player();
      bool check_board_full();
      // private variables
      string winner;

      void clear_board();
};

class Error
{
public: 
	Error(string msg) : message{ msg } {};
	string get_message();
private:
	string message;

};

#endif