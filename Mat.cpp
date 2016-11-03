#include"Mat.h"

Mat::Mat() //无参构造函数 
{
	rows = 0;
	cols = 0;
}
Mat::Mat(int rows,int cols)
{
	this->cols = cols;
	this->rows = rows;
	this->size = cols * rows;
	vector<int> tempVec(cols);
	for(int i = 0;i < rows; i++)
	{
		vec.insert(vec.begin() + i,tempVec);
	}
}
Mat::Mat(Mat& newMat)
{
	this->cols = newMat.cols;
	this->rows = newMat.rows;
	this->size = newMat.size;
	for(int i = 0;i < rows; i++)
	{
		this->vec.insert(vec.begin() + i,newMat.vec[i]);
	}
}



void Mat::display(void) const
{
	for(int i = 0;i < rows; i++)
	{
		for(int j = 0;j < cols; j++)
			cout<<vec[i][j]<<" ";
		cout<<endl;
	}
}

int& Mat::at(int rows,int cols)
{
	return vec[rows][cols];
}

int Mat::getRows(void) const
{
	return rows;
}
int Mat::getCols(void) const
{
	return cols;
}
int Mat::getSize(void) const
{
	return size;
}

ostream& operator << (ostream &newOstream,Mat &newMat)
{
	for(int i = 0;i < newMat.rows; i++)
	{
		for(int j = 0;j < newMat.cols; j++)
		{
			newOstream << newMat.vec[i][j]<<" ";
		}
		newOstream << endl;
	}
	return newOstream;
}

bool Mat::operator == (Mat & newMat)const
{
	if(newMat.rows != this->rows || newMat.cols != this->cols)
	{
		return false;
	}
	else
	{
		for(int i = 0;i < newMat.rows; i++)
		{
			if(this->vec[i] != newMat.vec[i])
			{
				return false;
			}
		}
		return true;
	}
	
}

Mat& Mat::operator = (Mat &newMat)
{
	if(newMat.rows != this->rows || newMat.cols != this->cols)
	{
		cout<<"Mat's size is different. Error!";
		exit(0);
	}
	for(int i = 0; i < newMat.rows; i++)
	{
		this->vec[i] = newMat.vec[i];
	}
	return *this;
}

Mat& Mat::operator + (Mat & newMat)
{
	if(newMat.rows != this->rows || newMat.cols != this->cols)
	{
		cout<<"Size is different. Can't sum!\n";
		exit(0);
	}
	
	static Mat temp(newMat);
	
	for(int i = 0; i < newMat.rows; i++)
	{
		for(int j = 0;j < newMat.cols; j++)
		{
			temp.vec[i][j] = this->vec[i][j] + newMat.vec[i][j];
		}
		
	}
	return temp;
}

Mat& Mat::operator - (Mat & newMat)
{
	if(newMat.rows != this->rows || newMat.cols != this->cols)
	{
		cout<<"Size is different. Can't sum!\n";
		exit(0);
	}
	
	static Mat temp(newMat);
	
	for(int i = 0; i < newMat.rows; i++)
	{
		for(int j = 0;j < newMat.cols; j++)
		{
			temp.vec[i][j] = this->vec[i][j] - newMat.vec[i][j];
		}
		
	}
	return temp;
}

Mat Mat::operator -= (Mat & newMat)
{
	if(newMat.rows != this->rows || newMat.cols != this->cols)
	{
		cout<<"Mat's size is different. Can't sum!\n";
		exit(0);
	}
	
	for(int i = 0; i < newMat.rows; i++)
	{
		for(int j = 0;j < newMat.cols; j++)
		{
			this->vec[i][j] -= newMat.vec[i][j];
		}
		
	}
	return *this;
} 

Mat Mat::operator += (Mat & newMat)
{
	if(newMat.rows != this->rows || newMat.cols != this->cols)
	{
		cout<<"Mat's size is different. Can't sum!\n";
		exit(0);
	}
	
	for(int i = 0; i < newMat.rows; i++)
	{
		for(int j = 0;j < newMat.cols; j++)
		{
			this->vec[i][j] += newMat.vec[i][j];
		}
		
	}
	return *this;
} 


