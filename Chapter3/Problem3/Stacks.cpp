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
		MyStack st(3);

		st.Push(81);
		st.Push(10);
		st.Push(7);
		st.Push(6);
		st.Push(5);

		int val = st.Pop();
		cout << "Stack 1 top: " << val << endl;
		val = st.Pop();
		cout << "Stack 1 top: " << val << endl;
		

		val = st.Peek();
		cout << "Stack 1 peek: " << val << endl;
		val = st.Peek();
		cout << "Stack 1 peek: " << val << endl;
		val = st.Pop();
		cout << "Stack 2 top: " << val << endl;
		val = st.Pop();
		cout << "Stack 3 top: " << val << endl;
		return 1;
	}
	catch(exception ex)
	{
		cout << "Exception Ocurred" << endl;
	}
}


