/*
fractional knapsack
by chinmay Rakshit
date : 20/11/2015
*/

#include <bits/stdc++.h>
using namespace std;
bool cmpfun(pair<int ,int> x,pair<int ,int > y)
{
    return(x.first>y.first);
}
int main()
{
    int n,m,x,y;
    scanf("%d %d",&n,&m);
    std::vector< pair<double,int> > v(m+1);
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&x,&y);
        v[i].first=(double)y/x;
        v[i].second=x;
    }
    sort(v.begin(),v.end(),cmpfun);
    int i=0;
    double cost=0;
    while(n)
    {
        if(v[i].second<=n)
        {
            cost+=v[i].first*v[i].second;
            n=n-v[i].second;
        }
        else
        {
            cost+=v[i].first*n;
            n=0;
        }
        i++;
    }
    printf("%lf\n",cost );
    return 0;
}