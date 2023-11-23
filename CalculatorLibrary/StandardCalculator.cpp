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
	return num1 + num2;
}

float StandardCalculator::Divide(float num1, float num2)
{
	return float();
}

float StandardCalculator::Subtract(float num1, float num2)
{
	return float();
}

void StandardCalculator::Clear()
{
	// Todo clear internal vars
}

