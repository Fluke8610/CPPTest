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

/*******************************
* Define button group id's for 
* push buttons.
********************************/
#define BTNADD          -2
#define BTNSUBTRACT     -3
#define BTNDIVIDE       -4
#define BTNMULTIPLY     -5
#define BTNEQUALS       -6
#define BTNDECIMALPOINT -7
#define BTNDELETE       -8
#define BTNZERO         -9
#define BTNCLEAR        -10

CalculatorGUI::CalculatorGUI(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(QSize(mWidth, mHeight));

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
    mainWidget->setMinimumSize(QSize(mWidth, mHeight));
    mainWidget->setObjectName(QString("MainWidget"));

    CreateMenu();

    /********************************************
    * Main text Display for the calculator
    *********************************************/
    QLabel* mainTextDisplay = new QLabel(QString("0"), mainWidget);
    mainTextDisplay->setMinimumWidth(240);
    mainTextDisplay->setMinimumHeight(20);
    mainTextDisplay->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
    mainTextDisplay->setStyleSheet("QLabel { background-color: white; color: black; border-radius: 5px; }");
    mainTextDisplay->setObjectName(QString("MainTextDisplayLabel"));

    QLabel* mainInputDisplay = new QLabel(QString(""), mainWidget);
    mainInputDisplay->setMinimumWidth(240);
    mainInputDisplay->setMinimumHeight(30);
    mainInputDisplay->setWordWrap(true);
    mainInputDisplay->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
    mainInputDisplay->setStyleSheet("QLabel { background-color: white; color: black; border-radius: 5px; }");
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
    mLayout->addWidget(keypadWidget, 3, 0, 4, 5, Qt::AlignVCenter | Qt::AlignHCenter);

    
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

    // Declared in header file.
    mButtonGroup = new QButtonGroup(keypad);

    int rows = 3;
    int cols = 3;
    int num = 1;

    if (keypad != nullptr && layout != nullptr)
    {
        QPushButton* btnClear = new QPushButton(QString("C"), keypad);
        btnClear->setFixedSize(QSize(60, 40));
        btnClear->setObjectName(QString("BtnDecimalPoint"));

        mButtonGroup->addButton(btnClear, BTNCLEAR);

        layout->addWidget(btnClear, 0, 3, Qt::AlignHCenter | Qt::AlignVCenter);

        QPushButton* btnDecimalPoint = new QPushButton(QString("."), keypad);
        btnDecimalPoint->setFixedSize(QSize(60, 40));
        btnDecimalPoint->setObjectName(QString("BtnDecimalPoint"));

        mButtonGroup->addButton(btnDecimalPoint, BTNDECIMALPOINT);

        layout->addWidget(btnDecimalPoint, 4, 0, Qt::AlignHCenter | Qt::AlignVCenter);

        QPushButton* btnZero = new QPushButton(QString("0"), keypad);
        btnZero->setFixedSize(QSize(mBtnWidth, mBtnHeight));
        btnZero->setObjectName(QString("BtnZero"));

        mButtonGroup->addButton(btnZero, BTNZERO);

        layout->addWidget(btnZero, 4, 1, Qt::AlignHCenter | Qt::AlignVCenter);

        QPushButton* btnDelete = new QPushButton(QString("DEL"), keypad);
        btnDelete->setFixedSize(QSize(mBtnWidth, mBtnHeight));
        btnDelete->setObjectName(QString("BtnDelete"));

        mButtonGroup->addButton(btnDelete, BTNDELETE);

        layout->addWidget(btnDelete, 4, 2, Qt::AlignHCenter | Qt::AlignVCenter);

        QPushButton* btnSubtract = new QPushButton(QString("-"), keypad);
        btnSubtract->setFixedSize(QSize(mBtnWidth, mBtnHeight));
        btnSubtract->setObjectName(QString("BtnSubtract"));

        mButtonGroup->addButton(btnSubtract, BTNSUBTRACT);

        layout->addWidget(btnSubtract, 1, 3, Qt::AlignHCenter | Qt::AlignVCenter);

        QPushButton* btnDivide = new QPushButton(QString("/"), keypad);
        btnDivide->setFixedSize(QSize(mBtnWidth, mBtnHeight));
        btnDivide->setObjectName(QString("BtnDivide"));

        mButtonGroup->addButton(btnDivide, BTNDIVIDE);

        layout->addWidget(btnDivide, 2, 3, Qt::AlignHCenter | Qt::AlignVCenter);

        QPushButton* btnMultiply = new QPushButton(QString("*"), keypad);
        btnMultiply->setFixedSize(QSize(mBtnWidth, mBtnHeight));
        btnMultiply->setObjectName(QString("BtnMultiply"));

        mButtonGroup->addButton(btnMultiply, BTNMULTIPLY);

        layout->addWidget(btnMultiply, 3, 3, Qt::AlignHCenter | Qt::AlignVCenter);

        QPushButton* btnAdd = new QPushButton(QString("+"), keypad);
        btnAdd->setFixedSize(QSize(mBtnWidth, mBtnHeight));
        btnAdd->setObjectName(QString("BtnAdd"));

        mButtonGroup->addButton(btnAdd, BTNADD);

        layout->addWidget(btnAdd, 4, 3, Qt::AlignHCenter | Qt::AlignVCenter);

        QPushButton* btnEquals = new QPushButton(QString("="), keypad);
        btnEquals->setFixedSize(QSize(240, 40));
        btnEquals->setObjectName(QString("BtnEquals"));

        mButtonGroup->addButton(btnEquals, BTNEQUALS);

        layout->addWidget(btnEquals, 5, 0, 1, 4, Qt::AlignHCenter | Qt::AlignVCenter);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                // Create button
                QPushButton* btn = new QPushButton(QString("%1").arg(num), keypad);
                btn->setFixedSize(QSize(mBtnWidth, mBtnHeight));
                btn->setObjectName(QString("Btn%1").arg(num));

                mButtonGroup->addButton(btn, num);

                // Add to layout
                layout->addWidget(btn, i +1, j, Qt::AlignHCenter | Qt::AlignVCenter);

                num++;
            }

        }

        connect(mButtonGroup, &QButtonGroup::idClicked, this, &CalculatorGUI::onKeypadButtonPressed);
    }
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

        QLabel* lblDisplay = findChild<QLabel*>(QString("mainInputDisplayLabel"));
        if (lblDisplay != nullptr)
        {
            lblDisplay->setText(QString(""));
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
    QLabel* lblDisplay = findChild<QLabel*>(QString("mainInputDisplayLabel"));
    if (lbl == nullptr || lblDisplay == nullptr)
    {
        // TODO: Create error dialog
        return;
    }

    // Get current text in label
    QString text = lbl->text();
    QString dispText = lblDisplay->text();

    switch (id)
    {
    case BTNCLEAR:
        mCalculator->Clear();
        dispText = "";
        text = "0";
        break;
    case BTNADD:
        mCalculator->AddInput(text.toStdString());
        mCalculator->onAddPressed();
        dispText.append("+");
        text = "0";
        break;
    case BTNSUBTRACT:
        mCalculator->AddInput(text.toStdString());
        mCalculator->onSubtractPressed();
        dispText.append("-");
        text = "0";
        break;
    case BTNDIVIDE:
        mCalculator->AddInput(text.toStdString());
        mCalculator->onDivisionPressed();
        dispText.append("/");
        text = "0";
        break;
    case BTNMULTIPLY:
        mCalculator->AddInput(text.toStdString());
        mCalculator->onMultiplicationPressed();
        dispText.append("*");
        text = "0";
        break;
    case BTNEQUALS:
        mCalculator->AddInput(text.toStdString());
        text = QString("%1").arg(mCalculator->onEqualsPressed());
        mCalculator->Clear();
        break;
    case BTNDECIMALPOINT:
        if (text.startsWith('0'))
        {
            // clear text, assume we have initial 0
            text = "0";
        }
        else
        {
            if (!text.contains('.'))
            {
                text.append('.');
                dispText.append('.');
            }
        }
        break;
    case BTNDELETE:
        // clear text
        dispText.remove(text);
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
            dispText.append("1");
        }
        else
        {
            text.append('1');
            dispText.append('1');
        }
        break;
    case 2:
        if (text.startsWith('0'))
        {
            // clear text, assume we have initial 0
            text = '2';
            dispText.append('2');
        }
        else
        {
            text.append('2');
            dispText.append('2');
        }
        break;
    case 3:
        if (text.startsWith('0'))
        {
            // clear text, assume we have initial 0
            text = '3';
            dispText.append('3');
        }
        else
        {
            text.append('3');
            dispText.append('3');
        }
        break;
    case 4:
        if (text.startsWith('0'))
        {
            // clear text, assume we have initial 0
            text = '4';
            dispText.append('4');
        }
        else
        {
            text.append('4');
            dispText.append('4');
        }
        break;
    case 5:
        if (text.startsWith('0'))
        {
            // clear text, assume we have initial 0
            text = '5';
            dispText.append('5');
        }
        else
        {
            text.append('5');
            dispText.append('5');
        }
        break;
    case 6:
        if (text.startsWith('0'))
        {
            // clear text, assume we have initial 0
            text = '6';
            dispText.append('6');
        }
        else
        {
            text.append('6');
            dispText.append('6');
        }
        break;
    case 7:
        if (text.startsWith('0'))
        {
            // clear text, assume we have initial 0
            text = '7';
            dispText.append('7');
        }
        else
        {
            text.append('7');
            dispText.append('7');
        }
        break;
    case 8:
        if (text.startsWith('0'))
        {
            // clear text, assume we have initial 0
            text = '8';
            dispText.append('8');
        }
        else
        {
            text.append('8');
            dispText.append('8');
        }
        break;
    case 9:
        if (text.startsWith('0'))
        {
            // clear text, assume we have initial 0
            text = '9';
            dispText.append('9');
        }
        else
        {
            text.append('9');
            dispText.append('9');
        }
        break;
    default:

        break;
    }

    lbl->setText(text);
    lblDisplay->setText(dispText);
}

void CalculatorGUI::onMenuActionExit()
{
    QApplication::quit();
}
