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

#define NOV 300005
vector<pair<ll,ll> > v(NOV);
ll sum[NOV];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	ll x;
	for(int i=1;i<=n;i++){
		cin>>x;
		v[i] = mp(x,i);
	}

	sort(v.begin()+1, v.begin()+n+1);

	sum[0] = 0;
	ll totsum = 0;
	for(int i=1;i<=n;i++){
		sum[i] = sum[i-1] + v[i].ff;
		totsum += v[i].ff;
	}
	ll cursum,remsum;
	vector<int> ans;
	for(int i=1;i<n;i++){
		cursum = totsum-v[i].ff;
		remsum = cursum - v[n].ff;
		if(remsum==v[n].ff){
			ans.pb(v[i].ss);
			// cout<<v[i].ss<<" ";
		}
	}

	cursum = totsum - v[n].ff;
	remsum = cursum - v[n-1].ff;
	if(remsum==v[n-1].ff)
		ans.pb(v[n].ss);
	cout<<ans.size()<<endl;

	for(int v:ans)
		cout<<v<<" ";
	cout<<endl;

}