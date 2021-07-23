#include <iostream>
#include <string.h>
using namespace std;

void main()
{
start:
	char message[1000];
	int key;
	cout << "Enter message to encrypt/decrypt\n (place two spaces before typing sentence the first time)\n\n--> ";
	cin.ignore(2, '\n');									//without this first 2 input char gets ommited. Reason:unknown
	cin.getline(message, 1000);
	system("cls");
	cout << "Message: " << "> " << message << endl;
	cout << endl << "Enter key: ";
	cin >> key;
	int length = strlen(message);
	system("cls");
	cout << "Message: " << message << "\nkey: " << key << endl;
	goto choice;

choice:
	int choice;
	cout << "\nEnter your choice: \n1. Encrypt\n2. Decrypt\n\n--> ";
	cin >> choice;
	goto sort;

sort:
	if (choice == 1)
	{
		char ch;
		for (int i = 0; message[i] != '\0'; i++)
		{
			ch = message[i];
			if (ch >= 'a' && ch <= 'z')					//Lowercase Encryption
			{
				ch = ch + key;
				if (ch>'z')
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
		goto exit;
	}

	else if (choice == 2)
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
		goto exit;
	}
	else
	{
		system("cls");
		cout << "Invalid input entered. Please try again using '1' or '2'\n\n";
		goto choice;
	}

exit:
	system("cls");
	cout << "Would you like to use the cipher service again? (y/n)\n\n--> ";
	char askexit;
	cin >> askexit;
	if (askexit == 'n' || askexit == 'N')
	{
		system("cls");
		cout << "Thank you for using the cipher.\n\n";
		exit(0);
	}
	else if (askexit == 'y' || askexit == 'Y')
	{
		system("cls");
		goto start;
	}
	else
	{
		system("cls");
		cout << "\nInvalid input entered. Please try again using 'y' or 'n'\n\n";
		goto exit;
	}
}
