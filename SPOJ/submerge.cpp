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


vector<int> gr[NOV];
int vis[NOV];
int tin[NOV];
int fup[NOV];
int tim = 0;
int cutpoint[NOV];

void dfs(int u,int p){
	vis[u] = 1;
	tim++;
	tin[u] = tim;
	fup[u] = tin[u];
	int child = 0;
	for(int v:gr[u]){
		if(v==p)
			continue;
		if(!vis[v]){
			dfs(v,u);
			fup[u] = min(fup[u],fup[v]);

			if(fup[v]>=tin[u] && p!=-1)
				cutpoint[u] = 1;
			child++;
		}
		else{
			fup[u] = min(fup[u], tin[v]);
		}
	}

	if(p==-1 && child > 1)
		cutpoint[u] = 1;

}

int main(){
	ios_base::sync_with_stdio(false);

	int n,m,u,v;

	while(1){
		cin>>n>>m;
		if(n==0&&m==0)
			break;
		for(int i=1;i<=n;i++)
			gr[i].clear();

		while(m--){
			cin>>u>>v;
			gr[u].pb(v);
			gr[v].pb(u);
		}
		memset(vis,0,sizeof(vis));
		tim = 0;
		memset(cutpoint,0,sizeof(cutpoint));
		dfs(1,-1);
		int c = 0;
		for(int i=1;i<=n;i++)
			if(cutpoint[i])
				c++;
		cout<<c<<endl;

	}
}