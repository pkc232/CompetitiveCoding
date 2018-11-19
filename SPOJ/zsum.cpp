#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 10000007
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
    	a %= MOD;
        if (b & 1){
            res = (((res) * (a)));
            res %= MOD;
        }
        a = (a*a);
        a %= MOD;
        b >>= 1;
    }
    return (res%MOD);
}

int main(){
	ios_base::sync_with_stdio(false);

	ll n,k;
	while(1){
		cin>>n>>k;
		if(n==0&&k==0)
			return 0;
		ll x1 = binpow(n,k);
		ll x2 = binpow(n-1,k);
		ll y1 = binpow(n,n);
		ll y2 = binpow(n-1,n-1);
		ll s = x1+2*x2+y1+2*y2; 
		cout<<(s%MOD)<<endl;
	}

}