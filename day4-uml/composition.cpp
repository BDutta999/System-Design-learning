#include<bits/stdc++.h>
using namespace std;

class A{
public: 
    void method1(){
        cout<<"Method1 from class A"<<endl;
    }
};

class B{
private:
    A& aRef;
public:
    B(A& obj) : aRef(obj){}
    void method2() {
        cout << "Method2 from class B" << endl;
        aRef.method1();  // Call A's method via reference
    }
};

int main(){
    A aObj;
    B bObj(aObj);  // Pass reference of A to B

    bObj.method2();  // Calls B's and then A's method
}