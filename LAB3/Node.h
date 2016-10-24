// Program 3:    Lab 3
// Name:         Tyler Jewell
// Class:        COMP 2710
// Date:         October 24, 2016
// E-Mail:       tjj0013@auburn.edu
//
// Description:  This is the header file for the Node class

#include <iostream>

using namespace std;

//Class: Node
// Description: This class will set the node names and attach nodes.

class Node
{
public:
    Node(string newname);
    Node();
    void setNodeName(string newname);
    string getNodeName();
    void attachNewNode(Node *newNode, int direction);
    Node* getAttachedNode(int direction);
    void attachSnakeLadderNode(Node *newNode);
    Node* getSnakeLadderNode();

private:
    string name;
    Node* attachedNodes[4];
    Node* snakeOrLadderNodes;
};
