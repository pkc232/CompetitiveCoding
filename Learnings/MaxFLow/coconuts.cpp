#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll G[315][315];
int vis[315];
int from[315];
int src;
int sink;
int n;

ll bfs(){
	queue<int> Q;
	Q.push(src);

	fill(from,from+n+3,-1);
	fill(vis,vis+n+3,0);

	vis[src]=1;

	

	int where,prev;

	while(!Q.empty()){
		where = Q.front();
		Q.pop();

		for(int i=0;i<=n+1;i++){
			if(G[where][i]){
				if(!vis[i]){
					Q.push(i);
					vis[i]=1;
					from[i]=where;
				}
				if(i==sink)
					goto outwhile;
			}
		}
	}

	//finding out the min capacity edge along the path

	outwhile:
		ll path_cap = LONG_MAX;
		where = sink;

		while(from[where]>-1){
			prev=from[where];
			path_cap=min(path_cap,G[prev][where]);
			where = prev;
		}

		if(path_cap==LONG_MAX)
			return 0;

	//updating the residual network

		where = sink;
		while(from[where]>-1){
			prev = from[where];
			G[prev][where]-= path_cap;
			G[where][prev]+=path_cap;
			where = prev;
		}
		return path_cap;
}

ll maxFlow(){
	ll res=0;
	ll path_cap;
	while(1){
		path_cap = bfs();
		if(path_cap==0)
			break;
		else
			res+=path_cap;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while(1){
	int m;
	cin>>n>>m;
	if(n==0&&m==0)
		return 0;

	memset(G,0,sizeof(G));
	int x;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x==1)
			G[0][i]=1;
		else
			G[i][n+1]=1;
	}

	int u,v;
	while(m--){
		cin>>u>>v;
		G[u][v]=G[v][u]=1;
	}
	// for(int i=0;i<=n+1;i++){
	// 	for(int j=0;j<=n+1;j++)
	// 		cout<<G[i][j]<<" ";
	// 	cout<<endl;
	// }
	src=0;
	sink=n+1;
	cout<<maxFlow()<<endl;
		
	}

	return 0;
}