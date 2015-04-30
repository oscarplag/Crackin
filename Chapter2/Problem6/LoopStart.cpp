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

node* findLoopStart(node* root);


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
	val5->data = 4;
	val4->next = val5;

	node* val6 = new node();
	val6->data = 5;
	val5->next = val6;

	node* val7 = new node();
	val7->data = 6;
	val6->next = val7;
	val7->next = val4; 

	node* loopStart = findLoopStart(val1);
 
	if(loopStart == NULL)
	{
		cout << "List is not circular!" << endl;
	}	
	else
	{
		cout << "Loop starts at: " << loopStart->data << endl;
	}
	
	return 1;

}


node* findLoopStart(node* root)
{
	node* slowRunner = root;
	node* fastRunner = root;

	while(slowRunner!=NULL && fastRunner!=NULL)
	{
		slowRunner = slowRunner->next;
		fastRunner = fastRunner->next;
		if(fastRunner->next!=NULL)
			fastRunner = fastRunner->next;
		if(slowRunner == fastRunner)
			break;
	}

	if(slowRunner == NULL || fastRunner == NULL)
	{
		return NULL;
	}	
	
	slowRunner = root;
	
	while(slowRunner != fastRunner)
	{
		slowRunner = slowRunner->next;
		fastRunner = fastRunner->next;
	}

	return slowRunner;
}
