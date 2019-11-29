//
// Created by msi on 11/28/2019.
//

#ifndef ABSTRACTFACTORY_MAZE_HPP
#define ABSTRACTFACTORY_MAZE_HPP


#include "room.hpp"
#include "door.hpp"
#include "wall.hpp"
#include "vector"

class Maze {
public:
    vector<Room*> rooms;
    vector<Door*> doors;
    vector<Wall*> walls;
    void addRoom(Room* newRoom){
        rooms.push_back(newRoom);
    };
    void addDoor(Door* newDoor){
        doors.push_back(newDoor);
    };
    void addWall(Wall* newWall){
        walls.push_back(newWall);
    };

    virtual void print(){
        for (int i = 0; i <rooms.size() ; ++i) {
            rooms[i]->print();
        }
        for (int i = 0; i <doors.size() ; ++i) {
            doors[i]->print();
        }
        for (int i = 0; i <walls.size() ; ++i) {
            walls[i]->print();
        }
    };
    // deleting
    virtual ~Maze(){
        for (int i = 0; i <doors.size() ; ++i) {
            delete doors[i];
        }
        for (int i = 0; i <walls.size() ; ++i) {
            delete walls[i];
        }
        for (int i = 0; i <rooms.size() ; ++i) {
            delete rooms[i];
        }

    };
};

class futuristicMaze: public Maze{
public:
    void print()override {
        cout<<"Futuristic Maze"<<endl;
        Maze::print();
    }
    ~futuristicMaze() override = default;
};

class enhancedMaze:public Maze{
public:
    void print()override {
        cout<<"Enhanced Maze"<<endl;
        Maze::print();

    }
    ~enhancedMaze() override = default;

};


#endif //ABSTRACTFACTORY_MAZE_HPP
