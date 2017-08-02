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
	int c, v0, v1, a, l;
	cin >> c >> v0 >> v1 >> a >> l;

	int days = 1;
	c -= v0;
	while(c>0)
	{
		c += l;
		if(v0+a <v1)
			v0 += a;
		else
			v0 = v1;

		c -= v0;
		days++;
	}

	cout << days << "\n";
	return 0;
}