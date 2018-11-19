#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

vector<int> gr[100007];
int col[100007];
int impos=0;

void dfs(int n){
	int tc = 1-col[n];
	for(int i=0;i<gr[n].size();i++){
		int v = gr[n][i];
		if(col[v]==-1)
		{
			col[v]=tc;
			dfs(v);
		}
		else{
			if(col[v]!=tc){
				impos=1;
				return;
			}
		}
	}

}

int main(){
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	int u,v;
	while(m--){
		cin>>u>>v;
		gr[u].pb(v);
		gr[v].pb(u);
	}
	memset(col,-1,sizeof(col));
	for(int i=1;i<=n;i++){
		if(col[i]==-1)
		{
			col[i]=1;
			dfs(i);
		}
		if(impos){
			cout<<-1<<endl;
			return 0;
		}
	}
	vector<int> v1,v2;
	for(int i=1;i<=n;i++){
		if(col[i]){
			v1.pb(i);
		}
		else{
			v2.pb(i);
		}
	}
	cout<<v1.size()<<endl;
	for(int i=0;i<v1.size();i++)
		cout<<v1[i]<<" ";
	cout<<endl;
	cout<<v2.size()<<endl;
	for(int i=0;i<v2.size();i++)
		cout<<v2[i]<<" ";
	cout<<endl;

	

}