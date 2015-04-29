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
node* AddNums(node* val1, node* val2, int& carryOver);
int GetLength(node* n);
node* padZeros(node* n, int numZeros);
void insertNode(node* head, int val);
void printList(node* head);

int main (int argc, char* argv[])
{
	node* val1 = new node();
	val1->data = 6;
	insertNode(val1,1);
	insertNode(val1,7);

	node* val2 = new node();
	val2->data = 5;
	insertNode(val2,7);
	insertNode(val2,2);
	insertNode(val2,9);
	
	cout << "Val 1: ";
	printList(val1);
	cout << "val 2: ";
	printList(val2);
	node* retVal = AddNums(val1,val2); 
	cout << "result: " ;
	printList(retVal);
	return 1;

}
node* AddNums(node* val1, node* val2, int& carryOver)
{
	node* newVal = new node();
	newVal->data = 0;
	newVal->next = NULL;

	if(val1->next != NULL)
	{
		if(val2->next != NULL)
		{
			newVal->next = AddNums(val1->next, val2->next, carryOver);
		}
		else
			newVal->next = AddNums(val1->next, val2, carryOver);
	}
	else if(val2->next != NULL)
	{
		newVal->next = AddNums(val1,val2->next,carryOver);
	}
	int temp = val1->data + val2->data + carryOver;
	newVal->data = temp % 10;
	carryOver = temp/10;
	
	return newVal;	
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
	int len1 = GetLength(val1);
	int len2 = GetLength(val2);
	if(len1>len2)
		val2 = padZeros(val2, len1-len2);
	else if(len2>len1)
		val1 = padZeros(val1, len2-len1);
	int carryOver = 0;
	node* val3 = AddNums(val1,val2,carryOver);
	if(carryOver == 1)
	{
		node* temp = new node();
		temp->data = 1;
		temp->next = val3;
		val3 = temp;
	}
	return val3;
}

int GetLength(node* n)
{
	node* temp = n;
	int counter = 0;
	while(temp != NULL)
	{
		temp = temp->next;
		counter++;
	}
	return counter;
}

node* padZeros(node* n, int numZeros)
{
	node* newRoot = new node();
	newRoot->data = 0;
	node* temp = newRoot;

	for(int i = 1; i<numZeros; i++)
	{
		temp->next = new node();
		temp->next->data = 0;
		temp = temp->next;
	}	
	
	temp->next = n;
}
