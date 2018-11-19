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

ll binpow(ll a, ll b) {
    ll res = 1;
    if(a<0||b<0)
    	return res;
    while (b > 0) {
    	// a %= MOD;
        if (b & 1){
            res = (((res) * (a)));
            // res %= MOD;
        }
        a = (a*a);
        // a %= MOD;
        b >>= 1;
    }
    return (res);
}

int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;

	ll x1 = binpow(4,n-4);
	ll x2 = binpow(4,n-3);

	ll t1 = 4*(n-3)*(x1)*3*3;
	ll t2 = 4*2*x2*3;
	ll res = t1+t2;

	cout<<res<<endl;
	return 0;
}