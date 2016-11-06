// Program 3:    Lab 3
// Name:         Tyler Jewell
// Class:        COMP 2710
// Date:         October 24, 2016
// E-Mail:       tjj0013@auburn.edu
//
// Description:  This class will create the graph for
//               the game and will ask the user which
//               direction they would like to go until
//               they reach the end of the game.

#include "Menu.h"
string start;
string destination;

//Function:    userIn
//Description: Prompts the user for the direction they would like to go.

void Menu::userIn()
{
    string fileIn;
    bool goodIn = false;
    ifstream infile;

    //Continues to prompt user for input until a valid file name is entered
    while(!goodIn)
    {
		cout << "Please enter file name: ";
		cin >> fileIn;
		cout << endl;

        //Opens the file
        infile.open(fileIn.c_str());
        if (infile.is_open())
        {
            //calls the read file function
            readFile(fileIn);
            goodIn = true;
            infile.close();
        }
    }

    cout << endl;
    cout << "=========================================================================" << endl;
    cout << "|          Welcome to the Maze Runner with Snakes and Ladders           |" << endl;
    cout << "=========================================================================" << endl << endl << endl;

    //calls the promptUser function
    promptUser();
}

//Function:    readFile
//Description: Reads the file and creates the graph

void Menu::readFile(string file)
{
    string filenameIn = file, name, north, south, east, west, snakeOrladder, star;
    ifstream infile;
    int j;

    //opens file for reading
    infile.open(filenameIn.c_str());

	string dummyString;
	infile >> dummyString;
	infile >> start;
	infile >> destination;

    //creates 49 node objects
    for(int i = 0; i < 49; i++)
        NodeArray[i] = new Node();

    //reads the file and sets the name of each node
    //and attaches the nodes in the correct places
    for(int i = 0; i < 48; i++)
    {
        //Reads the first thing on each line and creates a node with that name
        infile >> name;
        NodeArray[i]->setNodeName(name);

        //Reads the second thing on each line and attaches the node in the north direction
        infile >> north;

        //checks to see if an actual node is being attached if not attaches it to a star node
        if(north == "*")
        {
            NodeArray[i]->attachNewNode(NodeArray[48], 0);
        }

        //Attaches the correct node to the current node in the right direction
        else
        {
            char temp[1] = {north[1]};
            j = atoi (temp);

            char temp1[1] = {north[0]};
            int mod = temp1[0] - 'A';
            NodeArray[i]->attachNewNode(NodeArray[(j - 1) * 8 + mod], 0);
        }

        //Reads the third thing on each line and attaches the node in the east direction
        infile >> east;

        //checks to see if an actual node is being attached if not attaches it to a star node
        if(east == "*")
        {
            NodeArray[i]->attachNewNode(NodeArray[48], 1);
        }

        //Attaches the correct node to the current node in the right direction
        else
        {
            char temp[1] = {east[1]};
            j = atoi (temp);

            char temp1[1] = {east[0]};
            int mod = temp1[0] - 'A';
            NodeArray[i]->attachNewNode(NodeArray[(j - 1) * 8 + mod], 1);
        }

        //Reads the fourth thing on each line and attaches the node in the south direction
        infile >> south;

        //checks to see if an actual node is being attached if not attaches it to a star node
        if(south == "*")
        {
            NodeArray[i]->attachNewNode(NodeArray[48], 2);
        }

        //Attaches the correct node to the current node in the right direction
        else
        {
            char temp[1] = {south[1]};
            j = atoi (temp);

            char temp1[1] = {south[0]};
            int mod = temp1[0] - 'A';
            NodeArray[i]->attachNewNode(NodeArray[(j - 1) * 8 + mod], 2);
        }

        //Reads the fifth thing on each line and attaches the node in the west direction
        infile >> west;

        //checks to see if an actual node is being attached if not attaches it to a star node
        if(west == "*")
        {
            NodeArray[i]->attachNewNode(NodeArray[48], 3);
        }

        //Attaches the correct node to the current node in the right direction
        else
        {
            char temp[1] = {west[1]};
            j = atoi (temp);

            char temp1[1] = {west[0]};
            int mod = temp1[0] - 'A';
            NodeArray[i]->attachNewNode(NodeArray[(j - 1) * 8 + mod], 3);
        }

        //Reads the sixth thing on each line and attaches the node as a chute or ladder
        infile >> snakeOrladder;

        //checks to see if an actual node is being attached if not attaches it to a star node
        if(snakeOrladder == "*")
        {
            NodeArray[i]->attachSnakeLadderNode(NodeArray[48]);
        }

        //Attaches the correct node to the current node in the right direction
        else
        {
            char temp[1] = {snakeOrladder[1]};
            j = atoi (temp);

            char temp1[1] = {snakeOrladder[0]};
            int mod = temp1[0] - 'A';
            NodeArray[i]->attachSnakeLadderNode(NodeArray[(j - 1) * 8 + mod]);
        }
    }
    infile.close();

    //Opens the file for reading
    infile.open(filenameIn.c_str());

    //Continues the loop until nothing is left or it hits break statement
    while (infile >> star)
    {
        //checks to see if star equals *
        if(star == "*")
        {
            //If a * is found in the file then the last node is set to * and breaks out of loop
            NodeArray[48]->setNodeName(star);
            break;
        }
    }

}

//Function:    promptUser
//Description: Continuously prompts the user for the direction they want to go

void Menu::promptUser()
{
    int counter = 0;
    currentNode = 0;

    //continues until the user reaches the last node
    while(currentNode != 47)
    {
        string choice;

        //counter variable to count the number of steps
        counter++;

        cout << endl << "You are currently in Node " << NodeArray[currentNode]->getNodeName();
        cout << " of the Maze Runner,";

        //calls maze function
        maze();

        //calls snakeOrLadder function
        snakeOrLadder();

        //checks to see if the snakeOrLadder function returned true that the room had a snake or ladder
        if(sORl)
        {
            //calls maze function
            maze();
			cout << " and you have" << endl << "taken a Ladder to Node " << node;
            cout << ", you can go ";

            //calls dirTaken function
            dirTaken();
            cout << move << ". What is your choice? ";

            //takes in users direction
            cin >> choice;

            //calls switchRoom function
            switchNode(choice);
        }

        //if room did not have a snake or ladder
        else
        {
            cout << " you can go " << endl;

            //calls dirTaken function
            dirTaken();
            cout << move << ". What is your choice? ";

            //takes in users direction
            cin >> choice;

            switchNode(choice);
        }

    }

    //Adds the last node visited to the string that tracks all the rooms visited
    mazeRoute += NodeArray[currentNode]->getNodeName();

    cout << endl << "Congratulations! You have reached the Destination point." << endl;
    cout << "You took " << counter << " steps." << endl;
    cout << "The nodes you visited are: " << mazeRoute << endl;
}

//Function:    snakeOrLadder
//Description: Checks to see if node has a snake or ladder attachement

void Menu::snakeOrLadder()
{
    sORl = false;

    //checks the name of the snake and ladder attachement
    if(NodeArray[currentNode]->getSnakeLadderNode()->getNodeName() == "*")
    {
    }

    //if name is actually a node enters else statement
    else
    {
        //sets node to the new node
        node = NodeArray[currentNode]->getSnakeLadderNode()->getNodeName();

        //converts string variable to a char* to be passed as a parameter
        char* p = new char[node.length() + 1];
        strcpy(p, node.c_str());

        //calls switchNodeLetter function
        switchNodeLetterSL(p);

        //deallocates the node
        delete(p);
        sORl = true;
    }
}

//Function:    dirTaken
//Description: Adds the directions that available for the user to move to the move variable

void Menu::dirTaken()
{
    move = "";
    string test;

    //checks to see if node has a north attachement
    if(NodeArray[currentNode]->getAttachedNode(0)->getNodeName() == "*")
    {
    }
    else
    {
        //sets move equal to North
        move = "North";
    }

    //checks to see if node has a east attachement
    if( NodeArray[currentNode]->getAttachedNode(1)->getNodeName() == "*")
    {
    }
    else
    {
        //Checks to see if move is empty
        if(move == "")
        {
            //sets move equal to East
            move = "East";
        }

        //if move is not empty then or is added between what is in move and east
        else
        {
            move += " or East";
        }
    }

    //checks to see if node has a south attachement
    if(NodeArray[currentNode]->getAttachedNode(2)->getNodeName() == "*")
    {
    }
    else
    {
        //Checks to see if move is empty
        if(move == "")
        {
            //sets move equal to East
            move = "South";
        }

        //if move is not empty then or is added between what is in move and south
        else
        {
            move += " or South";
        }
    }

    //checks to see if node has a west attachement
    if(NodeArray[currentNode]->getAttachedNode(3)->getNodeName() == "*")
    {
    }
    else
    {
        //Checks to see if move is empty
        if(move == "")
        {
            //sets move equal to West
            move = "West";
        }

        //if move is not empty then or is added between what is in move and west
        else
        {
            move += " or West";
        }
    }
}

//Function:    switchNode
//Description: Once user selects direction current node is situated to new node

void Menu::switchNode(string choice)
{
    string name;

    //checks to see if user input is N
    if(choice == "N")
    {
        //gets the name of node attached to the north
        name = NodeArray[currentNode]->getAttachedNode(0)->getNodeName();

        //calls checkNode function
        checkNode(name);
    }

    //checks to see if user input is E
    else if(choice == "E")
    {
        //gets the name of node attached to the east
        name = NodeArray[currentNode]->getAttachedNode(1)->getNodeName();

        //calls checkNode function
        checkNode(name);
    }

    //checks to see if user input is S
    else if(choice == "S")
    {
        //gets the name of node attached to the south
        name = NodeArray[currentNode]->getAttachedNode(2)->getNodeName();

        //calls checkNode function
        checkNode(name);
    }

    //checks to see if user input is W
    else if(choice == "W")
    {
        //gets the name of node attached to the west
        name = NodeArray[currentNode]->getAttachedNode(3)->getNodeName();

        //calls checkNode function
        checkNode(name);
    }

    //if input is not N, E, S, or W
    else
    {
        name = "*";

        //calls checkNode function
        checkNode(name);
    }

    //converts string object to char*
    char* p = new char[name.length() + 1];
    strcpy(p, name.c_str());

    //calls switchNodeLetterSL function
    switchNodeLetterSL(p);
}

//Function:    checkNode
//Description: checks to make sure user input was valid for direction

void Menu::checkNode(string name)
{
    string choice;

    //checks to see if user entered a correct selection for direction
    if(name == "*")
    {
        cout << endl << "Invalid selection please pick a valid direction." << endl << endl;
        cout << endl << "You are currently in Node " << NodeArray[currentNode]->getNodeName();
        cout << " of the Maze Runner,";

        //checks to see if the chuteOrLadder function returned true that the room had a chute or ladder
        if(sORl)
        {
            cout << ", you can go ";

            //calls dirTaken function
            dirTaken();
            cout << move << ". What is your choice? ";
            cin >> choice;

            //calls switchNode function
            switchNode(choice);
        }

        //if room did not have a chute or ladder
        else
        {
            cout << " you can go " << endl;

            //calls dirTaken function
            dirTaken();
            cout << move << ". What is your choice? ";
            cin >> choice;

            //calls switchNode function
            switchNode(choice);
        }
    }
}

//Function:    switchNodeLetterSL
//Description: sets a string variable to the letter in the node name

void Menu::switchNodeLetterSL(char* newNode)
{
    char nodeLetter = *newNode, nodeNumber = newNode[1];
    string letter;

    //switch statement based of the value in the first position of the node name
    switch(nodeLetter)
    {
        //checks to see if it is A, if so sets string equal to A
        case 'A':
            letter = "A";

            //calls switchNodeNumberSL
            switchNodeNumberSL(letter, nodeNumber);

            //breaks switch statement
            break;

        //checks to see if it is B, if so sets string equal to B
        case 'B':
            letter = "B";

            //calls switchNodeNumberSL
            switchNodeNumberSL(letter, nodeNumber);

            //breaks switch statement
            break;

        //checks to see if it is C, if so sets string equal to C
        case 'C':
            letter = "C";

            //calls switchNodeNumberSL
            switchNodeNumberSL(letter, nodeNumber);
            break;

        //checks to see if it is D, if so sets string equal to D
        case 'D':
            letter = "D";

            //calls switchNodeNumberSL
            switchNodeNumberSL(letter, nodeNumber);

            //breaks switch statement
            break;

        //checks to see if it is E, if so sets string equal to E
        case 'E':
            letter = "E";
            switchNodeNumberSL(letter, nodeNumber);

            //breaks switch statement
            break;

        //checks to see if it is F, if so sets string equal to F
        case 'F':
            letter = "F";

            //calls switchNodeNumberSL
            switchNodeNumberSL(letter, nodeNumber);

            //breaks switch statement
            break;

        //checks to see if it is G, if so sets string equal to G
        case 'G':
            letter = "G";

            //calls switchNodeNumberSL
            switchNodeNumberSL(letter, nodeNumber);

            //breaks switch statement
            break;

        //checks to see if it is H, if so sets string equal to H
        case 'H':
            letter = "H";

            //calls switchNodeNumberSL
            switchNodeNumberSL(letter, nodeNumber);

            //breaks switch statement
            break;
    }
}

//Function:    switchNodeNumberSL
//Description: sets currentNode to the index of the new node

void Menu::switchNodeNumberSL(string lett, char num)
{
    //switch case statement based on number in node name
    switch(num)
    {
        //checks to see if number equals 1
        case '1':

            //checks to see if the lesster of the node equals A
            if(lett == "A")
            {
                //sets currentNode to index of A1
                currentNode = 0;
            }

            //checks to see if the lesster of the node equals B
            else if(lett == "B")
            {
                //sets currentNode to index of B1
                currentNode = 1;
            }

            //checks to see if the lesster of the node equals C
            else if(lett == "C")
            {
                //sets currentNode to index of C1
                currentNode = 2;
            }

            //checks to see if the lesster of the node equals D
            else if(lett == "D")
            {
                //sets currentNode to index of D1
                currentNode = 3;
            }

            //checks to see if the lesster of the node equals E
            else if(lett == "E")
            {
                //sets currentNode to index of E1
                currentNode = 4;
            }

            //checks to see if the lesster of the node equals F
            else if(lett == "F")
            {
                //sets currentNode to index of F1
                currentNode = 5;
            }

            //checks to see if the lesster of the node equals G
            else if(lett == "G")
            {
                //sets currentNode to index of G1
                currentNode = 6;
            }

            //checks to see if the lesster of the node equals H
            else if(lett == "H")
            {
                //sets currentNode to index of H1
                currentNode = 7;
            }
            break;
        //checks to see if number equals 2
        case '2':

            //checks to see if the lesster of the node equals A
            if(lett == "A")
            {
                //sets currentNode to index of A2
                currentNode = 8;
            }

            //checks to see if the lesster of the node equals B
            else if(lett == "B")
            {
                //sets currentNode to index of B2
                currentNode = 9;
            }

            //checks to see if the lesster of the node equals C
            else if(lett == "C")
            {
                //sets currentNode to index of C2
                currentNode = 10;
            }

            //checks to see if the lesster of the node equals D
            else if(lett == "D")
            {
                //sets currentNode to index of D2
                currentNode = 11;
            }

            //checks to see if the lesster of the node equals E
            else if(lett == "E")
            {
                //sets currentNode to index of E2
                currentNode = 12;
            }

            //checks to see if the lesster of the node equals F
            else if(lett == "F")
            {
                //sets currentNode to index of F2
                currentNode = 13;
            }

            //checks to see if the lesster of the node equals G
            else if(lett == "G")
            {
                //sets currentNode to index of G2
                currentNode = 14;
            }

            //checks to see if the lesster of the node equals H
            else if(lett == "H")
            {
                //sets currentNode to index of H2
                currentNode = 15;
            }
            break;
        //checks to see if number equals 3
        case '3':

            //checks to see if the lesster of the node equals A
            if(lett == "A")
            {
                //sets currentNode to index of A3
                currentNode = 16;
            }

            //checks to see if the lesster of the node equals B
            else if(lett == "B")
            {
                //sets currentNode to index of B3
                currentNode = 17;
            }

            //checks to see if the lesster of the node equals C
            else if(lett == "C")
            {
                //sets currentNode to index of C3
                currentNode = 18;
            }

            //checks to see if the lesster of the node equals D
            else if(lett == "D")
            {
                //sets currentNode to index of D3
                currentNode = 19;
            }

            //checks to see if the lesster of the node equals E
            else if(lett == "E")
            {
                //sets currentNode to index of E3
                currentNode = 20;
            }

            //checks to see if the lesster of the node equals F
            else if(lett == "F")
            {
                //sets currentNode to index of F3
                currentNode = 21;
            }

            //checks to see if the lesster of the node equals G
            else if(lett == "G")
            {
                //sets currentNode to index of G3
                currentNode = 22;
            }

            //checks to see if the lesster of the node equals H
            else if(lett == "H")
            {
                //sets currentNode to index of H3
                currentNode = 23;
            }
            break;
        //checks to see if number equals 4
        case '4':
            //checks to see if the lesster of the node equals A
            if(lett == "A")
            {
                //sets currentNode to index of A4
                currentNode = 24;
            }

            //checks to see if the lesster of the node equals B
            else if(lett == "B")
            {
                //sets currentNode to index of B4
                currentNode = 25;
            }

            //checks to see if the lesster of the node equals C
            else if(lett == "C")
            {
                //sets currentNode to index of C4
                currentNode = 26;
            }

            //checks to see if the lesster of the node equals D
            else if(lett == "D")
            {
                //sets currentNode to index of D4
                currentNode = 27;
            }

            //checks to see if the lesster of the node equals E
            else if(lett == "E")
            {
                //sets currentNode to index of E4
                currentNode = 28;
            }

            //checks to see if the lesster of the node equals F
            else if(lett == "F")
            {
                //sets currentNode to index of F4
                currentNode = 29;
            }

            //checks to see if the lesster of the node equals G
            else if(lett == "G")
            {
                //sets currentNode to index of G4
                currentNode = 30;
            }

            //checks to see if the lesster of the node equals H
            else if(lett == "H")
            {
                //sets currentNode to index of H4
                currentNode = 31;
            }
            break;
        //checks to see if number equals 5
        case '5':
            //checks to see if the lesster of the node equals A
            if(lett == "A")
            {
                //sets currentNode to index of A5
                currentNode = 32;
            }

            //checks to see if the lesster of the node equals B
            else if(lett == "B")
            {
                //sets currentNode to index of B5
                currentNode = 33;
            }

            //checks to see if the lesster of the node equals C
            else if(lett == "C")
            {
                //sets currentNode to index of C5
                currentNode = 34;
            }

            //checks to see if the lesster of the node equals D
            else if(lett == "D")
            {
                //sets currentNode to index of D5
                currentNode = 35;
            }

            //checks to see if the lesster of the node equals E
            else if(lett == "E")
            {
                //sets currentNode to index of E5
                currentNode = 36;
            }

            //checks to see if the lesster of the node equals F
            else if(lett == "F")
            {
                //sets currentNode to index of F5
                currentNode = 37;
            }

            //checks to see if the lesster of the node equals G
            else if(lett == "G")
            {
                //sets currentNode to index of G5
                currentNode = 38;
            }

            //checks to see if the lesster of the node equals H
            else if(lett == "H")
            {
                //sets currentNode to index of H5
                currentNode = 39;
            }
            break;

        //checks to see if number equals 6
        case '6':
            //checks to see if the lesster of the node equals A
            if(lett == "A")
            {
                //sets currentNode to index of A6
                currentNode = 40;
            }

            //checks to see if the lesster of the node equals B
            else if(lett == "B")
            {
                //sets currentNode to index of B6
                currentNode = 41;
            }

            //checks to see if the lesster of the node equals C
            else if(lett == "C")
            {
                //sets currentNode to index of C6
                currentNode = 42;
            }

            //checks to see if the lesster of the node equals D
            else if(lett == "D")
            {
                //sets currentNode to index of D6
                currentNode = 43;
            }

            //checks to see if the lesster of the node equals E
            else if(lett == "E")
            {
                //sets currentNode to index of E6
                currentNode = 44;
            }

            //checks to see if the lesster of the node equals F
            else if(lett == "F")
            {
                //sets currentNode to index of F6
                currentNode = 45;
            }

            //checks to see if the lesster of the node equals G
            else if(lett == "G")
            {
                //sets currentNode to index of H6
                currentNode = 46;
            }

            //checks to see if the lesster of the node equals H
            else if(lett == "H")
            {
                //sets currentNode to index of A1
                currentNode = 47;
            }
    }
}

//Function:    maze
//Description: keeps track of nodes visited

void Menu::maze()
{
    //adds node to list of nodes visited and puts a space between them
    mazeRoute += NodeArray[currentNode]->getNodeName();
    mazeRoute += " ";
}
