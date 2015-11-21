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
	node(int Val, node* Left, node* Right)
	{
		val = Val;
		left = Left;
		right = Right;	
	}
	node(int Val)
	{
		val = Val;
		left = NULL;
		right = NULL;
	}
};

bool IsBST(node* n);
bool IsBST(node* n, int& prevVal);
bool IsBSTMinMax(node* n);
bool IsBSTMinMax(node* n, int min, int max);
void PrintTree(node* n);

int main(int argc, char* argv[])
{
	node* btree1 = new node(8);
	btree1->left = new node(4);
	btree1->right = new node(12);
	btree1->left->left = new node(2);
	btree1->left->right = new node(6);
	btree1->left->left->left = new node(1);
	btree1->left->left->right = new node(3);
	btree1->left->right->left = new node(5); 
	btree1->left->right->right= new node(7);
	btree1->right->left = new node(10);
	btree1->right->right = new node(14);
	btree1->right->left->left = new node(9);
	btree1->right->left->right = new node(11);
	btree1->right->right->left = new node(13);
	btree1->right->right->right = new node(15);
	
	node* btree2 = new node(8);
	btree2->left = new node(4);
	btree2->right = new node(12);
	btree2->left->left = new node(2);
	btree2->left->right = new node(6);
	btree2->left->left->left = new node(1);
	btree2->left->left->right = new node(2);
	btree2->left->right->left = new node(5); 
	btree2->left->right->right= new node(7);
	btree2->right->left = new node(10);
	btree2->right->right = new node(14);
	btree2->right->left->left = new node(9);
	btree2->right->left->right = new node(11);
	btree2->right->right->left = new node(13);
	btree2->right->right->right = new node(15);
	
	cout << "Tree1: " << endl;
	PrintTree(btree1);
	cout << endl << "Tree2: " << endl;
	PrintTree(btree2);
	
	//bool isBST1 = IsBSTMinMax(btree1);
	//bool isBST2 = IsBSTMinMax(btree2);	
	bool isBST1 = IsBST(btree1);
	bool isBST2 = IsBST(btree2);	

	if(isBST1)
		cout << "Tree 1 is a BST tree!" << endl;
	else
		cout << "Tree 1 is not a BST tree!" << endl;
	if(isBST2)
		cout << "Tree 2 is a BST tree!" << endl;
	else
		cout << "Tree 2 is not a BST tree!" << endl;
}
bool IsBST(node* n)
{
	if(!n)
		return true;
	if(!IsBST(n->left,n->val)||!IsBST(n->right,n->val))
		return false;
	return true;	
}
bool IsBST(node* n, int& prevVal)
{
	if(!n)
		return true;
	if(n->left && n->val < n->left->val)
		return false;
	if(n->right && n->val >= n->right->val)
		return false;
	if(!IsBST(n->left,n->val) || !IsBST(n->right,n->val))
		return false;
	return true;
}
bool IsBSTMinMax(node* n)
{
	return IsBSTMinMax(n,INT_MIN,INT_MAX);
}
bool IsBSTMinMax(node* n, int min, int max)
{
	if(!n)
		return true;
	if(n->val<= min || n->val>max)
		return false;	

	if(!IsBSTMinMax(n->left,min,n->val) || !IsBSTMinMax(n->right,n->val,max))
		return false;
	return true;
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
