#include "pch.h"
#include "StandardCalculator.h"
#include <exception>
#include <iostream>
#include <memory>

using namespace CalculatorClasses;;

StandardCalculator::StandardCalculator()
{
	display = new string("");
}

StandardCalculator::~StandardCalculator()
{
	Clear();
}

float StandardCalculator::Add(float num1, float num2)
{
	try
	{
		string input = std::to_string(num1) + "+" + std::to_string(num2);
		ConcatDisplay(input);

		return num1 + num2;

	}
	catch (const std::exception& e)
	{
		// TODO: log exception
		

		// Ensure program doesn't crash, in full application we would raise flag here to say we had an issue.
		return -1;
	}


}

float StandardCalculator::Divide(float num1, float num2)
{
	return float();
}

void StandardCalculator::ConcatDisplay(const string& in)
{
	if (display != nullptr)
	{
		display->append(in);
	}
}

float StandardCalculator::Subtract(float num1, float num2)
{
	try 
	{
		ConcatDisplay(std::to_string(num1) + "-" + std::to_string(num2));

		return num1 - num2;
	}
	catch (const std::exception& e)
	{
		// TODO: log exception


		// Ensure program doesn't crash, in full application we would raise flag here to say we had an issue.
		return -1;
	}
}

void StandardCalculator::Clear()
{
	// Todo clear internal vars
}

bool StandardCalculator::GetInError()
{
	return false;
}

string* StandardCalculator::GetCurrentTotalDisplay()
{
	string* currentTotal = new string(std::to_string(total));
	return currentTotal;
}

/*******************************************
* Return 
********************************************/
string* StandardCalculator::GetEquationDisplay()
{
	if (display != nullptr)
	{
		return display;
	}
	else
	{
		display = new string("");
		return display;
	}
}

