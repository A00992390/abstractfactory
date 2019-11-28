//
// Created by msi on 11/26/2019.
//
#include "maze_factory.hpp"
#ifndef ABSTRACTFACTORY_ENHANCEDFAERYLAND_HPP
#define ABSTRACTFACTORY_ENHANCEDFAERYLAND_HPP

// wall class
class enhancedwall: public wall {
public:
    enhancedwall(int side): wall(side) {
        switch(side) {
            case 0:
                cout << "creating North enhancedwall\n";
                break;
            case 1:
                cout << "creating East enhancedwall\n";
                break;
            case 2:
                cout << "creating South enhancedwall\n";
                break;
            case 3:
                cout << "creating West enhancedwall\n";
                break;
        }
    }
};
// room class
class enhancedroom:public room {
public:
    // constructing room with a roomNumber
    enhancedroom(int n): room(n) {
        cout << "creating enhancedroom " << n << endl;
    }
    // add wall north, east, south, west
    void add_wall(wall *w) override {
        switch(w->getSide()) {
            case 0:
                cout << "enhancedroom " << getRoomNo() << " now has North enhancedwall\n";
                break;
            case 1:
                cout << "enhancedroom " << getRoomNo() << " now has East enhancedwall\n";
                break;
            case 2:
                cout << "enhancedroom " << getRoomNo() << " now has South enhancedwall\n";
                break;
            case 3:
                cout << "enhancedroom " << getRoomNo() << " now has West enhancedwall\n";
                break;
        }
    }
};

// door class
class enhanceddoor:public door {
public:
    // door constructor that connects two rooms
    enhanceddoor(room &r1, room &r2): door(r1, r2) {
        cout << "creating enhanced door that connects to enhancedroom " << r1.getRoomNo() << " and enhancedroom " << r2.getRoomNo() << endl;
    }
};

// maze class
class enhancedmaze: public maze{
public:
    // construct a maze
    enhancedmaze() {
        cout << "creating enhancedmaze\n";
    }
    // add room
    void add_room(room &r) override {
        cout << "enhancedmaze now has enhancedroom " << r.getRoomNo() << endl;
    }
    // add door
    void add_door(door &d) override {
        cout << "enhancedmaze now has enhanceddoor that connects to  enhancedroom " << d.getRoom1().getRoomNo() << " and enhancedroom " << d.getRoom2().getRoomNo() << endl;
    }
};

class enhancedfaeryland: public maze_factory {
    maze* make_maze() override {
        return new enhancedmaze();
    }

    wall* make_wall(int side) override {
        return new enhancedwall{side};
    }

    room* make_room(int roomNum) override {
        return new enhancedroom{roomNum};
    }

    door* make_door(room &r1, room &r2) override {
        return new enhanceddoor{r1, r2};
    }
};


#endif //ABSTRACTFACTORY_ENHANCEDFAERYLAND_HPP
