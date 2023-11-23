#ifndef _STANDARDCALCULATOR_H_
#define _STANDARDCALCULATOR_H_

#include "Calculator.h"
#include <memory>

using std::string;
using std::unique_ptr;

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

		virtual bool GetInError() override;

		virtual string* GetEquationDisplay() override;
		virtual string* GetCurrentTotalDisplay() override;

	
	protected:
	
		virtual void ConcatDisplay(const string& in) override;
	
	private:
	
		string* display = nullptr;
		float total = 0;
		
	};

};

#endif // _STANDARDCALCULATOR_H_
