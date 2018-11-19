#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;


vector<int> gr[100007];
int status[100007];
int vis[100007];

void dfs(int u){
	vis[u]=1;

	if(gr[u].size()==0)
	{
		status[u]=0;
		return;
	}

	for(int i=0;i<gr[u].size();i++)
		if(!vis[gr[u][i]]){
			dfs(gr[u][i]);
			if(status[gr[u][i]]==0){
				status[u]=2;
			}
		}
		else
		{
			if(status[gr[u][i]]==-1){
				status[gr[u][i]]=1;
			}
			else
			{
				if(status[gr[u][i]]==0){
				status[u]=2;
			}
			}
		}


	if(status[u]==2)
		return;
	int x=1;
	for(int i=0;i<gr[u].size();i++)
	{
		if(status[gr[u][i]]==1){
			x=0;	
			break;	
		}
		if(status[gr[u][i]]==0){
			status[u]=2;
			return;
		}
	}
	if(x==0)
		status[u]=1;
	else
		status[u]=0;

}

void printpath(int u,int cur){
	int ncur;
	cout<<u<<" ";
	if(cur==2)
		ncur=0;
	else
		ncur=2;
	for(int i=0;i<gr[u].size();i++){
		if(status[gr[u][i]]==ncur){
			printpath(gr[u][i],ncur);
			break;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);


	int n,m;
	cin>>n>>m;
	int c,u,s;
	for(int i=1;i<=n;i++){
		cin>>c;
		while(c--){
			cin>>u;
			gr[i].pb(u);
		}
	}
	cin>>s;
	memset(vis,0,sizeof(vis));
	memset(status,-1,sizeof(status));
	dfs(s);
	if(status[s]==2){
		cout<<"Win\n";
		printpath(s,2);
		cout<<endl;
	}
	else if(status[s]==1)
		cout<<"Draw\n";
	else
		cout<<"Lose\n";
}