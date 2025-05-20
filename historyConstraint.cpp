#include<bits/stdc++.h>
using namespace std;

class BankAccount{
protected:
    double balance;
public:
    BankAccount(double b){
        if(b<0){
            throw invalid_argument("Balace cannot be -ve");
        }
        balance=b;
    }


    virtual void withdraw(double ammount){
        if((balance-ammount)<0) throw runtime_error("Insufficient balance");
        balance -= ammount;
        cout<<"Remaining balance: "<<balance<<'\n';
    }
    
};

class FixedDepositAccount : public BankAccount{
public:
    FixedDepositAccount(double b) : BankAccount(b){}
    
    void withdraw(double ammount) override{
        throw invalid_argument("Withdraw is not allowed in FD account");

    }
};



int main(){
    // BankAccount* bankAccount = new BankAccount(100);
    BankAccount* bankAccount = new FixedDepositAccount(200);
    bankAccount->withdraw(100);
}