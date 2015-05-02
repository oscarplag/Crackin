#include "MyStack.h"

MyStack::MyStack(int numStacks, int totalSize)
{
	_numStacks = numStacks;
	_stackSize = totalSize/_numStacks;
	_totalSize = totalSize;

	_indecies = new int[_numStacks];

	for(int i = 0; i<_numStacks; i++)
	{
		_indecies[i] = -1;
	}

	_stack = new int[_totalSize];
}

MyStack::~MyStack()
{
	delete[] _indecies;
	delete[] _stack;
}

int MyStack::GetTopIndex(int stackNum)
{
	int stackIndex = stackNum-1;
	
	return _stackSize*stackIndex+_indecies[stackIndex];
}

int MyStack::Peek(int stackNum)
{
	if(MyStack::IsEmpty(stackNum))
		throw -1;
	return _stack[GetTopIndex(stackNum)]; 
}

int MyStack::Pop(int stackNum)
{
	if(MyStack::IsEmpty(stackNum))
		throw -1;
	int index = MyStack::GetTopIndex(stackNum);
	int val = _stack[index];
	_stack[index] = 0;
	_indecies[stackNum-1]--;
	return val;
}

void MyStack::Push(int val, int stackNum)
{
	int index = GetTopIndex(stackNum);
	int nextStackIndex = _stackSize*stackNum;
	
	if(index>= nextStackIndex || index>= _totalSize)
		throw -1;

	_stack[index+1] = val;
	_indecies[stackNum-1]++;
}

bool MyStack::IsEmpty(int stackNum)
{
	if(_indecies[stackNum-1] <0)
		return true;
	else
		return false;
}
