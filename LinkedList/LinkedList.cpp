
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

using namespace std;

class node  //creating a node class
{
public:
	int data;
	node *next;
};

class linkedList
{
    	node *head;
    	node *tail;
    	int nodeCount;
public:
    	linkedList()
    	{
        	head = NULL;
        	tail = NULL;
	       	nodeCount = 0;
    	}
		 	void insertAtHead(int);   //Declaring the functions
			void insertAtTail(int);
			void displayData();
			void displayDetail();
			int deleteHead();
			int deleteTail();
			node* find(int, node**);
			int deleteTarget(int);
			void printReverse();
			void reverse(node*);

      ~linkedList()
      {
          node* prev=NULL;
          node* temp=head;
          while(temp!=NULL)
              {
                  //cout<<"Memory is being freed"<<endl;
                  prev=temp;
                  temp=prev->next;
                  free(prev);
              }
      }
};

void linkedList :: insertAtHead(int value)
{
    	node *temp;
    	temp=(node*)malloc(sizeof(node));
    	if(temp==NULL)
    	{
		cout<<"Unable to allocate memory for Node"<<endl;
		return;
    	}
	temp->data=value;
	temp->next=NULL;
	if(nodeCount==0)
	{
		head=temp;
		tail=temp;
	}
	else
	{
		temp->next=head;
		head=temp;
	}
	nodeCount++;
}

void linkedList :: insertAtTail(int value)
{
	node *temp;
    	temp=(node*)malloc(sizeof(node));
    	if(temp==NULL)
    	{
		   cout<<"Unable to allocate memory for Node"<<endl;
		   return;
    	}
	temp->data=value;
	temp->next=NULL;
	if(nodeCount==0)
	{
		head=temp;
		tail=temp;
	}
	else
	{
	tail->next=temp;
	tail=temp;
	}
	nodeCount++;
}

void menu()
{
	cout<<"######### Linked List Menu ######"<<endl;
	cout<<"#################################"<<endl;
	cout<<"1. Load from file"<<endl;
	cout<<"2. Create linked list from Random numbers"<<endl;
	cout<<"3. Insert at Head"<<endl;
	cout<<"4. Insert at Tail"<<endl;
	cout<<"5. Print Linked List data"<<endl;
	cout<<"6. Print Detailed Linked List"<<endl;
	cout<<"7. Find a target"<<endl;
	cout<<"8. Delete the head node"<<endl;
	cout<<"9. Delete the tail node"<<endl;
	cout<<"10.Delete a Target Node"<<endl;
	cout<<"11. Print reversed List"<<endl;
	cout<<"15. Quit"<<endl;
}

void linkedList :: displayData()
{
	if(nodeCount==0)
	{
		cout<<"Linked list is Empty"<<endl;
		return;
	}
	node *current;
	current=head;
	cout<<endl;
	while(current!=NULL)
	{
		cout<<current->data<<endl;
		current=current->next;
	}
	cout<<endl;
}

void linkedList :: displayDetail()
{
	if(nodeCount==0)
	{
		cout<<"Linked list is Empty"<<endl;
		return;
	}

	node *current;
	current=head;
	cout<<"Head= "<<head<<endl;
	while(current!=NULL)
	{
		cout<<"( "<<current<<" ) "<<"[ "<<current->data<<" | "<<current->next<<" ]"<<endl;
		current=current->next;
	}
	cout<<"Tail= "<<tail<<endl;
}

node* linkedList :: find(int target,node** ptr)
{
	*ptr=NULL; // *ptr is the pointer having the address of the previous node to our target node
	node* current=head;
	while(current!=NULL)
	{
		if(current->data==target)
		{
			break;
		}
		*ptr=current;
		current=current->next;
	}
	return current;
}

int linkedList :: deleteHead()
{
	if(nodeCount==0)
	{
		return -9999;
	}
	int target = head->data;
	node *first;                                                   //first is the node to be freed
	if(nodeCount==1)
	{
		head=NULL;
		tail=NULL;
	}
	else
	{
		first=head;
		head=head->next;
		free(first);
	}
	nodeCount--;
	return target;
}

int linkedList :: deleteTail()
{
	if(nodeCount==0)
	{
		return -9999;
	}
	int target = tail->data;
	if(nodeCount==1)
	{
		head=NULL;
		tail=NULL;
	}
	else
	{
		node *last,*prevToTail;
		last=tail;
		prevToTail=head;
		while(prevToTail->next != tail)
		{
			prevToTail=prevToTail->next;
		}
		tail=prevToTail;
		free(last);
	}
	nodeCount--;
	return target;
}

int linkedList :: deleteTarget(int target)
{
	node *current,*prevNode;
	prevNode=NULL;
	current = find(target,&prevNode);
	if(current==NULL)
		return -9999;
	else if (current == head)
		return deleteHead();
	else if (current == tail)
		return deleteTail();
	else
	{
		prevNode->next = current->next;
		free(current);
		nodeCount--;
	}
	return target;
}

void linkedList :: printReverse()
{
    node* temp;
    temp=head;
    cout<<endl;
    reverse(temp);
}

void linkedList :: reverse(node* temp)
    {
        if(temp==NULL)
            return;
        reverse(temp->next);
        cout<<temp->data<<endl;
    }


int main()
{
	linkedList list;
	int quit=0,choice,data,value;
	menu();
	while(!quit)
	{
		cout<<"Enter your choice"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"Code not completed"<<endl;
				break;

			case 2: cout<<"Type the no. of nodes to insert"<<endl;
                    cin>>value;
                    srand(time(NULL));
                    for(int i=1;i<=value;i++)
                    {
                        data=rand()%1000;
                        list.insertAtTail(data);
                    }
                    break;

			case 3: cout<<"Enter Value to be inserted at head\n";
				cin>>data;
				list.insertAtHead(data);
				break;

			case 4: cout<<"Enter Value to be inserted at tail\n";
				cin>>data;
				list.insertAtTail(data);
				break;

			case 5: list.displayData();
				break;

			case 6: list.displayDetail();
				break;

			case 7: {
					node *nodePtr,*receivedNode;
					cout<<"Enter Target data to find"<<endl;
					cin>>data;
					receivedNode=list.find(data,&nodePtr);
					if(receivedNode==NULL)
						cout<<"List is Empty or target not found"<<endl;
					else
						cout<<"Target data is at location"<<receivedNode<<endl;
					break;
				}

			case 8: data = list.deleteHead();
					if(data==-9999)
						cout<<"List is Empty"<<endl;
					else
					{
						cout<<"Deleted item is "<<data<<endl;
					}
					break;
			case 9: data = list.deleteTail();
					if(data==-9999)
						cout<<"List is Empty"<<endl;
					else
					{
						cout<<"Deleted item is "<<data<<endl;
					}
					break;

			case 10: {
					cout<<"Enter Target data to be deleted"<<endl;
					cin>>data;
					list.deleteTarget(data);
					if(data==-9999)
						cout<<"List is Empty"<<endl;
					else
					{
						cout<<"Deleted item is "<<data<<endl;
					}
					break;
				 }
            case 11: list.printReverse();
                     break;

			case 15: quit++;
				break;

		}
	}
}
