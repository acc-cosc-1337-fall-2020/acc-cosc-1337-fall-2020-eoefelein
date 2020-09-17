//write include statements
#include <iostream>
#include "variables.h"

//write namespace using statement for cin, cout
using namespace std;

/*
Call multiply_numbers with 10 and 10 parameter values and display function result
*/
int main()
{
	double meal_amount;
	double tip_rate;
	double tip_amount;
	double tax_amount;
	double total;

	cout << "Enter the meal amount: ";
	cin >> meal_amount;
	tax_amount = get_sales_tax_amount(meal_amount);

	cout << "Enter the tip rate: ";
	cin >> tip_rate;
	tip_amount = get_tip_amount(meal_amount, tip_rate);

	total = tip_amount + tax_amount + meal_amount;

	cout << "Meal Amount: 	" << meal_amount << endl;
	cout << "Sales Tax: 	" << tax_amount << endl;
	cout << "Tip: 		" << tip_rate << endl;
	cout << "Total: 		" << total;	
	return 0;
}
