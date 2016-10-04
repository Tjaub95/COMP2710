// Program 2: Lab 2
// Name: Tyler Jewell
// Class: COMP 2710
// Date: October 2, 2016
// E-mail: tjj0013@auburn.edu
//
// Description: This is the header file for messages class.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Class: Messages
//
// Description: This class handles the storing of the posted
//              messages in the direct files. It
//              also puts a timestamp on each message.

class Messages
{
public:
	string msg_buffer;
	int time;

	void message(string);
	void tweet(string);
	void timestamp();
};
