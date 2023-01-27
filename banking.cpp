#include <iostream>
#include <fstream>
using namespace std;
class account
{
public:
    // variables
    char n[24];
    int account_number;
    int deposit;
    int withdraw;
    int balance = 1000;
    // member functions or methods
    void get_money()
    {
        cin >> deposit;
    }
    void get_wmoney()
    {
        cin >> withdraw;
    }
    void get_details()
    {
        cin >> account_number;
    }
    int deposit_cust()
    {
        balance = balance + deposit;
        cout << "Your account number is " << account_number << endl;
        cout << "Your balance is " << balance << endl;
        return balance;
    }
    int withdraw_cust()
    {
        if (withdraw < balance)
        {
            balance = balance - withdraw;
            cout << "Your account number is " << account_number << endl;
            cout << "Your balance is " << balance << endl;
        }
        else if (withdraw >= balance)
        {
            balance = balance - 0;
            cout << "Your balance is:" << balance;
            cout << "You have insufficient money in your account!!!In order to make this transaction successful deposit some amount in your account now" << endl;
            return balance;
        }
    }

    // for deleting account
    void del_money()
    {
        deposit = 0;
    }
    void del_wmoney()
    {
        withdraw = 0;
    }
    void del_details()
    {
        account_number = 0;
    }
    int del_deposit_cust()
    {
        balance = 0;
        cout << "Your account number is " << account_number << endl;
        cout << "Your balance is " << balance << endl;
        return balance;
    }
};

int main() // execution begins from here
{
    char name[24];
    int account1;
    char name2[24];
    int modify;
    int del;
    int ex;
    int op;
    void file_op(void);
    account obj1;
    cout << "Enter the type of account you have(1 for saving account and 2 for current account): " << endl;
    cin >> account1;
    cout << "Enter your name: " << endl;
    cin >> name;
    {
        if (account1 == 1)
        {
            cout << "Enter your account number:" << endl;
            obj1.get_details();
            cout << "Enter the amount you want to deposit :" << endl;
            obj1.get_money();
            obj1.deposit_cust();
            cout << "Enter 2 to switch to your current account or 3 if you want to modify your account or press 5 to exit" << endl;
            cin >> op;
            {
                if (op == 2)
                {
                    cout << "Enter your account number:" << endl;
                    obj1.get_details();
                    cout << "Enter the amount you want to withdraw :" << endl;
                    obj1.get_wmoney();
                    obj1.withdraw_cust();
                }
                else if (op == 3)
                {
                    cout << "Enter the type of account you have(1 for saving account and 2 for current account): " << endl;
                    cin >> account1;
                    cout << "Enter your name in order to modify your account: " << endl;
                    cin >> name2;
                    cout << "Your name has been changed from " << name << "to " << name2 << endl;
                }
                else
                {
                    cout << "Thanks for visiting :)" << endl;
                    file_op();
                }
            }
        }

        else if (account1 == 2)
        {
            cout << "Enter your account number:" << endl;
            obj1.get_details();
            cout << "Enter the amount you want to withdraw :" << endl;
            obj1.get_wmoney();
            obj1.withdraw_cust();
            cout << "Enter 1 to switch to your saving account or 3 if you want to modify your account or press 5 to exit" << endl;
            cin >> op;
            {
                if (op == 1)
                {

                    cout << "Enter your account number:" << endl;
                    obj1.get_details();
                    cout << "Enter the amount you want to deposit :" << endl;
                    obj1.get_money();
                    obj1.deposit_cust();
                }
                else if (op == 3)
                {
                    cout << "Enter the type of account you have(1 for saving account and 2 for current account): " << endl;
                    cin >> account1;
                    cout << "Enter your name in order to modify your account: " << endl;
                    cin >> name2;
                    cout << "Your name has been changed from " << name << "to " << name2 << endl;
                }
                else
                {
                    cout << "Thanks for visiting :)" << endl;
                    file_op();
                }
            }
        }
    }

    cout << "Enter 3 to modify the account 0r press 5 to exit" << endl;
    cin >> modify;
    if (modify == 3)
    {
        cout << "Enter the type of account you have(1 for saving account and 2 for current account): " << endl;
        cin >> account1;
        cout << "Enter your name in order to modify your account: " << endl;
        cin >> name2;

        cout << "Your name has been changed from " << name << "to " << name2 << endl;
        cout << "Enter 1 to switch to your saving account or 2 if you want to switch to your current account or press 5 to exit" << endl;
        cin >> op;
        {
            if (op == 1)
            {

                cout << "Enter your account number:" << endl;
                obj1.get_details();
                cout << "Enter the amount you want to deposit :" << endl;
                obj1.get_money();
                obj1.deposit_cust();
            }
            else if (op == 2)
            {
                cout << "Enter your account number:" << endl;
                obj1.get_details();
                cout << "Enter the amount you want to withdraw :" << endl;
                obj1.get_wmoney();
                obj1.withdraw_cust();
            }
            else if (op == 5)
            {
                cout << "Thanks for visiting :)" << endl;
                file_op();
            }
        }
    }
    else
    {
        cout << "Your account is not modified" << endl;
    }
    cout << "Press 4 to delete your account from our bank or press 5 to exit" << endl;
    cin >> del;
    if (del == 4)
    {
        obj1.del_money();
        obj1.del_wmoney();
        obj1.del_details();
        obj1.del_deposit_cust();

        cout << "Your account is inactive from now" << endl;
    }
    else if (del != 4)
    {
        cout << "Your account is not deleted" << endl;
    }
    cout << "Press 5 to exit" << endl;
    cin >> ex;
    cout << "Thanks for visiting :)";
    // file operations
    void file_op(void)

    {
        fstream File1;
        File1.open("File1.txt", ios::out);
        if (!File1)
        {
            cout << "File not created!";
        }
        else
        {
            cout << "File created successfully!";
            File1 << "The name of the customer: " << name << endl;
            File1 << "The account number of the customer: " << obj1.account_number << endl;
            File1 << "The account type of the customer: " << account1 << endl;
            File1 << "The deposit money of the customer: " << obj1.deposit_cust() << endl;
            File1 << "The withdraw money of the customer: " << obj1.withdraw_cust() << endl;
            File1 << "The changed name of the customer : " << name2 << endl;
            File1.close();
        }
    }
        return 0;
}