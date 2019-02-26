#include "reportwindow.h"
#include "ui_reportwindow.h"

reportWindow::reportWindow(QString text, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::reportWindow)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    ui->textBrowser->setPlainText(text);
}
reportWindow::~reportWindow()
{
    delete ui;
}

