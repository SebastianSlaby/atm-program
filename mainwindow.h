#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QShortcut>
#include <client.h>
#include <reportwindow.h>
#include <QDateTime>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    client *currentUser;
    reportWindow *r;

private slots:
    void checkPin();
    void withdraw();
    void deposit();
    void createReport();
    void closeHandler();
    void enableWindow();
};

#endif // MAINWINDOW_H
