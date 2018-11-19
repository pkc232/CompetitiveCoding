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
    a %= 10;
    while (b > 0) {
        if (b & 1){
            res = res * a;
            res %= 10;
        }
        a = ((a * a)%10);
        b >>= 1;
    }
    return (res%10);
}

int main(){
	ios_base::sync_with_stdio(false);

	int t;
	cin>>t;

	ll a,b;
	while(t--){
		cin>>a>>b;
		cout<<binpow(a,b)<<endl;
	}


}