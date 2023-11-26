#include "CalculatorGUI.h"

#include <QApplication>
#include <QLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QLabel>
#include <QButtonGroup>

#define BTNSUBTRACT     -1
#define BTNDIVIDE       -2
#define BTNMULTIPLY     -3
#define BTNEQUALS       -4
#define BTNDECIMALPOINT -5
#define BTNDELETE       -6
#define BTNZERO         -7

CalculatorGUI::CalculatorGUI(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(QSize(250, 500));

    mCalculator = new StandardCalculator();

    BuildView();
}

CalculatorGUI::~CalculatorGUI()
{
    /*********************************************
    * Free mCalculator as it is not a QObject and
    * will not be free'd by the framework 
    * automatically.
    **********************************************/
    if (mCalculator != nullptr)
    {
        delete mCalculator;
        mCalculator = nullptr;
    }
}

void CalculatorGUI::BuildView()
{
    /********************************************
    * Main layout for the widget
    *********************************************/
    mLayout = new QGridLayout();
    mLayout->setSpacing(2);
    mLayout->setContentsMargins(2, 2, 2, 2);
    mLayout->setObjectName(QString("MainWidgetGridLayout"));

    /********************************************
    * Main Widget for the calculator
    *********************************************/
    QWidget* mainWidget = new QWidget(this);
    mainWidget->setLayout(mLayout);
    mainWidget->setContentsMargins(2, 2, 2, 2);
    mainWidget->setMinimumSize(QSize(250, 500));
    mainWidget->setObjectName(QString("MainWidget"));

    CreateMenu();

    /********************************************
    * Main text Display for the calculator
    *********************************************/
    QLabel* mainTextDisplay = new QLabel(QString("0"), mainWidget);
    mainTextDisplay->setMinimumWidth(200);
    mainTextDisplay->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
    mainTextDisplay->setStyleSheet("QLabel { background-color: white; color: black; }");
    mainTextDisplay->setObjectName(QString("MainTextDisplayLabel"));

    QLabel* mainInputDisplay = new QLabel(QString(""), mainWidget);
    mainInputDisplay->setMinimumWidth(200);
    mainInputDisplay->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
    mainInputDisplay->setStyleSheet("QLabel { background-color: white; color: black; }");
    mainInputDisplay->setObjectName(QString("mainInputDisplayLabel"));

    mKeypadLayout = new QGridLayout();
    mKeypadLayout->setSpacing(2);
    mKeypadLayout->setContentsMargins(2, 2, 2, 2);
    mKeypadLayout->setObjectName(QString("KeypadGridLayout"));

    /********************************************
    * Keypad Widget
    *********************************************/
    QWidget* keypadWidget = new QWidget(mainWidget);
    keypadWidget->setLayout(mKeypadLayout);
    keypadWidget->setObjectName(QString("KeypadWidget"));

    SetupKeypad();
    
    mLayout->addWidget(mTabBar, 0, 0, 1, 5, Qt::AlignTop | Qt::AlignLeft);
    mLayout->addWidget(mainInputDisplay, 1, 0, 1, 5, Qt::AlignVCenter | Qt::AlignHCenter);
    mLayout->addWidget(mainTextDisplay, 2, 0, 1, 5, Qt::AlignVCenter | Qt::AlignHCenter);
    mLayout->addWidget(keypadWidget, 3, 0, 4, 4, Qt::AlignVCenter | Qt::AlignHCenter);

    
}

void CalculatorGUI::CreateMenu()
{
    QWidget* mainwidget = findChild<QWidget*>(QString("MainWidget")); // Needed for parenting to a widget.

    /********************************************
    * Tab Bar at the top of the application
    *********************************************/
    mTabBar = new QMenuBar(mainwidget);

    QAction* actionNew = new QAction(QString("New"),mTabBar);
    actionNew->setEnabled(true);

    QAction* actionExit = new QAction(QString("Exit"), mTabBar);
    actionExit->setEnabled(true);

    /********************************************
    * Menu Item
    *********************************************/
    QMenu* file = new QMenu(QString("&file"), mTabBar);
    file->addAction(actionNew);
    file->addAction(actionExit);

    connect(actionExit, &QAction::triggered, this, &CalculatorGUI::onMenuActionExit);
    connect(actionNew, &QAction::triggered, this, &CalculatorGUI::onMenuActionNew);

    mTabBar->addMenu(file);
}

void CalculatorGUI::SetupKeypad()
{
    /**********************************************
    * Here we are setting up the keypad, finding 
    * items declared and initialised in the build view.
    * We could inject the dependency of the button group
    * and the widget for the keypad or as below search 
    * for the object or declare in the header file.
    ***********************************************/
    QWidget* keypad = findChild<QWidget*>(QString("KeypadWidget")); // Needed for parenting to a widget.
    QGridLayout* layout = findChild<QGridLayout*>(QString("KeypadGridLayout"));

    mButtonGroup = new QButtonGroup(keypad);

    int rows = 3;
    int cols = 3;
    int num = 1;

    if (keypad != nullptr && layout != nullptr)
    {
        QPushButton* btnDecimalPoint = new QPushButton(QString("."), keypad);
        btnDecimalPoint->setFixedSize(QSize(60, 40));
        btnDecimalPoint->setObjectName(QString("BtnDecimalPoint"));

        mButtonGroup->addButton(btnDecimalPoint, BTNDECIMALPOINT);

        layout->addWidget(btnDecimalPoint, 3, 0, Qt::AlignHCenter | Qt::AlignVCenter);

        QPushButton* btnZero = new QPushButton(QString("0"), keypad);
        btnZero->setFixedSize(QSize(60, 40));
        btnZero->setObjectName(QString("BtnZero"));

        mButtonGroup->addButton(btnZero, BTNZERO);

        layout->addWidget(btnZero, 3, 1, Qt::AlignHCenter | Qt::AlignVCenter);

        QPushButton* btnDelete = new QPushButton(QString("DEL"), keypad);
        btnDelete->setFixedSize(QSize(60, 40));
        btnDelete->setObjectName(QString("BtnDelete"));

        mButtonGroup->addButton(btnDelete, BTNDELETE);

        layout->addWidget(btnDelete, 3, 2, Qt::AlignHCenter | Qt::AlignVCenter);

        for (int i = 0; i < rows; i++)
        {

            for (int j = 0; j < cols; j++)
            {
                // Create button
                QPushButton* btn = new QPushButton(QString("%1").arg(num), keypad);
                btn->setFixedSize(QSize(60, 40));
                btn->setObjectName(QString("Btn%1").arg(num));

                mButtonGroup->addButton(btn, num);

                // Add to layout
                layout->addWidget(btn, i, j, Qt::AlignHCenter | Qt::AlignVCenter);

                num++;
            }

        }

        connect(mButtonGroup, &QButtonGroup::idClicked, this, &CalculatorGUI::onKeypadButtonPressed);
    }
}

void CalculatorGUI::ConnectSignals()
{

}

void CalculatorGUI::ParseCalculation()
{
    // TODO: Parse 
}

void CalculatorGUI::onMenuActionNew()
{
    if (mCalculator != nullptr)
    {
        mCalculator->Clear();

        QLabel* lbl = findChild<QLabel*>(QString("MainTextDisplayLabel"));
        if (lbl != nullptr)
        {
            lbl->setText(QString("0"));
        }
    }
    else
    {
        mCalculator = new StandardCalculator();
    }
}

// TODO: Refactor this logic to send only needed to calculator class.
//       Ensure no calculation is done in the GUI.
void CalculatorGUI::onKeypadButtonPressed(int id)
{
    QLabel* lbl = findChild<QLabel*>(QString("MainTextDisplayLabel"));
    if (lbl == nullptr)
    {
        // TODO: Create error dialog
        return;
    }

    // Get current text in label
    QString text = lbl->text();

    switch (id)
    {
    case BTNSUBTRACT:
        
        break;
    case BTNDIVIDE:

        break;
    case BTNMULTIPLY:

        break;
    case BTNEQUALS:

        break;
    case BTNDECIMALPOINT:
        if (text.startsWith('0'))
        {
            // clear text, assume we have initial 0
            text = "0.0";
        }
        else
        {
            if (!text.contains('.'))
            {
                text.append('.');
            }
        }
        break;
    case BTNDELETE:
        // clear text
        text = "0";
        break;
    case BTNZERO:
        if (!text.startsWith('0'))
        {
            text.append('0');
        }
        break;
    case 1:
        if (text.startsWith('0'))
        {
            // clear text, assume we have initial 0
            text = "1";
        }
        else
        {
            text.append('1');
        }
        break;
    case 2:
        if (text.startsWith('0'))
        {
            // clear text, assume we have initial 0
            text = "2";
        }
        else
        {
            text.append('2');
        }
        break;
    case 3:
        if (text.startsWith('0'))
        {
            // clear text, assume we have initial 0
            text = "3";
        }
        else
        {
            text.append('3');
        }
        break;
    case 4:
        if (text.startsWith('0'))
        {
            // clear text, assume we have initial 0
            text = "4";
        }
        else
        {
            text.append('4');
        }
        break;
    case 5:
        if (text.startsWith('0'))
        {
            // clear text, assume we have initial 0
            text = "5";
        }
        else
        {
            text.append('5');
        }
        break;
    case 6:
        if (text.startsWith('0'))
        {
            // clear text, assume we have initial 0
            text = "6";
        }
        else
        {
            text.append('6');
        }
        break;
    case 7:
        if (text.startsWith('0'))
        {
            // clear text, assume we have initial 0
            text = "7";
        }
        else
        {
            text.append('7');
        }
        break;
    case 8:
        if (text.startsWith('0'))
        {
            // clear text, assume we have initial 0
            text = "8";
        }
        else
        {
            text.append('8');
        }
        break;
    case 9:
        if (text.startsWith('0'))
        {
            // clear text, assume we have initial 0
            text = "9";
        }
        else
        {
            text.append('9');
        }
        break;
    default:

        break;
    }

    lbl->setText(text);
}

void CalculatorGUI::onMenuActionExit()
{
    QApplication::quit();
}
