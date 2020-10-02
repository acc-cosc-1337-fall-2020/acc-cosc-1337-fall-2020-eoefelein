//write includes statements
#include <iostream>
#include "loops.h"
//write using statements for cin and cout
using namespace std;
// using std::cout; using std::cin;

/*
Use a do while loop to prompt the user for 
a number, call the factorial function, and display the number's
factorial.  Also, loop continues as long as user wants to.
*/
int main() 
{
	char choice;

	do{
		cout<<"Enter a number between 1 and 10: "<<endl;
		int num;
		cin>>num;
		cout<<"\n";

		while(!(num >=1 && num <=10))
		{
			cout<< "Number is invalid" << endl;

			cout<<"Enter a number between 1 and 10: ";
			cout<<"\n";
			cin>>num;

		}
		int result = factorial(num);
		cout << "Result=" << result << endl;

		// check to make sure this is how char var would get defined
		cout<<"\nEnter y if you wish to continue. Enter n to exit."<<endl;
		cin>>choice;
 
	}while(choice != 'n');
	
	return 0;
}