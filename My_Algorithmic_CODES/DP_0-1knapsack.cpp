/*
0-1 knapscak
by chinmay rakshit
date:20/11/2015
*/
#include <bits/stdc++.h>
int max(int a,int b)
{
    return(a>b)?a:b;
}
int main()
{
    int dp[101][101]={0},w[101]={0},val[101]={0},n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d %d",&w[i],&val[i]);
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(w[i]<=j)
                dp[i][j]=max(dp[i-1][j-w[i]]+val[i],dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    // row items and column is weight.....
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
            printf("%d ",dp[i][j]);
        printf("\n");
    }
    printf("%d\n",dp[m][n] );
    return 0;
}