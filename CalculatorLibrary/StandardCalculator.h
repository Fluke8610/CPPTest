#ifndef _STANDARDCALCULATOR_H_
#define _STANDARDCALCULATOR_H_

#include "Calculator.h"

using std::string;

namespace CalculatorClasses
{
	class StandardCalculator : public Calculator
	{
	
	public:
	
		StandardCalculator();
		virtual ~StandardCalculator() override;
	
		virtual float Add(const float num1, const float num2) override;
		virtual float Subtract(const float num1, const float num2) override;
		virtual float Divide(const float num1, const float num2) override;

		virtual void Clear() override;
	
	protected:
	
		virtual void ConcatDisplay(const string& in, string& out) override;
		
	
	private:
	
		string* display = nullptr;
		double total = 0;
		
	};

};

#endif // _STANDARDCALCULATOR_H_
