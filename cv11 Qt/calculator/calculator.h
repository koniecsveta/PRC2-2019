#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>

class QPushButton;

class Calculator : public QDialog
{
    Q_OBJECT
    QLabel *lblLeft;
    QLineEdit *editLeft;
    QLabel *lblRight;
    QLineEdit *editRight;

    QLabel *lblOperator;
    QRadioButton *rbAdd;
    QRadioButton *rbSub;
    QRadioButton *rbMul;
    QRadioButton *rbDiv;

    QPushButton *btnAbout;
    QPushButton *btnCalculate;
    QPushButton *btnQuit;
    void error(QString msg);
private slots:
    void calculate();
    void showAbout();
public:
    Calculator(QWidget *parent = 0);
    ~Calculator();
};

#endif // CALCULATOR_H
