#include "pch.h"
#include "StandardCalculator.h"

using namespace CalculatorClasses;

namespace CalculatorTestSuite
{

	TEST(TestStandardCalculator, AddExpectedTrue) {

		StandardCalculator* calc = new StandardCalculator();


		EXPECT_EQ(calc->Add(1, 2), 3);
		EXPECT_TRUE(true);
	}


};
