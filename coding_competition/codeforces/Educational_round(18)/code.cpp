#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll min(ll x, ll y)
{
	return (x<y)?x:y;
}
int main(int argc, char const *argv[])
{
	int n,k,x;
	int a[2* 101] = {0};
	cin >> n >> k;
	cout << "\n";
	int start = 1;
	for (int i = 1; i <= k; ++i)
	{
		cin >> x;
		int index = (start + x) % n;
		cout << index << " ";
		if (index ==0)
			index = n;
		start = index;
		int c= 0;
		for(int j=1; j <=n; j++)
		{
			if(a[j]==0)
				c++;
			if(c==index)
			{
				a[j]=1;
				//cout << j << " ";
				break;
			}
		}
		n--;
	}
	cout <<"\n";
	return 0;
}