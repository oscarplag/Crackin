#include<set>
#include<string>
#include<iostream>

using namespace std;

bool AreCharsUnique(const string& str1);
bool AreCharsUnique2(const string& str1);

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		cout << "Please pass in a string!" << endl;
	}
	
	string str1(argv[1]);
	cout << "AreCharsUnique1: " <<str1; 
	if(AreCharsUnique(str1))
		cout << " has unique characters!" << endl;
	else
		cout << " does not have unique characters!" << endl;
	cout << "AreCharsUnique2: " <<str1; 
	if(AreCharsUnique2(str1))
		cout << " has unique characters!" << endl;
	else
		cout << " does not have unique characters!" << endl;
}

bool AreCharsUnique(const string& str1)
{
	set<char> mySet;
	
	for(string::const_iterator it = str1.begin(); it!=str1.end(); it++)
	{
		if(mySet.count(*it) !=0)
			return false;
		mySet.insert(*it);	
	}
	return true;
}
bool AreCharsUnique2(const string& str1)
{
 	int buff = 0;
	int smallStart = (int)'a';
	int smallEnd = (int) 'z';
	int bigStart = (int) 'A';
	int bigEnd = (int) 'Z';
	for(string::const_iterator it = str1.begin(); it!=str1.end();it++)
	{
		int temp = (int)*it;	
		if(temp>=smallStart && temp<=smallEnd)
		{
			temp -= smallStart;
		}
		else if(temp>=bigStart&& temp<=bigEnd)
		{
			temp -= bigStart;
		}
		else
			return false;

		int temp2 = 1<<temp;
		if(temp2&buff)	
			return false;
		buff = buff|temp2;
	}
	return true;
}
