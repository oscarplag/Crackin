#include<string>
#include<iostream>

using namespace std;

string ReverseChar(string str);

int main(int argc, char* argv[])
{
	if(argc<2)
	{
		cout << "Pass in input string!" << endl;
		return -1;
	}
	string str(argv[1]);
	string str2 = ReverseChar(str);
	
	cout << "Forward string: " << str << endl;
	cout << "Reverse string: " << str2 << endl;
}
string ReverseChar(string str)
{
	char* end = &str[str.length()-1];	
	char* start = &str[0];
	
	if(!end || !start)
		return NULL;
	
	while(start<end)
	{
		char temp = *end;
		*end = *start;
		*start = temp;
		start++;
		end--;
	}
	
	return str;
}
