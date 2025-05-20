#include<bits/stdc++.h>
using namespace std;

class Animal{
public: 
    void eat(){
        cout<<"this animal eats food"<<endl;
    }
};

class Dog : public Animal{
public:
    void bark(){
        cout<<"The dog barks"<<endl;
    }
};

int main(){
    Dog d;
    d.eat();   // inherited from Animal
    d.bark();  // defined in Dog
}