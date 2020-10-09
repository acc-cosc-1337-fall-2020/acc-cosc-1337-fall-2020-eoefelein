//write include statements
#include "dna.h"
#include<string>
#include<iostream>

//write using statements
using std::string; using std::cout; using std::cin;

/*
Write code that prompts user to enter 1 for Get GC Content, 
or 2 for Get DNA Complement.  The program will prompt user for a 
DNA string and call either get gc content or get dna complement
function and display the result. Program runs as long as 
user enters a y or Y.
*/
int main() 
{
	string dummy = "";

	do {
	
	string DNA;
	cout<<"Enter your DNA string in capital letters: "<<"\n";
	cin>>DNA;

	int choice;
	cout<<"Enter 1 to get DNA GC Content. Enter 2 to get DNA Complement."<<"\n";
	cin>>choice;

	if (choice == 1)
	{
		cout<<get_gc_content(DNA)<<"\n";
		cout<<"Would you like to input another DNA String? Enter \"y\" or \"Y\" for yes, or any other key to exit the program."<<std::endl;
		cin>>dummy;
	}
	else if (choice == 2)
	{
		cout<<get_dna_complement(DNA)<<"\n";
		cout<<"Would you like to input another DNA String? Enter \"y\" or \"Y\" for yes, or any other key to exit the program."<<std::endl;
		cin>>dummy;
	}
	else 
	{
		cout<<"Sorry! Number is invalid. Please enter either a 1 or a 2."<<std::endl;
		cout<<"Would you like to input another DNA String? Enter \"y\" or \"Y\" for yes, or any other key to exit the program."<<std::endl;
		cin>>dummy;
	}
	} while (dummy == "y" || dummy == "Y");
	
	return 0;
}