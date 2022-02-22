int binary(int arr[], int val, int l)
{int f=0,middle=0,position=-1;
	while(f<=l)
	{
		middle=(l+f)/2;
		if(arr[middle]==val)
		{
			position=middle;
			return position;
		}
	
		else if(arr[middle]>val)
		l=middle-1;
		else
		f=middle+1;
	}
	return position;
}


int main()
{
int arr[10];
	for(int i=0; i<10; i++)
		arr[i]=i;
	cout<<binary(arr,-1,10);
}
