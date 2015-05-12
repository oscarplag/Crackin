#include<iostream>
#include<string>
#include<sstream>
#include "MyQueue.h"

using namespace std;

int main (int argc, char* argv[])
{
	try
	{
		MyQueue q;

		q.EnQueue(0);
		q.EnQueue(1);
		q.EnQueue(2);
		q.EnQueue(3);
		q.EnQueue(4);

		while(!q.empty())
		{
			cout << "Dequeued value: " << q.DeQueue() << endl;
		}
		return 0;
	}
	catch(exception ex)
	{
		cout << "Exception Ocurred" << endl;
	}
}


