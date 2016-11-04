#include<iostream>
//#include<vector>
#include"Mat.h"

int main(int argc, char** argv) 
{
	Mat mat1(10,5);
	Mat mat2(5,8);
	Mat mat3(10,8);
	Mat mat4(8,10);
	
	for(int i = 0;i < 10;i++)
	{
		for(int j = 0;j < 5;j++)
		{
			mat1.at(i,j) = (i + j);
		}
	}
	for(int i = 0;i < 5;i++)
	{
		for(int j = 0;j < 8;j++)
		{
			mat2.at(i,j) = (i + j);
		}
	}
	
	mat3 = mat1 * mat2;
	mat4 = mat3.T();
	cout<<mat4;
	return 0;
}
