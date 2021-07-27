#include <iostream>
#include <string.h>
using namespace std;

class Cipher
{
public:
	void getInput();
	void UserChoice();
	
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
	cout << "Message: " << message << "\nkey: " << key << endl;
}

void Cipher::UserChoice()
{
	
	system("cls");
	cout << "\nEnter your choice: \n1. Encrypt\n2. Decrypt\n\n--> ";
	cin >> choice;
	if (choice == 1)
	{

	}
	else if (choice == 2)
	{

	}
	else
	{
		cout << "Invalid input entered. Try again using '1' or '2'\n\n";
		system("pause");
		Cipher::UserChoice();
	}
}

void main()
{
	Cipher C;
	C.getInput();
	C.UserChoice();
}