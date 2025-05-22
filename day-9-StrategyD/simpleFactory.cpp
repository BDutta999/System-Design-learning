#include<bits/stdc++.h>
using namespace std;

class Burger{
public:
    virtual void prepare() = 0;
    virtual ~Burger(){}
};

class Basicburger : public Burger{
public:
    void prepare() override{
        cout<<"It is a Basic Burger"<<endl;
    }
};

class StandardBurger : public Burger{
public:
    void prepare() override {
        cout<<"It is a Standard Burger"<<endl;
    }
};

class PremiumBurger : public Burger{
public:
    void prepare() override {
        cout<<"It is a Premium Burger"<<endl;
    }
};

class BurgerFactory{
public:
    Burger* createBurger(string& type){
        if(type=="Basic"){
            return new Basicburger();
        }
        else if(type=="Standard"){
            return new StandardBurger();
        }
        else if(type=="Premium"){
            return new PremiumBurger();
        }
        else{
            cout<<"invalid burger type"<<endl;
            return nullptr;
        }
    }
};

int main(){
    string type = "Gold";
    BurgerFactory* myBurgerFactory = new BurgerFactory();
    Burger* burger = myBurgerFactory->createBurger(type);
    burger->prepare();
}