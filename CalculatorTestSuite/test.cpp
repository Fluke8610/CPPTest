#include "pch.h"
#include "StandardCalculator.h"

using namespace CalculatorClasses;
using namespace testing;
using std::tuple;

namespace CalculatorTestSuite
{
	class StandardCalculatorTesting : public Test
	{

	protected:
		// Instantiate calculator
		StandardCalculator* calc;

		StandardCalculatorTesting() {}

		virtual ~StandardCalculatorTesting() { }

		/*******************************************
		* Setup the test environment.
		********************************************/
		virtual void SetUp()
		{
			calc = new StandardCalculator();
		}

		/*******************************************
		* Cleanup test environment.
		********************************************/
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

	TEST_F(StandardCalculatorTesting, AddExpectedEqualMultipleInteger)
	{
		EXPECT_EQ(calc->Add(vector<int> { 1, 8, 12, 26, 45, 7, -13 }), 86);
	}

	TEST_F(StandardCalculatorTesting, SubtractExpectedEqualInteger)
	{
		EXPECT_EQ(calc->Subtract(2, 1), 1);
	}

	TEST_F(StandardCalculatorTesting, SubtractExpectedEqualMultipleInteger)
	{
		EXPECT_EQ(calc->Subtract(vector<int> { 500, 25, 22, 16, 94, 16, 21, 25 }), 281);
	}

	TEST_F(StandardCalculatorTesting, DivideExpectedEqualInteger)
	{
		EXPECT_EQ(calc->Divide(10, 2), 5);
	}

	TEST_F(StandardCalculatorTesting, DivideExpectedEqualMultipleInteger)
	{
		EXPECT_NEAR(calc->Divide(vector<int> { 500, 2, 6, 3 }), 13.88, 0.01);
	}

	TEST_F(StandardCalculatorTesting, MultiplyExpectedEqualInteger)
	{
		EXPECT_EQ(calc->Multiply(7, 5), 35);
	}

	TEST_F(StandardCalculatorTesting, MultiplyExpectedEqualMultipleInteger)
	{
		EXPECT_EQ(calc->Multiply(vector<int> { 7, 13, 5, 2, 6 }), 5460);
	}

	TEST_F(StandardCalculatorTesting, ParseInputExpectedValueFromCalculator)
	{
		calc->AddInput("324 + 400 - 600 * 2 / 3");
		EXPECT_NEAR(calc->onEqualsPressed(), 82.66, 0.01);
	}

	/*************************************
	* TODO: Test Fixtures
	* 
	* The aim here was to try and make a more
	* mature test suite using parameterised 
	* test fixtures as well as standard test
	* fixtures.
	* 
	* Due to the nature of the NuGet googletest
	* plugin it seems it has a bug for parameterised 
	* testing that makes it unfeasible for usage.
	* 
	* Looking at a few sources it seems to be better
	* supported in other IDE's.
	**************************************/

};
