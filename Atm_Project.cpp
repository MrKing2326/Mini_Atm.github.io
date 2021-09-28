#include<conio.h>
#include<iostream>
#include<string>
using namespace std;

/* Mini Project- ATM
    -> Check balance
    -> Cash Withdraw
    -> User Details
    => Update Mobile No.
*/

 class atm {
 private:
     long int account_No;
     string name;
     int Pin;
     double balance;
     string mobile_no;

 public:
    void setData(long int account_No_a, string name_a, int pin_a, double balance_a, string mobile_no_a) {
        account_No = account_No_a;
        name = name_a;
        Pin = pin_a;
        balance = balance_a;
        mobile_no = mobile_no_a;
    }

    long int getAccountNo() {
        return account_No;
    }

    string getName() {
        return name;
    }

    int getPin() {
        return Pin;
    }

    double getBalance() {
        return balance;
    }
    string getMobileNo() {
        return mobile_no;
    }

    void checkBalance(double acc_balance) {

    }

    void setMobileNo(string mob_prev, string mob_new) {
        if(mob_prev == mobile_no) {
            mobile_no = mob_new;
            cout<< "Successfully updated your Mobile Number.";
            _getch();
        }
        else {
            cout<< "Invalid Input or Incorrect Old Mobile Number !!!" <<endl;
            cout<< "Kindly Try Again...";
            _getch();
        }
    }

    void CashWithdraw(double amount_a) {
        if(amount_a > 0 && amount_a < balance) {
            balance -= amount_a;
            cout<< endl << "Please Collect Your Cash";
            cout<< endl << "Available Balance : "<< balance;
            _getch();
        }
        else {
            cout<< endl << "Amount entered is Incorrect !!!  Insufficient Balance...";
            cout<< endl << "kindly Check the balance...";
            _getch();
        }
    }

 };

 int main() {
     int choice=0, enterPin;
     long int enterAccountNo;

     system("cls");

    atm user1;

    user1.setData(123456789, "Vikas", 1111, 4900000, "0987654321");

    do {
        system("cls");
        cout<< endl << "**************Welcome to ATM***************"<<endl;
        cout<< endl << "Enter Your Account Number : ";
        cin>> enterAccountNo;

        cout<< endl << "Enter the Pin : ";
        cin>> enterPin;

        if((enterAccountNo == user1.getAccountNo()) && (enterPin == user1.getPin())) {
            do {
                int amount = 0;
                string oldMobNo, newMobNo;

                system("cls");

                  cout << endl << "**************Welcome to ATM***************"<<endl;
                  cout << endl <<"Select options " ;
                  cout << endl << "1. Check Balance";
                  cout << endl << "2. Cash Withdrawal";
                  cout << endl << "3. See Your Details";
                  cout << endl << "4. update Mobile Number";
                  cout << endl << "5. Exit";
                  cout << endl;
                  cin >> choice;

                  switch(choice) {
                case 1:
                    cout<< endl << "Your Bank Balance is :" << user1.getBalance();
                    _getch();
                    break;

                case 2:
                    cout<< endl << "Enter the Amount :";
                    cin>> amount;
                    user1.CashWithdraw(amount);
                    break;

                case 3:
                    cout << endl << "***User Details are :- ";
                    cout << endl << "-> Account no. :" <<user1.getAccountNo();
                    cout << endl << "-> Name :" << user1.getName();
                    cout << endl << "-> Balance :" << user1.getBalance();
                    cout << endl << "-> Mobile Number :" << user1.getMobileNo();
                    _getch();
                    break;

                case 4:
                    cout<< endl <<" Enter Your Old Mobile No. :";
                    cin>> oldMobNo;

                    cout << endl << "Enter Your New Mobile No. :";
                    cin>> newMobNo;

                    user1.setMobileNo(oldMobNo, newMobNo);
                    break;

                case 5:
                    exit(0);

                default:
                    cout << endl << "Enter Valid Input !!!";
            }
        }while(1);
    }
 }while(1);
 return 0; }
