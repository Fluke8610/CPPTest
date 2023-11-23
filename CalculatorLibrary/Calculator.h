#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

/* Abstract class calculator */
/* From this create Standard Calculator, Scientific etc.*/

class Calculator
{

public:

	Calculator() {};
	virtual ~Calculator() {};

	virtual float Add(float num1, float num2) = 0;
	virtual float Subtract(float num1, float num2) = 0;
	virtual float Divide(float num1, float num2) = 0;
	
	virtual void Clear() = 0;


protected:


private:



};



#endif // _CALCULATOR_H_
