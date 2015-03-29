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
			else if(i == 7 && j ==6)
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
	cout << " Original Image: " << endl;
	int imSize = m*n; 
	for(int i = 0; i<imSize; i++)
	{
		if(i%m== 0)
			cout << endl;
		cout << image[i] << " ";
		if(image[i]<10)
			cout << " ";
	}

	vector<int> colIndex;
	vector<int> rowIndex;
	for(int i = 0; i<n; i++)
	{
		int rowOffset = i*m;
		for(int j = 0; j<m; j++)
		{
			if(image[rowOffset+j] == 0)
			{
				colIndex.push_back(j);
				rowIndex.push_back(i);
			}
		}
	}

	for(vector<int>::iterator it = colIndex.begin();it!=colIndex.end();it++)
	{
		int rowOffset = (*it)*m; 
		for(int i = 0; i<m; i++)
		{
			image[rowOffset+i] = 0;
		}
	}
	for(vector<int>::iterator it = rowIndex.begin();it!=rowIndex.end();it++)
	{
		int colIndex = *it;
		for(int i = 0;i<n;i++)
		{
			image[i*m+colIndex] = 0;
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
