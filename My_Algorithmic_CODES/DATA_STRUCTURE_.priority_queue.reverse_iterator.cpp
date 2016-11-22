/*
by chinmay rakshit
on 3 jan,2016
spoj expedi
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


int a[100000][2];
int main(int argc, char const *argv[])
{
    int t,n,x,y;
    scanf("%d",&t);
    std::vector<pp> v;
    while(t--)
    {
        priority_queue<int> q;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&x,&y);
            v.push_back(pp(x,y));
        }
        sort(v.begin(),v.end());
        std::vector<pp> :: reverse_iterator it=v.rbegin();
        scanf("%d %d",&x,&y);
        int c=0,flag=0,dis=x-y;
        while(1)
        {
            if(dis<=0)
            {
                printf("%d\n",c );
                flag=1;
                break;
            }
            else if(it!=v.rend() && dis<=it->first)
            {
                q.push(it->second);
                it++;
            }
            else
            {
                if(!q.empty())
                {
                    dis-=q.top();
                    q.pop();
                    c++;
                }
                else
                    break;
            }
        }
        if(flag==0)
            printf("-1\n");
        v.clear();
    }
    return 0;
}