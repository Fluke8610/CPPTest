#include "pch.h"
#include "StandardCalculator.h"
#include <exception>
#include <iostream>
#include <memory>
#include <sstream>

using namespace CalculatorClasses;
using std::stringstream;
using std::getline;

StandardCalculator::StandardCalculator()
{
	mInput = new string("");
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

float StandardCalculator::Add(const vector<int> numbers)
{
	
	for (int num : numbers)
	{
		if (mTotal == 0)
		{
			mTotal = num;
		}
		else
		{
			mTotal += num;
		}
	}

	return mTotal;
}

float StandardCalculator::Divide(float num1, float num2)
{
	try
	{
		return num1 / num2;
	}
	catch (const std::exception&)
	{
		// TODO: Introduce error enumeration (BYTE) for calculation errors e.g. Divide by 0.
	}

	return 0;
	
}

float StandardCalculator::Divide(const vector<int> numbers)
{
	for (int num : numbers)
	{
		if (mTotal == 0)
		{
			mTotal = num;
		}
		else
		{
			mTotal /= num;
		}
	}

	return mTotal;
}

float StandardCalculator::Multiply(const float num1, const float num2)
{
	return num1 * num2;
}

float StandardCalculator::Multiply(const vector<int> numbers)
{

	for(int num : numbers)
	{
		if (mTotal == 0)
		{
			mTotal = num;
		}
		else
		{
			mTotal = mTotal * num;
		}
	}

	return mTotal;
}

const string* StandardCalculator::AddInput(const string& input)
{
	if (mInput == nullptr)
	{
		mInput = new string(input);
	}
	else
	{
		mInput->append(input);
	}

	return mInput;
}

void StandardCalculator::onAddPressed()
{
	mInput->append(" + ");
}

void StandardCalculator::onSubtractPressed()
{
	mInput->append(" - ");
}

void StandardCalculator::onDivisionPressed()
{
	mInput->append(" / ");
}

void StandardCalculator::onMultiplicationPressed()
{
	mInput->append(" * ");
}

float StandardCalculator::onEqualsPressed()
{
	ParseInput();

	return mTotal;
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

float StandardCalculator::Subtract(const vector<int> numbers)
{
	for (int num : numbers)
	{
		if (mTotal == 0)
		{
			mTotal = num;
		}
		else
		{
			mTotal -= num;
		}
	}

	return mTotal;
}

void StandardCalculator::Clear()
{
	// Todo clear internal vars
	mTotal = 0;

	if (mInput != nullptr)
	{
		delete mInput;
		mInput = nullptr;
	}


}

bool StandardCalculator::GetInError()
{
	return false;
}

void StandardCalculator::ParseInput()
{
	if (mInput->empty() == true)
	{
		return;
	}

	vector<string> tokens;
	string substr;
	
	string copyString = *mInput;
	stringstream stream(copyString);

	while (getline(stream, substr, ' '))
	{
		tokens.push_back(substr);
	}

	float previousValue = 0.0f;
	float value = 0.0f;
	bool previousTokenPlus = false;
	bool previousTokenMinus = false;
	bool previousTokenDivde = false;
	bool previousTokenTimes = false;

	for (string token : tokens)
	{
		if (token == "+")
		{
			previousTokenPlus = true;
		}
		else if (token == "-")
		{
			previousTokenMinus = true;
		}
		else if (token == "*")
		{
			previousTokenTimes = true;
		}
		else if (token == "/")
		{
			previousTokenDivde = true;
		}
		else
		{
			size_t found = token.find('.');
			if (found == string::npos)
			{
				try
				{
					value = stoi(token);
				}
				catch (const std::exception&)
				{
					// TODO: raise error flag
				}
			}
			else
			{
				try
				{
					value = stof(token);
				}
				catch (const std::exception&)
				{
					// TODO: raise error flag
				}
			}

			if (previousTokenPlus)
			{
				mTotal += value;
				previousTokenPlus = false;
			}
			else if (previousTokenMinus)
			{
				mTotal -= value;
				previousTokenMinus = false;
			}
			else if (previousTokenDivde)
			{
				mTotal /= value;
				previousTokenDivde = false;
			}
			else if (previousTokenTimes)
			{
				mTotal *= value;
				previousTokenTimes = false;
			}
			else
			{
				previousTokenPlus = false;
				previousTokenMinus = false;
				previousTokenDivde = false;
				previousTokenTimes = false;

				mTotal = value;
			}
		}
	}
}

