#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

/************************************/
/*        Account Class             */
/************************************/

class Account
{
private:
    static void M_displayTimestamp(void); // Displays the current timestamp (will be used in log messages)
    static int NoOFAccounts;
    static int m_totalAmount;
    static int m_totalNoFDeposits;
    static int m_totalNoWithdrawals;

    int m_accountIndex;
    int m_amount;
    int m_nbDeposits;
    int m_nbWithdrawals;

public:
    static int getNo_Accounts(void) // Returns the number of accounts
    {
        return NoOFAccounts;
    }
    static int getTotalAmount(void) // Returns the total amount of all accounts
    {
        return m_totalAmount;
    }
    static int getNbDeposits(void) // Returns the number of deposits
    {
        return m_totalNoFDeposits;
    }
    static int getNbWithdrawals(void) // Returns the number of withdrawals
    {
        return m_totalNoWithdrawals;
    }
    static void displayAccountsInfos(void) // Displays the number of accounts, the total amount, the number of deposits, the number of withdrawals, and the total amount of all accounts
    {
        std::cout << " Number of Accounts : " << NoOFAccounts << " Total Amount : " << m_totalAmount << "Number of desposits : " << m_totalNoFDeposits << " Number of Withdrawls : " << m_totalNoWithdrawals << "\n";
    }
    Account() = delete;
    Account(int initial_deposit)
    {
        m_amount = initial_deposit;
        m_nbDeposits = 0;
        m_nbWithdrawals = 0;
        m_accountIndex = NoOFAccounts;
        NoOFAccounts++;
        m_totalAmount += initial_deposit;
        m_totalNoFDeposits++;
    }
    ~Account()
    {
    }

    void makeDeposit(int deposit)
    {
        m_nbDeposits++;
        m_amount += deposit;
        m_totalAmount += deposit;
        m_totalNoFDeposits++;
    }
    bool makeWithdrawal(int withdrawal)
    {
        m_nbWithdrawals++;
        if (m_amount - withdrawal >= 0)
        {
            m_amount -= withdrawal;
            m_totalAmount -= withdrawal;
            m_totalNoWithdrawals++;
            return true;
        }
        else
        {
            return false;
        }
    }
    int checkAmount(void) const
    {
        return m_amount;
    }
    void displayStatus(void) const
    {
        std::cout << " Account number : " << m_accountIndex << " Balance : " << m_amount << " Number of Withdrawal " << m_nbWithdrawals << " Number of Deposit " << m_nbDeposits << "\n";
    }
};

#endif /* __ACCOUNT_H__ */
