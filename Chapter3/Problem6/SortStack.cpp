#include<iostream>
#include<string>
#include<sstream>
#include<stack> 

using namespace std;
stack<int> SortMyStack(stack<int> s);

int main (int argc, char* argv[])
{
	try
	{
		stack<int> s;
		s.push(5);
		s.push(7);
		s.push(4);
		s.push(6);
		s.push(3);
		s.push(8);
		s.push(2);
		s.push(9);
		s.push(1);
		s.push(0);

		stack<int> sorted = SortMyStack(s);
		cout << "Sorted stack: " << endl;
		while(!sorted.empty())
		{
			int val = sorted.top();
			sorted.pop();
			cout << val << endl;
		}
				
		return 0;
	}
	catch(exception ex)
	{
		cout << "Exception Ocurred" << endl;
	}
}

stack<int> SortMyStack(stack<int> s)
{
	stack<int> r;
	while(!s.empty())
	{
		int val = s.top();
		s.pop();

		while(!r.empty() && r.top() > val)
		{
			s.push(r.top());
			r.pop();
		}
		r.push(val);
	}
	return r;
}
