#include<iostream>
#include<string>
#include<sstream>
#include<stack>
#include "MyStack.h"

using namespace std;

int main (int argc, char* argv[])
{
	MyStack st(100);
	st.Push(80);
	st.Push(60);
	st.Push(70);
	st.Push(50);
	st.Push(40);

	cout << "Current Minimum: " << st.GetMin() << endl;
	cout << "Popping value: " << st.Pop() << endl;
	cout << "Current Minimum: " << st.GetMin() << endl;
	cout << "Popping value: " << st.Pop() << endl;
	cout << "Current Minimum: " << st.GetMin() << endl;

	return 0;
}


