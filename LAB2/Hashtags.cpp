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
	bool found = false;
	ifstream infile;
	ofstream outfile;

	cout << "Please enter hashtag to follow: ";
	cin >> newHashtag;
	cout << endl;

	// Checks to see if user has a hashtag's file.
	filename = user + ".hashtags";
	ifstream my_file(filename.c_str());
	if (my_file.good())
	{
		my_file.close();

		// If a user has a hashtag's file, it will open.
		infile.open(filename.c_str());

		// If user is already following the hashtag error message.
		while (infile >> hashtagName)
		{
			if (hashtagName == newHashtag)
			{
				found = false;
				cerr << "Users already follows this hashtag." << endl;
			}
		}
		infile.close();

		// If the hashtag is not being followed then the program continuesto try and follow hashtag.

		outfile.open(filename.c_str(), ios::app);
		outfile << newHashtag + " ";
		outfile.flush();
		outfile.close();
	}

	// If user does not have a hashtag text file one will be created.
	else
	{
		outfile.open(filename.c_str());
		outfile << newHashtag + " ";
		outfile.flush();
		outfile.close();
	}

	welcome = "Added " + newHashtag + " to Hashtag's List!";
	hash_length = welcome.length();
	_length = (WELCOME_LENGTH - hash_length) / 2;
	while (_length > 0)
	{
		welcome = " " + welcome + " ";
		_length--;
	}

	cout << "========================================================" << endl;
	cout << "|" << welcome << "|" << endl;
	cout << "========================================================" << endl << endl << endl;
}
