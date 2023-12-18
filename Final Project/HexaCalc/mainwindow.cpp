#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <bitset>


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

void hexadecimalToBinaryOctalDecimal(const QString &hexadecimalNumber, std::string &binaryNumber, std::string &octalNumber, long long &decimalNumber) {
    bool conversionOk;
    decimalNumber = hexadecimalNumber.toLongLong(&conversionOk, 16);

    if (conversionOk) {
        // Converting decimal to binary
        std::stringstream binaryStream;
        binaryStream << std::bitset<16>(decimalNumber >> 48 & 0xFFFF)
                     << std::bitset<16>(decimalNumber >> 32 & 0xFFFF)
                     << std::bitset<16>(decimalNumber >> 16 & 0xFFFF)
                     << std::bitset<16>(decimalNumber & 0xFFFF);

        binaryNumber = binaryStream.str();

        // Converting decimal to octal
        std::stringstream octalStream;
        octalStream << std::oct << decimalNumber;
        octalNumber = octalStream.str();
    }
}

void MainWindow::on_pushButton_clicked()
{
    QString hexadecimalInput = ui->lineEdit->text();

    // to check the input
    if (!hexadecimalInput.isEmpty()) {
        std::string binaryNumber, octalNumber;
        long long decimalNumber;

        hexadecimalToBinaryOctalDecimal(hexadecimalInput, binaryNumber, octalNumber, decimalNumber);

        // Display for textBrowser
        ui->textBrowser->clear();  // To clear so not full
        ui->textBrowser->append("Hexadecimal: " + hexadecimalInput);
        ui->textBrowser->append("Binary: " + QString::fromStdString(binaryNumber));
        ui->textBrowser->append("Octal: " + QString::fromStdString(octalNumber));
        ui->textBrowser->append("Decimal: " + QString::number(decimalNumber));
    } else {
        // for empty input
        ui->textBrowser->setText("Please enter a hexadecimal number");
    }
}
