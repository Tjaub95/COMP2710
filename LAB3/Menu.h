// Program 3:    Lab 3
// Name:         Tyler Jewell
// Class:        COMP 2710
// Date:         October 24, 2016
// E-Mail:       tjj0013@auburn.edu
//
// Description:  This is the header file for the Menu class

#include <iostream>
#include <string>
#include <fstream>
#include "Node.h"
#include <cstdlib>
#include <cstring>

using namespace std;

// Class:        Menu
// Description:  This class will create the graph for
//               the game and will ask the user which
//               direction they would like to go until
//               they reach the end of the game.

class Menu
{
public:
    void userIn();
    void readFile(string);
    void dirTaken();
    void switchNodeLetterSL(char*);
    void switchNodeNumberSL(string, char);
    void switchNode(string);
    void promptUser();
    void snakeOrLadder();
    void maze();
    void checkNode(string);

private:
    Node* NodeArray[49];
    string move, node, mazeRoute;
    int currentNode;
    bool sORl;
};
