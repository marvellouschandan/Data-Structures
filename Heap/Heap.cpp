#include<stdio.h>
#include<iostream>
#include<queue>
#define heapSize 10
using namespace std;


class Heap   //creating a Heap Class
{
	int data[heapSize];
	int current;
    public:
	Heap()
	{
		for (int i=0; i < heapSize; i++)
		{
			/* Intializes array content to zero */
			data[i] = 0;
		}
		current = -1;
	}
	void insert(int);   //Declaring the functions
	bool isFull();
	void fixHeap(int);
	void heapSort();
	void max_heap(int, int);
	int deleteRoot();
	void displayArray()
	{
		for(int i=0; i <= current; i++)
		{
			cout<<data[i]<<"\t";
		}
		cout<<endl;
	}
};

void Heap :: insert(int value)
{
	/* Insert element into heap */
	if (isFull())
	{
		cout<<"Heap is Full!"<<endl;
		return;
	}

	current += 1;
	/* TIP- Element fills in sequence in heap i.e 0, 1, 2, 3, 4... */
	data[current] = value;
	fixHeap(current);
}

bool Heap :: isFull()
{
	return (current == heapSize ? true : false);
}

void Heap :: fixHeap(int index)
{
	int parentIndex = (index - 1)/2;
	int temp;

	while (parentIndex >= 0 && data[parentIndex] < data[index])
	{
		/* Condition for max heap */
		temp = data[parentIndex];
		data[parentIndex] = data[index];
		data[index] = temp;

		/* Now check the parent of parent */
		index = parentIndex;
		parentIndex = (index - 1)/2;
	}
}

void Heap :: heapSort()
{
	int temp;

	cout<<"Sorted Heap is: ";
	for (int i =0; i <= current; i++)
	{
		temp = data[current - i];
		data[current - i] = data[0];
		data[0] = temp;

		cout<<data[current-i]<<"\t";

		max_heap(0, current -i - 1);
	}
	cout<<endl;
}

void Heap :: max_heap(int rootIndex, int UB)
{
	int leftChild = 2*rootIndex+1;
	int rightChild = 2*rootIndex+2;
	int childToSwap;
	int temp;

	while (rootIndex <= UB)
	{
		if (leftChild < UB)
		{
			/* leftChild greater than UB represents invalid array element */
			if (rightChild > UB)
			{
				/* meaning rightChild doesn't exist */
				childToSwap = leftChild;
			}
			else
			{
				/*  */
				if (data[rightChild] > data[leftChild])
					childToSwap = rightChild;
				else
					childToSwap = leftChild;
			}

			if (data[rootIndex] < data[childToSwap])
			{
				temp = data[rootIndex];
				data[rootIndex] = data[childToSwap];
				data[childToSwap] = temp;
			}
			else
			{
				/* After this the children hold good the max_heap property */
				break;
			}

			rootIndex = childToSwap;
			leftChild = 2*rootIndex+1;
			rightChild = 2*rootIndex+2;
		}
		else
		{
			break;
		}
	}
}

int Heap :: deleteRoot()
{
	int temp;
	temp = data[0];
	data[0] = data[current];
	data[current] = temp;
	--current;
	max_heap(0,current);
	return data[current + 1];
}

void menu()
{
	cout<<"##### Heap ######"<<endl;
	cout<<"#################"<<endl;
	cout<<"1. Insert"<<endl;
	cout<<"2. Delete"<<endl;
	cout<<"3. Display"<<endl;
	cout<<"4. Heap Sort"<<endl;
	cout<<"5. Quit"<<endl;
}
int main()
{
	system("clear");
	menu();
	char choice[2];
	int quit = 0, value;
	Heap obj;  //creating an object
	while(!quit)
	{
		cout<<"Please Enter your choice: ";
		cin>>choice;

		switch(atoi(choice))
		{
			case 1: cout<<"Enter the value to be inserted: ";
					cin>>value;
					obj.insert(value);
					break;

			case 2: cout<<"Deleted Item is :"<<obj.deleteRoot()<<endl;
					break;

			case 3: obj.displayArray();
					break;

			case 4: obj.heapSort();
					break;

			case 5: quit++;
					break;

			default: cout<<"Please enter correct input!"<<endl;
		}
	}

	return 0;
}
