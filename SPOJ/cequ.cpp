#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define pii pair<int,int>
#define large_int 2139062143
#define large_long_long_int 9187201950435737471
using namespace std;

#define NOV 100005


int main(){
	ios_base::sync_with_stdio(false);

	int t;
	cin>>t;
	int a,b,c,g;
	for(int ti = 1;ti<=t;ti++){
		cin>>a>>b>>c;
		g = __gcd(a,b);
		cout<<"Case "<<ti<<": ";
		if(c%g)
		{
			cout<<"No\n";
		}
		else
		{
			cout<<"Yes\n";
		}

	}
}