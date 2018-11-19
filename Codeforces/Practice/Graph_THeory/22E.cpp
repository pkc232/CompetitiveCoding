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

#define NOV 300005

vector<int> gr[NOV], trgr[NOV];
int tout[NOV],tin[NOV];
int tim = 0;
int vis[NOV];
vector<pii> ans;
int comp[NOV];
int fl = 0;


void dfs1(int u){
	// tim++;
	// cout<<"tin: "<<tim<<" u: "<<u<<endl;
	vis[u] = 1;
	for(int v:gr[u]){
		if(!vis[v])
			dfs1(v);
	}
	tim++;
	// cout<<"tout: "<<tim<<" u: "<<u<<endl;
	tout[tim] = u;

}

void dfs2(int u, int num){
	vis[u] = 1;
	comp[u] = num;
	// cout<<u<<" ";
	for(int v:trgr[u]){
		if(!vis[v])
			dfs2(v);
		else
		{
			
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	int n,u;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>u;
		gr[i].pb(u);
		trgr[u].pb(i);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs1(i);
		}
	}

	cout<<"Touts"<<endl;
	for(int i=1;i<=tim;i++)
		cout<<tout[i]<<" ";
	cout<<endl;
	memset(vis,0,sizeof(vis));
	int cnt = 1;

	for(int i=tim;i>0;i--){
		u = tout[i];
		if(!vis[u]){
			dfs2(u,cnt);
			cout<<"------\n";
		}
	}
}