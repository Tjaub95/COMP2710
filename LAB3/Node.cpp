// Program:      Lab 3
// Name:         Tyler Jewell
// Class:        COMP 2710
// Date:         October 24, 2016
// E-Mail:       tjj0013@auburn.edu
//
// Description:  This class will set the node names and attach nodes.

#include "Node.h"

//Constructor: Node()
//Description: Sets the initial variables to null.

Node::Node()
{
    attachedNodes[0] = NULL;
    attachedNodes[1] = NULL;
    attachedNodes[2] = NULL;
    attachedNodes[3] = NULL;
    snakeOrLadderNodes = NULL;
}

//Constructor: Node()
//Description: Sets the initial variables to null and sets the name of the current node.

Node::Node(string newname)
{
    name = newname;
    attachedNodes[0] = NULL;
    attachedNodes[1] = NULL;
    attachedNodes[2] = NULL;
    attachedNodes[3] = NULL;
    snakeOrLadderNodes = NULL;
}

//Function:    setNodeName
//Description: sets the name of the node to
//             the variable that is being passed
//             to the function.

void Node::setNodeName(string newname)
{
    name = newname;
}

//Function:    getName
//Description: returns the name of the node.

string Node::getNodeName()
{
    return name;
}

//Function:    attachNewNode
//Description: attaches a node to the current
//             node in the correct direction

void Node::attachNewNode(Node *newNode, int direction)
{
    attachedNodes[direction] = newNode;
}

//Function:    getAttachedNode
//Description: returns the node that is attached to the
//             current node in the direction that is being
//             passed to the function.

Node* Node::getAttachedNode(int direction)
{
    return attachedNodes[direction];
}

//Function:    attachSnakeLadderNode
//Description: attaches the ladder or chute node to the current node

void Node::attachSnakeLadderNode(Node *newNode)
{
    snakeOrLadderNodes = newNode;
}

//Function:    getSnakeLadderNode
//Description: returns the ladder or chute node

Node* Node::getSnakeLadderNode()
{
    return snakeOrLadderNodes;
}
