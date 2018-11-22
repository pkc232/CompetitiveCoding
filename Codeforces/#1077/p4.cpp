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

#define NOV 500005

ll freq[NOV];
ll n,k;

int check(ll f){
	ll s =0;
	for(int i=1;i<NOV;i++){
		s += freq[i]/f;
	}
	return s>=k;
}

int main(){
	ios_base::sync_with_stdio(false);

	
	cin>>n>>k;
	ll x;
	for(int i=1;i<=n;i++){
		cin>>x;
		freq[x]++;
	}

	ll lo = 1, hi = n/k;
	ll mid,ans = 1;
	while(lo<=hi){
		mid = lo + (hi-lo)/2;
		if(check(mid)){
			ans = max(ans, mid);
			lo = mid+1;
		}
		else
			hi = mid-1;
	}
	// cout<<ans<<endl;
	// cout<<freq[1]<<" : "<<endl;

	int cnt = 0;
	for(int i = 1;i<NOV;i++){

		while(freq[i]-ans >= 0){
			cout<<i<<" ";
			cnt++;
			if(cnt==k)
				goto done;
			freq[i] -= ans;
		}
	}

	done:
	cout<<endl;
}