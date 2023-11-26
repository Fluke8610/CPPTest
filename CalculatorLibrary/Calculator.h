#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

/* Abstract class calculator
*  From this create Standard Calculator, Scientific etc.
* 
*  Abstract class through pure virtual functions, cannot instantiate.
*/

#include <string>
#include <vector>

using std::string;
using std::vector;

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
	virtual float Add(const int numAdditions, const vector<int> numbers) = 0;
	virtual float Subtract(const float num1, const float num2) = 0;
	virtual float Subtract(const int numSubtractions, const vector<int> numbers) = 0;
	virtual float Divide(const float num1, const float num2) = 0;
	virtual float Divide(const float numMultiplications, const vector<int> numbers) = 0;
	virtual float Multiply(const float num1, const float num2) = 0;
	virtual float Multiply(const int numMultiplications, const vector<int> numbers) = 0;

	virtual string AddInput(const string& input) = 0;

	virtual void onAddPressed() = 0;
	virtual void onSubtractPressed() = 0;
	virtual void onDivisionPressed() = 0;
	virtual void onMultiplicationPressed() = 0;
	virtual float onEqualsPressed() = 0;

	virtual void Clear() = 0;

	virtual bool GetInError() = 0;

	virtual void ParseInput() = 0;

protected:

	

private:

};



#endif // _CALCULATOR_H_
