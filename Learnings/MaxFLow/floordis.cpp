#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll G[505][505];
int vis[505];
int from[505];
int src;
int sink;
int n;

ll bfs(){
	queue<int> Q;
	Q.push(src);

	fill(from+1,from+n+1,-1);
	fill(vis+1,vis+n+1,0);

	vis[src]=1;

	

	int where,prev;

	while(!Q.empty()){
		where = Q.front();
		Q.pop();

		for(int i=1;i<=n;i++){
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
	cin>>n;
	int m,w,k,r;
	cin>>m>>w>>k>>r;

	int floor[n+5][m+5];


	memset(floor,0,sizeof(floor));

	int x1,y1,x2,y2;
	while(w--){
		cin>>x1>>y1>>x2>>y2;
		floor[]
	}


	return 0;
}
