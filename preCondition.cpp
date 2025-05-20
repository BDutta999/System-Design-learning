#include<bits/stdc++.h>
using namespace std;

class User{
public:
    virtual void createPass(string pass){
        if(pass.length()<8){
            throw invalid_argument("pass must be 8 chars long");
        }
        cout<<"Pass created successfully"<<endl;
    }
};

class AdminUser : public User{
public:    
    void createPass(string pass) override{
        if(pass.length()<6){
            throw invalid_argument("pass must be 6 chars long");
        }
        cout<<"Pass created successfully"<<endl;
    }
};



int main(){
    User* user = new User();
    user->createPass("a56905ffg");
}