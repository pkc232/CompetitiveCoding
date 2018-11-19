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


int n,l;
vector<int> adj[NOV];

int timer = 0;
int tin[NOV], tout[NOV];
int up[NOV][25];

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
	int cnt = 0;
	for(int i=l;i>=0;i--){
		if(!is_ancestor(up[u][i],v)){
			u = up[u][i];
			cnt += pow(2,i);
		}
	}
	cnt++;
	cout<<"above u "<<cnt<<endl;
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

int main(){
	ios_base::sync_with_stdio(false);
	int t,m,x;
	cin>>t;
	int tc=0;
	while(t--){
		tc++;
		cin>>n;
		for(int i=1;i<=n;i++){
		adj[i].clear();
		cin>>m;
		while(m--){
			cin>>x;
			adj[i].pb(x);
		}
	}

	int q;
	cin>>q;

	preprocess(1);
	cout<<"Case "<<tc<<":"<<endl;
	while(q--){
		int v,w;
		cin>>v>>w;
		cout<<get_lca(v,w)<<endl;
		}		
	}
}