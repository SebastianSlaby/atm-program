#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QShortcut>
#include <client.h>

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

private slots:
    void checkPin();
    void withdraw();
    void deposit();
    void createReport();
    void closeHandler();
};

#endif // MAINWINDOW_H
