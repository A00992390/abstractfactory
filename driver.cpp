#include <iostream>
#include "maze_game.hpp"
#include "maze_factory.hpp"

// main
int main() {
    cout<<"======== Enhanced Factory ========"<<endl;

    Maze_Game mazeGame;
    Maze_Factory* enhancedfactory = new enhancedFactory;
    Maze* enhancedMaze = mazeGame.createMaze(enhancedfactory);


    cout<<"\n======== Futuristic Factory ========"<<endl;

    Maze_Factory* futuristicfactory = new futuristicFactory;
    Maze* futuristicMaze = mazeGame.createMaze(futuristicfactory);


    cout<<"\n======== Deleting ========"<<endl;
    // deleting allocated memory
    delete enhancedMaze;
    delete enhancedfactory;

    delete  futuristicMaze;
    delete futuristicfactory;

    return 0;
}