//
// Created by msi on 11/28/2019.
//

#ifndef ABSTRACTFACTORY_MAZE_GAME_HPP
#define ABSTRACTFACTORY_MAZE_GAME_HPP
#include "maze_factory.hpp"

// Maze game
class Maze_Game {
public:
    Maze* createMaze(Maze_Factory* mazeFactory){
        Maze*maze= mazeFactory->createMaze();
        // room
        Room* room1=mazeFactory->createRoom();
        Room* room2=mazeFactory->createRoom();
        maze->addRoom(room1);
        maze->addRoom(room2);

        Door* door1 = mazeFactory->createDoor(room1,room2);
        maze->addDoor(door1);

        Wall* wall1=mazeFactory->createWall();
        maze->addWall(wall1);

        maze->print();

        return maze;
    }
};


#endif //ABSTRACTFACTORY_MAZE_GAME_HPP
