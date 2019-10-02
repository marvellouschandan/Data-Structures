#include<stdio.h>
#include<string.h>
#include<iostream>
#define SIZE 10

using namespace std;

class hashTable   //creating a class
{
	char keys[SIZE][20];
	int values[SIZE];
	int hashFunction(char key[]);
public:
	hashTable()
	{
		for (int i=0; i<SIZE;i++)
		{
			/* Making all string to NULL */
			strcpy(keys[i],"\0");
		}
	}
	void put();
	void get();
};

void hashTable :: get()
{
	char key[20];
	cout<<"Enter the key: ";
	cin>>key;

	int index = hashFunction(key);  //initialising

	while (strcmp(keys[index],"\0") != 0)
	{
		/* Loop runs till it gets an NULL string */
		if (strcmp(keys[index], key) == 0)
		{
			/* If an already present key is again given */
			cout<<"Item found!"<<endl;
			cout<<"Value of entered key is: "<<values[index]<<endl;
			return;
		}

		index = (index+1) % SIZE;
	}

	cout<<"Key not found!"<<endl;
}

void hashTable :: put()
{
	char key[20];
	cout<<"Enter the key: ";
	cin>>key;

	int index = hashFunction(key);
	int value;
	while (strcmp(keys[index],"\0") != 0)
	{
		/* Loop runs till it gets an NULL string */
		if (strcmp(keys[index], key) == 0)
		{
			/* If an already present key is again given */
			cout<<"Enter new value of key: ";
			cin>>value;
			values[index] = value;
			return;
		}

		index = (index+1) % SIZE;
	 }

	cout<<"Enter the value: ";
	cin>>value;
	strcpy(keys[index],key);
	values[index] = value;
}

int hashTable :: hashFunction(char key[])
{
	/* Sums all the ascii values of each character of a key and returns an array index
	e.g- "Hello" has ASCII value of 500, so index is 0 */

	int sum=0;

	for(int i=0; i < strlen(key); i++)
	{
		sum = sum + key[i];
	}

	return sum%10;
}

void menu()
{
	cout<<"######## HASH TABLE #########"<<endl;
	cout<<"#############################"<<endl;
	cout<<"1. Insert"<<endl;
	cout<<"2. Search"<<endl;
	cout<<"3. Quit"<<endl;
}

int main()
{
	system("clear");
	char choice[2];
	int quit = 0;

	hashTable obj;
	menu();
	while (!quit)
	{
		cout<<"Enter your choice: ";
		cin>>choice;

		switch(atoi(choice))
		{
			case 1: obj.put();
					break;

			case 2: obj.get();
					break;

			case 3: quit++;
					break;

			default: cout<<"Wrong Input!"<<endl;
		}
	}
	return 0;
}
