#include "tic_tac_toe_4.h"

/*
class function check_column_win
Win by column if and return true if (each column index)
0, 1,  2,  3 
4, 5,  6,  7 
8, 9, 10, 11 
12,13,14, 15 
else
false
*/
bool TicTacToe4::check_column_win()
{
    if ((slots[0] == "X" && slots[4] == "X" && slots[8] == "X" && slots[12] == "X")  || (slots[0] == "O" && slots[4] == "O" && slots[8] == "O" && slots[12] == "O")) 
    {
        return true;
    }
    
    else if ((slots[1] == "X" && slots[5] == "X" && slots[9] == "X" && slots[13] == "X")  || (slots[1] == "O" && slots[5] == "O" && slots[9] == "O" && slots[13] == "0")) 
    {
        return true;
    }
    
    else if ((slots[2] == "X" && slots[6] == "X" && slots[10] == "X" && slots[14] == "X")  || (slots[2] == "O" && slots[6] == "O" && slots[10] == "O" && slots[14] == "0")) 
    {
        return true;
    }
    
    else if ((slots[3] == "X" && slots[7] == "X" && slots[11] == "X" && slots[15] == "X")  || (slots[3] == "O" && slots[7] == "O" && slots[11] == "O" && slots[15] == "0")) 
    {
        return true;
    }
    return false;
}



/*
class function check_row_win
Win by row if
0, 1,  2,  3 are equal
4, 5,  6,  7 are equal
8, 9, 10, 11 are equal 
12,13,14, 15 are equal
*/
bool TicTacToe4::check_row_win() 
{
    if ((slots[0] == "X" && slots[1] == "X" && slots[2] == "X" && slots[3] == "X")  || (slots[0] == "O" && slots[1] == "O" && slots[2] == "O" && slots[3] == "O")) 
    {
        return true;
    }
    
    else if ((slots[4] == "X" && slots[5] == "X" && slots[6] == "X" && slots[7] == "X")  || (slots[4] == "O" && slots[5] == "O" && slots[6] == "O" && slots[7] == "O")) 
    {
        return true;
    }
    
    else if ((slots[8] == "X" && slots[9] == "X" && slots[10] == "X" && slots[11] == "X")  || (slots[8] == "O" && slots[9] == "O" && slots[10] == "O" && slots[11] == "O")) 
    {
        return true;
    }
    
    else if ((slots[12] == "X" && slots[13] == "X" && slots[14] == "X" && slots[15] == "X")  || (slots[12] == "O" && slots[13] == "O" && slots[14] == "O" && slots[15] == "O")) 
    {
        return true;
    }

    return false;
}


/*
class function check_diagonal_win
Win diagonally
0, 1,  2,  3
4, 5,  6,  7
8, 9, 10, 11
12,13,14, 15

*/
bool TicTacToe4::check_diagonal_win() 
{
    if ((slots[0] == "X" && slots[5] == "X" && slots[10] == "X" && slots[15] == "X")   || (slots[0] == "O" && slots[5] == "O" && slots[10] == "O" && slots[15] == "O")) 
    {
        return true;
    }
     
    else if ((slots[3] == "X" && slots[6] == "X" && slots[9] == "X"  && slots[12] == "X")  || (slots[3] == "O" && slots[6] == "O" && slots[9] == "O"  && slots[15] == "O")) 
    {
        return true;
    }

    return false;
}