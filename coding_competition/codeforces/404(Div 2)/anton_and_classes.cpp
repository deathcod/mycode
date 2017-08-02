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
	int n;
	int x1=2*1e9,y1 = 0,x2=2*1e9,y2 = 0,a,b;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a >> b;
		x1 = min(b,x1);

		y2 = max(a,y2);
	}
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a >> b;
		y1 = max(a,y1);

		x2 = min(b,x2);
	}
	int xx1 = y1 - x1;
	int xx2 = y2 - x2;

	int ac = max(xx1, xx2);
	if(ac>0)
		cout << ac << "\n";
	else
		cout << 0 << "\n";
	return 0;
}