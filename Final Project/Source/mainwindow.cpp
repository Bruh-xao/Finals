#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    long long binaryValue = ui->binary->value();
    binaryNumberDigit1 = binaryValue / 1000;
    binaryNumberDigit2 = (binaryValue / 100) % 10;
    binaryNumberDigit3 = (binaryValue / 10) % 10;
    binaryNumberDigit4 = (binaryValue / 1) % 10;

    long long decimalNumber = 0;
    int exponent = 0;

    while (binaryValue != 0)
    {
        long long digit = binaryValue % 10;
        decimalNumber += digit * pow(2, exponent);
        exponent++;
        binaryValue /= 10;
    }

    ui->textBrowser->setText("");  // Clear the previous content
    ui->textBrowser->append("Digit 1: " + QString::number(binaryNumberDigit1));
    ui->textBrowser->append("Digit 2: " + QString::number(binaryNumberDigit2));
    ui->textBrowser->append("Digit 3: " + QString::number(binaryNumberDigit3));
    ui->textBrowser->append("Digit 4: " + QString::number(binaryNumberDigit4));
    ui->textBrowser->append("Decimal equivalent: " + QString::number(decimalNumber));
}
