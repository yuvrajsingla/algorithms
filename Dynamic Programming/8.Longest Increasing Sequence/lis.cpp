#include <iostream>
using namespace std;

int max(int a,int b)
{
   return a>b?a:b;
}


int longestIncreasingSequence(int arr[],int n)
{
	int maxans=0;
	int list[n];

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
	return maxans;
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

    cout<<longestIncreasingSequence(arr,size);
	return 0;
}