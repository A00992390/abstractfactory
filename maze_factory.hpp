//
// Created by msi on 11/26/2019.
//
#include <iostream>
using namespace std;
#ifndef ABSTRACTFACTORY_MAZE_FACTORY_HPP
#define ABSTRACTFACTORY_MAZE_FACTORY_HPP


// wall class
class wall {
protected:
    int side;
public:
    wall(int side): side{side} {
//        switch(side) {
//            case 0:
//                cout << "creating North wall\n";
//                break;
//            case 1:
//                cout << "creating East wall\n";
//                break;
//            case 2:
//                cout << "creating South wall\n";
//                break;
//            case 3:
//                cout << "creating West wall\n";
//                break;
//        }
    }

    int getSide() {
        return side;
    }
};

// room class
class room {
protected:
    int roomNo;
public:
    // constructing room with a roomNumber
    room(int n): roomNo{n} {
//        cout << "creating room " << n << endl;
    }
    // get room number
    int getRoomNo() {
        return this->roomNo;
    }
    // add wall north, east, south, west
    virtual void add_wall(wall* w) {
        switch(w->getSide()) {
            case 0:
                cout << "room " << getRoomNo() << " now has North wall\n";
                break;
            case 1:
                cout << "room " << getRoomNo() << " now has East wall\n";
                break;
            case 2:
                cout << "room " << getRoomNo() << " now has South wall\n";
                break;
            case 3:
                cout << "room " << getRoomNo() << " now has West wall\n";
                break;
        }
    }
};
// door class
class door {
protected:
    room r1, r2;
public:
    // door constructor that connects two rooms
    door(room &r1, room &r2): r1{r1}, r2{r2} {
//        cout << "creating door that connects to room " << r1.getRoomNo() << " and room " << r2.getRoomNo() << endl;
    }
    // get the room
    room getRoom1() {
        return r1;
    }
    // get the room
    room getRoom2() {
        return r2;
    }
};

// maze class
class maze{
public:
    // construct a maze
    maze() {
//        cout << "creating maze\n";
    }
    // add room
    virtual void add_room(room &r) {
        cout << "maze now has room " << r.getRoomNo() << endl;
    }
    // add door
    virtual void add_door(door &d) {
        cout << "maze now has door that connects to  room " << d.getRoom1().getRoomNo() << " and room " << d.getRoom2().getRoomNo() << endl;
    }
};

// maze_factory class
class maze_factory {
public:
    virtual maze* make_maze() = 0;

    virtual wall* make_wall(int side)  = 0;

    virtual room* make_room(int roomNum)  = 0;

    virtual door* make_door(room &r1, room &r2)  = 0;
};

#endif //ABSTRACTFACTORY_MAZE_FACTORY_HPP
