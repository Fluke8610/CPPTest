#include "pch.h"
#include "StandardCalculator.h"
#include <exception>
#include <iostream>
#include <memory>

using namespace CalculatorClasses;;

StandardCalculator::StandardCalculator()
{
	input = new string("");
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
		// TODO: log exception
		

		// Ensure program doesn't crash, in full application we would raise flag here to say we had an issue.
		return -1;
	}


}

float StandardCalculator::Add(const int numAdditions, const vector<int> numbers)
{
	return 0.0f;
}

float StandardCalculator::Divide(float num1, float num2)
{
	return float();
}

float StandardCalculator::Divide(const float numMultiplications, const vector<int> numbers)
{
	return 0.0f;
}

float StandardCalculator::Multiply(const float num1, const float num2)
{
	return 0.0f;
}

float StandardCalculator::Multiply(const int numMultiplications, const vector<int> numbers)
{
	return 0.0f;
}

string StandardCalculator::AddInput(const string& input)
{
	return string();
}

void StandardCalculator::onAddPressed()
{

}

void StandardCalculator::onSubtractPressed()
{

}

void StandardCalculator::onDivisionPressed()
{

}

void StandardCalculator::onMultiplicationPressed()
{

}

float StandardCalculator::onEqualsPressed()
{
	return 0.0f;
}

float StandardCalculator::Subtract(float num1, float num2)
{
	try 
	{
		return num1 - num2;
	}
	catch (const std::exception& e)
	{
		// TODO: log exception


		// Ensure program doesn't crash, in full application we would raise flag here to say we had an issue.
		return -1;
	}
}

float StandardCalculator::Subtract(const int numSubtractions, const vector<int> numbers)
{
	return 0.0f;
}

void StandardCalculator::Clear()
{
	// Todo clear internal vars
	total = 0;
	if (input != nullptr)
	{
		delete input;
		input = nullptr;
	}
}

bool StandardCalculator::GetInError()
{
	return false;
}

void StandardCalculator::ParseInput()
{

}

