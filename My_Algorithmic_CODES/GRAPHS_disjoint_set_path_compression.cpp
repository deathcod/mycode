#include <bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
    return (a>b)?a:b;
}
int min(int a,int b)
{
    return (a<b)?a:b;
}
int find(int disjoint[],int x)
{
    if(disjoint[x]==x)
        return x;
    else 
        disjoint[x]=find(disjoint,disjoint[x]);
    return disjoint[x];
}
void unio(int disjoint[],int rank[],int x,int y)
{
    int val1=find(disjoint,x);
    int val2=find(disjoint,y);
    if(val1==val2)return;
    if(rank[val1]>rank[val2])
    {
        disjoint[val2]=val1;
        rank[val1]++;
    }
    else
    {
        disjoint[val1]=val2;
        rank[val2]++;
    }
}
int main()
{
    int n,m,disjoint[100005]={0},rank[100005]={0},x,y;
    scanf("%d %d",&n,&m);
    set<int>s;
    for(int i=1;i<=n;i++)
        disjoint[i]=i;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&x,&y);
        unio(disjoint,rank,x,y);
    }
    for(int i=1;i<=n;i++)
        s.insert(find(disjoint,i));
    printf("%lu",s.size());
    return 0;
}