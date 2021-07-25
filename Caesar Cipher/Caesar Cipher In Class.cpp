#include <iostream>
#include <string.h>
using namespace std;

class Cipher
{
public:
	void getInput();

private:
	char message[1000];
	int key;
	int choice;
};

void Cipher::getInput()
{
	cout << "Enter message to encrypt/decrypt\n (place two spaces before typing sentence the first time)\n\n--> ";
	cin.ignore(2, '\n');									//without this first 2 input char gets ommited. Reason:unknown
	cin.getline(message, 1000);
	system("cls");
	cout << "Message: " << "> " << message << endl;
	cout << endl << "Enter key: ";
	cin >> key;
	system("cls");
	cout << "Message: " << message << "\nkey: " << key << endl;
}

void main()
{
	Cipher C;
	C.getInput();
}