#include "calculator.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>


Calculator::Calculator(QWidget *parent)
    : QDialog(parent)
{
    QVBoxLayout *lMain = new QVBoxLayout;
    QHBoxLayout *lTop = new QHBoxLayout;
    QVBoxLayout *lOperands = new QVBoxLayout;
    QVBoxLayout *lOperators = new QVBoxLayout;
    QHBoxLayout *lButtons = new QHBoxLayout;

    lblLeft = new QLabel(tr("&Left operator: "));
    editLeft = new QLineEdit;
    lblLeft->setBuddy(editLeft);

    lblRight = new QLabel(tr("&Right operator"));
    editRight = new QLineEdit;
    lblRight->setBuddy(editRight);
    lOperands->addWidget(lblLeft);
    lOperands->addWidget(editLeft);
    lOperands->addWidget(lblRight);
    lOperands->addWidget(editRight);
    lOperands->addStretch();
    lTop->addLayout(lOperands);

    lblOperator = new QLabel(tr("Operator: "));
    rbAdd = new QRadioButton(tr("&Addition"));
    rbSub = new QRadioButton(tr("&Subtraction"));
    rbMul = new QRadioButton(tr("&Multiplication"));
    rbDiv = new QRadioButton(tr("&Division"));
    lOperators->addWidget(lblOperator);
    lOperators->addWidget(rbAdd);
    lOperators->addWidget(rbSub);
    lOperators->addWidget(rbMul);
    lOperators->addWidget(rbDiv);
    lOperators->addStretch();
    rbAdd->setChecked(true);
    lTop->addLayout(lOperators);

    btnAbout = new QPushButton(tr("About"));
    btnCalculate = new QPushButton(tr("&Calculate"));
    btnQuit = new QPushButton(tr("&Quit"));

    lButtons->addWidget(btnAbout);
    lButtons->addStretch();
    lButtons->addWidget(btnCalculate);
    lButtons->addWidget(btnQuit);

    lMain->addLayout(lTop);
    lMain->addLayout(lButtons);
    setLayout(lMain);
    setWindowTitle(tr("Calculator"));
    connect(btnAbout, SIGNAL(clicked()), this, SLOT(showAbout()));
    connect(btnQuit, SIGNAL(clicked()), this, SLOT(close()));
    connect(btnCalculate, SIGNAL(clicked()), this, SLOT(calculate()));
}

void Calculator::showAbout(){
    QMessageBox::about(this, tr("About Calculator"),
                       tr("Sample calculator created by FNSPE students"));
}

void Calculator::error(QString msg){
    QMessageBox::warning(this, tr("Error"), msg);
}

void Calculator::calculate(){
    double x, y, result;
    bool ok;
    x = editLeft->text().toDouble(&ok);
    if(!ok){
        error(tr("Left operand must be a number!"));
        return;
    }
    y = editRight->text().toDouble(&ok);
    if(!ok){
        error(tr("Right operand must be a number!"));
        return;
    }
    if(rbAdd->isChecked()){
        result = x + y;
    } else if(rbSub->isChecked()){
        result = x - y;
    } else if(rbMul->isChecked()){
        result = x * y;
    } else if(rbDiv->isChecked()){
        if(y == 0){
            error(tr("Division by zero!"));
            return;
        }
        result = x / y;
    } else{
        error(tr("No operator selected!"));
        return;
    }
    QMessageBox::information(this, tr("Result"),
                tr("Result is %1").arg(result));
}

Calculator::~Calculator()
{

}
