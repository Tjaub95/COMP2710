// Program 2:   Lab2
// Name:        Tyler Jewell
// Class:       COMP 2710
// Date:        October 1, 2016
// E-mail:      tjj0013@auburn.edu
//
// Description: This class handles the printing of the main
//              menu and the control of the switching based on
//              user selection.

#include "Menu.h"

// Function:    program
// Description: Prompts the user name and prints main menu

void Menu::program()
{
	// This is a constant length between the two | chars
	const int WELCOME_LENGTH = 55;

	string welcome, users, option2, filename;
	int name_length, _length;
	char option;
	bool found = false; // determines if a word was found
	ofstream outfile;
	ifstream infile, readFile;

	cout << "========================================================" << endl;
	cout << "|             Distributed AubieBook System!             |" << endl;
	cout << "========================================================" << endl << endl << endl;

	cout << "Please enter user name: ";
	cin >> name;
	cout << endl;

	// Checks to see if "users" is already created.
	ifstream my_file("users");
	if (my_file.good())
	{
		my_file.close();

		filename = "users";
		infile.open(filename.c_str());

		// Checks to see if user is already in the file.
		while (infile >> users)
		{
			if (users == name)
			{
				found = true;
			}
		}

		// If user is not already in file
		if (found == false)
		{
			// Opens file for appending and adds user to file.
			outfile.open("users", ios::app);
			outfile << name + "\n";
			outfile.flush();
			outfile.close();

			// Creates a file with users name.
			filename = name;
			outfile.open(filename.c_str());
			outfile.flush();
			outfile.close();
		}
	}
	else
	{
		// Creates "users" and adds user
		filename = "users";
		outfile.open(filename.c_str());
		outfile << name + "\n";
		outfile.flush();
		outfile.close();

		// Creates a file with users name.
		filename = name;
		outfile.open(filename.c_str());
		outfile.flush();
		outfile.close();
	}

	welcome = "Welcome to Distributed AubieBook System, " + name + "!";
	name_length = welcome.length();
	_length = (WELCOME_LENGTH - name_length) / 2;
	while (_length > 0)
	{
		welcome = " " + welcome + " ";
		_length--;
	}

	cout << "========================================================" << endl;
	cout << "|" << welcome << "|" << endl;
	cout << "========================================================" << endl << endl << endl;

	// Continue loop until user selects to quit AubieBook
	do
	{
		// Prints main menu for program.
		cout << "Add Friend (f), Post (p), Follow (t), Wall (w), Home (h), Quit (q)" << endl;
		cout << "Enter option: ";
		cin >> option;
		cout << endl;

		getline(cin, option2);

		switchOption(option);
	}
	while (option != 'q');
}
// Function:    switchOption
// Description: This function switches to different classes
//              within the program based off user input.

void Menu::switchOption(char option)
{
	Messages msg;
	Friends newFriend;
	int i;
	char selection = option;

	// Used in Pages class to go to correct function based off user input.
	if (selection == 'h')
	{
		i = 0;
	}
	else
	{
		i = 1;
	}

	// Goes to correct class based off user input.
	switch (selection)
	{
		case 'f':
			newFriend.addFriend(name);
			break;

		case 'p':
			msg.message(name);
			break;

		case 't':
			break;

		case 'w':
			break;

		case 'h':
			break;

		case 'q':
			cout << "========================================================" << endl;
			cout << "|       Thank you for using the AubieBook System        |" << endl;
			cout << "========================================================" << endl << endl << endl;
			break;

		default:
			cerr << "Invalid menu option." << endl;
			break;
	}
}
