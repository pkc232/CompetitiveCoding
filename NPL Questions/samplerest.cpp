#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define all(v) v.begin(),v.end()
#define rev(v) reverse(v.begin(),v.end())
#define MOD 1000000007
vector<pair<ll,ll> >v;
int main()
{
	int t;
	cin>>t;
	while(t--) {
		int m;
		cin>>m;
		int ans = 0;
		for(int i=0;i<m;i++) {
			ll l, r;
			cin>>l>>r;
			v.pb(mp(l,r));
		}
		sort(all(v));
		rev(v);
		ll anss = -1e18, ansss= -1e18;
		//for(auto x: v) cout<<x.fi<<" "<<x.se<<"\n";
		//cout<<"\n";
		for(int i=0;i<v.size();i++) {
			cout<<anss<<" "<<v[i].se<<endl;
			if(anss <= v[i].se) ans++;
			if(i+1 < v.size() && v[i+1].fi != v[i].fi) {
				anss = max(anss, max(ansss, v[i].se));
			}
			else ansss = max(ansss, v[i].se);
			cout<<i<<" "<<ans<<" "<<ansss<<"\n";
		}
		cout<<ans<<"\n";
		v.clear();
	}
	return 0;
}