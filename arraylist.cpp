#include <iostream>
using namespace std;
template <class T>
class ArrayList
{
public:
	T* arr;
	int curr;
	int size;
	ArrayList()
	{
		size = 10;
		arr = new T[size];
		curr = 0;
		
	}
	void add(T data)
	{
		if (isfull())
		{
			arr = increaseSize();
			arr[curr] = data;
		}
		arr[curr] = data;
		curr++;
	}
	T* increaseSize()
	{
		T* newarr;
		newarr = new T[size + 10];
		for (int i = 0; i < size; i++)
		{
			newarr[i] = arr[i];
		}
		size = size + 10;
		return newarr;
	}
	bool isfull()
	{
		if (curr == size - 1)
			return true;
		else
			return false;
	}
	void display()
	{
		for (int i = 0; i < curr; i++)
		{
			cout << arr[i];
		}
	}
	void remove(T a)
	{
		int j;
		for (int i = 0; i < curr; i++)
		{
			if (arr[i] == a)
			{
				arr[i] = arr[i + 1];
			}
		}
		curr--;
	}
};

int main()
{
	ArrayList<int> arrobj;
	int a = 0;
	while (1)
	{
		cin >> a;
		arrobj.add(a);
		if (a == -1)
		{
			break;
		}

	}
	arrobj.display();
	arrobj.remove(2);
	cout << "\n\n\n";
	arrobj.display();


	return 0;
}
