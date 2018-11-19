#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

vector<int> gr[1000];
vector<pair<int,int> > ans;

int tin[1000],fup[1000];
int tim;

void dfs(int u,int p){
	tin[u] = tim++;
	fup[u] = tin[u];
	for(int v:gr[u]){
		if(v==p)
			continue;
		if(tin[v]==-1){
			dfs(v,u);
			fup[u] = min(fup[u],fup[v]);
		}
		else if(tin[v]<tin[u])
			fup[u] = min(fup[u],tin[v]);
		if(fup[v]>tin[u]){
			ans.pb(mp(min(u,v),max(u,v)));
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);

	int nc;
	cin>>nc;
	int n,m,u,v;
	for(int ti = 1;ti<=nc;ti++){
		cin>>n>>m;

		for(int i=1;i<=n;i++)
			gr[i].clear();

		while(m--){
			cin>>u>>v;
			gr[u].pb(v);
			gr[v].pb(u);
		}

		ans.clear();
		memset(tin,-1,sizeof(tin));
		memset(fup,0,sizeof(fup));
		tim = 0;


		dfs(1,-1);
		// for(int i=1;i<=n;i++)
		// 	cout<<tin[i]<<" "<<fup[i]<<endl;

		sort(ans.begin(), ans.end());
		cout<<"Caso #"<<ti<<endl;
		if(ans.size()){
			cout<<ans.size()<<endl;
			for(pair<int,int> p : ans){
				cout<<p.ff<<" "<<p.ss<<endl;
			}
		}
		else
		{
			cout<<"Sin bloqueos"<<endl;
		}
	}
}