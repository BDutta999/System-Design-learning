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

//garlicBread
class GarlicBread{
public:
    virtual void prepare() = 0;
};

class BasicGarlicBread : public GarlicBread{
public:
    void prepare() override{
        cout<<"It is a Basic Garlic Bread"<<endl;
    }
};

class CheeseGarlicBread : public GarlicBread{
public:
    void prepare() override {
        cout<<"It is a Cheese Garlic Bread"<<endl;
    }
};

class BasicWheatGarlicBread : public GarlicBread{
public:
    void prepare() override {
        cout<<"It is a Basic Wheat Garlic Bread "<<endl;
    }
};
class CheeseWheatGarlicBread : public GarlicBread{
public:
    void prepare() override {
        cout<<"It is a Cheese Wheat Garlic Bread"<<endl;
    }
};

class MealFactory{
public:
    virtual Burger* createBurger(string& type) = 0;
    virtual GarlicBread* createGarlicBread(string& type) = 0;
};

class SinghBurger : public MealFactory{
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
    GarlicBread* createGarlicBread(string& type) override {
        if(type=="Basic"){
            return new BasicGarlicBread();
        }
        else if(type=="Cheese"){
            return new CheeseGarlicBread();
        }
        else{
            cout<<"invalid Garlic Bread type"<<endl;
            return nullptr;
        }
    }
};
class KingBurger : public MealFactory{
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
    GarlicBread* createGarlicBread(string& type) override {
        if(type=="Basic"){
            return new BasicWheatGarlicBread();
        }
        else if(type=="Cheese"){
            return new CheeseWheatGarlicBread();
        }
        else{
            cout<<"invalid Wheat Garlic Bread type"<<endl;
            return nullptr;
        }
    }
};

int main(){
    string type = "Basic";
    MealFactory* myMealFactory1 = new KingBurger();
    Burger* burger = myMealFactory1->createBurger(type);
    burger->prepare();
    cout<<endl;
    string type1 = "Cheese";
    MealFactory* myMealFactory2 = new KingBurger();
    GarlicBread* garlicBread = myMealFactory2->createGarlicBread(type1);
    garlicBread->prepare();
}