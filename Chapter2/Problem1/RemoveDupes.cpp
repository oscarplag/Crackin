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

void RemoveDupesSet(node* head);
void RemoveDupesNoSet(node* head);
void insertNode(node* head, int val);
void printList(node* head);

int main (int argc, char* argv[])
{
	node* head = new node();
	head->data = 12;

	insertNode(head,10);
	insertNode(head,9);
	insertNode(head,8);
	insertNode(head,10);
	insertNode(head,9);
	insertNode(head,111);

	printList(head);
#ifdef NOSET
	RemoveDupesNoSet(head);
#else
	RemoveDupesSet(head);
#endif	
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

void RemoveDupesSet(node* head)
{
	set<int> intSet;
	
	if(head==NULL)
		return ;

	node* current = head;
	intSet.insert(current->data);
	node* prev = current;
	current = current->next;

	while(current!=NULL)
	{
		if(intSet.count(current->data)==0)
		{
			intSet.insert(current->data);
			prev = current;
			current = current->next;
		}	
		else
		{
			node* temp = current;
			prev->next = current->next;
			current = current->next;
			delete temp;
		}
	}	
}	

void RemoveDupesNoSet(node* head)
{
	node* runner = head->next;
	node* current = head;
	node* prev = current;
	
	while(current!=NULL)
	{
		while(runner!=NULL)
		{
			if(runner->data == current->data)
			{
				node* temp = runner;
				prev->next = runner->next;
				runner = runner->next;
				delete temp;
			}	
			else
			{
				if(runner!=NULL)
					runner = runner->next;
				prev = prev->next;
			}
		}
		current = current->next;
		prev = current;
		if(current!=NULL)
			runner = current->next;
	}
}
