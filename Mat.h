#ifndef MAT_H_
#define MAT_H_

#include<iostream>
#include<vector>
using namespace std;

class Mat
{
	public:
		Mat(); //�޲ι��캯�� 
		Mat(int rows,int cols);
		Mat(Mat& newMat);
		void display(void) const;
		int& at(int rows,int cols);
		int getRows(void) const;
		int getCols(void) const;
		int getSize(void) const;
		friend ostream& operator << (ostream &newOstream,Mat &newMat);
		bool operator == (Mat & newMat)const;
		Mat& operator = (Mat &newMat);
		Mat& operator + (Mat & newMat);
		Mat& operator - (Mat & newMat);
		Mat& operator -= (Mat & newMat);
		Mat& operator += (Mat & newMat);
		Mat& operator * (Mat &newMat);
		Mat& T(void) const; //�����װ��  
	
	private:
		private:
		int rows;
		int cols;
		int size;
		vector<vector<int> > vec;

};


#endif

