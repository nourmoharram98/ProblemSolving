#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
//using namespace std;




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


class Stack{

    LinkedList Stk;
    int existSize;
	int maxSize;
	public:
		Stack();
		~Stack();
		int isFull();
		int isEmpty();
		int push(Node *ele);
		int pop(Node &ele);
		Node * peek();
		int getSize();

};
//implement constructor of stack and redirect to constructor of linkedlist
Stack::Stack():Stk()
{
	existSize=0;
	maxSize=5;
}

Stack::~Stack()
{
	Stk.freeList();
}

int Stack::isFull()
{
    return maxSize==existSize;
}

int Stack::isEmpty()
{
    return Stk.isEmpty();
}

Node * Stack::peek()
{
    return Stk.peekLast();
}

int Stack::push(Node *ele)
{
	cout<<"****the push function is called****"<<endl;
	if(isFull())
	{
		return 0;
	}
	Stk.appendNode(ele);
	existSize++;
	cout<<"the size of stack now = "<<existSize<<endl;
	return 1;
}

int Stack::pop(Node &ele)
{
	cout<<"****the Pop function is called****"<<endl;
	if(isEmpty())
	{
		return 0;
	}
	ele = *Stk.getLast();
	cout<<"the return of getlast "<<ele.data<<endl;
	existSize--;
	return 1;
}

int Stack::getSize()
{
	cout<<"the size of the stack = "<<existSize<<endl;
	return existSize;
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
	clrscr();
	//initialize objects from class stack and class node
	Stack S1;
	Node Ntemp;
	Node *Nptr;
	//initialize variables to hold return values
	int stack_status=0;
	int size_stack=0;
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

	//push the nodes to stack
	stack_status=S1.push(NPTR1);
	stack_status=S1.push(NPTR2);
	stack_status=S1.push(NPTR3);
	stack_status=S1.push(NPTR4);
	stack_status=S1.push(NPTR5);
	stack_status=S1.push(NPTR6);
	//check for the stack status after excess push
	if(stack_status==0)
	{
		cout<<"the stack is full"<<endl;
	}
	//pop last element from stack
	S1.pop(Ntemp);
	cout<<"data of last poped node = "<<Ntemp.data<<endl;
	//check the size of stack after pop
	size_stack=S1.getSize();
	cout<<"the size of stack = "<<size_stack<<endl;
	//get the peek value
	Nptr=S1.peek();
	cout<<"the data of peek element = "<<Nptr->data<<endl;
	getch();
   return 0;
}