// Program 2:   Lab 2
// Name:        Tyler Jewell
// Class:       COMP 2710
// Date:        October 9, 2016
// E-mail:      tjj0013@auburn.edu
//
// Description: This is the header file for the pages class.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

// Class:       Pages
// Description: This class handles the printing
//              of both the wall and home page for
//              the user.

class Pages
{
public:
	int time, i;
	string hashtags, message, msg_bug, friendmsgs;

	void msgs(string, int);
	void homepage(string);
	void homemsg(string);
	void allmsgs(string);
	void wallpage(string);
	void wall(string);
	void wallbanner(string);
	void hashtag(string);
	void usermessages(string);
	void homebanner(string);
	void home(string);
	void homehashtag(string);
	void homemessage(string);
	void friendmsg(string);
	string checkhashtag(string);
	string checkfriendmsg();
};
