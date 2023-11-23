#ifndef _STANDARDCALCULATOR_H_
#define _STANDARDCALCULATOR_H_

#include "Calculator.h"

//#include <map>
//#include <vector>
namespace CalculatorClasses
{



	class StandardCalculator : public Calculator
	{
	
	public:
	
		StandardCalculator();
		virtual ~StandardCalculator() override;
	
		virtual float Add(float num1, float num2) override;
		virtual float Subtract(float num1, float num2) override;
		virtual float Divide(float num1, float num2) override;
	
		virtual void Clear() override;
	
	protected:
	
	
	
	
	private:
	
		
	};

};

#endif // _STANDARDCALCULATOR_H_
