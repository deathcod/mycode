/*job scheduling 
By chinmay Rakshit
date: 20/11/2015
*/
#include <bits/stdc++.h>
using namespace std;
typedef struct $
{
    int first,second,index;   
}ss;
bool cmpfun(ss x,ss y)
{
    if(x.first==y.first)
        return(x.second>y.second);
    return(x.first<y.first);
}
int min(int a,int b)
{
    return (a<b)?a:b;
}
int main()
{
    int n,m,x,y;
    scanf("%d %d",&n,&m);
    std::vector< ss > v(m+1),u(m+1);
    v[0].first=0;
    v[0].second=0;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&x,&y);
        v[i].first=x;
        v[i].second=y;
        v[i].index=i;
        u[i].first=x;
        u[i].second=y;
    }
    // making two array one sorted in a special way and another unsorted 
    sort(v.begin(),v.end(),cmpfun);
    int pos[101]={0};
    for(int i=1;i<=m;i++)
    {
        int k=min(v[i].first,n);
        /*
        here to check the minimum index it may happen the time is
        less than the time of a specific task to complete check the 
        second input output
        */ 
        if(pos[k]==0)
            pos[k]=v[i].index;
        else
        {
            for(int j=1;j<=k;j++)
                if(u[pos[j]].second<v[i].second)
                    pos[j]=v[i].index;
        }
        printf("%d\n",pos[k] );
    }
    for(int i=1;i<=n;i++)
        printf("%d,",pos[i]);
    printf("\n");
    return 0;
}
/*
input
3 5         2 4
2 100       4 20
1 19        1 10
2 27        1 40
1 25        1 30
3 15
output      output
3,1,5       3,1
*/