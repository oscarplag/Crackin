#include<iostream>
#include<string>
#include<sstream>
#include<math.h>

using namespace std;

typedef long long pixel;
void RotateImage(pixel* image,int n);

int main (int argc, char* argv[])
{
	int  n = 5;
	pixel* image = new pixel[n*n];
	for(int i = 0; i<n*n; i++)
	{
		image[i] = i+1;
	}
	RotateImage(image,n);
	delete [] image;
	return 1;
}
void RotateImage(pixel* image, int n)
{
	cout << " Original Image: " << endl;
	int imSize = n*n; 
	for(int i = 0; i<imSize; i++)
	{
		if(i%n== 0)
			cout << endl;
		cout << image[i] << " ";
	}
	int layer = n;
	pixel temp = 0;
	for(int i = 0; i<n/2;i++)
	{
		for(int j = i; j <n-i-1;j++)
		{
			int TL = i*n + i+j;
			int TR = (i+j)*n + n-i-1; 
			int BR = n*(n-i)-i-1-j;
			int BL = n*(n-i-1-j)+i;

			temp = image[TL];
			image[TL] = image[BL];
			image[BL] = image[BR];
			image[BR] = image[TR];
			image[TR] = temp;
		}
	}

	cout << endl << endl << "Rotated Image: " << endl;
	for(int i = 0; i<imSize; i++)
	{
		if(i%n== 0)
			cout << endl;
		cout << image[i] << " ";
	}
}
