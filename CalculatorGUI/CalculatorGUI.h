#pragma once

#include <QtWidgets/QMainWindow>

#include "StandardCalculator.h"

/************************************
* Forward declare classes so that we 
* don't need to add an include in the
* header. Keeps it a bit cleaner.
* .cpp file will include the necessary
* headers.
*************************************/

class QGridLayout;
class QMenuBar;
class QButtonGroup;

using namespace CalculatorClasses;

class CalculatorGUI : public QMainWindow
{
    Q_OBJECT

public:
    CalculatorGUI(QWidget *parent = nullptr);
    ~CalculatorGUI();

    void BuildView();
    void CreateMenu();
    void SetupKeypad();
    void ConnectSignals();

public slots:

    void onKeypadButtonPressed(int id);

protected:

    void ParseCalculation();

signals:

    // Signals declared here if needed to notify other classes.

protected slots:

    void onMenuActionExit();
    void onMenuActionNew();

private:
    QGridLayout* mLayout            = nullptr;
    QGridLayout* mKeypadLayout      = nullptr;

    QMenuBar*     mTabBar           = nullptr;

    QButtonGroup* mButtonGroup      = nullptr;

    StandardCalculator* mCalculator = nullptr;

};
