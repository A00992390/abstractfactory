//
// Created by msi on 11/28/2019.
//

#ifndef ABSTRACTFACTORY_WALL_HPP
#define ABSTRACTFACTORY_WALL_HPP


#include <iostream>
using namespace std;

// abstract wall
class Wall {
public:
    virtual void print(){};
    virtual ~Wall()= default;
};

// enhanced wall
class enhancedWall: public Wall {
public:
    void print()override {
        cout<<"Enhanced Wall"<<endl;
    };
    ~enhancedWall() override {
        cout<<"delete Enhanced Wall "<<endl;
    };
};

// futuristic wall
class futuristicWall: public Wall {
public:
    void print()override {
        cout<<"Futuristic Wall"<<endl;
    };
    ~futuristicWall()override {
        cout<<"delete futuristic Wall "<<endl;
    };
};

#endif //ABSTRACTFACTORY_WALL_HPP
