// Program 2:   Lab 2
// Name:        Tyler Jewell
// Class:       COMP 2710
// Date:        October 1, 2016
// E-mail:      tjj0013@auburn.edu
//
// Description: This is the header file for the Menu class.

#include <iostream>
#include <fstream>
#include <string>
#include "Friends.h"
#include "Messages.h"
#include "Hashtags.h"
#include "Pages.h"

using namespace std;

// Class:       Menu
//
// Description: This class handles the printing of the main
//              menu and the control of the switching based on
//              user selection.

class Menu
{
public:
	string name;

	void program();
	void switchOption(char);
};
