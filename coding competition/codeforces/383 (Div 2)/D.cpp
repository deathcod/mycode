#include <bits/stdc++.h>
using namespace std;
#ifndef M
#define M 1000000007
#endif
typedef pair<int,int>pp;
typedef std::vector<pp> vpp;
typedef long long ll;
#ifndef pb
#define pb push_back 
#endif 
int min(int x,int y){return(x<y)?x:y;}
int max(int x,int y){return(x>y)?x:y;}

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

int dp[1003][1003] = {0};
int main(int argc, char const *argv[])
{
    int n,m,w,x,y;
    scanf("%d %d %d",&n,&m,&w);

    int weight[1003],beauty[1003];
    int disjoint[1003]={0},rank[1003]={0};
    for(int i=1;i<=n;i++)
        disjoint[i]=i;

    for (int i = 1; i <= n; ++i)
        scanf("%d",&weight[i]);

    for (int i = 1; i <= n; ++i)
        scanf("%d",&beauty[i]);

    for (int i = 0; i < m; ++i)
    {
        scanf("%d %d",&x,&y);
        unio(disjoint, rank, x, y);
    }

    std::map<int, std::vector<int> > map;
    for (int i = 1; i <= n; ++i)
    {
        map[find(disjoint,i)].pb(i);
    }

    int max_weight[1003]={0},max_beauty[1003]={0};

    /*
    //testing disjoint
    for(std::map<int, std::vector<int> > :: iterator it = map.begin(); it!= map.end();it++)
    {
        printf("%d : ",it->first );
        std::vector<int> v = it->second;
        for (int i = 0; i < v.size(); ++i)
            cout << v[i] << " ";
        cout << "\n";
    }
    */
    /*
    max weight and beauty for a particular group calculated.
    */
    for(std::map<int, std::vector<int> > :: iterator it = map.begin(); it!= map.end();it++)
    {
        int we = 0;
        int sum = 0;
        std::vector<int> v = it->second;
        int length = v.size();
        for (int i = 0; i < length; ++i)
        {
            sum +=  beauty[v[i]];
            we +=weight[v[i]];
        }
        max_weight[it->first] = we;
        max_beauty[it->first] = sum;
    }

    /*Calculate the weight for wth size array*/
    int map_count = 1;
    for(std::map<int, std::vector<int> > :: iterator it = map.begin(); it!= map.end();it++)
    {
        std::vector<int> v = it->second;
        int length = v.size();
        for (int i = 0; i < length; ++i)
        {
            for (int j = 1; j <= w; ++j)
            {
                if(weight[v[i]] <=j)
                    dp[map_count][j] = max(dp[map_count][j],max(dp[map_count-1][j],(beauty[v[i]]+
                                                                  dp[map_count-1][j- weight[v[i]]])));
                else
                    dp[map_count][j] = max(dp[map_count][j],dp[map_count-1][j]);
            }   
        }
        for (int i = 1; i <= w; ++i)
        {
            if(max_weight[it->first] <=i)
                dp[map_count][i] = max(dp[map_count][i],max(dp[map_count-1][i],(max_beauty[it->first] +
                                                                  dp[map_count-1][i- max_weight[it->first]])));
        }
        map_count++;
        /*
        // testing the dp for the weight/vs beauty in dpp
        for (int i = 0; i <= w ; ++i)
        {
            printf("%d, ",dp[map_count-1][i]);
        }
        printf("\n");
        */
    }
    printf("%d\n",dp[map_count-1][w] );

    return 0;
}