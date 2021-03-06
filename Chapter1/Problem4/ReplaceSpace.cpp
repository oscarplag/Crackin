#include <iostream>
#include <memory.h>

using namespace std;

void replaceSpaces(char* input, int length);

using namespace std;

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		cout << "Please pass in input argument!" << endl;
		return -1;
	}
	char* it = argv[1];
	int length = 0;
	int fullLength = 0;
	while(*it!='\0')
	{
		length++;
		fullLength++;
		if(*it == ' ')
			fullLength+= 2;
		it++;
	}
	char* str = new char[fullLength];
	memcpy(str,argv[1],length);
	replaceSpaces(str,length);
}

void replaceSpaces(char* input, int length)
{
	char* it = input;
	int numSpaces = 0;
	
	for(int i = 0; i<length;i++)
	{

		if(input[i] == ' ') 
			numSpaces++;
	}

	int i2 = length+2*numSpaces;
	input[length+2*numSpaces] = '\0';
	for(int i = length-1;i>0;i--)
	{
		if(input[i] == ' ')
		{
			input[--i2] = '0';
			input[--i2] = '2';
			input[--i2] = '%';
		}
		else
		{
			input[--i2] = input[i];
		}
	}
	cout << "New string: " << input << endl;

}
