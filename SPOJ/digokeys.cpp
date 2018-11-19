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
int n;
int dis[NOV];
int vis[NOV];
int par[NOV];

void bfs(){
	queue<int> Q;
	Q.push(1);
	dis[1] = 0;
	vis[1] = 1;
	par[1] = -1;
	int u;
	while(!Q.empty()){
		u = Q.front();
		Q.pop();
		for(int v:gr[u]){
			if(!vis[v]){
				par[v] = u;
				vis[v] = 1;
				Q.push(v);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);

	int t,m,x;
	cin>>t;

	while(t--){
		cin>>n;

		for(int i=1;i<=n-1;i++){
			gr[i].clear();
			cin>>m;
			while(m--){
				cin>>x;
				gr[i].pb(x);
			}
			sort(gr[i].begin(), gr[i].end());
		}
		
		// memset(dis,0x7f,sizeof(dis));

		memset(vis,0,sizeof(vis));

		bfs();
		if(par[n]){
			vector<int> v;
			int u=n;
			while(u!=-1){
				v.pb(u);
				u = par[u];
			}
			reverse(v.begin(), v.end());
			int l = v.size();
			cout<<l-1<<endl;
			for(int i=0;i<l-1;i++){
				cout<<v[i]<<" ";
			}
			cout<<endl;
		}
		else
			cout<<-1<<endl;


	}
}