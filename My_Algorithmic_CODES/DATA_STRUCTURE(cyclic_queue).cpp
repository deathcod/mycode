/*
by chinmay
spoj ctrick;
implementation of cyclic queue
*/

#include <bits/stdc++.h>
using namespace std;
int min(int x,int y){return(x<y)?x:y;}
int max(int x,int y){return(x>y)?x:y;}
 
typedef pair<int,int> pp;
bool cmpfun(pp a,pp b)
{
    return(a.first<b.first);
}
int main(int argc, char const *argv[])
{
    int t,x;
    scanf("%d",&t);
    queue<int>q;
    std::vector<pp> v;
    while(t--)
    {
        scanf("%d",&x);
        for(int i=1;i<=x;i++)
            q.push(i);
        int i=1;
        while(!q.empty())
        {
            for(int j=1;j<=i;j++)
            {
                int f=q.front();
                q.pop();
                q.push(f);
            }
            pp xx;
            xx.first=q.front(),xx.second=i;
            v.push_back(xx);
            q.pop();
            i++;
        }
        for(int i=0;i<5;i++)
            printf("%d %d",v[i].second, v[i].second);
        sort(v.begin(),v.end(),cmpfun);
        for(int i=0;i<x;i++)
            printf("%d ",v[i].second);
        printf("\n");
        v.clear();
    }
    return 0;
}