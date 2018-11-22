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

unordered_map<ll,ll> cnt;
vector<ll> s;
ll mx;
int len;

ll getsum(ll a){
	ll sum = 0;
	auto ind = lower_bound(s.begin(), s.end(),a);
	while(ind!=s.end()){
		sum += a;
		a *= 2;
		ind = lower_bound(ind+1, s.end(),a);
	}
	return sum;
}

int main(){
	// ios_base::sync_with_stdio(false);

	ll n;
	scanf("%lld",&n);
	ll x;
	for(int i=1;i<=n;i++){
		scanf("%lld",&x);
		if(cnt.find(x) == cnt.end())
			cnt[x] = 0;
		cnt[x]++;
	}
	for(auto it = cnt.begin();it!=cnt.end();it++){
		s.pb(it->second);
	}
	len = s.size();

	sort(s.begin(), s.end());
	// cout<<"Hello\n";

	mx = s[len-1];
	ll ans = 0,mxans=0;
	ll curpow = 1;
	for(ll a = 1;a<=n;a++){
		ans = getsum(a);
		if(ans == 0)
			break;
		mxans = max(ans,mxans);
	}
	cout<<mxans<<endl;



}