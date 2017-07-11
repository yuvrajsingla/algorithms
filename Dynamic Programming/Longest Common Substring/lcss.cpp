#include <iostream>
using namespace std;

int max(int a,int b)
{
	return a>b?a:b;
}

int LongestCommonSubstring(char s1[],char s2[],int n1,int n2)
{
	int dp[n1+1][n2+1];
    
    int maxSubstringL=0;
    for(int i=0;i<=n1;i++)
    {
    	for(int j=0;j<=n2;j++)
    	{
    		if(i==0 || j==0)
    		{
    			dp[i][j]=0;
    		}
    		else if(s1[i-1]==s2[j-1])
    		{
    			dp[i][j]=dp[i-1][j-1]+1;
    			maxSubstringL=max(maxSubstringL,dp[i][j]);
    		}
    		else {
    			dp[i][j]=0;
    		}
    	}
    }
    return maxSubstringL;
}

int main(int argc, char const *argv[])
{
	int s1size,s2size;
	cin>>s1size;
	cin>>s2size;

	char str1[s1size],str2[s2size];
	cin>>str1;
	cin>>str2;

	cout<<LongestCommonSubstring(str1,str2,s1size,s2size);

	return 0;
}