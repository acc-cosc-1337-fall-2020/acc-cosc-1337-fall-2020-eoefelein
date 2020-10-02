//cpp

//Write the include statement for loops.h
#include "loops.h"

//factorial
int factorial(int num){
    int total=1;
    int factorial=1;

    while(factorial<num+1){
        total=total*factorial;
        factorial++;
    }
    return total;
}