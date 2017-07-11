#include <iostream>
using namespace std;

int max(int a,int b)
{
   return a>b?a:b;
}


void longestIncreasingSequence(int arr[],int n,int *list)
{
	int maxans=0;
	for(int i=0;i<n;i++)
	{
		list[i]=1;
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[i]>arr[j])
			{
				list[i]=max(list[i],list[j]+1);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(maxans<list[i])
		{
			maxans=list[i];
		}
	}
	
}

int LongestBitonicSequence(int arr[],int n)
{
	int forwdlist[n];
	longestIncreasingSequence(arr,n,forwdlist);
	int revarr[n];
	for(int i=0;i<n;i++)
	{
		revarr[i]=arr[n-i-1];
	}
	int reverlist[n];
	longestIncreasingSequence(revarr,n,reverlist);

	int resultmax=0;

	for(int i=0;i<n;i++)
	{
		if(resultmax<(forwdlist[i]+reverlist[i]))
		{
			resultmax=forwdlist[i]+reverlist[i];
		}
	}
	return resultmax-1;
}

int main(int argc, char const *argv[])
{
	int size;
	cin>>size;
    
    int arr[size];
    for(int i=0;i<size;i++)
    {
    	cin>>arr[i];
    }

    cout<<LongestBitonicSequence(arr,size);
	return 0;
}