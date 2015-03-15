#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool IsPermutationSort(const string& str1, const string& str2);

int main(int argc, char* argv[])
{
	if(argc !=3)
	{
		cout << "Please pass in two (string) arguments! " << endl;
		return -1;
	}
	string str1 = argv[1];
	string str2 = argv[2];
	if(IsPermutationSort(str1,str2))
		cout << endl << "\"" << str2 << "\" is a permutation of: \"" << str1 << "\"" << endl;
	else
		cout << endl << "\"" << str2 << "\" is not a permutation of: \"" << str1 << "\"" <<  endl;
}

bool IsPermutationSort(const string& str1, const string& str2)
{
	string str1cpy = str1;
	string str2cpy = str2;
	sort(str1cpy.begin(),str1cpy.end());
	sort(str2cpy.begin(),str2cpy.end());
	return(str1cpy.compare(str2cpy)==0);	
}
