#include <iostream>
#include <limits.h>
using namespace std;

int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}

int rodCut(int price[],int n)
{
	int BestPrice[n+1];  // last value of this array will give us best solution.
	BestPrice[0]=0;

	for(int i=1;i<=n;i++)
	{
		 int max_level=INT_MIN;
		 for(int j=0;j<i;j++)
		 {
		 	  max_level=max(max_level,price[j] + BestPrice[i-j-1]);
		 }
		 BestPrice[i]=max_level;
	}
	return BestPrice[n];
}

int main(int argc, char const *argv[])
{
	int arr[] = {3, 5, 8, 9, 10, 17, 17, 20};

   cout<<rodCut(arr,8);
	return 0;
}