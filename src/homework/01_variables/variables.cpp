#include "variables.h"

//example
int add_numbers(int num1, int num2)
{
	return num1 + num2;
}

//get_sales_tax_amount function
//function returns product of meal_amount and tax_rate
const double tax_rate = 0.0675;
double get_sales_tax_amount(double meal_amount)
{
	return tax_rate * meal_amount;
}

//get_sales_tax_amount function
//function returns prduct of meal_amount and tip_rate
double get_tip_amount(double meal_amount, double tip_rate)
{
	return meal_amount * tip_rate;
}
