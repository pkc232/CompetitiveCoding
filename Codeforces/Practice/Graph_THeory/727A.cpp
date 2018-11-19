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

unordered_map<ll,ll> dist;
unordered_map<ll,ll> par;
ll a,b;

int possible(ll x){
	if(x<=b&&dist.find(x)==dist.end())
		return 1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);

	
	cin>>a>>b;

	queue<ll> Q;
	Q.push(a);
	ll t,nt;
	dist[a] = 0;
	par[a] = -1;
	int fl=0;
	while(!Q.empty()){
		t = Q.front();
		Q.pop();
		if(t==b)
		{	
			fl = 1;
			break;
		}

		nt = t*2;
		if(possible(nt)){
			Q.push(nt);
			dist[nt] = dist[t] + 1;
			par[nt] = t;
		}

		nt = t*10+1;
		if(possible(nt)){
			Q.push(nt);
			dist[nt] = dist[t] + 1;
			par[nt] = t;
		}
	}

	if(fl){
		cout<<"YES\n";
		cout<<dist[b]+1<<endl;
		ll u = b;
		vector<ll> v;
		while(u!=-1){
			// cout<<u<<" ";
			v.pb(u);
			u = par[u];
		}
		reverse(v.begin(), v.end());
		for(ll x:v)
			cout<<x<<" ";
		cout<<endl;
	}
	else
	{
		cout<<"NO\n";
	}
}