/*
network flow 
ford fulkerson by chinmay Rakshit
date 18/11/2015
*/
#include <bits/stdc++.h>
using namespace std;
int min(int a,int b)
{
    return (a<b)?a:b;
}
int main()
{
    int n,m,adj[101][101]={0},x,y,z,scr,des,cost=0,parent[101]={0};//adjacent matrix
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        adj[x][y]=z;
    }
    scanf("%d %d",&scr,&des);
    while(1)
    {
        int flag=0;
        queue<int>q;
        q.push(scr);
        while(!q.empty())
        {
            int f=q.front();
            cout << f << "\n";
            q.pop();
            for(int i=1;i<=n;i++)
            {
                if(adj[f][i]!=0 && parent[i]==0 && i!=scr)
                {
                    parent[i]=f;
                    if(i==des)
                    {
                        flag=1;
                        while(!q.empty())
                            q.pop();
                        break;
                    }
                    q.push(i);
                }
            }
        }
        cout << "________________________\n";
        //BFS to find the parent.....
        if(flag!=1)
            break;
        int local=1e9,i;
        for(i=des;i!=1;i=parent[i])
            local=min(local,adj[parent[i]][i]);
        // to find the lowest in the augumented path
        cost+=local;
        for(i=des;i!=1;i=parent[i])
        {
            adj[parent[i]][i]-=local;
            adj[i][parent[i]]+=local;
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << "\n";
        }
        //making cancelation and addition to the flow.....
        memset(parent,0,(n+1)*sizeof(int));
    }
    //printf("%d\n",cost );
    return 0;
}