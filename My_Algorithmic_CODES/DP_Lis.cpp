/*
    LIS
    by chinmay 
    28/10/2015
*/
#include <bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
    return(a>b)?a:b;
}
int main()
{
    int a[]={10,9,8,7,6,5,4,3,2};
    int dp[10];
    for(int i=0;i<=8;i++)
    {
        dp[i]=1;
        for(int j=i-1;j>=0;j--)
        {
            if(a[i]>a[j])
            dp[i]=max(dp[i],1+dp[j]);
        }
    }
    printf("%d\n",dp[8] );
    return 0;
}
//O(N^2)solution..
