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

node* KthElement(node* head, int k);
void insertNode(node* head, int val);
void printList(node* head);

int main (int argc, char* argv[])
{
	if(argc!=2)
	{
		cout << "Please pass in ""k"" argument!" << endl;
		return -1;
	}
	istringstream ss(argv[1]);
	int k;
	if(!(ss >> k))
	{
		cout << "Invalid Number " << argv[1] << endl;
		return -1;
	}
	node* head = new node();
	head->data = 12;

	insertNode(head,10);
	insertNode(head,9);
	insertNode(head,8);
	insertNode(head,10);
	insertNode(head,9);
	insertNode(head,111);

	printList(head);
	node* kthEl = KthElement(head,k); 
	if(kthEl!=NULL)
		cout << k << "th to last element is: " << kthEl->data << endl;
	else
		cout << "Invalid argument!" << endl;
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


node* KthElement(node* head, int k)
{
	node* prev = head;
	node* runner = head;

	for(int i = 0; i<k; i++)
	{
		if(runner== NULL)
			return NULL;
		runner = runner->next;
	}		
	while(runner!=NULL)
	{
		runner = runner->next;
		prev = prev->next;
	}
	return prev;
}
