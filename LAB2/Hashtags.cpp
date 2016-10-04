// Program 2:   Lab 2
// Name:        Tyler Jewell
// Class:       COMP 2710
// Date:        October 3, 2016
// E-mail:      tjj0013@auburn.edu
//
// Description: This class adds hashtags to the user's hashtag's list.

#include "Hashtags.h"

// Function:    addHashtag
// Description: Add hashtag to user's hashtag's list.

void Hashtags::addHashtag(string name)
{
	const int WELCOME_LENGTH = 55;
	string newHashtag, user = name, hashtagName, hashtags, welcome, filename;
	int hash_length, _length;
	bool found = false, same = false;
	ifstream infile;
	ofstream outfile;

	cout << "Please enter hashtag to follow: ";
	cin >> newHashtag;
	cout << endl;

	// Checks to see if user has a hashtag's file.
	filename = user + ".hashtags";
}
