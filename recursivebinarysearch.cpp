#include<iostream>
int recbinary(int array[], int first, int last, int value)
{
	int	middle, position = -1;
   bool found = false;
	while (!found && first <= last)
	{	middle = (first + last) / 2;  // Calculate mid point
		if (array[middle] == value)   // If value is found at mid
         {   found = true;
		    position = middle;
         }
		else if (array[middle] > value) // If value is in lower half
             return recbinary(array,first,middle-1,value);
		else
		    return recbinary(array,middle +1,last,value);	   
	}
	return position;  
}
int main()
{
int arr[10];
	for(int i=0; i<10; i++)
		arr[i]=i+1;
//	std::cout<<binary(arr,-1,10);
std::cout<<recbinary(arr,0,9,10);
return 0;
}
