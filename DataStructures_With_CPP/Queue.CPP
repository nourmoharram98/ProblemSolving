#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;




class Node{

	public:
	int data;
	Node *prev;
	Node *next;
	Node()
	{
		prev=next=NULL;
		cout<<"default cons is called"<<endl;
	}
	Node(int d)
	{
		prev=next=NULL;
		data=d;
		cout<<"parametrized constructor is called"<<endl;
	}

};

class LinkedList{

	Node * start;
	Node * end;
	int size;
	public:
	LinkedList();
	Node * searchOnNode(int key);
	void appendNode(Node * ele);
	void insertNode(Node *ele);
	int deleteNode(int key);
	void freeList();
	int getSize();
	int isEmpty();
	Node * getFirst();
	Node *getLast();
	Node *peekFirst();
	Node *peekLast();
	int Display_Nodes(void);
};

/*
class Queue
{
    int *que, size, rear;
    public:
        Queue();
        Queue(int s);
        ~Queue();
        int isFull();
        int isEmpty();
        int input(int ele);
        int output(int &ele);
        int peek(int &ele);
};
*/

class Queue
{
    LinkedList Que;
    int  size, rear;
    public:
        Queue();
        Queue(int s);
        ~Queue();
        int isFull();
        int isEmpty();
        int input(Node* ele);
        int output(Node &ele);
        int peek(Node &ele);
		int getSize();
};

Queue::Queue():Que()
{
    rear=0;
    size=5;
}
Queue::Queue(int s):Que()
{
    rear=0;
    size=s;
}

Queue::~Queue()
{
    rear=0;
    size=0;
}
int Queue::isFull()
{
    return (rear==size);
}

int Queue::isEmpty()
{
    return (rear==0);
}

int Queue::input(Node* ele)
{
	cout<<"****the input func is called****"<<endl;
	if(isFull())
	{
		return 0;
	}
	Que.appendNode(ele);
	rear++;
	cout<<"the rear position now = "<<rear<<endl;
	return 1;
}

int Queue::output(Node &ele)
{
	cout<<"****the output func is called****"<<endl;
	if(isEmpty())
	{
		return 0;
	}
	ele = *Que.getFirst();
	rear--;
	cout<<"the rear position = "<<rear<<endl;
	return 1;
}

int Queue::peek(Node &ele)
{
	if(isEmpty())
	{
		return 0;
	}
	ele=*Que.peekFirst();
	return 1;
}
int Queue::getSize()
{
	if(isEmpty())
	{
		return 0;
	}
	cout<<"the size of queue = "<<rear<<endl;
	return rear;
}

LinkedList::LinkedList()
{
	start=end=NULL;
	size=0;
}

Node * LinkedList::searchOnNode(int key)
{
	Node *temp = start;
	if(start==NULL)
	{
		return NULL;
	}
	while(temp && temp->data!=key)
	{
		temp = temp -> next;
	}
	return temp;
}

void LinkedList::appendNode(Node *ele)
{
 //	cout<<"append is called"<<endl;
	if(start==NULL) //CASE 1: empty list
	{
		start=end=ele;
	}
	else             //CASE 2: general case
	{
		ele->prev=end;
		end->next=ele;
		end=ele;
	}
	size++;
	cout<<"number of nodes appended = "<<size<<endl;
}

void LinkedList::insertNode(Node *ele)
{
	Node * temp=start;
	while(temp&&(temp->data < ele->data))
	{
		temp = temp->next;
	}
	//case 1 : empty list or the new ele has largest data
	if(!temp)
	{
		appendNode(ele);
	}
	else
	{
		//case 2 : new ele has the smallest data
		if(temp==start)
		{
			start->prev=ele;
			ele->next=start;
			start=ele;
		}
		else //case 3 : insert node at specifc location
		{
			temp->prev->next=ele;  //1
			ele->prev=temp->prev;   //2
			temp->prev=ele;           //3
			ele->next=temp;           //4
			cout<<"node with data "<<ele->data<<" added after node data = "<<ele->prev->data<<endl;
		}
	}
	size++;
	cout<<"number of nodes appended = "<<size<<endl;

}

int LinkedList::deleteNode(int key)
{
	Node *temp;
	if(!start)
	{
		return 0;  //case 1 : empty list
	}
	temp=searchOnNode(key);
	if(!temp)
	{
		return 0; //case 2: not found
	}
	if(start==temp && end==temp) //case 3: only one node
	{
		start=end=NULL;
		free(temp);
	}
	else
	{
		if(start==temp) //case 4: first node
		{
			start = start->next;  //1
			start->prev=NULL;  //2
			free(temp);
		}
		else if(end==temp)   //case 5:last node
		{
			end=end->prev;      //1
			end->next=NULL;     //2
			free(temp);         //3
		}
		else      //case 6: normal case
		{
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			free(temp);
		}
	}
	size--;
	return 1;
}

void LinkedList::freeList()
{
	Node *temp = start; //make temp pointer hold address of first node in the list
	while(temp)
	{
		start = start->next; //move the start pointer to the next node
		free(temp);     //free the current node
		temp=start;      //make the temp pointer hold the address of the start pointer that point to next node to be freed
	}
	end=NULL; //make the end pointer point to null
	size=0;
}

int LinkedList::getSize()
{
	return size;
}

int LinkedList::isEmpty()
{
	return (start==NULL);
}
Node * LinkedList::getFirst()
{
	if(isEmpty())
	{
		return NULL;
	}
	Node *temp= start;
	start = start->next;
	if(start)
	{
		start->prev=NULL;
	}
	else
	{
		end=NULL;
	}
	temp->prev=temp->next=NULL;
	size--;
	return temp;
}

Node * LinkedList::getLast()
{
	if(isEmpty())
	{
		return NULL;
	}
	Node *temp=end;
	end=end->prev;
	if(end)
	{
		end->next=NULL;
	}
	else
	{
		start=NULL;
	}
	temp->prev=temp->next=NULL;
	size--;
	return temp;
}

Node * LinkedList::peekFirst()
{
	if(isEmpty())
	{
		return NULL;
	}
	Node *temp = new Node();
	temp->data = start->data;
	temp->prev=temp->next=NULL;
	return temp;
}

Node * LinkedList::peekLast()
{
	if(isEmpty())
	{
		return NULL;
	}
	Node * temp = new Node();
	temp->data = end->data;
	temp->prev=temp->next=NULL;
	return temp;
}


int LinkedList::Display_Nodes(void)
{
	int counter=1;
	if(start==NULL && end==NULL)
	{
        cout<<"list is empty"<<endl;
		return 0;
	}
	else
	{
		while(start)
		{
			cout<<"node number "<<counter<<" = "<<start->data<<endl;
			start = start->next;
			counter++;
		}
	}
	return 1;
}

int main(void)
{
	//clear screen
	//clrscr();
	//initialize objects from Queue and node class
	Queue Q1;
	Node Ntemp;
	//Initialize variables to receive return values
	int queue_status=0;
	int size_queue=0;
	//Create 5 nodes
	Node *NPTR1 = (Node *)malloc(sizeof(Node));
	Node *NPTR2 = (Node *)malloc(sizeof(Node));
	Node *NPTR3 = (Node *)malloc(sizeof(Node));
	Node *NPTR4 = (Node *)malloc(sizeof(Node));
	Node *NPTR5 = (Node *)malloc(sizeof(Node));
	Node *NPTR6 = (Node *)malloc(sizeof(Node));

	//Initialize the 5 nodes with data
	NPTR1->data=10;
	NPTR2->data=20;
	NPTR3->data=30;
	NPTR4->data=40;
	NPTR5->data=25;
	NPTR6->data=50;

   //add values to queue	
   Q1.input(NPTR1);
   Q1.input(NPTR2);
   Q1.input(NPTR3);
   Q1.input(NPTR4);
   Q1.input(NPTR5);
   //add node after size is full
   queue_status=Q1.input(NPTR6);
	if(queue_status==0)
	{
		cout<<"the stack is full"<<endl;
	}
	//remove first node in queue
	Q1.output(Ntemp);
	cout<<"the data of out element = "<<Ntemp.data<<endl;
	//print the first element in queue
	Q1.peek(Ntemp);
	cout<<"the data of the first element in queue = "<<Ntemp.data<<endl;
	//print the size of nodes in queue
	size_queue=Q1.getSize();
	if(size_queue==0)
	{
		cout<<"number of nodes in queue = "<<size_queue<<endl;
	}
	else
	{
		cout<<"number of nodes in queue = "<<size_queue<<endl;
	}
	getch();
   return 0;
}