#include<bits/stdc++.h>
using namespace std;
//Interface for walk
class WalkableRobot{
public:
    virtual void walk()=0;
    virtual ~WalkableRobot(){}
};
//strategy for walk
//Normal walk
class NormalWalk : public WalkableRobot{
public:
    void walk() override{
        cout<<"walking normally"<<endl;
    }
};
//No walk
class NoWalk : public WalkableRobot{
public:
    void walk() override{
        cout<<"can't able to walk"<<endl;
    }
};
//Interface for talk
class TalkableRobot{
public:
    virtual void talk()=0;
    virtual ~TalkableRobot(){}
};
//strategy for talk
//normal talk
class NormalTalk : public TalkableRobot{
public:
    void talk() override {
        cout<<"Normal Talk"<<endl;
    }
};
//No talk
class NoTalk : public TalkableRobot{
public:
    void talk() override {
        cout<<"can't able to talk"<<endl;
    }
};

//Interface for fly
class FlyableRobot{
public:
    virtual void fly()=0;
    virtual ~FlyableRobot(){}
};
//strategy for fly
//normal fly
class NormalFly : public FlyableRobot{
public:
    void fly() override {
        cout<<"Normal fly"<<endl;
    }
};
//No fly
class NoFly : public FlyableRobot{
public:
    void fly() override {
        cout<<"can't able to fly"<<endl;
    }
};

//base class for robot
class Robot{
protected:  
    WalkableRobot* walkBehaviour;
    TalkableRobot* talkBehaviour;
    FlyableRobot* flyBehaviour;

public:
    Robot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f){
        this->walkBehaviour=w;
        this->talkBehaviour=t;
        this->flyBehaviour=f;
    }
    void walk(){
        walkBehaviour->walk();
    }  
    void talk(){
        talkBehaviour->talk();
    }  
    void fly(){
        flyBehaviour->fly();
    }  

    virtual void projection() = 0; //abstract method ->does not change

};

class CompanionRobot : public Robot {
public:
    CompanionRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f) : Robot(w, t, f) {}

    void projection() override {
        cout << "Displaying friendly companion features" << endl;
    }
};

class WorkerRobot : public Robot {
public:
    WorkerRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f) : Robot(w, t, f) {}

    void projection() override {
        cout << "Displaying worker efficiency features" << endl;
    }
};

int main(){
    Robot *robot1 = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NoFly());
    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection();
    cout<<endl;
    Robot *robot2 = new WorkerRobot(new NoWalk(), new NoTalk(), new NoFly());
    robot2->walk();
    robot2->talk();
    robot2->fly();
    robot2->projection();
}