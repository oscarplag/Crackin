#include<iostream>
#include<string>
#include<sstream>
#include<stack>
#include "math.h"

using namespace std;

struct node
{
	int val;
	node* left;
	node* right;
};

int max (int a, int b);

bool isBalanced(node* root);

int getHeight(node* n);

int main (int argc, char* argv[])
{
}
int max (int a, int b)
{
	if(a>=b)
		return a;
	else
		return b;
}

bool isBalanced(node* root)
{
	if(getHeight(root)==1)
		return false;
	else
		return true;	
}

int getHeight(node* n)
{
	if(n == NULL)
	{
		return 0;
	}

	int leftHeight = getHeight(n->left);
	if(leftHeight == -1)
		return -1;	

	int rightHeight = getHeight(n->right);
	if(rightHeight == -1)
		return -1;

	int heightDiff = abs(leftHeight-rightHeight);

	if(heightDiff>1)
		return-1;
	else
		return max(leftHeight,rightHeight)+1;

}
