/*
dijiskra algorithm
by chinmay rakshit on 14/11/2015
code monk:
Mittal wants to go to play!
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;
int main()
{
    int t,n,m,x,y,z,cost;
    scanf("%d",&t);
    set< pp >q;
    while(t--)
    {
        scanf("%d %d",&n,&m);
        vector<vector< pp> >v(n+1);
        int visited[10004]={0};
        for(int i=2;i<=n;i++)
            visited[i]=1e9;
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&x,&y,&z);
            pp f;
            f.first=y,f.second=z;
            v[x].push_back(f);
            f.first=x;
            v[y].push_back(f);
        }
        q.insert(pp(1,0));
        while(!q.empty())
        {
            pp f=*q.begin();
            q.erase(q.begin());
            x=f.first;
            int len=v[x].size();
            for(int i=0;i<len;i++)
            {
                if(visited[v[x][i].first]>visited[x]+v[x][i].second && v[x][i].first!=1)
                {
                    pp w;
                    w.first=v[x][i].first;
                    w.second=visited[v[x][i].first];
                    while(q.find(w)!=q.end())
                        q.erase(q.find(w));
                    visited[v[x][i].first]=visited[x]+v[x][i].second;
                    w.second=visited[v[x][i].first];
                    q.insert(w);
                }
            }
        }
        scanf("%d",&z);
        while(z--)
        {
            scanf("%d %d",&x,&y);
            if(2*visited[x]<y)
                printf("%d\n",y-2*visited[x]);
            else
                printf("0\n");
        }
    }
    return 0;
}
