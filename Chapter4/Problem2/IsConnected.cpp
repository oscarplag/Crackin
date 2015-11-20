#include<iostream>
#include<string>
#include<sstream>
#include<stack>
#include "math.h"
#include<queue>

using namespace std;

enum state
{
	unvisited,
	visiting,
	visited
};

struct node
{
	int val;
	state st;
};

bool IsConnected(graph* g, node* start, node* end); 

int getHeight(node* n);

int main (int argc, char* argv[])
{

}

bool IsConnected(graph* g, node* start, node* end)
{
	if(start == end)
		return true;
	
	for(int i = graph.begin(); i!=graph.end();i++)
	{	
		graph[i].
	}
		
}

