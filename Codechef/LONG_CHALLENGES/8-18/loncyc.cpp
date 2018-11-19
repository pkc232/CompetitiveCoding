#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

vector<int> gr[100007];
int vis[100007];
stack<int> s;
vector<pair<int,int> > edge;
map<pair<int,int>,int> edgeType;
int par[100007];
int done[100007];
void dfs(int u){
	vis[u]=1;
	// cout<<"on "<<u<<" ryt now"<<endl;
	for(int i=0;i<gr[u].size();i++){
		int v = gr[u][i];
		if(v!=par[u]){
			if(vis[v]){
				if(done[v])
					continue;
				edgeType[mp(v,u)]=edgeType[mp(u,v)]=1;
				int x = u;
				// cout<<u<<" "<<v<<" "<<x<<endl;
				while(x!=v){
					edgeType[mp(x,par[x])]=edgeType[mp(par[x],x)]=1;
					x=par[x];
				}
			}
			else{
				par[v]=u;
				dfs(v);
				if(edgeType.find(mp(u,v))==edgeType.end())
					edgeType[mp(u,v)]=edgeType[mp(v,u)]=0;
			}
		}
	}
	done[u]=1;
}

int numberOfPaths(int u,int v,int count){

	if(count>1)
		return 0;
	int s1=1,s2=1;
	vis[u]=1,vis[v]=1;
	for(int i=0;i<gr[u].size();i++){
		if(gr[u][i]!=v){
			if(vis[gr[u][i]])
				continue;
			int npth;
			if(edgeType[mp(u,gr[u][i])]==1)
				npth=numberOfPaths(u,gr[u][i],count+1);
			else
				npth=numberOfPaths(u,gr[u][i],count);
			s1+=npth;
		}
	}
	for(int i=0;i<gr[v].size();i++){
			if(gr[v][i]!=v){
			if(vis[gr[v][i]])
				continue;
			int npth;
			if(edgeType[mp(u,gr[v][i])]==1)
				npth=numberOfPaths(v,gr[v][i],count+1);
			else
				npth=numberOfPaths(v,gr[v][i],count);
			s2+=npth;
		}
	}
	return s1*s2;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		memset(vis,0,sizeof(vis));
		edge.clear();
		edgeType.clear();
		memset(done,0,sizeof(done));
		for(int i=1;i<=n;i++)
			gr[i].clear();
		
		int u,v;
		while(m--){
			cin>>u>>v;
			edge.pb(mp(u,v));
			gr[u].pb(v);
			gr[v].pb(u);
		}
		dfs(1);
		for(int i=0;i<edge.size();i++){
			u=edge[i].ff;
			v=edge[i].ss;
			// if(edgeType.find(mp(u,v))!=edgeType.end())
			// 	cout<<u<<" "<<v<<"::"<<edgeType[mp(u,v)]<<endl;
			// else
			// 	cout<<"pp";
		}
		

		for(int i=0;i<edge.size();i++){
			memset(vis,0,sizeof(vis));
			u=edge[i].ff,v=edge[i].ss;
			cout<<numberOfPaths(u,v,edgeType[mp(u,v)])<<endl;
		}

	}
}