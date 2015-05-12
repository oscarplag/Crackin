#include "MyStack.h"

MyStack::MyStack(int stackSize)
{
	_stackSize = stackSize;
	_stackIndex = -1;
	_stack = vector<stack<int>*>(); 
}

MyStack::~MyStack()
{
}

int MyStack::Peek(int stackNum)
{
	if(_stack.size() <= stackNum)
		throw -1;
	return _stack[stackNum]->top();
}

int MyStack::Pop(int stackNum)
{
	if(_stack.size() <= stackNum)
		throw-1;
	stack<int>* temp = _stack[stackNum];
	int val = temp->top();
	temp->pop();
	if(temp->empty())
	{
		//delete temp;
		_stack.pop_back();
		_stackIndex--;
	}
	return val;
}
int MyStack::Peek()
{
	if(_stackIndex < 0)
		throw -1;
	return _stack[_stackIndex]->top();
}

int MyStack::Pop()
{
	if(_stackIndex<0)
		throw-1;
	stack<int>* temp = _stack[_stackIndex];
	int val = temp->top();
	temp->pop();
	if(temp->empty())
	{
		delete temp;
		_stack.pop_back();
		_stackIndex--;
	}
	return val;
}
void MyStack::Push(int val)
{
	if(_stackIndex == -1)	
	{
		stack<int>* temp = new stack<int>();
		temp->push(val);
		_stack.push_back(temp);
		_stackIndex++;
	}
	else
	{
		stack<int>* temp = _stack[_stackIndex];
		if(temp->size() >= _stackSize)
		{
			stack<int>* temp2 = new stack<int>();
			temp2->push(val);
			_stack.push_back(temp2);
			_stackIndex++;
		}
		else
		{
			temp->push(val);
		} 
	}

}

bool MyStack::IsEmpty(int stackNum)
{
	if(_stackIndex < 0)
		return true;
	return false;
}
