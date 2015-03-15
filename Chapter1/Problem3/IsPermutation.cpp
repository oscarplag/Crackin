#include <iostream>
#include <string>

using namespace std;

bool IsPermutation(string& str1, string& str2);

int main(int argc, char* argv[])
{
	if(argc!=3)
	{
		cout << "Please pass in two input parmeters (strings)." << endl;
		return -1;
	}
	string str1 = argv[1];
	string str2 = argv[2];

	if(IsPermutation(str1,str2))
		cout << "\"" << str2 << "\" is a permutation of: \"" << str1 << "\"" << endl;
	else
		cout << "\"" << str2 << "\" is not a permutation of: \"" << str1 << "\"" << endl;
}

bool IsPermutation(string& str1, string& str2)
{
	if(str1.size()!=str2.size())
		return false;

	int charVals[128]={0};

	for(string::iterator it = str1.begin();it!=str1.end();++it)
	{
		charVals[(int)*it]++;
	}
	for(string::iterator it = str2.begin();it!=str2.end();++it)
	{
		charVals[(int)*it]--;
		if(charVals[(int)*it]<0)
			return false;
	}	
	return true;
}
