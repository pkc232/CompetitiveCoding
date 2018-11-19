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

#define NOV 400005


int n,l;
vector<int> adj[NOV];

int timer = 0;
int tin[NOV], tout[NOV];
int up[NOV][25];
ll val[NOV];


void dfs(int u, int p){
	tin[u] = ++timer;
	up[u][0] = p;
	for(int i=1;i<=l;i++){
		up[u][i] = up[up[u][i-1]][i-1];
	}

	for(int v:adj[u]){
		if(v!=p)
			dfs(v,u);
	}

	tout[u] = ++timer;
}

//checks whether u is an ancestor of v
int is_ancestor(int u, int v){
	if(tin[u]<=tin[v] && tout[u]>=tout[v])
		return 1;
	return 0;
}

int get_lca(int u, int v){
	if(is_ancestor(u,v))
		return u;
	if(is_ancestor(v,u))
		return v;

	for(int i=l;i>=0;i--){
		if(!is_ancestor(up[u][i],v))
			u = up[u][i];
	}
	return up[u][0];
}

void preprocess(int root){
	memset(tin,0,sizeof(tin));
	memset(tout,0,sizeof(tout));
	timer = 0;
	l = ceil(log2(n));
	// cout<<l<<" pp"<<endl;
	dfs(root,root);
}

pii getans(int u, int anc){
	int lv1 = level[u];
	int lv2 = level[anc];

	int dep = lv1-lv2;
	// cout<<dep<<endl;
	int mn = large_int, mx = -large_int;
	int c = 0;
	while(dep){
		if(dep&1){
			// cout<<"ok "<<u<<" : "<<c<<" "<<up[u][c].nd<<endl;
			// cout<<up[u][c].mn<<" "<<up[u][c].mx<<endl;
			mn = min(mn, up[u][c].mn);
			mx = max(mx, up[u][c].mx);
			u = up[u][c].nd;
		}
		dep>>=1;
		c++;
	}
	return mp(mn,mx);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin>>n;

	ll u,v;

	for(int i=1;i<n;i++){
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	int q;
	cin>>q;

	ll ;
	while(q--){
		cin>>x>>y>>v;

	}

}