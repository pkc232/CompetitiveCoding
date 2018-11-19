#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
using namespace std;

int gr[505][505];
int vis[505];
int ret[505];
bool present;
int par[505];
int st,en;
ll n;
vector<vector<int> > adj(505);
void dfs(int u,int fl){
	vis[u]=1;

	if(present)
		return;
	for(int p=0;p<adj[u].size();p++){
		int i=adj[u][p];
		{
		if(gr[u][i]==0)
			continue;
		if(vis[i]){
			if(!ret[i])
			{
				present=true;
				if(fl){
				st=i;
				en=u;	
				}
				return;
			}
		}
		else
		{
			if(fl)
			par[i]=u;
			dfs(i,fl);
		}
	}
	}

	
	ret[u]=1;
}

void checkCycle(int fl){
	present=false;
	// memset(vis,0,sizeof(vis));
	// memset(ret,0,sizeof(ret));
	for(int i=1;i<=n;i++)
		vis[i]=ret[i]=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]&&!present)
			dfs(i,fl);
	}

}


int main(int argc, char const *argv[])
{
	memset(gr,0,sizeof(gr));
	ll e;int x,y;
	cin>>n>>e;

	while(e--){
		scanf("%d %d",&x,&y);
		adj[x].pb(y);
		gr[x][y]=1;
	}

	
	checkCycle(1);
	if(present){
		// cout<<st<<" "<<en<<endl;
		bool mila=false;
		gr[en][st]=0;
		checkCycle(0);
		gr[en][st]=1;
		mila|=(!present);
		while(1){
			if(mila)
				break;
			// cout<<par[en]<<" -> "<<en<<endl;
			gr[par[en]][en]=0;
			checkCycle(0);
			gr[par[en]][en]=1;
			en=par[en];
			mila|=(!present);
			if(st==en)
				break;
		}
	if(mila)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	}
	else
		cout<<"YES\n";

	return 0;
}