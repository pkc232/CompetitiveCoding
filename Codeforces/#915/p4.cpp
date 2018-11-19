#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
using namespace std;

int gr[505][505];
int indeg[505];
int vis[505];
int n;
int ret[505];

int par[505];
bool isCycle(int u){
	vis[u]=1;
	int fl=0;
	int i;

	bool ans = 0;
	for(i=1;i<=n;i++){
		if(gr[u][i]){
			if(vis[i]&&!ret[i]){
				fl=1;
				ans=1;
				break;
			}
			else
			{
				par[i]=u;
				ans|=isCycle(i);
			}
		}
	}
	ret[u]=1;


	if(fl==1){
		int v;
		do{
			v=par[u];
			gr[v][u]=0;

			u=v;
			v=par[v];

		}while(u!=i);
	}
	return ans;
}

bool topoSort(){
	memset(indeg,0,sizeof(indeg));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(gr[i][j])
				indeg[j]++;
		}
	}
	queue<int> Q;
	for(int i=1;i<=n;i++){
		if(indeg[i]==0)
			Q.push(i);
	}

	while(!Q.empty()){
		for(int i=0;i<Q.size();i++){
			int u=Q.front();
			vis[u]=1;
			Q.pop();
			for(int j=1;j<=n;j++){
				if(gr[u][j]){
					indeg[j]--;
					if(indeg[j]==0)
						Q.push(j);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i])
			return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int m,x,y,tm;
	cin>>n>>m;
	tm=m;

	
	memset(indeg,0,sizeof(indeg));
	
	memset(gr,0,sizeof(gr));
	while(m--){
		cin>>x>>y;
		indeg[y]++;
		gr[x][y]=1;
	}

	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		memset(ret,0,sizeof(ret));
		if(isCycle(i)){
			// cout<<"Yahaan\n";
			if(topoSort())
				cout<<"Yes\n";
			else
				cout<<"No\n";
			return 0;
		}
	}

	cout<<"Yes\n";


	return 0;
}