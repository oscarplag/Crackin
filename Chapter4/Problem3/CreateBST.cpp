#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct node
{
	int val;
	node* left;
	node* right;
	node(int Val)
	{
		val = Val;
		left = NULL;
		right = NULL;
	}
	node(int Val, node* Left, node* Right)
	{
		val = Val;
		left = Left;
		right = Right;
	}
};

node* CreateBST(vector<int> array);
node* CreateBST(const vector<int>& array, int start, int end);
void PrintLevels(node* tree);

int main(int argc, char* argv[])
{
	vector<int> array;
	array.push_back(18);
	array.push_back(15);
	array.push_back(23);
	array.push_back(1);
	array.push_back(49);
	array.push_back(21);
	array.push_back(78);
	array.push_back(3);
	array.push_back(9);

	node* tree = CreateBST(array);
	PrintLevels(tree);
}

node* CreateBST(vector<int> array)
{
	sort(array.begin(),array.end());
	
	cout << "Sorted Array: ";
	for(vector<int>::iterator it = array.begin();it!=array.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	node* root = CreateBST(array,0,array.size()-1);
	return root;
}

node* CreateBST(const vector<int> &array, int start, int end)
{
	if(start>end)
		return NULL;
	int mid = (end-start)/2+start;
	node* n = new node(array[mid]);
	n->left = CreateBST(array,start,mid-1);
	n->right = CreateBST(array,mid+1,end);
	return n;
}

void PrintLevels(node* tree)
{
	queue<node*> myQueue;
	myQueue.push(tree);

	while(!myQueue.empty())
	{
		queue<node*> tempQueue;
		
		while(!myQueue.empty())
		{
			node* tempNode = myQueue.front();
			myQueue.pop();
			
			cout << tempNode->val << " ";
		
			if(tempNode->left)
				tempQueue.push(tempNode->left);
			if(tempNode->right)
				tempQueue.push(tempNode->right);
		}
		cout << endl;
		while(!tempQueue.empty())
		{
			myQueue.push(tempQueue.front());
			tempQueue.pop();
		}
	}
}
