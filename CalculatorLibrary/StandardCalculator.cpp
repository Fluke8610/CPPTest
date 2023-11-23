#include "pch.h"
#include "StandardCalculator.h"
#include <exception>

using namespace CalculatorClasses;

StandardCalculator::StandardCalculator()
{

}

StandardCalculator::~StandardCalculator()
{

	Clear();
}

float StandardCalculator::Add(float num1, float num2)
{
	try
	{
		return num1 + num2;
	}
	catch (const std::exception& e)
	{
		// Ensure program doesn't crash, in full application we would raise flag here to say we had an issue.
		return -1;
	}
}

float StandardCalculator::Divide(float num1, float num2)
{
	return float();
}

void CalculatorClasses::StandardCalculator::ConcatDisplay(const string& in, string& out)
{
	
}

float StandardCalculator::Subtract(float num1, float num2)
{
	try 
	{
		return num1 - num2;
	}
	catch (const std::exception& e)
	{
		// Ensure program doesn't crash, in full application we would raise flag here to say we had an issue.
		return -1;
	}
}

void StandardCalculator::Clear()
{
	// Todo clear internal vars
}

