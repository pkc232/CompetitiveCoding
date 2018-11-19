#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define MOD 1000000007
#define mp make_pair
using namespace std;


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	

	ll x,y;
	cin>>x>>y;
	ll cop = y-1;
	if(y==0)
		goto no;

	
	if(cop==0&&x==0)
		goto yes;
	else if(cop==0&&x!=0)
		goto no;
	else{
		if(cop>x)
			goto no;

		if((cop%2)==(x%2))
			goto yes;
		else
		goto no;
	}

	yes:
	cout<<"Yes\n";
	return 0;

	no:
	cout<<"No\n";
	return 0;
}