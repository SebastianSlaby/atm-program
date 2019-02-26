#ifndef CLIENT_H
#define CLIENT_H
#include <qstring.h>

class client
{
public:
    client(int currentBalance,QString fullName);
    QString getFullName();
    int getCurrentBalance();
private:
    int currentBalance;
    QString fullName;
};

#endif // CLIENT_H
