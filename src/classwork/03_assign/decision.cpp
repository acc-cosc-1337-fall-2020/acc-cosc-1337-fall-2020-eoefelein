//cpp

//Write the include statement for decision.h
#include "decision.h"

//get_letter_grade_using_if
char get_letter_grade_using_if(int grade){
  if (grade < 60){
    return "F";
  } else if (grade <= 70){
    return "D";
  } else if (grade <= 80){
    return "C";
  } else if (grade <= 90){
    return "B";
  } else {
    return "A";
  }
}

//get_letter_grade_using_switch
char get_letter_grade_using_switch(int grade){
  int conversion=grade/10;
  char result;
  switch(conversion) {
    case 10:
      result='A';
      break;
    case 9:
      result='A';
      break;
    case 8:
      result='B';
      break;
    case 7:
      result='C';
      break;
    case 6:
      result='D';
      break;
    default:
      result='F';
      break;
  }
  return result;
}