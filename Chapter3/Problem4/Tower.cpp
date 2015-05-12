#include "Tower.h"
#include <stdio.h>

Tower::Tower(int index)
{
	_index = index;
	mystack = stack<int>();
}

Tower::~Tower()
{
}

void Tower::add(int d)
{
	if(!mystack.empty()&&mystack.top()<d)
	{
		printf("Top of stack: %d, current: %d\n",mystack.top(),d);
		throw -1;
	}
	else
		mystack.push(d);
}

void Tower::moveTop(Tower* destination)
{
	int d = mystack.top();
	
	destination->add(d);

	mystack.pop();
	
	printf("moved disk: %d from %d to %d\n",d,_index,destination->_index); 
}

void Tower::moveDisks(int n, Tower* destination, Tower* buffer)
{
	if(n>0)
	{
		moveDisks(n-1,buffer,destination);
		moveTop(destination);
		buffer->moveDisks(n-1,destination,this);
	}
}

void Tower::moveDisks(int n, Tower& destination, Tower& buffer)
{
	moveDisks(n, &destination, &buffer);
}
