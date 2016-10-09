// Program 2:   Lab 2
// Name:        Tyler Jewell
// Class:       COMP 2710
// Date:        October 9, 2016
// E-mail:      tjj0013@auburn.edu
//
// Description: This class handles the printing
//              of both the wall and home page for
//              the user.

#include "Pages.h"

// Function:    msgs
// Description: This function checks the files that need
//              to be opened to be able to print both
//              the wall and home pages.

void Pages::msgs(string name, int page)
{
	string user=name, temp, filename;
	int option = page;
	ifstream infile, file;
	bool found = false;

	// Checks to see if time file is already created.
	ifstream my_file("time");
	if (my_file.good())
	{
		// If it is already created open time file for reading.
		filename = "time";
		infile.open(filename.c_str());

		// Reads the number in time file.
		infile.close();

		found = true;

		//Checks to see if a hashtag file is already created
		filename = user + ".hashtags";
		ifstream my_file(filename.c_str());
		if(my_file.good())
		{
			my_file.close();

			//Opens the hashtag file for reading
			infile.open(filename.c_str());

			//Stores what is in the tweet file in a string
			while( infile >> temp )
			{
				hashtags = hashtags + " " + temp;
			}
			infile.close();
		}

		// Checks to see if a user's file is already created.
		filename = user;
		ifstream file(filename.c_str());
		if (file.good())
		{
			// Opens the user's file for reading
			infile.open(filename.c_str());

			// Reads user file stores it in a string
			while (infile >> temp)
			{
				message = message + " " + temp;
			}
		}
		infile.close();
	}

	// If the time file is created then messages has been posted.
	if (found)
	{
		// Checks to see which option was selected between wall and home page.
		if (option == 1)
		{
			wallbanner(user);
		}
		else if (option == 0)
		{
			allmsgs(user);
		}
	}

	// If the time file has not been created then an err
	// message saying no messages have been posted yet will apper.
	else
	{
		cerr << "No messages have been posted yet.";
	}
}

// Function:    wallbanner
// Description: Displays the greeting of the wall page and ending.
//              Calls the wallpage() function to display messages.

void Pages::wallbanner(string name)
{
	const int WELCOME_LENGTH = 55;
	string user = name, welcome;
	int name_length, _length;
	welcome = user + "'s Wall Page";
	name_length = welcome.length();
	_length = (WELCOME_LENGTH - name_length) / 2;

	// Contine loop to add spaces to the front and back of the greeting.
	while (_length > 0)
	{
		welcome = " " + welcome + " ";
		_length--;
	}

	cout << "========================================================" << endl;
	cout << "|" << welcome << "|" << endl;
	cout << "========================================================" << endl << endl << endl;

	// Calls wallpage() function
	wallpage(user);

	welcome = "End of " + user + "'s Wall Page";
	name_length = welcome.length();
	_length = (WELCOME_LENGTH - name_length) / 2;

	// Continues loop to add spaces to the front and back of the end message.
	while (_length > 0)
	{
		welcome = " " + welcome + " ";
		_length--;
	}

	cout << "========================================================" << endl;
	cout << "|" << welcome << "|" << endl;
	cout << "========================================================" << endl << endl << endl;
}

void Pages::wallpage(string name)
{
	string user = name, more, hashtagstring;
	i = 0;

	// While time is greater than zero and i is less than
	// three this loop will continue.
	while (time >= 0 && i < 3)
	{
		// Calls wall() function decrements time.
		wall(user);
		time--;
	}

	// Prints only the first three messages.
	cout << msg_buf << endl;

	// Checks to see if i equals three.
	if (i == 3)
	{
		// Sets hashtagstring to the string returned by checkhashtag() function.
		hashtagstring = checkhashtag(user);

		// If there are no more messages in user folder or no more hashtags
		// for the user then wall page is done displaying messages,
		// otherwise the user is asked if they want to display more messages.
		if (message != "" || hashtagstring != "")
		{
			cout << "More messages (yes/no): ";
			cin >> more;
			cout << endl;

			// If the user selects yes the rest of the messages are displayed.
			if (more == "yes")
			{
				msg_buf = "";

				// Continues until time is negative.
				while (time >= 0)
				{
					// Calls wall function and decrements time.
					wall(user);
					time--;
				}

				// Prints the rest of the messages.
				cout << msg_buf << endl;
			}
		}
	}
}

// Function:    wall
// Description: Calls two different functions to check the timestamp on the messages.

void Pages::wall(string name)
{
	string user = name;

	// If hashtags is not empty calls the hashtag function.
	if (hashtags != "")
	{
		hashtag(user);
	}

	// If messages is not empty calls the usermessages() function.
	if (message != "")
	{
		usermessages(user);
	}
}

// Function:    hastag
// Description: Compares the time stamp of the latest hashtag
//              with the time int adds the msg to msg_buffer
//              if it is the next message to be displayed.

void Pages::hashtag(string name)
{

}

// Function:    usermessages
// Description: Compares the time stamp of the latest message
//              with the time int adds the msg to msg_buffer
//              if it is the next message to be displayed.

void Pages::usermessages(string name)
{

}

// Function:    allmsgs
// Description: Opens the user's friend's list file and
//              reads in the list of their friends. Then
//              opens each friend's user file and stores
//              all friends and their messages in one string.

void Pages::allmsgs(string name)
{

}

// Function:    homebanner
// Description: Dispays the banners for the home page
//              and calls homepage() function

void Pages::homebanner(string name)
{

}

// Function:    homepage
// Description: Prints first three messages for the home page
//              and the rest of the messages if user selects
//              to diplay more

void Pages::homepage(string name)
{

}

// Function:    home
// Description: Calls three different functions to check the timestamp on the messages.

void Pages::home(string name)
{

}

// Function:    homehashtag
// Description: Compares the time stamp of the latest hashtag
//              with the time int adds the msg to msg_buffer
//              if it is the next message to be displayed.

void Pages::homehashtag(string name)
{

}

// Function:    homemessage
// Description: Compares the time stamp of the latest message
//              with the time int adds the msg to msg_buffer
//              if it is the next message to be displayed.

void Pages::homemessage(string name)
{

}

// Function:    friendmsg
// Description: Compares the time stamp of the latest message
//              with the time int adds the msg to msg_buffer
//              if it is the next message to be displayed.

void Pages::friendmsg(string name)
{

}

// Function:    checkhashtag
// Description: Checks to see if the user has any
//              more hashtags messages. Returns a string

string Pages::checkhashtag(string name)
{
	return "";
}

// Function:    checkfriendmsg
// Description: Checks to see if there are anymore
//              messages for user's friends.

string Pages::checkfriendmsg()
{
	return "";
}
