//
// Created by msi on 11/28/2019.
//

#ifndef ABSTRACTFACTORY_DOOR_HPP
#define ABSTRACTFACTORY_DOOR_HPP


#include <iostream>
using namespace std;
// abstract door
class Door {
public:
    Room*r1= nullptr;
    Room*r2= nullptr;
    Door()= default;
    Door(Room* r1,Room*r2){
        this->r1=r1;
        this->r2=r2;
    }
    virtual void print(){};
    virtual ~Door()= default;
};

class enhancedDoor:public Door{
public:


    enhancedDoor(Room* r1,Room*r2){
        Door(r1,r2);

    }
    void print()override {
        cout<<"Enhanced Door connect"<<endl;
    }
    ~enhancedDoor() override {
        cout<<"delete enhanced Door "<<endl;
    };
};


class futuristicDoor:public Door{
public:
    futuristicDoor(Room* r1,Room*r2){
        Door(r1,r2);
    }
    void print()override {
        cout<<"futuristic Door connect"<<endl;
    }
    ~futuristicDoor() override{
        cout<<"delete futuristic Door "<<endl;
    };
};


#endif //ABSTRACTFACTORY_DOOR_HPP
