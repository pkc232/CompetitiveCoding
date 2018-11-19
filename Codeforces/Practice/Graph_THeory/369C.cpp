#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

vector<pair<int,int> > gr[100007];
int taken[100007];
int done[100007];

void dfs(int u, int par){
	// cout<<u<<endl;
	for(int i=0;i<gr[u].size();i++){
		int v = gr[u][i].ff;
		if(v!=par)
		{
			dfs(v,u);
			if(gr[u][i].ss==2){
				int tk = 0;
				for(int j=0;j<gr[v].size();j++){
					if(gr[v][j].ff!=v)
						tk|=done[gr[v][j].ff];
				}
				if(!tk){
					taken[v]=1;
				}
				done[v]=1;
			}
		}
	}
	for(int i=0;i<gr[u].size();i++){
		done[u]|=done[gr[u][i].ff];
	}

} 

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int u,v,c;
	for(int i=1;i<n;i++){
		cin>>u>>v>>c;
		gr[u].pb(mp(v,c));
		gr[v].pb(mp(u,c));
	}
	dfs(1,-1);
	vector<int> ans;
	for(int i=1;i<=n;i++){
		if(taken[i])
			ans.pb(i);
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	cout<<endl;

}