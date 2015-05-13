#include<iostream>
#include<string>
#include<sstream>
#include<stack> 
#include "Animal.h"
#include "AnimalQueue.h"

using namespace std;



int main (int argc, char* argv[])
{
	try
	{
		Animal bob("Bob", CAT);
		Animal frank("Frank",CAT);
		Animal shank("Shank",DOG);
		Animal bruce("Bruce",DOG);
		
		AnimalQueue q;

		q.EnQueue(bob);
		q.EnQueue(frank);
		q.EnQueue(shank);
		q.EnQueue(bruce);

		Animal a = q.DeQueue();
		if(a.GetType() == CAT)
			cout << "The adopted animal was a cat and his name is: " << a.GetName() << endl;
		else
			cout << "The adopted animal was a dog and his name is: " << a.GetName() << endl;
		Animal b = q.DeQueueDog();
		if(b.GetType() == CAT)
			cout << "The adopted animal was a cat and his name is: " << b.GetName() << endl;
		else
			cout << "The adopted animal was a dog and his name is: " << b.GetName() << endl;
	
			
		return 0;
	}
	catch(exception ex)
	{
		cout << "Exception Ocurred" << endl;
	}
}

