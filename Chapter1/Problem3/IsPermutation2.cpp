#include<string>
#include<iostream>

using namespace std;

bool IsPermutation(const string& str1, const string& str2);
bool IsPermutationSort(string str1,string str2);

int main(int argc, char* argv[])
{
	if(argc < 3)
	{
		cout << "Please pass in 2 string input arguments!" << endl;
		return -1;
	}
	string str1(argv[1]);
	string str2(argv[2]);
	
	cout << "IsPermutation: ";
	if(IsPermutation(str1,str2))
		cout << str1 << " is a permutation of " << str2 << endl;
	else
		cout << str1 << " is not a permutation of " << str2 << endl;
	cout << "IsPermutationSort: ";
	if(IsPermutationSort(str1,str2))
		cout << str1 << " is a permutation of " << str2 << endl;
	else
		cout << str1 << " is not a permutation of " << str2 << endl;
	return 0;
}
bool IsPermutation(const string& str1, const string& str2)
{
	if(str1.length()!=str2.length())
		return false;
	
	int buf[256]={0};

	for(string::const_iterator it = str1.begin();it!=str1.end();it++)
	{
		buf[(int)*it]++;
	}	
	for(string::const_iterator it = str2.begin();it!=str2.end();it++)
	{
		int temp = (int)*it;
		buf[temp]--;
		if(buf[temp]<0)
			return false;
	}	
	return true;
}
bool IsPermutationSort(string str1, string str2)
{
	if(str1.length()!=str2.length())
		return false;

	sort(str1.begin(),str1.end());
	sort(str2.begin(),str2.end());
	
	if(str1!=str2)
		return false;
	return true;
}
