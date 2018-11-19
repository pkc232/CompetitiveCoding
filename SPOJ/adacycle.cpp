#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

#define NOV 2005

int gr[NOV][NOV];
int n;

vector<int> adj[NOV];
int vis[NOV];
int dis[NOV];

int bfs(int u){
	// cout<<"For "<<u<<endl;
	dis[u] = 0;
	queue<int> Q;
	Q.push(u);
	int temp;
	while(!Q.empty()){
		temp = Q.front();
		Q.pop();
		// cout<<temp<<endl;
		for(int i:adj[temp]){
			// if(gr[temp][i])
			{
				if(i==u)
					return dis[temp]+1;
				else
				{
					if(dis[i]==-1){
						dis[i] = dis[temp]+1;
						Q.push(i);
					}
				}
			}
		}
	}

	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);

	cin>>n;

	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin>>gr[i][j];
			if(gr[i][j])
				adj[i].pb(j);
		}

	for(int i=1;i<=n;i++){
		memset(dis,-1,sizeof(dis));
		int x = bfs(i);
		if(x==-1)
			cout<<"NO WAY\n";
		else
			cout<<x<<endl;
	}
}