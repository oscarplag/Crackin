#include<iostream>
#include<string>
#include<sstream>
#include "Tower.h"

using namespace std;

int main (int argc, char* argv[])
{
	try
	{
		int n = 4;
		Tower towers[3] = {Tower(1),Tower(2),Tower(3)};
		/*for(int i = 0; i<3;i++)
		{
			towers[i] = new Tower();
		}*/	
		for(int i = n-1; i>=0; i--)
		{
			towers[0].add(i);
		}
		towers[0].moveDisks(n-1,towers[2],towers[1]);
		return 0;
	}
	catch(exception ex)
	{
		cout << "Exception Ocurred" << endl;
	}
}


