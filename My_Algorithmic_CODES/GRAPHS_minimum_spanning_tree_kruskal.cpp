/*
by chinmay rakshit
date 31/10/2015
*/
#include <bits/stdc++.h>
using namespace std;
typedef struct $
{
    int v,u,wt;
}bla;
bool cmpfun(bla x,bla y)
{
    return(x.wt>y.wt);
}
int find(int disjoint[],int x)
{
    if(disjoint[x]==x)
        return x;
    disjoint[x]=find(disjoint,disjoint[x]);
    return disjoint[x];
}
bool unio(int disjoint[],int rank[],int x,int y)
{
    int val1=find(disjoint,x);
    int val2=find(disjoint,y);
    if(val1==val2)return false;
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
    return true;
}
int main()
{
    int t,a,b,disjoint[5005];
    scanf("%d",&t);
    while(t--)
    {
        int sum=0,x,y,z,rank[5005]={0};
        scanf("%d %d",&a,&b);
        for(int i=1;i<=a;i++)
            disjoint[i]=i;
        vector<bla>V;
        for(int i=0;i<b;i++)
        {
            scanf("%d %d %d",&x,&y,&z);
            bla Z;
            Z.v=x;
            Z.u=y;
            Z.wt=z;
            V.push_back(Z);
        }
        sort(V.begin(),V.end(),cmpfun);
        for(int i=0;i<b;i++)
        {
            bla z=V[i];
            if(unio(disjoint,rank,z.v,z.u))
                sum+=z.wt;
        }
        printf("%d\n",sum);
    }
    return 0;
}
