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

int level[NOV];

struct node{
	int nd;
	int mn;
	int mx;
};


int n,l;
vector<int> adj[NOV];
map<pair<int,int>,int> edge;

int timer = 0;
int tin[NOV], tout[NOV];
node up[NOV][25];

void dfs(int u, int p, int lev){
	tin[u] = ++timer;
	up[u][0].nd = p;
	level[u] = lev;
	if(p==u)
	{
		up[u][0].mn = large_int;
		up[u][0].mx = -large_int;
	}
	else
	{
		up[u][0].mn = edge[mp(u,p)];
		up[u][0].mx = edge[mp(u,p)];
	}
	// cout<<"For "<<u<<endl;
	// cout<<up[u][0].mn<<" "<<up[u][0].mx<<endl;
	for(int i=1;i<=l;i++){

		up[u][i].nd = up[up[u][i-1].nd][i-1].nd;
		up[u][i].mn = min(up[u][i-1].mn, up[up[u][i-1].nd][i-1].mn);
		up[u][i].mx = max(up[u][i-1].mx, up[up[u][i-1].nd][i-1].mx);
		// cout<<up[u][i].mn<<" "<<up[u][i].mx<<endl;
	}

	for(int v:adj[u]){
		if(v!=p)
			dfs(v,u,lev+1);
	}

	tout[u] = ++timer;
}

//checks whether u is an ancestor of v
int is_ancestor(int u, int v){
	// cout<<tin[u]<<" "<<tin[v]<<" "<<tout[u]<<" "<<tout[v]<<endl;
	if(tin[u]<=tin[v] && tout[u]>=tout[v])
		return 1;
	return 0;
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

int get_lca(int u, int v){
	if(is_ancestor(u,v))
		return u;
	if(is_ancestor(v,u))
		return v;
	// cout<<"Hello\n";
	for(int i=l;i>=0;i--){
		if(!is_ancestor(up[u][i].nd,v))
			u = up[u][i].nd;
	}
	return up[u][0].nd;
}

void preprocess(int root){
	memset(tin,0,sizeof(tin));
	memset(tout,0,sizeof(tout));
	timer = 0;
	l = ceil(log2(n));
	// cout<<l<<" pp"<<endl;
	dfs(root,root,1);
}

int main(){
	// ios_base::sync_with_stdio(false);

	int u,v,w;
	scanf("%d",&n);

	for(int i=1;i<n;i++){
		scanf("%d",&u);
		scanf("%d",&v);
		scanf("%d",&w);
		edge[mp(u,v)] = edge[mp(v,u)] = w;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	preprocess(1);
	up[1][0].nd = 1;
	up[1][0].mn = large_int;
	up[1][0].mx = -large_int;
	int q;
	scanf("%d",&q);
	while(q--){
		scanf("%d",&u);
		scanf("%d",&v);
		int anc = get_lca(u,v);
		// cout<<"Ancestor "<<anc<<endl;
		pii p1,p2;
		p1.ff = p2.ff = large_int;
		p1.ss = p2.ss = -large_int;
		if(u!=anc)
			p1 = getans(u,anc);
		if(v!=anc)
			p2 = getans(v,anc);
		// cout<<p1.ff<<" "<<p1.ss<<endl;
		// cout<<p2.ff<<" "<<p2.ss<<endl;
		int mn = min(p1.ff,p2.ff), mx = max(p1.ss,p2.ss);  
		printf("%d %d\n",mn,mx);
	}
}