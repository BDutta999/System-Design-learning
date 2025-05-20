#include<bits/stdc++.h>
using namespace std;

class Car{
protected:
    int speed;
public:
    Car(){
        speed=100;
    }
    void accelerate(){
        cout<<"Accelerating"<<endl;
        speed+=50;
    }
    void displaySpeed() {
        cout << "Speed: " << speed << endl;
    }

    virtual void brake(){
        cout<<"applying brakes"<<endl;
        speed-=20;
    }
    
};

class ElectricCar : public Car{
private:
    int charge;

public:
    ElectricCar() : Car(){
        charge=0;
    }
    void brake(){
        cout<<"applying brakes"<<endl;
        speed-=20;
        charge+=20;
    }
};



int main(){
    Car *c = new Car();
    c->brake();
    c->accelerate();
    c->displaySpeed();
}