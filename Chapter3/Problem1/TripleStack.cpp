#include<iostream>
#include<string>
#include<sstream>
#include<stack>
#include "MyStack.h"

using namespace std;



int main (int argc, char* argv[])
{
	try
	{
		MyStack st(3,100);

		st.Push(8,1);
		st.Push(10,2);
		st.Push(7,1);
		st.Push(6,1);
		st.Push(5,1);

		int val = st.Pop(1);
		cout << "Stack 1 top: " << val << endl;
		val = st.Pop(1);
		cout << "Stack 1 top: " << val << endl;

		val = st.Peek(1);
		cout << "Stack 1 peek: " << val << endl;
		val = st.Peek(1);
		cout << "Stack 1 peek: " << val << endl;

		val = st.Pop(2);
		cout << "Stack 2 top: " << val << endl;

		val = st.Pop(3);
		cout << "Stack 3 top: " << val << endl;

		return 1;
	}
	catch(exception ex)
	{
		cout << "Exception Ocurred" << endl;
	}
}


