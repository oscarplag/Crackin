#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include<vector>

using namespace std;

bool IsRotated(const string& str1, const string& str2);
bool IsSubstring(const string& str1, const string& str2); 

int main (int argc, char* argv[])
{
	if(argc != 3)
	{
		cout << "Please pass in 2 strings to compare" << endl;
		return -1;
	}
	
	string str1(argv[1]);
	string str2(argv[2]);

	if(IsRotated(str1,str2))
		cout << str2 << " is a rotated version of: " << str1 << endl;
	else
		cout << str2 << " is not a rotated version of: " << str2 << endl;	

	return 1;
}

bool IsSubstring(const string& str1, const string& str2)
{
	size_t found = str1.find(str2);
	if(found!=string::npos)
		return true;
	else
		return false;
} 

bool IsRotated(const string& str1, const string& str2)
{
	if(str1.length() != str2.length())
		return false;
	string str3 = str1+str1;
	if(IsSubstring(str3,str2))
		return true;
	else
		return false;
}
