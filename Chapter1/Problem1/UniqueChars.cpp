#include <iostream>
#include <string>


using namespace std;

bool AreCharsUnique(string& str);

int main(int argc, char* argv[])
{
	try
	{
		if(argc !=2)
			throw 0;

		string str = argv[1];
		bool isUnique = AreCharsUnique(str);
		if(isUnique)
			cout << "Characters are unique in string: " << str << endl;
		else
			cout << "Characters are not unique in string: " << str << endl;
	}
	catch (int e)
	{
		if(e == 0)
			cout << "Please pass in a single command line argument to parse!" << endl;
		else
			cout << "An exception occurred. Exception Nr. " << e << endl;
	}
}

bool AreCharsUnique(string& str)
{
	int smallStartOffset = (int)'a';
	int smallEndOffset = (int) 'z';
	int bigStartOffset = (int) 'A';
	int bigEndOffset = (int) 'Z';
	
	long long bitMap;	

	for(string::iterator it = str.begin(); it != str.end() ; ++it)
	{
		int temp = (int)*it;
		if(temp>=smallStartOffset && temp<= smallEndOffset)
		{
			int tempOffset = temp-smallStartOffset;
			long long bitVal = 1 <<tempOffset;
			if(bitMap&bitVal)
				return false;
			else
				bitMap = bitMap | bitVal;
		}
		else if(temp>=bigStartOffset && temp <=bigEndOffset)
		{
			int tempOffset = temp-bigStartOffset;// + (smallEndOffset - smallStartOffset);
			long long bitVal = 1 << tempOffset;
			if(bitMap&bitVal)
				return false;
			else
				bitMap = bitMap | bitVal;	
		}
		else if(temp == (int)' ')
		{
		}
		else
		{
			throw -1;
		}
	}
	return true;	
}
