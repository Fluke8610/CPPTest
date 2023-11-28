# Introduction
### About Me
Hello, my name is Chris and I am a Software Engineer with a degree from Staffordshire University 
and 9 - 10 years of programming experience in multiple programming languages.  
I have worked in multiple industries such as: 
- Avionic Simulation and Aviation.
- Medical Devices.
- Betting software.

### This Repository
I have created this repository to showcase my skills and understanding of some programming concepts
that I have used in my day to day work and to try and build up a small portfolio.  
This is a test branch to demonstrate gained knowledge in programming practices and ability.  
The calculator concept was chosen as this has the ability to provide some Abstraction, Interfaces,
Unit Tests, Test Drivers and a GUI implementation.  

### Environment and Tools

> [!NOTE]  
> The following headings comprise an index of the project, this project was created using <b>Visual Studio
> 2022 Community Edition</b> and the <b>QT VS Tools Extension</b> with the Windows platform as the intended target.  
> To be able to build the solution you will need a QT build, I have downloaded 6.4.2 and you will need to
> install Desktop development with C++ in the Visual Studio installer if you are using Visual Studio.  

> [!IMPORTANT]
> The project currently does not have any CMake or Makefile associated with it to allow for building in VS Code.

# CPPTest
##### Solution Folder
This folder contains 4 projects, the sub headings below describe the individual projects themselves.  
The intention of this is to keep all project files in one place allowing for easier setup of the build environment.

## CalculatorLibrary
##### Project
This project is a C++ Class Library that defines the classes for the different types of calculator derived from the
abstract base class.

##### Files
Contains: 
- Abstract class Calculator
  - <b><i>Calculator.h</i></b>
- Concrete class Standard calculator.
  - <b>StandardCalculator.h</b>
  - <b>StandardCalculator.cpp</b> 

##### Future tasks
I plan to improve this project incrementally, planning future tasks for implementation of new features is necessary
to keep improving the portfolio and the calculator.  
I plan to implement the following:
- Implement Scientific Calculator.
- Implement Programmers Calculator.
- Implement factory class and methods for creating new Calculator Instances.

## CalculatorTestSuite
##### Project
This is a C++ Unit Test project that is intended to verify calculator behaviour using unit tests.  
The project utilises <b>Google Test</b> to provide a Unit Testing framework.

##### Current State
This project currently defines 8 Unit tests for the Calculator Library.
The Tests are grouped under the test suite name <b>StandardCalculatorTesting</b>  
The following tests are defined:
- <b>AddExpectedEqualInteger</b>
- <b>AddExpectedEqualMultipleInteger</b>
- <b>SubtractExpectedEqualInteger</b>
- <b>SubtractExpectedEqualMultipleInteger</b>
- <b>DivideExpectedEqualInteger</b>
- <b>DivideExpectedEqualMultipleInteger</b>
- <b>MultiplyExpectedEqualInteger</b>
- <b>MultiplyExpectedEqualMultipleInteger</b>
- <b>ParseInputExpectedValueFromCalculator</b>

##### Files
Contains:
- <b>test.cpp</b>

##### Future Tasks
I plan to improve this project incrementally, the intention is to utilise TDD and BDD to define
the Library functionality through the addition of tests.
- Implement further tests for the test suite (Mix of TDD and BDD for Scientific and Programmer Calculators).
- Utilise mocking of the Calculator instances.
- Calculate code coverage for the solution.

## TestApp
##### Project
This project is a standard C++ console used for testing the CalculatorLibrary in the console.

##### Files
Contains:
- <b>TestApp.cpp</b>

### Future Tasks
As the StandardCalculator library functions are improved, this will be used to test creation of instances
of the calculators, perform some basic testing of the calculator such as processing a series of inputs.
- Implement further test functionality of the CalculatorLibrary Classes.

## CalculatorGUI
##### Project
This project provides a user interface for the class library.  
It uses the QT Widgets framework to render the UI and uses the Calculator library to calculate values input.

##### Files
- CalculatorGUI
  - <b>CalculatorGUI.cpp</b>
  - <b>CalculatorGUI.h</b>
- <b>main.cpp</b>  

##### Future Tasks
I plan to improve this project incrementally, additional tweaks of the user interface will be added to this.  
I plan for the following tasks to be done:
- Add interfaces for Scientfic Calculator and Programmer Calculator.
- Implement GUI using QML replacing widgets.
