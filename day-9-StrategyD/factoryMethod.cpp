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
class BasicWheatBurger : public Burger{
public:
    void prepare() override {
        cout<<"It is a Basic Wheat Burger "<<endl;
    }
};
class StandardWheatBurger : public Burger{
public:
    void prepare() override {
        cout<<"It is a Standard Wheat Burger"<<endl;
    }
};
class PremiumWheatBurger : public Burger{
public:
    void prepare() override {
        cout<<"It is a Premium Wheat Burger"<<endl;
    }
};
class BurgerFactory{
public:
    virtual Burger* createBurger(string& type) = 0;
};
class SinghBurger : public BurgerFactory{
public:
    Burger* createBurger(string& type) override {
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
class KingBurger : public BurgerFactory{
public:
    Burger* createBurger(string& type) override {
        if(type=="Basic"){
            return new BasicWheatBurger();
        }
        else if(type=="Standard"){
            return new StandardWheatBurger();
        }
        else if(type=="Premium"){
            return new PremiumWheatBurger();
        }
        else{
            cout<<"invalid wheat burger type"<<endl;
            return nullptr;
        }
    }
};

int main(){
    string type = "Basic";
    BurgerFactory* myBurgerFactory = new KingBurger();
    Burger* burger = myBurgerFactory->createBurger(type);
    burger->prepare();
}