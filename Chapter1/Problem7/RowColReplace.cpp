#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include<vector>

using namespace std;

typedef long long pixel;
void RowColReplace(pixel* image,int n, int m);

int main (int argc, char* argv[])
{
	int counter = 1;
	int  n = 8;
	int m = 9;
	pixel* image = new pixel[m*n];
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			if(i == 3 && j ==3)
			{
				image[i*m+j] = 0;
			}
			else if(i == 3 && j ==6)
			{
				image[i*m+j] = 0;
			}
			else
			{
				image[i*m+j] = counter;
			}
			counter++;
		}
	}
	RowColReplace(image,n,m);
	delete [] image;
	return 1;
}
void RowColReplace(pixel* image, int n, int m)
{

	bool colZero [m]; 
	bool rowZero[n]; 
	cout << " Original Image: " << endl;
	int imSize = m*n; 
	for(int i = 0; i<n; i++)
	{
		cout << endl;
		int colNum = i*m;
		rowZero[i] = 0;
		for(int j = 0; j<m; j++)
		{
			cout << image[colNum+j] << " ";
			if(image[colNum+j] < 10)
				cout << " ";
			colZero[j] = 0;
		}
		
	}
	
	for(int i = 0; i<n; i++)
	{
		int rowOffset = i*m;
		for(int j = 0; j<m; j++)
		{
			if(image[rowOffset+j] == 0)
			{
				colZero[j] = true;
				rowZero[i] = true;
			}
		}
	}
	for(int i = 0; i<m; i++)
	{
		if(colZero[i] == 1)
		{
			for(int j = 0; j<n; j++)
			{
				image[j*m+i] = 0;
			}
		}
	}
	for(int i = 0; i<n; i++)
	{
		if(rowZero[i] == 1)
		{
			int colIndex = i*m;
			for(int j = 0; j<m; j++)
			{
				image[colIndex+j] = 0;
			}

		}
	}
	cout << endl << endl << "Rotated Image: " << endl;
	for(int i = 0; i<imSize; i++)
	{
		if(i%m== 0)
			cout << endl;
		cout << image[i] << " ";
		if(image[i] < 10)
			cout << " ";
	}
}
