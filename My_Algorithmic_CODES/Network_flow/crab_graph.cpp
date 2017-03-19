#include <bits/stdc++.h>
using namespace std;
int min(int a,int b)
{
    return (a<b)?a:b;
}
int ford_fulkerson(int scr, int des, int adj[300][300], int n)
{
    int cost=0,parent[300]; //adjacent matrix
    while(1)
    {
        memset(parent,-1,sizeof(parent));
        int flag = 0;
        queue<int>q;
        q.push(scr);
        while(!q.empty())
        {
            int f=q.front();
            //cout << f << "\n";
            q.pop();
            for(int i=0;i<n;i++)
            {
                if(adj[f][i]!=0 && parent[i]==-1 && i!=scr)
                {
                    parent[i]=f;
                    if(i==des)
                    {
                        flag=1;
                        //cout << f << "\n";
                        while(!q.empty())
                            q.pop();
                        break;
                    }
                    q.push(i);
                }
            }
        }
        /*cout << "____________________\n";
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << "\n";
        }*/
        //BFS to find the parent.....
        if(flag!=1)
            break;
        int local=1e9,i;
        for(i=des;i!=scr;i=parent[i])
            local=min(local,adj[parent[i]][i]);
        // to find the lowest in the augumented path
        cost+=local;
        for(i=des;i!=scr;i=parent[i])
        {
            adj[parent[i]][i]-=local;
            adj[i][parent[i]]+=local;
        }
        //making cancelation and addition to the flow.....
        //cout << "fuck cost" << cost << "\n";
       
    }
    return cost;
}
int main(int argc, char const *argv[])
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,x,y,z,fk;
        scanf("%d %d %d",&n,&fk,&m);
        int N = 2*n +2;
        int scr = 0;
        int des = N-1;
        int adj[300][300] = {0};
        for(int i=0;i<m;i++)
        {
            scanf("%d %d",&x,&y);
            adj[x][y+n] = adj[y][x+n] = n;
        }
        for(int i=1; i<=n; i++)
        {
            adj[scr][i] = fk;
            adj[i+n][des] = 1;
        }
        cout << ford_fulkerson(scr, des, adj, N) << "\n";
    }
    return 0;
}