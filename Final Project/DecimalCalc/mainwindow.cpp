#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>
#include <iomanip>

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

void decimalToBinaryOctalHexadecimal(int decimalNumber, std::string &binaryNumber, std::string &octalNumber, std::string &hexadecimalNumber) {
    // Converting to binary
    std::stringstream binaryStream;
    int binaryRemainder;
    while (decimalNumber > 0) {
        binaryRemainder = decimalNumber % 2;
        binaryStream << binaryRemainder;
        decimalNumber /= 2;
    }
    binaryNumber = binaryStream.str();
    std::reverse(binaryNumber.begin(), binaryNumber.end());

    // Converting to octal
    std::stringstream octalStream;
    int octalRemainder;
    decimalNumber = stoi(binaryNumber, nullptr, 2); // Convert binary to decimal
    while (decimalNumber > 0) {
        octalRemainder = decimalNumber % 8;
        octalStream << octalRemainder;
        decimalNumber /= 8;
    }
    octalNumber = octalStream.str();
    std::reverse(octalNumber.begin(), octalNumber.end());

    // Converting to hexadecimal
    std::stringstream hexStream;
    int hexRemainder;
    decimalNumber = stoi(binaryNumber, nullptr, 2); // Convert binary to decimal
    while (decimalNumber > 0) {
        hexRemainder = decimalNumber % 16;
        if (hexRemainder < 10) {
            hexStream << hexRemainder;
        } else {
            hexStream << static_cast<char>('A' + (hexRemainder - 10));
        }
        decimalNumber /= 16;
    }
    hexadecimalNumber = hexStream.str();
    std::reverse(hexadecimalNumber.begin(), hexadecimalNumber.end());
}

void MainWindow::on_pushButton_clicked()
{
    int decimalNumber = ui->Deci->value();

    std::string binaryNumber, octalNumber, hexadecimalNumber;
    decimalToBinaryOctalHexadecimal(decimalNumber, binaryNumber, octalNumber, hexadecimalNumber);


    ui->textBrowser->clear();  // To clear textBrowser so it doesn't take much space
    ui->textBrowser->append("Decimal: " + QString::number(decimalNumber));
    ui->textBrowser->append("Binary: " + QString::fromStdString(binaryNumber));
    ui->textBrowser->append("Octal: " + QString::fromStdString(octalNumber));
    ui->textBrowser->append("Hexadecimal: " + QString::fromStdString(hexadecimalNumber));
}
