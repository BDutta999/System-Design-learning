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

class CheatAccount : public BankAccount{
public:
    CheatAccount(double b) : BankAccount(b){}
    
    void withdraw(double ammount) override{
        balance -= ammount;
        cout<<"Remaining balance: "<<balance<<'\n';

    }
};



int main(){
    BankAccount* bankAccount = new BankAccount(100);
    // BankAccount* bankAccount = new CheatAccount(200);
    bankAccount->withdraw(200);
}