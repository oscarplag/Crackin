#include<iostream>
#include<string>
#include<sstream>
#include<stack>
using namespace std;

struct node
{
	node* next=NULL;
	int data;
};

bool isPalindrome(node* list);

int main (int argc, char* argv[])
{
	node* val1 = new node();
	val1->data = 0;
	
	node* val2 = new node();
	val2->data = 1;
	val1->next = val2;

	node* val3 = new node();
	val3->data =2;
	val2->next = val3;

	node* val4 = new node();
	val4->data = 3;
	val3->next = val4;

	node* val5 = new node();
	val5->data = 2;
	val4->next = val5;
	
	node* val6 = new node();
	val6->data = 1;
	val5->next = val6;

	node* val7 = new node();
	val7->data = 0;
	val6->next = val7;
	val7->next = NULL; 

	bool isPali = isPalindrome(val1);
 
	if(isPali)
	{
		cout << "The list is a Palindrome!" << endl;
	}	
	else
	{
		cout << "The list is not a Palindrome! " << endl;
	}
	
	return 1;

}


bool isPalindrome(node* list)
{
	stack<int> myStack;
	
	node* slow = list;
	node* fast = list;

	while(fast!=NULL)
	{
		slow = slow->next;
		fast = fast->next;
		if(fast!=NULL)
		{
			fast = fast->next;
			myStack.push(slow->data);
		}
	}
	myStack.pop();
	while(!myStack.empty())
	{
		if(slow->data != myStack.top())
			return false;
		myStack.pop();
		slow = slow->next;
		if(slow == NULL)
			return false;
	}

	return true;
}
