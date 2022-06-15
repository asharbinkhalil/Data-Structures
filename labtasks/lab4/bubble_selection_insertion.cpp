#include<iostream>
using namespace std;
void bubblesort(int **arr, int n){
     for(int i=0; i<n-1; i++)
        {
        	for(int j=0; j<n-i-1; j++)
        	{
        		if(arr[0][j]<arr[0][j+1])
					{
			        int val=arr[0][j];
					arr[0][j]=arr[0][j+1];
					arr[0][j+1]=val;
					}
			}
	
}
}
void insertionSort(int **arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[2][i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[2][j]< key)
        {
            arr[2][j + 1] = arr[2][j];
            j = j - 1;
        }
        arr[2][j + 1] = key;
    }
}
void swap(int *a, int *b )
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void selectionsort(int **arr, int n)
{
	int min_index;
	for(int i=0; i<n-1; i++)
	{
		min_index=i;
		for(int j=i+1; j<n; j++)
		{
			if(arr[1][j]>arr[1][min_index])
			min_index=j;
		}
		swap(&arr[1][i],&arr[1][min_index]);
	}
}
int main()
{
	int **arr=new int*[3];
for(int i=0; i<3; i++)
{
	arr[i]=new int[7];
}

		for(int i=0; i<3; i++)
	{
		for(int j=0; j<7; j++)
		{
			arr[i][j]=i+j;
		}
	}
	for(int i=0; i<3; i++){
	
		for(int j=0; j<7; j++)
		{
			cout<<arr[i][j];
		}
	cout<<"\n";}
	cout<<"\n\n";
	bubblesort(arr,7);
	selectionsort(arr,7);
	insertionSort(arr,7);
	for(int i=0; i<3; i++){
	
		for(int j=0; j<7; j++)
		{
			cout<<arr[i][j];
		}
	cout<<"\n";}
}
