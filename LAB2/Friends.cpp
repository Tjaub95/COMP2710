// Program 2: Lab 2
// Name: Tyler Jewell
// Class: COMP 2710
// Date: October 2, 2016
// E-mail: tjj00113@auburn.edu
//
// Description: This class adds friends to the user's friend's list.


#include "Friends.h"

// Function: addFriend
// Description: Add friend to user's friend's list.

void Friends::addFriend(string name)
{
	const int WELCOME_LENGTH  = 55;
	string newFriend, user = name, friendName, users, welcome, filename;
	int name_length, _length;
	bool found = false, same = false;
	ifstream infile;
	ofstream outfile;

	cout << "Please enter friend's name: ";
	cin >> newFriend;
	cout << endl;

	// Opens "users" file.
	filename = "users";
	infile.open(filename.c_str());

	// Checks to see if friend being added is a user.
	while (infile >> users)
	{
		if (users == newFriend)
		{
			// Checks to see if friend being addeed is the current user.
			if (users != user)
			{
				found = true;
			}
			else
			{
				same = true;
				cerr << "You can not add yourself as a friend." << endl;
			}
		}
	}
	infile.close();

	// If friend is a user attempts to add a friend to user's friend's list.
	if (found)
	{
		// Checks to see if user has a friend's text file.
		filename = user + ".friends";
		ifstream my_file(filename.c_str());
		if (my_file.good())
		{
			my_file.close();

			// If user has a friend's file, it will open.
			filename = user + ".friends";
			infile.open(filename.c_str());

			// If user and friend are already friends error message is printed.

			while (infile >> friendName)
			{
				if (friendName == newFriend)
				{
					found = false;
					cerr << "Users are already friends." << endl;
				}
			}
			infile.close();

			// If they are not friends then the program continues to try and add friend.

			if (found)
			{
				// Opens user's friend's text file and adds friend to friend list.

				filename = user + ".friends";
				outfile.open(filename.c_str(), ios::app);
				outfile << newFriend + " ";
				outfile.flush();
				outfile.close();
			}
		}
		// If user does not already have a friend text file one is created for them and friend is added.
		else
		{
			// Checks to make sure found is still true.
			if (found)
			{
				filename = user + ".friends";
				outfile.open(filename.c_str());
				outfile << newFriend + " ";
				outfile.flush();
				outfile.close();
			}
		}

		// Checks to make sure found is still true.
		if (found)
		{
			welcome = "Added " + newFriend + " to Friend's List!";
			name_length = welcome.length();;;
			_length = (WELCOME_LENGTH - name_length) / 2;;
			while (_length > 0)
			{
				welcome = " " + welcome + " ";
				_length--;
			}
			cout << "========================================================" << endl;
			cout << "|" << welcome << "|" << endl;
			cout << "========================================================" << endl << endl << endl;
		}
	}

		// Print error message if friend is not a valif user and is not the user him/herself.
		else if (!same)
		{
			cerr << "Friend is not a valid user." << endl;
		}
}
