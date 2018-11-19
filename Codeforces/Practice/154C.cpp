#include <bits/stdc++.h>
#include <functional>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000009
#define pii pair<int,int>
#define large_int 2139062143
#define large_long_long_int 9187201950435737471

using namespace std;

#define NOV 1000005


unordered_map<ll,ll> hash1;
unordered_map<ll,ll> hash2;
vector<ll> gr[NOV]; 

ll gen(ll i) {
    return 9237477 * i * i * i * i * i + 2347189 * i * i * i * i + 8717127 * i * i * i + 128615331 * i * i + 9981717 * i + 13;
}

ll hash_and_store(vector<ll> &v){
	
	ll s = 0;
	for(ll i:v)
		s += gen(i);
	return s;
}


int main(){
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	int a,b;
	while(m--){
		cin>>a>>b;
		gr[a].pb(b);
		gr[b].pb(a);
	}
	ll x1,x2;
	for(int i=1;i<=n;i++){
		x1 = hash_and_store(gr[i]);
		gr[i].pb(i);
		x2 = hash_and_store(gr[i]);

		hash1[x1]++;
		hash2[x2]++;
	}
	ll cnt = 0;
	for(auto it = hash1.begin();it!=hash1.end();it++){
		ll c = it->second;
		cnt += (c*(c-1))/2;
	}

	for(auto it = hash2.begin();it!=hash2.end();it++){
		ll c = it->second;
		cnt += (c*(c-1))/2;
	}
	
	cout<<cnt<<endl;

}