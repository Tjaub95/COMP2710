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

// Function:    hashtag
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
	string user = name, msg, num1, msg_temp, tempmsg;
	int number2;
	size_t first_char, last_char, slash;
	size_t start_pos = 0;
	stringstream num2;

	while ((start_pos = message.find("$^", start_pos)) != std::string::npos)
	{
		message.replace(start_pos, 2, "\n");
		start_pos += 2;
	}

	// Finds the first "%[" in the string.
	first_char = message.find("%[");

	// Finds the first "]%" in the string.
	last_char = message.find("]%");

	// Gets the number associated with the message.
	num1 = message.substr(first_char + 2, last_char - 2);

	// Converts the number from a string to an int.
	num2 << num1;
	num2 >> number2;

	// Creates a temporary variable to be user.
	msg = message;

	// Checks to see if the number associated with the message is equal to the time.
	if (number2 == time)
	{
		// Substring message after the appearance of the last_char.
		message = message.substr(last_char + 2);

		// Find the first "%[" in the new string.
		first_char = message.find("%[");

		// Checks to make sure "%[" actually appears.
		if (first_char != string::npos)
		{
			msg = message.substr(0, first_char - 2);

			message = message.substr(first_char);
		}

		else
		{
			// Sets msg equal to the message that is left.
			msg = message;

			// Empties message if there are no more.
			message = "";
		}

		// Adds the message to the msg_buffer if found and increments i.
		msg_buf = msg_buf + msg + "\n\n";
		i++;
	}
}

// Function:    allmsgs
// Description: Opens the user's friend's list file and
//              reads in the list of their friends. Then
//              opens each friend's user file and stores
//              all friends and their messages in one string.

void Pages::allmsgs(string name)
{
	string user = name, temp, friends, friendlist, friendmsg_temp, filename;
	size_t space;
	ifstream infile;

	//Checks if user has a friend's list file
    filename = user + ".friends";
	ifstream my_file(filename.c_str());
	if(my_file.good())
	{
		infile.open(filename.c_str());

		//Reads everything in file and puts in a string
		while(infile >> temp)
		{
			friendlist = friendlist + " " + temp;
		}
		infile.close();

		//Continues loop until friendlist string is emptied
		while(friendlist != "")
		{
			//Finds first space in string
			space = friendlist.find(" ");

			//Makes sure there is a space in the string
			if(space != string::npos)
			{
				//Gets first friends name
				friends = friendlist.substr(0, space);

				//Removes friend from list
				friendlist = friendlist.substr(space + 1);
			}

			else
			{
				//Sets friends to the last friend in list
				friends = friendlist;

				//Sets list to an empty string
				friendlist = "";
			}

			//Initializes friendsmsg_temp
			friendmsg_temp = "";

			//Checks if friends user file is created
			filename = friends;
			ifstream file(filename.c_str());
			if(file.good())
			{
				infile.open(filename.c_str());

				//Reads everything in file into a string
				while(infile >> temp)
				{
					friendmsg_temp = friendmsg_temp + " " + temp;
				}
				infile.close();

				//Sets variable equal to friends name plus their messages
				friendmsg_temp = "(" + friends + ")" + friendmsg_temp;
			}

			//Adds each friend and their messages together
			friendmsgs += friendmsg_temp;
		}
	}

	//Calls homebanner() function
	homebanner(user);
}

// Function:    homebanner
// Description: Dispays the banners for the home page
//              and calls homepage() function

void Pages::homebanner(string name)
{
	const int WELCOME_LENGTH = 55;
	string user = name, welcome;
	int name_length, _length;
	welcome = user + "'s Home Page";
	name_length = welcome.length();
	_length = (WELCOME_LENGTH - name_length) / 2;

	//Continues loop to add spaces to the front and back of the greeting
	while(_length > 0)
	{
		welcome = " " + welcome + " ";
		_length--;
	}
	cout << "========================================================" << endl;
	cout << "|" << welcome << "|" << endl;
	cout << "========================================================" << endl << endl << endl;

	//Calls homepage() function
	homepage(user);

	welcome = "End of " + user + "'s Home Page";
	name_length = welcome.length();
	_length = (WELCOME_LENGTH - name_length)/2;

	//Continues loop to add spaces to the front and back of the end message
	while(_length > 0)
	{
		welcome = " " + welcome + " ";
		_length--;
	}
	cout << "========================================================" << endl;
	cout << "|" << welcome << "|" << endl;
	cout << "========================================================" << endl << endl << endl;
}

// Function:    homepage
// Description: Prints first three messages for the home page
//              and the rest of the messages if user selects
//              to diplay more

void Pages::homepage(string name)
{
	string user = name, more, hashtagstring, checkfriends;
	i = 0;

	//Continues until time is less then 0 or i equals 3
	while(time >= 0 && i < 3)
	{
		//Calls home() function and decremetns time
		home(user);
		time--;
	}

	//Prints frist three messages for home page
	cout << msg_buf << endl;

	//Checks if i equals 3
	if(i == 3)
	{
		//Sets hashtagstring to the string returned by checkhashtag
		hashtagstring = checkhashtag(user);

		//Sets checkfriends to the string returned by checkfriendmsg
		checkfriends = checkfriendmsg();

		//Checks to see if any of the strings contain messages
		if(message != "" || hashtagstring != "" || checkfriends != "")
		{
			//Asks the user if they would like to display more messages
			cout << "More messages (yes/no): ";
			cin >> more;
			cout << endl;

			//Checks to see if user selected yes
			if(more == "yes")
			{
				//empties msg_buf
				msg_buf = "";

				//Continues until time is negative
				while(time >= 0)
				{
					//Calls home() function and decrements time
					home(user);
					time--;
				}

				//Prints the rest of the home page messages
				cout << msg_buf << endl;
			}
		}
	}
}

// Function:    home
// Description: Calls three different functions to check the timestamp on the messages.

void Pages::home(string name)
{
	string user = name;

	//If tweets is not empty calls the hometweet function
	if(hashtags != "")
	{
		homehashtag(user);
	}

	//If message is not empty calls the homemessage function
	if(message != "")
	{
		homemessage(user);
	}

	//If friendmsgs is not empty calls the friendmsg function
	if(friendmsgs != "")
	{
		friendmsg(user);
	}
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
	string user = name, msg, num1, msg_temp, tempmsg;
	int number2;
	size_t first_char, last_char, slash;
	size_t start_pos = 0;
	stringstream num2;

	while ((start_pos = message.find("$^", start_pos)) != std::string::npos)
	{
		message.replace(start_pos, 2, "\n");
		start_pos += 2;
	}

	// Finds the first "%[" in the string.
	first_char = message.find("%[");

	// Finds the first "]%" in the string.
	last_char = message.find("]%");

	// Gets the number associated with the message.
	num1 = message.substr(first_char + 2, last_char - 2);

	// Converts the number from a string to an int.
	num2 << num1;
	num2 >> number2;

	// Creates a temporary variable to be user.
	msg = message;

	// Checks to see if the number associated with the message is equal to the time.
	if (number2 == time)
	{
		// Substring message after the appearance of the last_char.
		message = message.substr(last_char + 2);

		// Find the first "%[" in the new string.
		first_char = message.find("%[");

		// Checks to make sure "%[" actually appears.
		if (first_char != string::npos)
		{
			msg = message.substr(0, first_char - 2);

			message = message.substr(first_char);
		}

		else
		{
			// Sets msg equal to the message that is left.
			msg = message;

			// Empties message if there are no more.
			message = "";
		}

		// Adds the message to the msg_buffer if found and increments i.
		msg_buf = msg_buf + user + " >>\n" + msg + "\n\n";
		i++;
	}
}

// Function:    friendmsg
// Description: Compares the time stamp of the latest message
//              with the time int adds the msg to msg_buffer
//              if it is the next message to be displayed.

void Pages::friendmsg(string name)
{
	string user = name, friends, num1, frmsgtemp = friendmsgs, msg_temp, msg, tempmsg, temp;
	int number;
	size_t first_char, last_char, par1, par2, slash;
	size_t start_pos = 0;

	while ((start_pos = frmsgtemp.find("$^", start_pos)) != std::string::npos)
	{
		frmsgtemp.replace(start_pos, 2, "\n");
		start_pos += 2;
	}

	//Finds the first "(" in the string
	par1 = frmsgtemp.find("(");

	//Finds the first ")" in the string
	par2 = frmsgtemp.find(")");

	if(par1 != string::npos)
	{

		//Gets the friends name
		friends = frmsgtemp.substr(par1 + 1, par2 - 1);

		//Removes the friends name
		frmsgtemp = frmsgtemp.substr(par2 + 1);

	}

	//Continues until frmsgtemp is emptied
	while(frmsgtemp != "")
	{
		stringstream num;

		//Finds the first "<" in the string
		first_char = frmsgtemp.find("%[");

		//Finds the first ">" in the string
		last_char = frmsgtemp.find("]%");

		//Gets the number associated with the message
		num1 = frmsgtemp.substr(first_char + 2, last_char - 2);

		//Converts the number from a string to an int value
		num << num1;
		num >> number;

		//Checks to see if the number is equal to the time
		if(number == time)
		{
			//Removes everything before and including the ">'
			frmsgtemp = frmsgtemp.substr(last_char + 2);

			//Sets the variable for later use
			msg_temp = frmsgtemp;

			//Finds the first "<" in the string
			first_char = msg_temp.find("%[");

			//FInds the first "(" in the string
			par1 = msg_temp.find("(");

			//Compares to see which comes first
			if(first_char < par1)
			{
				//Substring everything from the start of the string until right before "<"
				msg_temp = msg_temp.substr(0, first_char - 2);

				//Sets msg equal to the message
				msg = msg_temp;

				//Empties string
				frmsgtemp = "";

				//Adds the message to msg_buffer and increments i if message is found
				msg_buf = msg_buf + friends + " >>\n" + msg + "\n\n";
				i++;
			}


			else if(first_char == par1)
			{
				//sets the temp variable
				msg = msg_temp;

				//Empties the string
				frmsgtemp = "";

				//Adds the message to msg_buffer and increments i if message is found
				msg_buf = msg_buf + friends + " >>\n" + msg + "\n\n";
				i++;
			}

			else
			{
				//Removes everything but the friend from aboves messages
				msg_temp = msg_temp.substr(0, par1);

				//Sets the temp variable
				msg = msg_temp;

				//Clears the string
				frmsgtemp = "";

				//Adds the message to msg_buffer and increments i if message is found
				msg_buf = msg_buf + friends + " >>\n" + msg + "\n";
				i++;
			}
		}

		else
		{
			//Removes everything before ">"
			frmsgtemp = frmsgtemp.substr(last_char + 2);

			//Finds the first "<" in the string
			first_char = frmsgtemp.find("%[");

			//Finds the first "(" in the string
			par1 = frmsgtemp.find("(");

			//Compares to see which comes first
			if(first_char < par1)
			{
				//Removes everything before "<" in the string
				frmsgtemp = frmsgtemp.substr(first_char);
			}

			else if(first_char == par1)
			{
				//Empties the string
				frmsgtemp = "";
			}

			else
			{
				//Finds the first "(" in the string
				par1 = frmsgtemp.find("(");

				//Removes everything before "(" in the string
				frmsgtemp = frmsgtemp.substr(par1);

				//Finds the first "(" in the string
				par1 = frmsgtemp.find("(");

				//Finds the first ")" in the string
				par2 = frmsgtemp.find(")");

				//Sets the friends variable equal to the next friend in the list
				friends = frmsgtemp.substr(par1 + 1, par2 - 1);

				//Removes the friends name from the string
				frmsgtemp = frmsgtemp.substr(par2 + 1);
			}
		}
	}
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
	string check = friendmsgs, num;
	size_t first_char, last_char;
	size_t start_pos = 0;
	int number;

	// Contines until check is emptied.
	while (check != "")
	{
		stringstream ss;

		// Finds the first "%[" and "]%"
		first_char = check.find("%[");
		last_char = check.find("]%");

		// Checks to see if "%[" actually appears.
		if (first_char != string::npos)
		{
			num = check.substr(first_char + 2, last_char - 2);

			check = check.substr(last_char + 2);

			ss << num;
			ss >> number;
		}

		else
		{
			check = "";
		}

		if (number < time)
		{
			// Resets check to friendmsgs and breaks out of loop.
			check = friendmsgs;
			break;
		}
	}

	return check;
}
