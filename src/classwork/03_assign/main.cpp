//Write the include statement for decision.h here
#include decision.h;

//Write namespace using statements for cout and cin
#include <iostream> 
using namespace std; 

int main() 
{
  int grade;
  cout<<"Enter the number grade, between 0 and 100, to be converted to a letter grade: ";
  cin>>grade;
  cout<<"\n";
  if(grade>=0)
  {
    cout<<"Converting"<<grade<<"using if_else is: "<<get_letter_grade_using_if(grade)<<"\n";
    cout<<"grade for"<<grade<<"using switch is"<<get_letter_grade_using_switch(grade)<<"\n";
  }
  else{
    cout<<"Number grade is out of specified range of 0-100"
  }
	return 0;
}

