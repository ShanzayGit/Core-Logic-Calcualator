#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Evaluator.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->ScientificCalculator->hide();

    setWindowFlags(Qt::Window);   // ensures normal window with minimize/maximize/close
    setMinimumSize(280, 450);   // ensures it doesn’t shrink too small
    setMaximumSize(280, 450);
 //   setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Digit buttons
    connect(ui->btn0, &QPushButton::clicked, this, &MainWindow::onDigitClicked);
    connect(ui->btn1, &QPushButton::clicked, this, &MainWindow::onDigitClicked);
    connect(ui->btn2, &QPushButton::clicked, this, &MainWindow::onDigitClicked);
    connect(ui->btn3, &QPushButton::clicked, this, &MainWindow::onDigitClicked);
    connect(ui->btn4, &QPushButton::clicked, this, &MainWindow::onDigitClicked);
    connect(ui->btn5, &QPushButton::clicked, this, &MainWindow::onDigitClicked);
    connect(ui->btn6, &QPushButton::clicked, this, &MainWindow::onDigitClicked);
    connect(ui->btn7, &QPushButton::clicked, this, &MainWindow::onDigitClicked);
    connect(ui->btn8, &QPushButton::clicked, this, &MainWindow::onDigitClicked);
    connect(ui->btn9, &QPushButton::clicked, this, &MainWindow::onDigitClicked);
    connect(ui->btndecimal, &QPushButton::clicked, this, &MainWindow::onDigitClicked);

    // Operators
    connect(ui->btnplus, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    connect(ui->btnmin, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    connect(ui->btnmul, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    connect(ui->btndiv, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    connect(ui->btnmod, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    connect(ui->btnPer, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    connect(ui->btnOpenBrackets, &QPushButton::clicked, this, &MainWindow::onDigitClicked);
    connect(ui->btnCloseBrackets, &QPushButton::clicked, this, &MainWindow::onDigitClicked);
    connect(ui->btnPower, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    // All scientific functions use onOperatorClicked
    connect(ui->btnSin, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    connect(ui->btnCos, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    connect(ui->btnTan, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);

    connect(ui->btnAsin, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    connect(ui->btnAcos, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    connect(ui->btnAtan, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);

    connect(ui->btnSqrt, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    connect(ui->btnLn, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    connect(ui->btnLog10, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    connect(ui->btnExp, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    connect(ui->btnAbs, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);


    // Special functions
    connect(ui->btnequal, &QPushButton::clicked, this, &MainWindow::onEqualClicked);
    connect(ui->btnclear, &QPushButton::clicked, this, &MainWindow::onClearClicked);
    connect(ui->btndel, &QPushButton::clicked, this, &MainWindow::onDeleteClicked);
    connect(ui->sci, &QPushButton::clicked, this, &MainWindow::onToggleScientific);
}

MainWindow::~MainWindow()
{
    delete ui;
}
 void MainWindow::onToggleScientific()
 {
        bool isVisible = ui->ScientificCalculator->isVisible();
        ui->ScientificCalculator->setVisible(!isVisible);

        // Adjust window size to fit new layout
       // this->setFixedSize(this->sizeHint());
 }


 void MainWindow::onDigitClicked() {
     QPushButton* button = qobject_cast<QPushButton*>(sender());
     if (button) {
         qDebug() << "Clicked:" << button->objectName() << button->text();
         std::string input = button->text().toStdString();

         // If the display only has "0", clear it before appending
         if (expression == "0") {
             expression.clear();
         }

         // Append the digit to the current expression
         expression += input;

         // Update the display
         ui->display->setText(QString::fromStdString(expression));
     }
 }


 void MainWindow::onOperatorClicked() {
     QPushButton* button = qobject_cast<QPushButton*>(sender());
     if (button) {
         std::string op = button->text().toStdString();

         // For functions, automatically append "("
         if (op == "sin" || op == "cos" || op == "tan" ||
             op == "asin" || op == "acos" || op == "atan" ||
             op == "sqrt" || op == "ln" || op == "log" ||
             op == "exp" || op == "abs")
         {
             addInput(op + "(");
         }
         else {
             // Normal operators (+, -, *, /, ^, etc.)
             addInput(op);
         }

         ui->display->setText(QString::fromStdString(expression));
     }
 }


void MainWindow::onEqualClicked() {
    double result = evaluate(expression);
    if (std::isnan(result)) {
        ui->display->setText("Error");
    }
    else {
        ui->display->setText(QString::number(result));
    }

}

void MainWindow::onClearClicked() {
    clearExpression();
    ui->display->clear();
}

void MainWindow::onDeleteClicked() {
    deleteLast();
    ui->display->setText(QString::fromStdString(expression));
}
