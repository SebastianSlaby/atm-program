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
    connect(ui->withdrawButton,SIGNAL(clicked()),this,SLOT(withdraw()));
    connect(ui->reportConfirmationButtons,SIGNAL(accepted()),this,SLOT(createReport()));
    connect(ui->reportConfirmationButtons,SIGNAL(rejected()),this,SLOT(closeHandler()));
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
    ui->reportConfirmationLabel->setVisible(false);
    ui->reportConfirmationButtons->setVisible(false);
    ui->balanceTitleLabel->setVisible(false);
    ui->nameTitleLabel->setVisible(false);
    client *currentUser;

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::checkPin(){
    if(ui->pinInput->text()=="2137"){
        client *currentUser= new client(static_cast<double>(5499.123215), "Sebastian Słaby");
        delete ui->pinInput;
        delete ui->pinSubmitButton;
        ui->withdrawButton->setEnabled(true);
        ui->depositButton->setEnabled(true);
        ui->nameLabel->setVisible(true);
        ui->nameLabel->setText(currentUser->getFullName());
        ui->nameLabel->setAlignment(Qt::AlignCenter);
        ui->balanceLabel->setVisible(true);
        QString text=QString::number(currentUser->getCurrentBalance());
        ui->balanceLabel->setText(text);
        ui->balanceLabel->setAlignment(Qt::AlignCenter);
        this->currentUser=currentUser;
        ui->balanceTitleLabel->setVisible(true);
        ui->nameTitleLabel->setVisible(true);

    }

}

void MainWindow::withdraw(){
    this->currentUser->withdraw(static_cast<double>( ui->withdrawSpinBox->value()));
    QString text=QString::number(this->currentUser->getCurrentBalance());
    ui->balanceLabel->setText(text);
    ui->reportConfirmationLabel->setVisible(true);
    ui->reportConfirmationButtons->setVisible(true);

}

void MainWindow::deposit(){


}

void MainWindow::closeHandler(){
    ui->reportConfirmationLabel->setVisible(false);
    ui->reportConfirmationButtons->setVisible(false);

}

void MainWindow::createReport(){

}
