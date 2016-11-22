/*
graph coloring(vertex coloring)
Welsh-powell algorithm...
by chinmay Rakshit
date: 20/11/2015
*/
#include <bits/stdc++.h>
using namespace std;
bool cmpfun(pair<int,int>x,pair<int,int>y)
{
    return(x.first>y.first);
}
int main()
{
    int x,y,n,m,visited[100]={0};
    scanf("%d %d",&n,&m);
    std::vector<std::vector<int> > v(n+1);
    std::vector<pair<int,int> > degree(n+1);
    for(int i=1;i<=n;i++)
    {
        degree[i].first=0;
        degree[i].second=i;
    }
    pair<int,int>pp;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
        degree[x].first++;
        degree[y].first++;
    }
    sort(degree.begin(),degree.end(),cmpfun);
    /*for(int i=0;i<n;i++)
        printf("%d %d\n",degree[i].second,degree[i].first);*/
    set<int>s;
    int col=1;
    while(1)
    {
        for(int i=0;i<n;i++)
        {
            if(visited[degree[i].second]==0 && s.find(degree[i].second)==s.end())
            {
                visited[degree[i].second]=col;
                s.insert(v[degree[i].second].begin(),v[degree[i].second].end());
            }
        }
        if(s.empty())
            break;
        s.clear();
        col++;
    }
    /*for(int i=0;i<n;i++)
        printf("%d,",visited[degree[i].second] );*/
    /*for(int i=1;i<=n;i++)
        printf("%d,",visited[i] );*/
    //printf("\n");
    printf("%d\n",col-1);
    return 0;
}