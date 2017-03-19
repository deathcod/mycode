#include <bits/stdc++.h>
using namespace std;
int min(int x,int y){return(x<y)?x:y;}
int max(int x,int y){return(x>y)?x:y;}
 
int LIS(int a[1000], int value, int index, int len)
{
    int c = 0;
    for(int i=index; i<len; i++)
    {
        if (value<=a[i])
            c = max(c, 1 + LIS(a, a[i], i+1, len));
    }
    return c;
}
int LIS_dp(int a[1000], int n)
{
    int lis_dp[1000]={0};
    int k=-1;
    for(int i=n-1;i>=0;i--)
    {
        lis_dp[i] = 1;
        for(int j=i+1;j<n;j++)
        {
            if(a[i]<a[j])
                lis_dp[i] = max(lis_dp[i],1+lis_dp[j]);
        }
    }
    for(int i=0;i<n;i++)
        k = max(lis_dp[i],k);
    
    return k;
}
int LIS_dp_2(int a[1000], int n)
{
    int lis_dp[1000]={0};
    int dp[1000];
    for(int i=0;i<=n-1;i++)
    {
        dp[i]=1;
        for(int j=i-1;j>=0;j--)
        {
            if(a[i]>a[j])
            dp[i]=max(dp[i],1+dp[j]);
        }
    }
    int max_Lis = 0;
    for (int i = 0; i <= n-1; ++i)
    {
        max_Lis = max(dp[i],max_Lis);
        //printf("%d ",dp[i] );
    }
    
    return max_Lis;
}
int main(int argc, char const *argv[])
{
    int t,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int a[1000];
        for(int i=0;i<n;i++)
            cin >> a[i];
        //cout << LIS(a, -1, 0, n);
        //cout << LIS_dp(a,n)<<"\n";
        cout << LIS_dp_2(a,n)<<"\n";
    }
    
    return 0;
}
/*
Given a sequence, find the length of the longest increasing subsequence from a given sequence .
The longest increasing subsequence means to find a subsequence of a given sequence in which the subsequence's elements are in sorted order, lowest
to highest, and in which the subsequence is as long as possible. This subsequence is not necessarily contiguous, or unique.

Note: Duplicate numbers are not counted as increasing subsequence.

For example:
 length of LIS for 
{ 10, 22, 9, 33, 21, 50, 41, 60, 80 } is 6 and LIS is {10, 22, 33, 50, 60, 80}.

 

Input:

The first line contains an integer T, depicting total number of test cases. 
Then following T lines contains an integer N depicting the size of array and next line followed by the value of array.


Output:

Print the Max length of the subsequence in a separate line.


Input
1
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
Output
6
*/