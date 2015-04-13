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

void RemoveNode(node* n);
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
	node* n = head;
	for(int i = 0; i< k-1; i++)
	{
		if(n!=NULL)
			n=n->next;
	}

	RemoveNode(n);
	
	printList(head);

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

void RemoveNode(node* n)
{
	if(n==NULL)
		return;
	
	if(n->next == NULL)
	{
		delete n;
		n=NULL;
		return;
	}
	node* temp = n->next;
	n->data = n->next->data;
	n->next = n->next->next;
	delete temp;
	return;
}
