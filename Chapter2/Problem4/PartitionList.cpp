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

node* PartitionList(node* head, int val);
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
	head = PartitionList(head,k);	
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

node* PartitionList(node* head, int val)
{
	node* newNode= NULL;
	node* newHead = newNode;
	node* newNode2= NULL; 
	node* newHead2 = newNode2;
	while(head!=NULL)
	{
		node* temp = head;
		if(head->data<val)
		{
			if(newNode== NULL)
			{
				newNode = new node();
				newNode->data = head->data;
				newHead = newNode;
			}
			else
			{
				newNode->next = new node();
				newNode->next->data = head->data;
				newNode = newNode->next;
			}
			head = head->next;
			delete temp;
		}
		else
		{
			if(newNode2== NULL)
			{
				newNode2 = new node();
				newNode2->data = head->data;
				newHead2 = newNode2;
			}
			else
			{
				newNode2->next = new node();
				newNode2->next->data = head->data;
				newNode2 = newNode2->next;
			}
			head = head->next;
			delete temp;

		}


	}
	newNode->next = newHead2;
	return newHead;
}

