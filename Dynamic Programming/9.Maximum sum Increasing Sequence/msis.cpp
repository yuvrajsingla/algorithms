#include <iostream>
using namespace std;

int max(int a,int b)
{
	return a>b?a:b;
}

int MaximumSumIncreasingSequence(int arr[],int n)
{
	int sum[n];
	int list[n];
	int maxsum=0;

	for(int i=0;i<n;i++)
	{
		sum[i]=arr[i];
		list[i]=1;
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			  if(arr[i]>arr[j])
			  {
			  	if(list[j]+1 > list[i])
			  	{
			  		sum[i]=sum[j]+arr[i];
			  		list[i]=list[j]+1;
			  	}
			  }
		}
	}

	for(int i=0;i<n;i++)
	{
		
          if(maxsum<sum[i])
          {
          	maxsum=sum[i];
          }
	}
   
	return maxsum;
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
	cout<<MaximumSumIncreasingSequence(arr,size);

	return 0;
}