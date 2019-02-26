#include "client.h"

client::client(int currentBalance, QString fullName)
{
    this->currentBalance = currentBalance;
    this->fullName = fullName;
}

QString client::getFullName(){
    return this->fullName;
}

int client::getCurrentBalance(){
    return this->currentBalance;
}
