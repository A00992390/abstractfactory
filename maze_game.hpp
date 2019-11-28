//
// Created by msi on 11/26/2019.
//
#include "maze_factory.hpp"
#ifndef ABSTRACTFACTORY_MAZE_GAME_HPP
#define ABSTRACTFACTORY_MAZE_GAME_HPP


class maze_game {
public:
    maze create_maze(maze_factory &mf) {
        // maze
        maze *maze = mf.make_maze();
        // room 1
        room *r1 = mf.make_room(1);
        // room 2
        room *r2 = mf.make_room(2);
        // door connects to r1 and r2
        door *door = mf.make_door(*r1, *r2);
        // north wall
        wall *w1 = mf.make_wall(0);
        // east wall
        wall *w2 = mf.make_wall(1);
        // south wall
        wall *w3 = mf.make_wall(2);
        // west wall
        wall *w4 = mf.make_wall(3);

        // add wall to room 1
        r1->add_wall(w1);
        r1->add_wall(w2);
        r1->add_wall(w3);
        r1->add_wall(w4);
        // add wall to room 2
        r2->add_wall(w1);
        r2->add_wall(w2);
        r2->add_wall(w3);
        r2->add_wall(w4);

        // add door
        maze->add_room(*r1);
        maze->add_room(*r2);
        // add door that connects to r1 and r2
        maze->add_door(*door);

        //deleting allocated memory
        delete w4;
        delete w3;
        delete w2;
        delete w1;
        delete door;
        delete r2;
        delete r1;
        delete maze;
    }
};


#endif //ABSTRACTFACTORY_MAZE_GAME_HPP
