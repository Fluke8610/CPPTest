// TestApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "StandardCalculator.h"

using namespace CalculatorClasses;
using std::cout;
using std::endl;

int main()
{
    cout << "Hello World!\n";

    StandardCalculator* calc = new StandardCalculator();


    cout << "Calculating addition of 54.5 and 77.3!\n";
    cout << calc->Add(54.5, 77.3) << endl;

    calc->AddInput("324 + 400 - 600 * 2 / 3");
    float val = calc->onEqualsPressed();

    cout << val << endl;

    if (calc != nullptr)
    {
        delete calc;
        calc = nullptr;
    }

    return 0;
}

/*   
    TODO:  * TDD/BDD with calculator code.
           * Factory Pattern
           * Explore other patterns.


*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
