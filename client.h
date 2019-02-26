#ifndef CLIENT_H
#define CLIENT_H
#include <qstring.h>

class client
{
public:
    client(double currentBalance,QString fullName);
    QString getFullName();
    double getCurrentBalance();
    void withdraw(double amount);
    void deposit(int);
private:
    double currentBalance;
    QString fullName;
};

#endif // CLIENT_H
