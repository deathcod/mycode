/*
floyd warshal
by chinmay rakshit 7/1/2016
Free Tickets codechef
input
4 5
1 2 10
1 3 24
2 3 2
2 4 15
3 4 7
output
19
*/

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;
int min(int x,int y){return(x<y)?x:y;}
int max(int x,int y){return(x>y)?x:y;}


int a[233][233];
int main(int argc, char const *argv[])
{
    int t,n,x,y,z;
    scanf("%d %d",&n,&t);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            a[i][j]=1e9;
    for(int i=1;i<=n;i++)
        a[i][i]=0;
    for(int i=0;i<t;i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        a[x][y]=z;
        a[y][x]=z;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    x=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            x=max(a[i][j],x);
    printf("%d\n",x);
    return 0;
}