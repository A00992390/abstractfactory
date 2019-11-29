//
// Created by msi on 11/28/2019.
//

#ifndef ABSTRACTFACTORY_ROOM_HPP
#define ABSTRACTFACTORY_ROOM_HPP


#include <iostream>
using namespace std;

// abstract room
class Room {
public:
    virtual void print()=0;
    virtual ~Room()= default;
};

// enhanced room
class enhancedRoom: public Room{
public:

    void print() override{
        cout<<"Enhanced Room"<<endl;
    }
    ~enhancedRoom() override {
        cout<<"delete enhanced Room "<<endl;
    };
};

// futuristic room
class futuristicRoom: public Room{
public:
    void print() override {
        cout<<"futuristic Room"<<endl;
    }
    ~futuristicRoom() override {
        cout<<"delete futuristic Room "<<endl;
    };
};


#endif //ABSTRACTFACTORY_ROOM_HPP
