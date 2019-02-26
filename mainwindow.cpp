#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("ATM");
    ui->pinInput->setAlignment(Qt::AlignCenter);
    QFont pinFont = ui->pinInput->font();
    pinFont.setPointSize(32);
    ui->pinInput->setFont(pinFont);
    //linking signals to slots
    connect(ui->pinSubmitButton,SIGNAL(clicked()),this,SLOT(checkPin()));
    //
    ui->pinInput->setFocus();
    ui->pinInput->setInputMask("9999");
    ui->pinInput->setEchoMode(QLineEdit::Password);
    QShortcut *shortcut = new QShortcut(QKeySequence("Return"),ui->pinSubmitButton);
    QShortcut *shortcut2 = new QShortcut(QKeySequence("Enter"),ui->pinSubmitButton);
    connect(shortcut,SIGNAL(activated()),this,SLOT(checkPin()));
    connect(shortcut2,SIGNAL(activated()),this,SLOT(checkPin()));
    ui->nameLabel->setVisible(false);
    ui->balanceLabel->setVisible(false);
    ui->withdrawSpinBox->setAlignment(Qt::AlignCenter);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::checkPin(){
    if(ui->pinInput->text()=="2137"){
        client currentUser=client(12345, "Sebastian Słaby");
        delete ui->pinInput;
        delete ui->pinSubmitButton;
        ui->withdrawButton->setEnabled(true);
        ui->depositButton->setEnabled(true);
        ui->nameLabel->setVisible(true);
        ui->nameLabel->setText(currentUser.getFullName());
        ui->nameLabel->setAlignment(Qt::AlignCenter);
        ui->balanceLabel->setVisible(true);
        ui->balanceLabel->setText(QString::number(currentUser.getCurrentBalance()));
        ui->balanceLabel->setAlignment(Qt::AlignCenter);

    }

}

void MainWindow::withdraw(){


}

void MainWindow::deposit(){


}
