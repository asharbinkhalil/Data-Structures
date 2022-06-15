#include <iostream>
using namespace std;
class twodarray
{
	int rows, col;
	float** arr;
public:
	twodarray(int r, int c)
	{
		rows = r;
		col = c;
		arr = new float* [rows];
		for (int i = 0; i < rows; i++)
		{
			arr[i] = new float[col];
		}

	}
	void getarray()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << "Enter number ";
				cin >> arr[i][j];
			}
		}
	}
	void displayarray()
	{

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << arr[i][j];
			}
			cout << "\n";
		}
	}
	bool checkmarkov()
	{
		float value=0;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < col; j++)
			{

				value += arr[i][j];
				if (value == 1)
				{
					cout << "markov";
						return true;
				}
			}
		}
		return false;
		
	}

		bool checksparse()
		{
			int count = 0;
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < col; j++)
				{

					if (arr[i][j] == 0)
					{
						count++;
						
					}
				}
			}
			if (count > ((rows * col) / 2))
				return true;
			else
				return false;
		}
		void checkmagic()
		{
			int count = 0,a=0;
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < col; j++)
				{
					if(i==j)
					{
						a += arr[i][j];
					}
				}
			}
			int rsum = 0, rs[3], cs[3];
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < col; j++)
				{
					rsum += arr[i][j];
				}
				rs[i] = rsum;
				rsum = 0;
			}
			int csum;
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < col; j++)
				{
					csum += arr[j][i];
				}
				cs[i] = csum;
				csum = 0;
			}
			for (int i = 0; i < 3; i++)
			{
				if (rs[i] == a && cs[i] == a)
				{
					count++;
				}
			}
			if (count == 3)
			{
				cout << "hyyyyy";
			}
		}

};