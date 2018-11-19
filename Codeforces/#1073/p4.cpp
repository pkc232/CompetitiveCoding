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


int main(){
	ios_base::sync_with_stdio(false);
	ll n,T;
	cin>>n>>T;

	ll arr[n+5];
	vector<ll> v1,v2;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		v1.pb(arr[i]);
	}
	ll cnt = 0;


	while(1){
		ll s = 0;
		ll c = 0;
		for(ll v:v1){
			if(v<=T-s){
				v2.pb(v);
				c++;
				s += v;
			}
		}
		if(c==0)
		{
			break;
		}
		else
		{
			cnt += c*(T/s);
			T = T%s;
		}
		if(T==0)
			break;
		// cout<<cnt<<" "<<T<<" "<<s<<endl;
		v1=v2;
		v2.clear();
	}
	
	cout<<cnt<<endl;



}