#include<iostream>
#include<stdlib.h>
#include<stdio.h>

#define SIZE 5

using namespace std;

class stack
{
	int data[SIZE];
	int top;
public:
	void push(int);
	int pop();
	void display();
	void menu();
	stack()
	{
		top=-1;
	}

};

void stack :: push(int value)
{
	if(top==SIZE-1)
	{
		cout<<"Stack Overflow"<<endl;
		return;
	}
	data[++top]=value;
}

int stack :: pop()
{
	if(top==-1)
	{
		return -9999;
	}
	int value=data[top--];
	return value;
}

void stack ::  display()
{
	if(top==-1)
	{
		cout<<"Stack is Empty"<<endl;
		return;
	}
	for(int i=0;i<=top;i++)
	{
		if(i==top)
			cout<<data[i]<<"<-- TOP"<<endl;
		else
			cout<<data[i]<<endl;
	}
}

void stack :: menu()
{
	cout<<"############## STACK MENU ###########"<<endl;
	cout<<"#####################################"<<endl;
	cout<<"1. Push an Element"<<endl;
	cout<<"2. Pop an Element"<<endl;
	cout<<"3. Display the Stack"<<endl;
	cout<<"4. Exit"<<endl;
}
int main()
{
	stack s1;
	s1.menu();
	int quit=0,choice,value;
	while(!quit)
	{
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"Enter Value to be pushed into stack: ";
				cin>>value;
				s1.push(value);
				break;

			case 2: value = s1.pop();
				if(value==-9999)
					cout<<"Stack Underflow"<<endl;
				else
					cout<<"Popped Item= "<<value<<endl;
				break;

			case 3: s1.display();
				break;

			case 4: quit++;
				break;

		}
	}
}

