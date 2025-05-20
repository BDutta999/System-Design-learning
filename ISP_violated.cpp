#include<bits/stdc++.h>
using namespace std;

class Shape{
public:
    virtual double area() = 0;
    virtual double volume() = 0;//2d shapes ❌
};

class Square : public Shape{
private:
    double side;

public:
    Square(double s) : side(s){}
    double area() override {
        return side*side;
    }
    double volume() override {
        throw logic_error("2D shapes don\'t have volume");
    }
};
class Rectangle : public Shape{
private:
    double length, breadth;

public:
    Rectangle(double l, double b) : length(l), breadth(b) {}
    double area() override {
        return length*breadth;
    }
    double volume() override {
        throw logic_error("2D shapes don\'t have volume");
    }
};
class Cube : public Shape{
private:
    double side;

public:
    Cube(double s) : side(s){}
    double area() override {
        return 6*side*side;
    }
    double volume() override {
        return side*side*side;
    }
};



int main(){
    // Shape* s1 = new Square(5);
    // cout<<s1->area()<<endl;
    // cout<<s1->volume()<<endl;
    Shape* s2 = new Rectangle(5,6);
    cout<<s2->area()<<endl;
    cout<<s2->volume()<<endl;
    // Shape* s3 = new Cube(5);
    // cout<<s3->area()<<endl;
    // cout<<s3->volume()<<endl;
}