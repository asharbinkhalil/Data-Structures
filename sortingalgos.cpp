#include<iostream>
using namespace std;
void bubbleSort(int arr[], int n)
{
    bool found=false;
	while(!found)
	{
		found =true;
    for(int i=0; i<n; i++)
    {
       for(int j=0; j<n-i-1; j++)
       {
           if(arr[j]>arr[j+1])
           {
               int temp;
               temp=arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=temp;
		   found=false;
           }
       }
    }
	}
}
   void insertionSort(int arr[], int n)
{
	
	for(int i=1; i<n ; i++)
	{
		for(int j=i; j>0; j--)
		{
			if( (arr[j]<arr[j-1]))
			swap(&arr[j-1],&arr[j]);
		}
	}
}
void swap(int *a, int *b )
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void selectionsort(int arr[], int n)
{
	int min_index;
	for(int i=0; i<n-1; i++)
	{
		min_index=i;
		for(int j=i+1; j<n; j++)
		{
			if(arr[j]<arr[min_index])
			min_index=j;
		}
		swap(&arr[i],&arr[min_index]);
	}
}
int main()
{
/*int arr[10];
	for(int i=0; i<10; i++)
		arr[i]=i+1;
	cout<<binary(arr,-1,10);
cout<<recbinary(arr,0,9,10);*/
//
int arr[]={5,3,9,2,1};
//bubblesort(arr,5);
selectionsort(arr,5);
for(int i=0; i<5; i++)
cout<<arr[i];

}

