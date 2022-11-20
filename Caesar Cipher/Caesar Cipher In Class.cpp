//Caesar Cipher encryption code by Aadith Sukumar (github.com/aadi1011)

/*Caesar Cipher is an encryption method that allow the user to encyprt their message by converting
charecter of the text into the next or set of number changes according to the alphabetical line.
This code is made using the OOP method using a class. If you want the same program but in a single function code,
check out "Caesar Cipher.cpp*/

#include <iostream>
#include <string.h>
using namespace std;

//class of Cipher
class Cipher
{
public:
	void getInput();
	void UserChoice();
	void encrypt();
	void decrypt();
	void askExit();
	
private:
	char message[1000]; //if user requires to input message of more than 1000 charecters, change the [number] accordingly
	int key;			//number of letters user wants to push ahead/behind
	int choice;			//choice of encryption or decryption
};

//function to get user input of message/key
void Cipher::getInput()
{
	cout << "Enter message to encrypt/decrypt\n\n--> ";
	cin >> ws;					//clears the whitespaces from the previous input when program is used in loop.
	cin.getline(message, 1000);
	system("cls");
	cout << "Message: " << message << endl;
	cout << endl << "Enter key: ";
	cin >> key;
	system("cls");
}

//function to act on user's choice of encryption or decryption
void Cipher::UserChoice()
{
	system("cls");
	cout << "Message: " << message << "\nkey: " << key << endl;
	cout << "\nEnter your choice: \n1. Encrypt\n2. Decrypt\n\n--> ";
	cin >> choice;
	if (choice == 1)
	{
		Cipher::encrypt();
	}
	else if (choice == 2)
	{
		Cipher::decrypt();
	}
	else
	{
		cout << "Invalid input entered. Try again using '1' or '2'\n\n";
		system("pause");
		Cipher::UserChoice();
	}
}

//encryption function
void Cipher::encrypt()
{
	char ch;
	for (int i = 0; message[i] != '\0'; i++)
	{
		ch = message[i];
		if (ch >= 'a' && ch <= 'z')					//Lowercase Encryption
		{
			ch = ch + key;
			if (ch > 'z')
			{
				ch = ch - 'z' + 'a' - 1;
			}
			message[i] = ch;
		}
		else if (ch >= 'A' && ch <= 'Z')			//Uppercase Encryption
		{
			ch = ch + key;
			if (ch > 'Z')
			{
				ch = ch - 'Z' + 'A' - 1;
			}
			message[i] = ch;
		}
	}
	cout << "Encrypted message: " << message << endl << endl;
	system("pause");
	system("cls");
}

//decryption function
void Cipher::decrypt()
{
	char ch;
	for (int i = 0; message[i] != '\0'; i++)
	{
		ch = message[i];
		if (ch >= 'a' && ch <= 'z')					//Lowercase Decryption
		{
			ch = ch - key;
			if (ch > 'z')
			{
				ch = ch + 'z' - 'a' + 1;
			}
			message[i] = ch;
		}
		else if (ch >= 'A' && ch <= 'Z')			//Uppercase Decryption
		{
			ch = ch - key;
			if (ch > 'Z')
			{
				ch = ch + 'Z' - 'A' + 1;
			}
			message[i] = ch;
		}
	}
	cout << "Decrypted message: " << message << endl << endl;
	system("pause");
	system("cls");
}


//funtion of exit menu
void Cipher::askExit()
{
	cout << "Would you like to use the cipher service again? (y/n)\n\n--> ";
	char askexit;
	cin >> askexit;
	if (askexit == 'n' || askexit == 'N')
	{
		system("cls");
		cout << "Thank you for using the cipher.\n\n";
		exit(0);		//program terminates
	}
	else if (askexit == 'y' || askexit == 'Y')	//executes the loop
	{
		system("cls");
		Cipher::getInput();
		Cipher::UserChoice();
		Cipher::askExit();
	}
	else
	{
		system("cls");
		cout << "\nInvalid input entered. Please try again using 'y' or 'n'\n\n";
		Cipher::askExit();
	}
}

int main()
{
	// Welcome message
    cout << "Caesar Cipher - by aadi1011 (https://www.github.com/aadi101).\n\n";
    cout << "This program allows you to encrypt or decrypt a message using the Caesar Cipher method.\n\n";
    cout << "Press any key to start...\n\n";
    system("pause");
    system("cls");

    
    Cipher C;
    C.UserChoice();
	C.getInput();
	C.askExit();
	return 0;
}
