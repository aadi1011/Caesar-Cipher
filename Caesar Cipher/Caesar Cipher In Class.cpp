#include <iostream>
#include <string.h>
using namespace std;

class Cipher
{
public:
	void getInput();
	void UserChoice();
	void encrypt();
	void decrypt();
	
private:
	char message[1000];
	int key;
	int choice;
};

void Cipher::getInput()
{
	cout << "Enter message to encrypt/decrypt\n(place two spaces before typing sentence the first time)\n\n--> ";
	cin.ignore(2, '\n');									//without this first 2 input char gets ommited. Reason:unknown
	cin.getline(message, 1000);
	system("cls");
	cout << "Message: " << "> " << message << endl;
	cout << endl << "Enter key: ";
	cin >> key;
	system("cls");
}

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
}

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
}

void main()
{
	Cipher C;
	C.getInput();
	C.UserChoice();
}