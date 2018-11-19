#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

vector<int> gr[1000007];
int vis[1000007];


int main(){
	ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int t;
	cin>>t;
	int n,r,m,u,v;
	while(t--){
		cin>>n>>r>>m;
		for(int i=1;i<=n;i++)
			gr[i].clear();

		while(r--){
			cin>>u>>v;
			gr[u].pb(v);
			gr[v].pb(u);
		}
		memset(vis,0,sizeof(vis));

		queue<pair<int,int> > Q;

		while(m--){
			cin>>u>>v;
			Q.push(mp(u,v));
			vis[u] = u;
		}
		int fl = 0;
		while(!Q.empty()){
			u = Q.front().ff;
			v = Q.front().ss;
			Q.pop();

			if(v){
				for(int i=0;i<gr[u].size();i++){
					if(vis[gr[u][i]]&&vis[gr[u][i]]!=vis[u]){
						fl=1;
						break;
					}
					else
					{
						vis[gr[u][i]] = vis[u];
						Q.push(mp(gr[u][i],v-1));
					}
				}	
			}

			if(fl)
				break;
		}


		if(fl==1){
			cout<<"No\n";
			continue;
		}

		for(int i=1;i<=n;i++)
		{
			if(!vis[i]){
				fl=1;
				break;
			}
		}
		if(fl==1){
			cout<<"No\n";
			continue;
		}

		cout<<"Yes\n";
	}
}