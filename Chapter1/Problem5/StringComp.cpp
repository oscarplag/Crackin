#include<iostream>
#include<string>
#include<sstream>

using namespace std;

string CompressString(string& str);
int CompressedLength(string& str);

int main (int argc, char* argv[])
{
	if(argc!=2)
		return -1;
	string str = argv[1];

	string outStr = CompressString(str);

	cout << "Original String: " << str << endl;
	cout << "Compressed String: " << outStr << endl;
}

string CompressString(string& str)
{
	int newLength = CompressedLength(str);
	cout << "Compressed string length: " << newLength << endl;
	if(newLength>str.size())
		return str;


	stringstream sstm;
	sstm.str("");

	int count = 1;
	string::iterator it = str.begin();
	char cur = *it;	

	for(it++;it!=str.end();it++)
	{
		if(*it==cur)
		{
			count++;
		}
		else 
		{
			sstm << cur << count; 
			count = 1;
			cur = *it;
		}
	}
	sstm << cur << count;
	return sstm.str();
}

int CompressedLength(string& str)
{
	int count = 0;
	int totalCount = 0;
	string::iterator it = str.begin();
	char cur = *it;
	for(it++;it!=str.end();it++)
	{
		if(*it == cur)
		{
			count++;
		}	
		else if(it!=str.begin())
		{
			cur = *it;
			totalCount += count/10 + 2;
			count = 0;
		}
	}
	totalCount += count/10 +2;
	return totalCount;
}
