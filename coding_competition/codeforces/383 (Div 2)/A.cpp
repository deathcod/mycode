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

int main(int argc, char const *argv[])
{
    int a;
    cin >> a;
    if (a==0)
        cout << 1;
    else
    {
        int f =a %4;
        int x[5]={6,8,4,2};
        cout << x[f];
    }
    return 0;
}