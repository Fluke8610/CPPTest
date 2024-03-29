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

public slots:

    void onKeypadButtonPressed(int id);

protected:

signals:

    // Signals declared here if needed to notify other classes.

protected slots:

    void onMenuActionExit();
    void onMenuActionNew();

private:
    QGridLayout*        mLayout         = nullptr;
    QGridLayout*        mKeypadLayout   = nullptr;

    QMenuBar*           mTabBar         = nullptr;

    QButtonGroup*       mButtonGroup    = nullptr;

    StandardCalculator* mCalculator     = nullptr;

    int                 mHeight         = 340;
    int                 mWidth          = 250;
    int                 mBtnHeight      = 40;
    int                 mBtnWidth       = 60;

};
