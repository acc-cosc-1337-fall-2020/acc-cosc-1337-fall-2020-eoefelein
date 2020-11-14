#include "tic_tac_toe_3.h"

/*
class function check_column_win
Win by column if and return true if
0,3, and 6 are equal
1, 4, and 7
2, 5, and 8
else
false
*/

// checks colum win
bool TicTacToe3::check_column_win()
{
    if ((slots[0] == "X" && slots[3] == "X" && slots[6] == "X")  || (slots[0] == "O" && slots[3] == "O" && slots[6] == "O"))
    {
        return true;
    }
    
    else if ((slots[1] == "X" && slots[4] == "X" && slots[7] == "X")  || (slots[1] == "O" && slots[4] == "O" && slots[7] == "O"))
    {
        return true;
    }
    
    else if ((slots[2] == "X" && slots[5] == "X" && slots[8] == "X")  || (slots[2] == "O" && slots[5] == "O" && slots[8] == "O"))
    {
        return true;
    }
    else
    {
        return false;
    }
}


/*
class function check_row_win
Win by row if
0, 1, 2 are equal
3,4,5 are equal
6,7,8 are equal
*/

// checks row win
bool TicTacToe3::check_row_win()
{
    if ((slots[0] == "X" && slots[1] == "X" && slots[2] == "X")  || (slots[0] == "O" && slots[1] == "O" && slots[2] == "O")) 
    {
        return true;
    }
    
    else if ((slots[3] == "X" && slots[4] == "X" && slots[5] == "X")  || (slots[3] == "O" && slots[4] == "O" && slots[5] == "O")) 
    {
        return true;
    }
    
    else if ((slots[6] == "X" && slots[7] == "X" && slots[8] == "X")  || (slots[2] == "O" && slots[6] == "O" && slots[7] == "O")) 
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
class function check_diagonal_win
Win diagonally
0 1 2
3 4 5
6 7 8

*/

// checks diagonal win
bool TicTacToe3::check_diagonal_win()
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