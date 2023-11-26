#include "pch.h"
#include "StandardCalculator.h"

using namespace CalculatorClasses;
using namespace testing;

namespace CalculatorTestSuite
{

	class StandardCalculatorTesting : public Test
	{

	protected:
		// Instantiate calculator
		StandardCalculator* calc;

		StandardCalculatorTesting() {}

		virtual ~StandardCalculatorTesting() { }

		virtual void SetUp()
		{
			calc = new StandardCalculator();
		}

		virtual void TearDown()
		{
			if (calc != nullptr)
			{
				delete calc;
				calc = nullptr;
			}
		}
	};


	TEST_F(StandardCalculatorTesting, AddExpectedEqualInteger) 
	{
		EXPECT_EQ(calc->Add(1, 2), 3);
	}

	TEST_F(StandardCalculatorTesting, SubtractExpectedEqualInteger)
	{
		EXPECT_EQ(calc->Subtract(2, 1), 1);
	}

	TEST_F(StandardCalculatorTesting, DivideExpectedEqualInteger)
	{
		EXPECT_EQ(calc->Divide(10, 2), 5);
	}
};
