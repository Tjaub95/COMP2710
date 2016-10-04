// Program 2:    Lab 2
// Name:         Tyler Jewell
// Class:        COMP 2710
// Date:         October 02, 2016
// E-Mail:       tjj0013@auburn.edu
//
// Description:  This class handles the storing of the posted
//               and tweeted messages in the dorrect files. It
//               also puts a timestamp on each message.

#include "Messages.h"

// Function: message
//
// Description: This function prompts for user input for a
//              message and then calls the timestamp
//              function to timestamp the message and stor
//              the message in a file.

void Messages::message(string name)
{
	string user = name, msg, msg_temp, msgs_temp, msgs, stamp, filename;
	ofstream outfile;
	ifstream infile;
	stringstream ss;

	cout << "Enter message: ";

	// Checks to make sure message is not the end of the message.
	while (msg != "$$")
	{
		getline(cin, msg);
		// If message = $$ then the user is through inputting and the if statement wil not execute.
		if (msg != "$$")
		{
			// If message string is empty then it will not add aything to the message_buffer.
			if (msg != "")
			{
				msg_temp += msg + "$^";
			}
		}
	}

	// Calls the timestamp() function.
	timestamp();

	// Converts the number in time to a string.
	ss << "%[" << time;
	ss >> stamp;

	// Creates the string that will need to be wrote to the user's file.
	msg_buffer = stamp + "]%" + msg_temp + msg_buffer;

	// Checks to make sure the user's file is available and opens it.
	filename = user;
	ifstream my_file(filename.c_str());
	if (my_file.good())
	{
		my_file.close();
		filename = user;
		infile.open(filename.c_str());

		// Reads anything that is in the user's file and stores it in a string.
		while (infile >> msgs)
		{
			msgs_temp = msgs_temp + " " + msgs;
		}

		// Adds the new message to the front of the string in the user file.
		msg_buffer += msgs_temp;

		// Opens the user's file for writing.
		outfile.open(filename.c_str());

		// Writes the new string to the user's file.
		outfile << msg_buffer;
		outfile.flush();
		outfile.close();
	}

	cout << "========================================================" << endl;
	cout << "|                   New message added                   |" << endl;
	cout << "========================================================" << endl << endl << endl;
	cout << endl;

}

void Messages::timestamp()
{
	string filename;
	ifstream infile;
	ofstream outfile;

	// Checks to see if a time file has been created and
	// opens it for reading if it has already been created.
	ifstream my_file("time");
	if (my_file.good())
	{
		my_file.close();
		filename = "time";
		infile.open(filename.c_str());

		// Readss the number in the file and stores it in an int.
		infile >> time;

		//Increments the number to show a new message has been added.
		time++;
		infile.close();

		// Opens the time file for writing.
		outfile.open(filename.c_str());

		// Writes the new time to the file.
		outfile << time;
		outfile.flush();
		outfile.close();
	}

	// If the time file does not already exist creates one.
	else
	{
		// Sets the intial timestamp to 0.
		time = 0;

		// Creates a time file for writing.
		filename = "time";
		outfile.open(filename.c_str());

		// Writes the time to the time file.
		outfile << time;
		outfile.flush();
		outfile.close();
	}
}
