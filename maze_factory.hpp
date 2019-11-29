//
// Created by msi on 11/28/2019.
//

#ifndef ABSTRACTFACTORY_MAZE_FACTORY_HPP
#define ABSTRACTFACTORY_MAZE_FACTORY_HPP


#include "maze.hpp"
// parent maze factory interface
class Maze_Factory {
public:
    // create maze pure virtual
    virtual Maze* createMaze() = 0;
    // create room pure virtual
    virtual Room*createRoom() = 0;
    // create door pure virtual
    virtual Door* createDoor(Room*r1,Room*r2) = 0;
    // create wall pure virtual
    virtual Wall* createWall() = 0;
    // default destructor
    virtual ~Maze_Factory() = default;
};

// enhanced factory
class enhancedFactory:public Maze_Factory{
public:
    Maze*createMaze()override {
        return new enhancedMaze;
    };
    Room*createRoom()override {
        return new enhancedRoom;
    };
    Door*createDoor(Room*r1,Room*r2)override {
        return  new enhancedDoor(r1,r2);
    };
    Wall*createWall()override {
        return new enhancedWall;
    };
    ~enhancedFactory()override = default;
};

// futuristic factory
class futuristicFactory:public Maze_Factory{
public:
    Maze*createMaze()override {
        return new futuristicMaze;

    };
    Room*createRoom()override {
        return new futuristicRoom;
    };
    Door*createDoor(Room*r1,Room*r2)override {
        return  new futuristicDoor(r1,r2);
    };
    Wall*createWall()override {
        return new futuristicWall;
    };
    ~futuristicFactory()override = default;
};




#endif //ABSTRACTFACTORY_MAZE_FACTORY_HPP
