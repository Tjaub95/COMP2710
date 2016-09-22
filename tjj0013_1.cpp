// Program 1:    Lab 1
// Name:         Tyler Jewell
// Class:        COMP 2710
// Date:         September 17, 2016
// E-Mail:       tjj0013@auburn.edu
//
// Description:  This program allows multiple users to share messages
//               if they are in the same friend group. Users can post
//               messages to their wall and friends. There are eight
//				 options for the user to pick from the main menu. The
//				 options include create new user, post a message,
//               display wall page, display home page, add a friend,
//				 switch to a different user, follow a hashtag topic
//               and quit Aubiebook.

#include <iostream>
#include <string>

using namespace std;

//Class: Menu
//Description: This class displays the main menu with the options
//             allow the user/current user to enter inputs, and
//             and handle baisic ou tof bounds options presented
//             by the user.

class Menu
{
public:
	string user;
	string message_buffer;
	string currentUser;
	string friendsList;
	string hashtagList;

	void userWelcome(string, bool);
	void welcomeWall();
	void optionWall();
	void registerFunction();
	void messageFunction(string);
	void newFriend();
	void swapUser();
	void followHashtag();
	void logOff();
};

//Class: HomePage
//Description: Will display messages in reverse chronological order
//             from the current user, their friends, and the hashtag's
//             they're follwoing.

class HomePage
{
public:
	void makeHPage(string, string, string, string);
};

//Class: FriendList
//Description: Contains each user's friend's list.

class FriendList
{
public:
	void findFriend();
};

//Class: HashtagList
//Description: Contains each user's followed hashatag list.

class HashtagList
{
public:
	void findHashtag();
};

//Class: User
//Description: Contains information from the current user,
//             they're friend's list, and followed hashtag topics.

class User
{
public:
	void currUser(string, string, string, string);
};

//Class: WallPage
//Description: Displays the wall page of the current user.

class WallPage
{
public:
	void makeWall(string, string);
};

//Function: main
//Description: This is the driver function for the program. It calls the welcomeWall fucntion.

int main() {
	Menu menu;

	menu.welcomeWall();

	return 0;
}

//Function: welcomeWall
//Description: Welcomes the user, whether it is registering, switching users or if it
//             is done with another function such as adding a friend, in whcih welcome
//             will now prompt the user with options. It will call optionWall after completion.

void Menu::welcomeWall()
{
	cout << "===============================================" << endl;
	cout << "|              Welcome to AubieBook!          |" << endl;
	cout << "===============================================\n\n";

	optionWall();
}

void Menu::optionWall()
{
	const char CASE1 = 'n', CASE2 = 'p', CASE3 = 'w', CASE4 = 'h', CASE5 = 'f', CASE6 = 't', CASE7 = 'c', CASE8 = 'q';

	string selection, friends, line;
	char choice;

	WallPage wall;
	HomePage home;

	do
	{
		cout << "Create new user (n), Post (p), Wall page (w), Home page (h), Add friend (f), follow hashtag (t), Change user (c), Quit (q)" << endl;
		cout << "\nEnter option: ";
		cin >> selection;

		getline(cin, line);

		cout << endl;

		if (selection.length() < 1)
		{
			choice = 'z';
		}
		else
		{
			choice = selection.at(0);
		}

		if (user.length() == 0 && choice != 'n' && choice != 'q')
		{
			cerr << "Your input was invalid!" << endl << endl;
		}
		else
		{
			switch (choice)
			{
				case CASE1:
					registerFunction();
					break;

				case CASE2:
					messageFunction(currentUser);
					break;

				case CASE3:
					wall.makeWall(currentUser, message_buffer);
					break;

				case CASE4:
					home.makeHPage(currentUser, friendsList, message_buffer, hashtagList);
					break;

				case CASE5:
					newFriend();
					break;

				case CASE6:
					followHashtag();
					break;

				case CASE7:
					swapUser();
					break;

				case CASE8:
					logOff();
					break;

				default:
					cerr << "Your input was invalid!" << endl << endl;
					break;
			}
		}
	}
	while(choice != 'q');
}

void Menu::userWelcome(string name, bool swapUser)
{
	string currentUser = name;

	bool check = swapUser;

	string welcome;

	const int WELCOME_LENGTH = 48;

	if (!check)
	{
		welcome = "Welcome to AubieBook, " + currentUser + "!";
	}
	else
	{
		welcome = "Welcome back, " + currentUser + "!";
	}
	int name_length = welcome.length();
	int length = (WELCOME_LENGTH - name_length)/2;

	while (length > 0)
	{
		welcome = " " + welcome + " ";
		length--;
	}

	cout << "==================================================" << endl;
	cout << "|" << welcome << "|" << endl;
	cout << "==================================================\n\n";
}

void Menu::registerFunction()
{
	cout << "Please enter user name: ";
	cin >> currentUser;

	user += "%(" + currentUser + ")%";
	userWelcome(currentUser, false);
}

void Menu::messageFunction(string name)
{
	string message, message_temp, user_temp = name;

	cout << "Enter message: ";

	while (message != "$$")
	{
		getline (cin, message);

		if (message != "$$")
		{
			if (message != "")
			{
				message_temp += message + "$^";
			}
		}
	}

	message_buffer = "%(" + user_temp + ")%" + message_temp + message_buffer;
	message = "";
	message_temp = "";
	cout << endl;
}

void Menu::newFriend()
{
	string friends, user_buffer = user, tempUser, user, new_friend, friendList_temp = friendsList;
	size_t first_char, last_char;
	bool check = false, available = false;

	cout << "Enter friend's name: ";
	cin >> friends;

	cout << endl;

	while (user_buffer.length() > 0)
	{
		first_char = user_buffer.find("%(");
		last_char = user_buffer.find(")%");
		user_buffer = user_buffer.substr(first_char + 2);
		tempUser = user_buffer.substr(0, last_char - 2);
		user_buffer = user_buffer.substr(last_char);

		if (friends == currentUser)
		{
			cerr << "You can not add yourself as a friend." << endl << endl;
			check = false;
			available = true;
			break;
		}

		if (friends == tempUser)
		{
			user_buffer = "";
			check = true;
			available = true;
		}

		else
		{
			available = false;
		}
	}

	if (!available)
	{
		cerr << "Friend is not a valid user." << endl << endl;
	}

	if (check)
	{
		while (friendList_temp.length() > 0)
		{
			first_char = friendList_temp.find("%(");
			last_char = friendList_temp.find(")%");
			tempUser = friendList_temp.substr(first_char + 2, last_char - 2);
			friendList_temp = friendList_temp.substr(last_char + 2);

			first_char = friendList_temp.find("@(");
			last_char = friendList_temp.find(")@");
			new_friend = friendList_temp.substr(first_char + 2, last_char - 2);
			friendList_temp = friendList_temp.substr(last_char + 2);

			if (tempUser == currentUser)
			{
				if (new_friend == friends)
				{
					cerr << "Users are already friends." << endl << endl;
					friendList_temp = "";
					break;
				}
			}
			else
			{
				new_friend = "";
			}
		}

		if (new_friend != friends)
		{
			friendsList = "%(" + currentUser + ")%" + "@(" + friends + ")@" + friendsList;
		}
	}
}

void Menu::swapUser()
{
	string user_buffer = user, tempUser, new_user;
	size_t first_char;

	cout << "Enter user's name: ";
	cin >> new_user;

	if (new_user == currentUser)
	{
		cerr << "You are already the current user." << endl << endl;
	}
	else
	{
		while (user_buffer.length() > 0)
		{
			first_char = user_buffer.find("%(");
			user_buffer = user_buffer.substr(first_char + 2);
			tempUser = user_buffer.substr(0, user_buffer.find(")%"));
			user_buffer = user_buffer.substr(user_buffer.find(")%") + 2);

			if (new_user == tempUser)
			{
				user_buffer = "";
				currentUser = new_user;
			}
		}

		if (currentUser == new_user)
		{
			cout << endl;
			userWelcome(new_user, true);
		}
		else
		{
			cout << endl;
			cerr << "You cannot switch to a user that is not created." << endl << endl;
		}
	}
}

void Menu::logOff()
{
	cout << "==============================================" << endl;
	cout << "|       Thank you for using AubieBook        |" << endl;
	cout << "==============================================" << endl;
}

void WallPage::makeWall(string currUser, string messages)
{
	const int WELCOME_LENGTH = 55;

	int name_length, length, i = 0, j = 0;
	string welcome, message_buffer_temp = messages, user_temp;
   	string message_temp, message_buffer_temp2, more_messages, current_user = currUser;
	size_t first_char, start_pos = 0;

	welcome = current_user + "'s Wall Page";
	name_length = welcome.length();
	length = (WELCOME_LENGTH - name_length)/2;

	while (length > 0)
	{
		welcome = " " + welcome + " ";
		length--;
	}

	cout << "========================================================" << endl;
	cout << "|" << welcome << "|" << endl;
	cout << "========================================================" << endl << endl;

	// Finds the first occurence of the string "$^" from the start position
	// and replaces it with "\n" so long as the index returned by find is not
	// equal to the end of the string.
	if (!message_buffer_temp.empty())
	{
		while ((start_pos = message_buffer_temp.find("$^", start_pos)) != std::string::npos)
		{
			message_buffer_temp.replace(start_pos, 2, "\n");
			start_pos += 2;
		}
	}

	while (message_buffer_temp.length() > 0)
	{
		while (i < 4)
		{
			first_char = message_buffer_temp.find("%(");
			message_buffer_temp = message_buffer_temp.substr(first_char + 2);
			user_temp = message_buffer_temp.substr(0, message_buffer_temp.find(")%"));
			message_buffer_temp = message_buffer_temp.substr(message_buffer_temp.find(")%") + 2);

			if (user_temp == current_user)
			{
				i++;

				if (i == 4)
				{
					message_buffer_temp = "";
					j = 3;
				}
				else
				{
					message_temp = message_buffer_temp.substr(0, message_buffer_temp.find("%("));
					message_buffer_temp = message_buffer_temp.substr(message_temp.length() - 2);
					message_buffer_temp = message_buffer_temp.substr(message_buffer_temp.find("\n") + 1);
					message_buffer_temp2 = message_buffer_temp;

					//Prints the user and their message is reverse chronological order.
					cout << message_temp << endl;
				}
			}
			else
			{
				message_temp = message_buffer_temp.substr(0, message_buffer_temp.find("%("));
				message_buffer_temp = message_buffer_temp.substr(message_temp.length() - 2);
				message_buffer_temp = message_buffer_temp.substr(message_buffer_temp.find("\n") + 1);
				message_buffer_temp2 = message_buffer_temp;
			}

			if (message_buffer_temp.length() == 0)
			{
				i = 4;
			}
		}
	}

	if (j == 3)
	{
		cout << "More messages? (yes/no): ";
		cin >> more_messages;
		cout << endl;

		if (more_messages == "yes")
		{
			while (message_buffer_temp2.length() > 0)
			{
				first_char = message_buffer_temp2.find("%(");
				message_buffer_temp2 = message_buffer_temp2.substr(first_char + 2);
				user_temp = message_buffer_temp2.substr(0, message_buffer_temp2.find(")%"));

				//Checks the users is the message_buffer to see if they are the current user.
				//If it is the current user then the user and message are printed and i is incremented.
				if (user_temp == current_user)
				{
					message_buffer_temp2 = message_buffer_temp2.substr(message_buffer_temp2.find(")%") + 2);
					message_temp = message_buffer_temp2.substr(0, message_buffer_temp2.find("%("));
					message_buffer_temp2 = message_buffer_temp2.substr(message_temp.length() - 2);

					//Checks to see if the string equals the new line character. If it does then the message_buffer_temp2
					//is cleared.
					if(message_buffer_temp2 == "\n")
					{
						message_buffer_temp2 = "";
					}

					//Prints the rest of the messages for the user.
					cout << message_temp << endl;
				}
			}
		}
	}
}

void HomePage::makeHPage(string user, string friends, string messages, string hashtags)
{
	const int WELCOME_LENGTH = 55;

	int name_length, length, i = 0, j = 0;
	string current_user = user, messageBuffer = messages, friendListTemp = friends, hashtagListTemp = hashtags;
	string user1, welcome, user_temp, message_temp, message_buffer_temp2, more_messages, home_buffer, user2;
	size_t first_char, start_pos = 0;

	welcome = current_user + "'s Home Page";
	name_length = welcome.length();
	length = (WELCOME_LENGTH - name_length)/2;

	while (length > 0)
	{
		welcome = " " + welcome + " ";
		length--;
	}

	cout << "========================================================" << endl;
	cout << "|" << welcome << "|" << endl;
	cout << "========================================================" << endl << endl;

	// Finds the first occurence of the string "$^" from the start position
	// and replaces it with "\n" so long as the index returned by find is not
	// equal to the end of the string.
	if (!messageBuffer.empty())
	{
		while ((start_pos = messageBuffer.find("$^", start_pos)) != std::string::npos)
		{
			messageBuffer.replace(start_pos, 2, "\n");
			start_pos += 2;
		}
	}

	while (messageBuffer.length() > 0)
	{

		while (i < 3)
		{
			first_char = messageBuffer.find("%(");
			messageBuffer = messageBuffer.substr(first_char + 2);
			user_temp = messageBuffer.substr(0, messageBuffer.find(")%"));
			messageBuffer = messageBuffer.substr(messageBuffer.find(")%") + 2);

			if (user_temp == current_user)
			{
				message_temp = messageBuffer.substr(0, messageBuffer.find("%("));
				messageBuffer = messageBuffer.substr(message_temp.length() - 2);
				messageBuffer = messageBuffer.substr(messageBuffer.find("\n") + 1);
				message_buffer_temp2 = messageBuffer;

				home_buffer += user_temp + " >>\n" + message_temp + "\n";

				i++;

				if (i == 3)
				{
					messageBuffer = "";
					j = 3;
				}

				if (messageBuffer.length() == 0)
				{
					i = 3;
				}
			}
			else if (friendListTemp.length() == 0)
			{
				if (messageBuffer.find(")%") == std::string::npos)
				{
					messageBuffer = "";
					i = 3;
				}
			}
			else
			{

				while (friendListTemp.length() > 0)
				{
					first_char = friendListTemp.find("%(");
					friendListTemp = friendListTemp.substr(first_char + 2);
					user1 = friendListTemp.substr(0, friendListTemp.find(")%"));
					friendListTemp = friendListTemp.substr(friendListTemp.find(")%") + 2);

					if (user1 == current_user)
					{
						first_char = friendListTemp.find("@(");
						friendListTemp = friendListTemp.substr(first_char + 2);
						user2 = friendListTemp.substr(0, friendListTemp.find(")@"));
						friendListTemp = friendListTemp.substr(friendListTemp.find(")@") + 2);

						if (user_temp == user2)
						{
							first_char = messageBuffer.find("%(");
							message_temp = messageBuffer.substr(0, first_char);
							message_buffer_temp2 = messageBuffer.substr(message_temp.length() + 2);

							home_buffer += user_temp + " >>\n" + message_temp + "\n";

							friendListTemp = "";

							i++;

							if (i == 3)
							{
								messageBuffer = "";
								j = 3;
							}
						}
					}

					else
					{
						first_char = friendListTemp.find("@(");
						friendListTemp = friendListTemp.substr(first_char + 2);
						user2 = friendListTemp.substr(0, friendListTemp.find(")@"));
						friendListTemp = friendListTemp.substr(friendListTemp.find(")@") + 2);
					}

					if (messageBuffer.length() == 0)
					{
						i = 3;
					}
				}

				friendListTemp = friends;
			}
		}
	}

	cout << home_buffer;

	if (j == 3)
	{
		cout << "More messages? (yes/no): ";
		cin >> more_messages;
		cout << endl;

		if (more_messages == "yes")
		{
			messageBuffer = message_buffer_temp2;
			home_buffer = "";

			//Continues until messageBuffer is empty
			while(messageBuffer.length() > 0)
			{
				first_char = messageBuffer.find("%(");
				messageBuffer = messageBuffer.substr(first_char + 2);
				user_temp = messageBuffer.substr(0, messageBuffer.find(")%"));
				messageBuffer = messageBuffer.substr(messageBuffer.find(")%") + 2);

				//Checks the users is the message_buffer to see if they are the current user.
				//If it is the current user then the user and message are printed and i is incremented.
				if(user_temp == current_user)
				{
					message_temp = messageBuffer.substr(0, messageBuffer.find("%("));
					messageBuffer = messageBuffer.substr(message_temp.length() - 2);
					messageBuffer = messageBuffer.substr(messageBuffer.find("\n") + 1);
					message_buffer_temp2 = messageBuffer;
					home_buffer += user_temp + " >>\n" + message_temp + "\n";
				}

				else if (friendListTemp.length() == 0)
				{
					if (messageBuffer.find(")%") == std::string::npos)
					{
						messageBuffer = "";
					}
				}
				//If it is not the current user then that user and message is removed from the message buffer.
				else
				{

					//Continues loop until friendList_temp is empty.
					while(friendListTemp.length() > 0)
					{
						first_char = friendListTemp.find("%(");
						friendListTemp = friendListTemp.substr(first_char + 2);
						user1 = friendListTemp.substr(0, friendListTemp.find(")%"));
						friendListTemp = friendListTemp.substr(friendListTemp.find(")%") + 2);

						//Checks to see if the user in the friend list is the current user.
						if(user1 == current_user)
						{
							first_char = friendListTemp.find("@(");
							friendListTemp = friendListTemp.substr(first_char + 2);
							user2 = friendListTemp.substr(0, friendListTemp.find(")@"));
							friendListTemp = friendListTemp.substr(friendListTemp.find(")@") + 2);

							//Checks to see if the friend in the friend list equals the friend in the message buffer.
							if(user_temp == user2)
							{
								first_char = messageBuffer.find("%(");
								message_temp = messageBuffer.substr(0, first_char);

								//If messageBuffer is emptied then i set to 3 to end the while loop.
								if(messageBuffer.length() == 0)
								{
									friendListTemp = "";
								}

								home_buffer += user_temp + " >>\n" + message_temp + "\n\n";
								friendListTemp = "";

							}
						}
					}
				}

				messageBuffer = messageBuffer.substr(messageBuffer.find("\n") + 1);

				//resets the friendListTemp to the friendList after the while loop.
				friendListTemp = friends;
			}

			//Prints out the user and the user's friends messages.
			cout << home_buffer;
		}
	}
}

void Menu::followHashtag()
{
	string hashtags, user_buffer = user, tempUser, user, new_hashtag, hashtagList_temp = hashtagList;
	size_t first_char, last_char;

	cout << "Enter hashtag to follow: ";
	cin >> hashtags;

	cout << endl;

	while (hashtagList_temp.length() > 0)
	{
		first_char = hashtagList_temp.find("%(");
		last_char = hashtagList_temp.find(")%");
		tempUser = hashtagList_temp.substr(first_char + 2, last_char - 2);
		hashtagList_temp = hashtagList_temp.substr(last_char + 2);

		first_char = hashtagList_temp.find("#(");
		last_char = hashtagList_temp.find(")#");
		new_hashtag = hashtagList_temp.substr(first_char + 2, last_char - 2);
		hashtagList_temp = hashtagList_temp.substr(last_char + 2);

		if (tempUser == currentUser)
		{
			if (new_hashtag == hashtags)
			{
				cerr << "You already follow this hashtag." << endl << endl;
				hashtagList_temp = "";
				break;
			}
		}
		else
		{
			new_hashtag = "";
		}
	}

	if (new_hashtag != hashtags)
	{
		hashtagList = "%(" + currentUser + ")%" + "#(" + hashtags + ")#" + hashtagList;
	}

}
