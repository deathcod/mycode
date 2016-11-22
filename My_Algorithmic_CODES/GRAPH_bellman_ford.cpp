/*
codemonk : monk's business day
bellman ford  
by chinmay rakshit 14/11/2015
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,m,n,visited[1001],v[1003][3];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(int i=0;i<=n;i++)
            visited[i]=-1002;
        visited[1]=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&v[i][0],&v[i][1],&v[i][2]);
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[v[j][1]]<visited[v[j][0]]+v[j][2])
                    visited[v[j][1]]=visited[v[j][0]]+v[j][2];
            }
        }
        int flag=0;
        for(int i=0;i<m;i++)
        {
            if(visited[v[i][1]]<visited[v[i][0]]+v[i][2])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}