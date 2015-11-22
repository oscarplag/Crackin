#include <stddef.h>
#include <limits.h>
#include <queue>
#include <iostream>

using namespace std;

struct node
{
	int val;
	node* left;
	node* right;
	node* parent;
	node(int Val, node* Left, node* Right, node* Parent)
	{
		val = Val;
		left = Left;
		right = Right;	
		parent = Parent;
	}
	node(int Val, node* Parent)
	{
		val = Val;
		parent = Parent;
		left = NULL;
		right = NULL;
	}
	node(int Val)
	{
		val = Val;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
};

void PrintTree(node* n);
node* GetNextNode(node* n);
node* GetLeftMostNode(node* n);

int main(int argc, char* argv[])
{
	node* btree1 = new node(8);
	btree1->left = new node(4,btree1);
	btree1->right = new node(12,btree1);
	btree1->left->left = new node(2,btree1->left);
	btree1->left->right = new node(6,btree1->left);
	btree1->left->left->left = new node(1,btree1->left->left);
	btree1->left->left->right = new node(3,btree1->left->left);
	btree1->left->right->left = new node(5,btree1->left->right); 
	btree1->left->right->right= new node(7,btree1->left->right);
	btree1->right->left = new node(10,btree1->right);
	btree1->right->right = new node(14,btree1->right);
	btree1->right->left->left = new node(9,btree1->right->left);
	btree1->right->left->right = new node(11,btree1->right->left);
	btree1->right->right->left = new node(13,btree1->right->right);
	btree1->right->right->right = new node(15,btree1->right->right);

	cout << "Tree1: " << endl;
	PrintTree(btree1);
	
	node* tn1 = btree1->right->right->left;
	node* tn2 = btree1->right->right;
	node* tn3 = btree1->right->right->right;
	
	node* n1 = GetNextNode(tn1);
	node* n2 = GetNextNode(tn2);
	node* n3 = GetNextNode(tn3);

	if(n1)
		cout << "Next node to " << tn1->val << " is: " << n1->val << endl; 
	else
		cout << "Node " << tn1->val << " does not have a next node!" << endl;
	if(n2)
		cout << "Next node to " << tn2->val << " is: " << n2->val << endl; 
	else
		cout << "Node " << tn2->val << " does not have a next node!" << endl;
	if(n3)
		cout << "Next node to " << tn3->val << " is: " << n3->val << endl; 
	else
		cout << "Node " << tn3->val << " does not have a next node!" << endl;
}
node* GetNextNode(node* n)
{
	if(n==NULL)	
		return NULL;
	else if(n->right!=NULL)
		return GetLeftMostNode(n->right);
	else
	{
		node* temp = n;
		node* parent = n->parent;	
		while(parent!=NULL && parent->left!=temp)
		{
			temp = parent;
			parent = temp->parent;	
		}
		return parent;
	}
}
node* GetLeftMostNode(node* n)
{
	if(n==NULL)
		return NULL;
	while(n->left != NULL)
		n = n->left;
	return n;
}

void PrintTree(node* n)
{
	queue<node*> myQueue;
	myQueue.push(n);
	
	while(!myQueue.empty())
	{
		queue<node*> tempQueue;
		while(!myQueue.empty())
		{
			node* tempNode = myQueue.front();
			myQueue.pop();
			if(tempNode->left)
				tempQueue.push(tempNode->left);
			if(tempNode->right)
				tempQueue.push(tempNode->right);	
			cout << tempNode->val << " ";
		}
		cout << endl;
		while(!tempQueue.empty())
		{
			myQueue.push(tempQueue.front());
			tempQueue.pop();
		}
	}
}
