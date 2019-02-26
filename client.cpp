#include "client.h"

client::client(double currentBalance, QString fullName)
{
    this->currentBalance = currentBalance;
    this->fullName = fullName;
}

QString client::getFullName(){
    return this->fullName;
}

double client::getCurrentBalance(){
    return this->currentBalance;
}

void client::withdraw(double amount){
    this->currentBalance-=amount;
}

void client::deposit(double amount){
    this->currentBalance+=amount;
}
