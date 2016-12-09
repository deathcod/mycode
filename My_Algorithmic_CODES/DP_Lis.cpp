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
    int a[]={10,9,8,7,6,5,3,4,2};
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
    int max_Lis = 0;
    for (int i = 0; i <= 8; ++i)
    {
        max_Lis = max(dp[i],max_Lis);
        //printf("%d ",dp[i] );
    }
    printf("%d\n",max_Lis );
    return 0;
}
//O(N^2)solution..
