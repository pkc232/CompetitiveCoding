#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

int n;
ll h[10007];
ll c[10007];

ll f(ll ht){
	ll cost = 0;
	for(int i=1;i<=n;i++)
		cost+=abs(h[i]-ht)*c[i];
	return cost;
}

int main(){
	ios_base::sync_with_stdio(false);


	int t,i;
	cin>>t;
	while(t--){
		cin>>n;
		ll mx = 0;
		for(i=1;i<=n;i++){
			cin>>h[i];
			mx=max(mx,h[i]);
		}
		for(i=1;i<=n;i++)
			cin>>c[i];

		ll lo=0,hi=mx,mid1,mid2;
		ll ans = LONG_MAX;
		ll v1,v2;
		while(lo<hi){
			mid1 = lo + (hi-lo)/3;
			mid2 = hi - (hi-lo)/3;
			v1 = f(mid1);
			v2 = f(mid2);

			ans = min(ans,v1);
			ans = min(ans,v2);

			if(v1>v2)
				lo = mid1+1;
			else
				hi = mid2-1;

		}
		cout<<ans<<endl;
	}
}