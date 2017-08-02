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
	int b,q,l,m;
	cin >> b >>q >>l >> m;
	set<int> s;
	for (int i = 0; i < m; ++i)
	{
		int x;
		cin >> x;
		s.insert(x);
	}
	if(abs(b)> l)
	{
		cout << "0\n";
		return 0;
	}
	if ( b == 0 or q == 0 )
	{
		if(s.find(b) == s.end())
		{
			if(s.find(0) == s.end())
				cout << "inf\n";
			else
				cout << "1\n";
		}
		else
		{
			if(s.find(0) == s.end())
				cout << "inf\n";
			else
				cout << "0\n";
		}
		return  0;
	}

	if (q == 1)
	{
		if(s.find(b) == s.end() and abs(b) <= l)
			cout << "inf\n";
		else
			cout << "0\n";
		return  0;
	}

	if(q == -1)
	{
		if(s.find(b) == s.end() or s.find(b*-1) == s.end() and abs(b) <= l)
			cout << "inf\n";
		else
			cout << "0\n";
		return  0;
	}

	int count = 0;
	ll x = b;
	while(abs(x)<=l)
	{
		if(s.find(x) == s.end())
			count++;
		x *= q;
	}
	cout << count << "\n";
	return 0;
}