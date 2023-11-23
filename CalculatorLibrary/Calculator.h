#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

/* Abstract class calculator
*  From this create Standard Calculator, Scientific etc.
* 
*  Abstract class through pure virtual functions, cannot instantiate.
*/

#include <string>

using std::string;

class Calculator
{

public:

	Calculator() {};
	virtual ~Calculator() {};

	/*******************************************************************
	* Assume for initial values float gives us 
	* enough for large values 
	* min/max (1.175494351 E - 38, 3.402823466 E + 38).
	* For scientific calculator use double
	* min/max (2.2250738585072014 E - 308, 1.7976931348623158 E + 308)
	********************************************************************/
	virtual float Add(const float num1, const float num2) = 0;
	virtual float Subtract(const float num1, const float num2) = 0;
	virtual float Divide(const float num1, const float num2) = 0;

	virtual void Clear() = 0;

	virtual bool GetInError() = 0;

	virtual string* GetEquationDisplay() = 0;
	virtual string* GetCurrentTotalDisplay() = 0;

protected:

	/*******************************************************************
	* Concat display to allow for any UI to display the numerical entries.
	********************************************************************/
	virtual void ConcatDisplay(const string& in) = 0;

private:

};



#endif // _CALCULATOR_H_
