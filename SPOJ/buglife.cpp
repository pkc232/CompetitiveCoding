#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

vector<int> gr[2005];
int col[2005];

int bfs(int u){
	col[u] = 0;
	queue<int> Q;
	Q.push(u);

	while(!Q.empty()){
		u = Q.front();
		Q.pop();

		for(int v:gr[u]){
			if(col[v]==-1){
				col[v]=1-col[u];
				Q.push(v);
			}
			else if(col[v]==col[u])
				return 0;
		}
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);

	int t,n,m,u,v;
	cin>>t;

	for(int ti=1;ti<=t;ti++){
		cin>>n>>m;

		for(int i=1;i<=n;i++)
			gr[i].clear();
		
		while(m--){
			cin>>u>>v;
			gr[u].pb(v);
			gr[v].pb(u);
		}

		memset(col,-1,sizeof(col));
		int isBipartite = 1;

		for(int i=1;i<=n;i++){
			if(col[i]==-1){
				isBipartite &= bfs(i);
			}
			if(!isBipartite)
				break;
		}

		cout<<"Scenario #"<<ti<<":"<<endl;
		if(!isBipartite)
			cout<<"Suspicious bugs found!\n";
		else
			cout<<"No suspicious bugs found!\n";



	}
}