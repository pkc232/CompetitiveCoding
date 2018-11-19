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


pair<ll, ll> fib (ll n) {
    if (n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    ll c = p.first * (2 * p.second - p.first);
    ll d = p.first * p.first + p.second * p.second;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}

int main(){
	ios_base::sync_with_stdio(false);

	int t;
	cin>>t;
	ll n;
	while(t--){
		cin>>n;
		auto p = fib(n);
		ll fn = p.ff;
		ll fn1 = p.ss;
		// ll fn2 = fn + fn+1;
		// cout<<fn<<" "<<fn1<<" "<<fn2<<endl;
		ll s = fn+fn1;
		cout<<s<<endl;
	}
}