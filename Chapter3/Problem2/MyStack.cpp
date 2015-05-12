#include "MyStack.h"

MyStack::MyStack(int totalSize)
{
	_stackSize = totalSize;

	_index = -1; 

	_stack = new stackVal[_stackSize];

	_curMin = 100000;
}

MyStack::~MyStack()
{
	delete[] _stack;
}

int MyStack::Peek()
{
	if(MyStack::IsEmpty())
		throw -1;
	return _stack[_index].val;
}

int MyStack::Pop()
{
	if(MyStack::IsEmpty())
		throw -1;
	int val = _stack[_index].val;
	_stack[_index].val = 0;
	_index--;
	_curMin = _stack[_index].min;
	
	return val;
}

void MyStack::Push(int val)
{
	if(_index>= _stackSize)
		throw -1;

	if(val<_curMin)
		_curMin= val;
	stackVal temp;
	temp.val = val;
	temp.min = _curMin; 
	_stack[_index+1] = temp;
	_index++;
}

bool MyStack::IsEmpty()
{
	if(_index<0)
		return true;
	else
		return false;
}

int MyStack::GetMin()
{
	if(MyStack::IsEmpty())
		throw -1;
	return _curMin;
}
