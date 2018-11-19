#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

unordered_map<int,vector<int>[105]> dict;
int vis[105];
void dfs(int u, int c){
	vis[u] = 1;
	for(int i=0;i<dict[c][u].size();i++)
		if(!vis[dict[c][u][i]])
			dfs(dict[c][u][i],c);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	int u,v,c;
	int cols = m;
	while(m--){
		cin>>u>>v>>c;
		dict[c][u].pb(v);
		dict[c][v].pb(u);
	}

	int q,ans;
	cin>>q;
	while(q--){
		cin>>u>>v;
		ans = 0;
		for(int i=1;i<=cols;i++){
			memset(vis,0,sizeof(vis));
			dfs(u,i);
			ans+=vis[v];
		}
	cout<<ans<<endl;
	}
}