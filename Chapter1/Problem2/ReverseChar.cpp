#include <iostream>
#include <string>

using namespace std;

void reverse(char* str);

int main (int argc, char* argv[])
{
	cout << "Input string: " << argv[1] << endl;
	reverse(argv[1]);
	cout << "Reversed Input string: " << argv[1] << endl;
}

void reverse(char* str)
{
	if(str)
	{
		char temp;
		char* end = str;
		while (*end)
		{
			end++;
		}
		end--;
		
		while(str<end)
		{
			temp = *end;
			*end = *str;
			*str = temp;
			str++;
			end--;
		}
	}
}

