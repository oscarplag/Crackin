#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include<vector>
#include<set>

using namespace std;

struct node
{
	node* next=NULL;
	int data;
};

node* AddNums(node* val1, node* val2);
void insertNode(node* head, int val);
void printList(node* head);

int main (int argc, char* argv[])
{
	node* val1 = new node();
	val1->data = 7;
	insertNode(val1,1);
	insertNode(val1,6);

	node* val2 = new node();
	val2->data = 5;
	insertNode(val2,9);
	insertNode(val2,2);
	insertNode(val2,7);
	
	cout << "Val 1: ";
	printList(val1);
	cout << "val 2: ";
	printList(val2);
	node* retVal = AddNums(val1,val2); 
	cout << "result: " ;
	printList(retVal);
	return 1;

}

void insertNode(node* head,int val)
{
	node* current = head;
	while(current->next!=NULL)
	{
		current = current->next;
	}
	current->next = new node();
	current->next->data = val;
}

void printList(node* head)
{
	node* current = head;
	while(current->next != NULL)
	{
		cout << current->data <<"->";
		current = current->next;
	}
	cout << current->data << endl;
}

node* AddNums(node* val1, node* val2)
{
	node* retVal = NULL;
	node* retHead;
	int carryOver = 0;
	while(val1 != NULL && val2 !=NULL)
	{
		int temp = val1->data + val2->data + carryOver;	
		if(retVal == NULL)
		{
			retVal = new node();
			retVal->data = temp%10;
			carryOver = temp/10;
			retHead = retVal;
		}
		else
		{
			retVal->next = new node();
			retVal->next->data = temp%10;
			carryOver = temp/10;
			retVal = retVal->next;	
		}
		val1 = val1->next;
		val2 = val2->next;
	}
	if(val1!=NULL)
	{
		while(val1!=NULL)
		{
			retVal->next = new node();
			int temp = val1->data+carryOver;
			retVal->next->data = temp%10;
			carryOver = temp/10;
			retVal = retVal->next;
			val1= val1->next;
		}
	}
	if(val2!=NULL)
	{
		while(val2!=NULL)
		{
			retVal->next = new node();
			int temp = val2->data+carryOver;
			retVal->next->data = temp%10;
			carryOver = temp/10;
			retVal = retVal->next;
			val2= val2->next;
		}
	}
	if(carryOver!=0)
	{
		retVal->next = new node();
		retVal->next->data = carryOver;
	}
	return retHead; 
}

