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
	int n,m;
	cin >> n >> m;
	int a[10004]= {0};
	for(int j=1;j<=n;j++)
		a[j]=10;
	
	for(int i=0; i<m; i++)
	{
		int x,y;
		cin >> x;
		if(x == 1)
		{
			cout << "YES\n";
			return 0;
		}
		int ignore_flag = 0;
		for(int j=0 ;j<x;j++)
		{
			cin >> y;
			int f_y = int(fabs(y));
			if(a[f_y] == 10)
			{
				//cout << a[f_y] << " " << f_y << "\n";
				a[f_y] = (y<0)?-1:1;
				//cout << a[f_y] << " " << f_y << "--\n";
			}
			else if( (a[f_y]<0 and y>0) or (a[f_y]>0 and y<0))
			{
				ignore_flag =1;
			}
		}
		for(int j=1;j<=n;j++)
		{
			a[j]=10;
		}
		if(ignore_flag ==1)
		{
			continue;
		}
		cout << "YES\n";
		return 0;
	}
	cout << "NO\n";
	return 0;
}