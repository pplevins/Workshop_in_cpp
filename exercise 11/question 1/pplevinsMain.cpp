/* Pinchas Plevinski 322211558
Workshop in C++ 150018
Exercise 11 Question 1
The program creates a binary file with list of families, and their classes registerations.*/

#include "Family.h"
#include <queue>
#include <iostream>
#include <fstream>
#include <exception>
using namespace std;

enum { EXIT, ADD, DEL, COUNT, UPDATE, WAITING, PRINT };

enum ACTIVITY {
	NONE, //  èøí áçø çåâ
	SWIMMING,          // ùçéä 
	GYMNATSTICS,         // äúòîìåú ÷ø÷ò
	DANCE = 4,     // îçåì
	ART = 8,    // àåîðåú
	SELF_DEFENSE = 16, // äâðä òöîéú
	MUSIC = 32, // îåñé÷ä
	DRAMA = 64, // ãøîä
	BASKETBALL = 128  // ëãåø ñì
};

void setFile(fstream& myFile) //initailizing the file with an empty 100 families
{
	Family f;
	f.setClasses(NONE);
	for (int i = 0; i < 100; i++)
		myFile.write((char*)&f, sizeof(Family));
}

void add(fstream& myFile) //adding new family to the file
{
	int num, amount, phone;
	char arr[21];
	Family f;
	cout << "enter the family's:  id, name, amount of people and a phone number:\n";
	cin >> num >> arr >> amount >> phone;
	if (num < 1 || num > 100) //check for the family number
		throw "ERROR: Invalid family number";
	//searching the family in the file
	myFile.seekg((num - 1) * sizeof(Family));
	myFile.read((char*)&f, sizeof(Family));
	if (f.getFamilyNum() != 0)
		throw "ERROR: Family is already in the file";
	f.setFamilyName(arr);
	f.setFamilyNum(num);
	f.setMembers(amount);
	f.setPhone(phone);
	f.setClasses(NONE);
	myFile.seekp((num - 1) * sizeof(Family));
	myFile.write((char*)&f, sizeof(Family)); //writing the new family in the file 
}

void del(fstream& myFile, int num) //erasing a family from the file
{
	Family f;
	if (num < 1 || num>100) //check for the family number
		throw "ERROR: Invalid family number";
	//searchong the family in the file
	myFile.seekg((num - 1) * sizeof(Family));
	myFile.read((char*)&f, sizeof(Family));
	if (f.getFamilyNum() == 0)
		throw "ERROR: Family is not in the file";
	Family f1;
	f1.setClasses(NONE);
	myFile.seekp((num - 1) * sizeof(Family));
	myFile.write((char*)&f1, sizeof(Family)); //overwriting an empty family in the file
}

int count(fstream& myFile, int num) //counting how many families in this class
{
	Family f;
	int counter = 0;
	myFile.seekg(0); //sets the position to the begining of the file
	for (int i = 0; i < 100; i++)
	{
		myFile.read((char*)&f, sizeof(Family));
		if ((f.getClasses() & num) != 0) //bitwise operation 'and' with the class num
			counter++;
	}
	return counter;
}

void update(fstream& myFile, int fnum, queue<Family>& q) //updating the family classes
{
	Family f1;
	char answer;
	if (fnum < 1 || fnum>100)
		throw "ERROR: Invalid family number";

	myFile.seekg((fnum - 1) * sizeof(Family));
	myFile.read((char*)&f1, sizeof(Family));
	if (f1.getFamilyNum() == 0)
		throw "ERROR: Family is not in the file";
	
	short regiser = 0;
	cout << "Do you want to register for swimming?\n";
	cin >> answer;
	if (answer == 'y' || answer == 'Y')
	{
		if (count(myFile, SWIMMING) < 10) //if there's a space in class
		{
			//registering the family to class
			f1.setClasses(SWIMMING);
			myFile.seekp((fnum - 1) * sizeof(Family));
			myFile.write((char*)&f1, sizeof(Family));
		}
		else
			regiser |= SWIMMING; //adding swimming to the variable with bitwise 'or'
	}
	else if (answer != 'n' && answer != 'N')
		throw "ERROR: Invalid response\n";

	cout << "Do you want to register for gymnastics?\n";
	cin >> answer;
	if (answer == 'y' || answer == 'Y')
	{
		if (count(myFile, GYMNATSTICS) < 10)
		{
			f1.setClasses(GYMNATSTICS);
			myFile.seekp((fnum - 1) * sizeof(Family));
			myFile.write((char*)&f1, sizeof(Family));
		}
		else
			regiser |= GYMNATSTICS;
	}
	else if (answer != 'n' && answer != 'N')
		throw "ERROR: Invalid response\n";

	cout << "Do you want to register for dance?\n";
	cin >> answer;
	if (answer == 'y' || answer == 'Y')
	{
		if (count(myFile, DANCE) < 10)
		{
			f1.setClasses(DANCE);
			myFile.seekp((fnum - 1) * sizeof(Family));
			myFile.write((char*)&f1, sizeof(Family));
		}
		else
			regiser |= DANCE;
	}
	else if (answer != 'n' && answer != 'N')
		throw "ERROR: Invalid response\n";

	cout << "Do you want to register for art?\n";
	cin >> answer;
	if (answer == 'y' || answer == 'Y')
	{
		if (count(myFile, ART) < 10)
		{
			f1.setClasses(ART);
			myFile.seekp((fnum - 1) * sizeof(Family));
			myFile.write((char*)&f1, sizeof(Family));
		}
		else
			regiser |= ART;
	}
	else if (answer != 'n' && answer != 'N')
		throw "ERROR: Invalid response\n";

	cout << "Do you want to register for self defense?\n";
	cin >> answer;
	if (answer == 'y' || answer == 'Y')
	{
		if (count(myFile, SELF_DEFENSE) < 10)
		{
			f1.setClasses(SELF_DEFENSE);
			myFile.seekp((fnum - 1) * sizeof(Family));
			myFile.write((char*)&f1, sizeof(Family));
		}
		else
			regiser |= SELF_DEFENSE;
	}
	else if (answer != 'n' && answer != 'N')
		throw "ERROR: Invalid response\n";

	cout << "Do you want to register for music?\n";
	cin >> answer;
	if (answer == 'y' || answer == 'Y')
	{
		if (count(myFile, MUSIC) < 10)
		{
			f1.setClasses(MUSIC);
			myFile.seekp((fnum - 1) * sizeof(Family));
			myFile.write((char*)&f1, sizeof(Family));
		}
		else
			regiser |= MUSIC;
	}
	else if (answer != 'n' && answer != 'N')
		throw "ERROR: Invalid response\n";

	cout << "Do you want to register for drama?\n";
	cin >> answer;
	if (answer == 'y' || answer == 'Y')
	{
		if (count(myFile, DRAMA) < 10)
		{
			f1.setClasses(DRAMA);
			myFile.seekp((fnum - 1) * sizeof(Family));
			myFile.write((char*)&f1, sizeof(Family));
		}
		else
			regiser |= DRAMA;
	}
	else if (answer != 'n' && answer != 'N')
		throw "ERROR: Invalid response\n";

	cout << "Do you want to register basketball?\n";
	cin >> answer;
	if (answer == 'y' || answer == 'Y')
	{
		if (count(myFile, BASKETBALL) < 10)
		{
			f1.setClasses(BASKETBALL);
			myFile.seekp((fnum - 1) * sizeof(Family));
			myFile.write((char*)&f1, sizeof(Family));
		}
		else
			regiser |= BASKETBALL;
	}
	else if (answer != 'n' && answer != 'N')
		throw "ERROR: Invalid response\n";

	if (regiser != 0) //if there's a class without a space for the family
	{
		f1.setClasses(NONE); //reseting the classes
		f1.setClasses(regiser);
		q.push(f1);
	}
}

void waiting(queue<Family> q) //printing the waiting queue
{
	Family f;
	while (!q.empty())
	{
		f = q.front();
		q.pop();
		cout << "family name: " << f.getFamilyName() << endl;
		cout << "number of persons: " << f.getMembers() << endl;
		cout << "phone number: " << f.getPhone() << endl;
		for (int i = 1; i <= BASKETBALL; i<<=1) //shift left the i every iteration
		{
			switch (f.getClasses() & i) //bitwise check with the i
			{
			case SWIMMING:
				cout << "SWIMMING\n";
				break;
			case GYMNATSTICS:
				cout << "GYMNATSTICS\n";
				break;
			case DANCE:
				cout << "DANCE\n";
				break;
			case ART:
				cout << "ART\n";
				break;
			case SELF_DEFENSE:
				cout << "SELF DEFENSE\n";
				break;
			case MUSIC:
				cout << "MUSIC\n";
				break;
			case DRAMA:
				cout << "DRAMA\n";
				break;
			case BASKETBALL:
				cout << "BASKETBALL\n";
				break;
			default:
				break;
			}
		}
	}
}

void print(fstream& myFile, int fnum)
{
	Family f;
	if (fnum < 1 || fnum>100)
		throw "ERROR: Invalid family number";

	myFile.seekg((fnum - 1) * sizeof(Family));
	myFile.read((char*)&f, sizeof(Family));
	if (f.getFamilyNum() == 0)
		throw "ERROR: Family is not in the file";
	cout << "family name: " << f.getFamilyName() << endl;
	cout << "number of persons: " << f.getMembers() << endl;
	cout << "phone number: " << f.getPhone() << endl;
	for (int i = 1; i <= BASKETBALL; i <<= 1) //shift left the i
	{
		switch (f.getClasses() & i) //bitwise 'and' check with i
		{
		case SWIMMING:
			cout << "SWIMMING\n";
			break;
		case GYMNATSTICS:
			cout << "GYMNATSTICS\n";
			break;
		case DANCE:
			cout << "DANCE\n";
			break;
		case ART:
			cout << "ART\n";
			break;
		case SELF_DEFENSE:
			cout << "SELF DEFENSE\n";
			break;
		case MUSIC:
			cout << "MUSIC\n";
			break;
		case DRAMA:
			cout << "DRAMA\n";
			break;
		case BASKETBALL:
			cout << "BASKETBALL\n";
			break;
		default:
			break;
		}
	}
}

//the standard function for the exercise
void handleCount(fstream& file) {
	int snum;
	cout << "enter activity number to count:\n";
	cout << "Choices are:\n1 SWIMMING\n2 GYMNASTICS\n3 DANCE\n4 ART\n5 SELF DEFENSE \n6 MUSIC \n7 DRAMA\n8 BASKETBALL\n";
	cin >> snum;
	cout << "there are ";
	switch (snum) {
	case 1:
		cout << count(file, SWIMMING);
		break;
	case 2:
		cout << count(file, GYMNATSTICS);
		break;
	case 3:
		cout << count(file, DANCE);
		break;
	case 4:
		cout << count(file, ART);
		break;
	case 5:
		cout << count(file, SELF_DEFENSE);
		break;
	case 6:
		cout << count(file, MUSIC);
		break;
	case 7:
		cout << count(file, DRAMA);
		break;
	case 8:
		cout << count(file, BASKETBALL);
		break;
	}
	cout << " families registered\n";
}

int main()
{


	queue<Family> q;
	fstream file;
	file.open("families.txt", ios::binary | ios::out);

	if (!file)
	{
		cout << "ERROR: couldn't open file\n";
		return 0;
	}
	setFile(file);
	file.close();

	file.open("families.txt", ios::binary | ios::in | ios::out);
	int choice;
	int snum;
	int cnum;
	cout << "Choices are:\n0 to exit\n1 to add a family\n2 to delete a family\n3 to  count number of families signed up\n4 to update the activities of a family \n5 print the waiting list \n6 to print a family\n";
	cout << "enter 0-6:\n";
	cin >> choice;
	while (choice)
	{
		try {
			switch (choice)
			{
			case ADD://add to the file
				add(file);
				break;
			case DEL://delete from file
				cout << "enter number of family to delete:\n";
				cin >> snum;
				del(file, snum);
				break;
			case COUNT:
				handleCount(file);
				break;
			case UPDATE://update the list of classes of a family
				cout << "enter number of family to update:\n";
				cin >> snum;
				update(file, snum, q);
				break;
			case WAITING://update the list of classes for waiting fam 			
				waiting(q);
				break;

			case PRINT://print the details of a specific family
				cout << "enter number of family to print:\n";
				cin >> snum;
				print(file, snum);
				break;
			default:
				cout << "ERROR: invalid choice\n";

			}
		}// try
		catch (const char* msg) {
			cout << msg;
		}
		cout << "\nenter 0-6:\n";
		cin >> choice;

	}
	file.close();
	return 0;
}

/*Run sample:

Choices are:
0 to exit
1 to add a family
2 to delete a family
3 to  count number of families signed up
4 to update the activities of a family
5 print the waiting list
6 to print a family
enter 0-6:
1
enter the family's:  id, name, amount of people and a phone number:
5 aaron 5 0505551235

enter 0-6:
1
enter the family's:  id, name, amount of people and a phone number:
123 brian 7 0505551123
ERROR: Invalid family number
enter 0-6:
1
enter the family's:  id, name, amount of people and a phone number:
5 aaron 5 0505551235
ERROR: Family is already in the file
enter 0-6:
1
enter the family's:  id, name, amount of people and a phone number:
6 carly 8 0505551236

enter 0-6:
1
enter the family's:  id, name, amount of people and a phone number:
7 daniella 9 0505551237

enter 0-6:
2
enter number of family to delete:
6

enter 0-6:
4
enter number of family to update:
6
ERROR: Family is not in the file
enter 0-6:
4
enter number of family to update:
5
Do you want to register for swimming?
Y
Do you want to register for gymnastics?
Y
Do you want to register for dance?
Y
Do you want to register for art?
Y
Do you want to register for self defense?
N
Do you want to register for music?
N
Do you want to register for drama?
N
Do you want to register basketball?
N

enter 0-6:
4
enter number of family to update:
7
Do you want to register for swimming?
Y
Do you want to register for gymnastics?
N
Do you want to register for dance?
Y
Do you want to register for art?
N
Do you want to register for self defense?
Y
Do you want to register for music?
N
Do you want to register for drama?
Y
Do you want to register basketball?
N

enter 0-6:
3
enter activity number to count:
Choices are:
1 SWIMMING
2 GYMNASTICS
3 DANCE
4 ART
5 SELF DEFENSE
6 MUSIC
7 DRAMA
8 BASKETBALL
1
there are 2 families registered

enter 0-6:
6
enter number of family to print:
5
family name: aaron
number of persons: 5
phone number: 505551235
SWIMMING
GYMNATSTICS
DANCE
ART

enter 0-6:
6
enter number of family to print:
6
ERROR: Family is not in the file
enter 0-6:
6
enter number of family to print:
7
family name: daniella
number of persons: 9
phone number: 505551237
SWIMMING
DANCE
SELF DEFENSE
DRAMA

enter 0-6:
6
enter number of family to print:
8
ERROR: Family is not in the file
enter 0-6:
5

enter 0-6:
0*/