#ifndef _STANDARDCALCULATOR_H_
#define _STANDARDCALCULATOR_H_

#include "Calculator.h"
#include <memory>

using std::string;

namespace CalculatorClasses
{
	class StandardCalculator : public Calculator
	{
	
	public:
	
		StandardCalculator();
		virtual ~StandardCalculator() override;
	
		virtual float Add(const float num1, const float num2) override;
		virtual float Add(const vector<int> numbers) override;
		virtual float Subtract(const float num1, const float num2) override;
		virtual float Subtract(const vector<int> numbers) override;
		virtual float Divide(const float num1, const float num2) override;
		virtual float Divide(const vector<int> numbers) override;
		virtual float Multiply(const float num1, const float num2) override;
		virtual float Multiply(const vector<int> numbers) override;

		virtual const string* AddInput(const string& input) override;

		virtual void onAddPressed() override;
		virtual void onSubtractPressed() override;
		virtual void onDivisionPressed() override;
		virtual void onMultiplicationPressed() override;
		virtual float onEqualsPressed() override;

		virtual void Clear() override;

		virtual bool GetInError() override;

		virtual void ParseInput() override;
	
	protected:
	
	
	private:
	
		string*		mInput		= nullptr;
		float		mTotal		= 0;
		bool		mIsInError	= false;
		
	};

};

#endif // _STANDARDCALCULATOR_H_
