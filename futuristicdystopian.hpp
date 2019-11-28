//
// Created by msi on 11/27/2019.
//
#include "maze_factory.hpp"
#ifndef ABSTRACTFACTORY_FUTURISTICDYSTOPIAN_HPP
#define ABSTRACTFACTORY_FUTURISTICDYSTOPIAN_HPP
// wall class
class futuristicdystopianwall: public wall {
public:
    futuristicdystopianwall(int side): wall(side) {
        switch(side) {
            case 0:
                cout << "creating North futuristicdystopianwall\n";
                break;
            case 1:
                cout << "creating East futuristicdystopianwall\n";
                break;
            case 2:
                cout << "creating South futuristicdystopianwall\n";
                break;
            case 3:
                cout << "creating West futuristicdystopianwall\n";
                break;
        }
    }
};
// room class
class futuristicdystopianroom:public room {
public:
    // constructing room with a roomNumber
    futuristicdystopianroom(int n): room(n) {
        cout << "creating futuristicdystopianroom " << n << endl;
    }
    // add wall north, east, south, west
    void add_wall(wall *w) override {
        switch(w->getSide()) {
            case 0:
                cout << "futuristicdystopianroom " << getRoomNo() << " now has North futuristicdystopianwall\n";
                break;
            case 1:
                cout << "futuristicdystopianroom " << getRoomNo() << " now has East futuristicdystopianwall\n";
                break;
            case 2:
                cout << "futuristicdystopianroom " << getRoomNo() << " now has South futuristicdystopianwall\n";
                break;
            case 3:
                cout << "futuristicdystopianroom " << getRoomNo() << " now has West futuristicdystopianwall\n";
                break;
        }
    }
};

// door class
class futuristicdystopiandoor:public door {
public:
    // door constructor that connects two rooms
    futuristicdystopiandoor(room &r1, room &r2): door(r1, r2) {
        cout << "creating futuristicdystopian door that connects to futuristicdystopian room " << r1.getRoomNo() << " and futuristicdystopian room " << r2.getRoomNo() << endl;
    }
};

// maze class
class futuristicdystopianmaze: public maze{
public:
    // construct a maze
    futuristicdystopianmaze() {
        cout << "creating futuristicdystopianmaze\n";
    }
    // add room
    void add_room(room &r) override {
        cout << "futuristicdystopianmaze now has futuristicdystopianroom " << r.getRoomNo() << endl;
    }
    // add door
    void add_door(door &d) override {
        cout << "futuristicdystopianmaze now has futuristicdystopiandoor that connects to  futuristicdystopianroom " << d.getRoom1().getRoomNo() << " and futuristicdystopianroom " << d.getRoom2().getRoomNo() << endl;
    }
};

class futuristicdystopian: public maze_factory {
    maze* make_maze() override {
        return new futuristicdystopianmaze();
    }

    wall* make_wall(int side) override {
        return new futuristicdystopianwall{side};
    }

    room* make_room(int roomNum) override {
        return new futuristicdystopianroom{roomNum};
    }

    door* make_door(room &r1, room &r2) override {
        return new futuristicdystopiandoor{r1, r2};
    }
};


#endif //ABSTRACTFACTORY_FUTURISTICDYSTOPIAN_HPP
