#include "MyQueue.h"
#include <stdio.h>

MyQueue::MyQueue()
{
}

MyQueue::~MyQueue()
{
}

void MyQueue::EnQueue(int val)
{
	stackNewest.push(val);
}

void MyQueue::shiftStacks()
{
	if(stackOldest.empty())
	{
		while(!stackNewest.empty())
		{
			stackOldest.push(stackNewest.top());
			stackNewest.pop();
		}
	}
}

int MyQueue::DeQueue()
{
	if(empty())
	{
		throw -1;
	}
	shiftStacks();
	int val = stackOldest.top();
	stackOldest.pop();
	return val;
}

int MyQueue::Peek()
{
	if(empty())
		throw -1;
	shiftStacks();
	return stackOldest.top();
}

int MyQueue::size()
{
	return stackOldest.size() +stackNewest.size();
}

bool MyQueue::empty()
{
	if(size() == 0)
		return true;
	return false;
}
