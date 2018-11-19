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

vector<pair<int,ll> > gr[NOV];
ll in[NOV];
ll out[NOV];

void dfs1(int u, int p){
	for(auto c:gr[u]){
		if(c.ff!=p){
			dfs1(c.ff,u);
			in[u] = max(in[u],c.ss+in[c.ff]);
		}
	}
}

void dfs2(int u, int p){
	ll mx1=0,mx2=0;
	for(auto c:gr[u]){
		if(c.ff!=p){
			if(in[c.ff]+c.ss>=mx1){
				mx2 = mx1;
				mx1 = in[c.ff] + c.ss;
			}
			else if(in[c.ff]+c.ss>=mx2)
				mx2 = in[c.ff] + c.ss;;
		}
	}
	// cout<<u<<" "<<p<<" "<<mx1<<" "<<mx2<<endl;
	ll use = 0;
	for(auto c:gr[u]){
		if(c.ff!=p){
			use = mx1;
			if(use == in[c.ff] + c.ss)
				use = mx2;
			out[c.ff] = max(out[c.ff], c.ss+use);
			out[c.ff] = max(out[c.ff], c.ss+out[u]);
			// cout<<c.ff<<" : "<<out[c.ff]<<" "<<c.ss<<" "<<" "<<u<<" : "<<out[u]<<endl;
			dfs2(c.ff,u);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);

	int n,u,v;
	ll w;

	int t;
	cin>>t;

	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			gr[i].clear();

		for(int i=1;i<n;i++){
			cin>>u>>v>>w;
			gr[u].pb(mp(v,w));
			gr[v].pb(mp(u,w));
		}
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		dfs1(1,-1);
		dfs2(1,-1);
		// for(int i=1;i<=n;i++)
		// 	cout<<in[i]<<" "<<out[i]<<endl;
		// cout<<endl;
		for(int i=1;i<=n;i++)
			cout<<max(in[i],out[i])<<" ";
		cout<<endl;
	}
}