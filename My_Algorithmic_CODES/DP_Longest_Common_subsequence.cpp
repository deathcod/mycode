#include <bits/stdc++.h>
using namespace std;

int max(int x,int y){return (x>y)?x:y;}
int main() {
    string A,B;
    int n;
    cin >> n;
    while(n--)
    {
        int dp[100][100]={0},len1,len2;
        cin >> len1 >> len2;
        cin >> A;
        cin >> B;
        //cout << A << B;
        for(int i=1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                if (A[i-1] == B[j-1])
                    dp[i][j] = max(dp[i][j],1 + dp[i-1][j-1]);
                
            }
        }
        cout << dp[len1][len2] << "\n";
    }
    return 0;
}

/*
in
---
2
6 6
ABCDGH
AEDFHR
3 2
ABC
AC
====================
Out
---
3
2
*/