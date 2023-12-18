#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>
#include <iomanip>
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

void MainWindow::on_pushButton_clicked()
{
    long long OctalValue = ui->spinBox->value();

    // Convert octal to decimal
    long long DecimalValue;
    std::istringstream octalStream(std::to_string(OctalValue));
    octalStream >> std::oct >> DecimalValue;

    // Convert decimal to binary
    std::bitset<64> binaryBits(DecimalValue);
    std::string BinaryValue = binaryBits.to_string();
    size_t firstNonZero = BinaryValue.find_first_not_of('0');
    if (firstNonZero != std::string::npos) {
        BinaryValue = BinaryValue.substr(firstNonZero);
    } else {
        BinaryValue = "0";  // Handle the case where BinaryValue is all zeros
    }

    // Convert decimal to hexadecimal
    std::stringstream hexStream;
    hexStream << std::hex << std::uppercase << DecimalValue;
    std::string HexadecimalValue = hexStream.str();

    // Display conversion results in QTextBrowser
    ui->textBrowser->clear();  // Clear previous content
    ui->textBrowser->append("Octal: " + QString::number(OctalValue));
    ui->textBrowser->append("Decimal: " + QString::number(DecimalValue));
    ui->textBrowser->append("Binary: " + QString::fromStdString(BinaryValue));
    ui->textBrowser->append("Hexadecimal: " + QString::fromStdString(HexadecimalValue));
}
