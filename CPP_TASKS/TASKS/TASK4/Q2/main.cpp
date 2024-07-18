#include <iostream>

#include "account.hpp"
int Account::NoOFAccounts;
int Account::m_totalAmount;
int Account::m_totalNoFDeposits;
int Account::m_totalNoWithdrawals;
int main()
{
    Account acc_one(10000);
    acc_one.makeDeposit(1000);
    acc_one.makeWithdrawal(500);
    acc_one.checkAmount();
    acc_one.displayStatus();
    //  Account::displayAccountsInfos();
    return 0;
}