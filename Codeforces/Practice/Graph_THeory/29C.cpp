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

unordered_map<ll,int> corres;
unordered_map<int,ll> revcorres;
int deg[NOV];

vector<int> gr[NOV];

void dfs(int u, int p){
	cout<<revcorres[u]<<" ";
	for(int v:gr[u]){
		if(v==p)
			continue;
		dfs(v,u);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	ll n;
	cin>>n;

	ll u,v;
	int cnt = 0;
	while(n--){
		cin>>u>>v;
		if(corres.find(u)==corres.end())
		{
			corres[u] = ++cnt;
			revcorres[cnt] = u;
		}
		if(corres.find(v)==corres.end())
		{
			corres[v] = ++cnt;
			revcorres[cnt] = v;
		}
		u = corres[u];
		v = corres[v];
		gr[v].pb(u);
		gr[u].pb(v);
		deg[u]++;
		deg[v]++;
	}
	for(int i=1;i<=cnt;i++){
		if(deg[i]==1){
			dfs(i,-1);
			break;
		}
	}
	cout<<endl;

}