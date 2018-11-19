#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define pii pair<int,int>
#define large_int 2139062143
#define large_long_long_int 9187201950435737471
using namespace std;

#define NOV 300005

vector<pair<int,int> > gr[NOV];
queue<int> Q;
int donttake[NOV];
int vis[NOV];
int par[NOV];
int d;
int police[NOV];

void bfs(){
	int u;
	int dist = 0;
	while(!Q.empty()){

		u = Q.front();
		// cout<<"Popping "<<u<<endl; 
		Q.pop();
		if(u==-1)
		{
			if(Q.size()){
				Q.push(-1);
				
			}
			dist++;
			if(dist==d)
				break;
			else
				continue;
		}

		for(pii v:gr[u]){
			// int i = edges[mp(u,v)];
			if(!vis[v.ff]){
				par[v.ff] = u;
				vis[v.ff] = 1;
				Q.push(v.ff);
				donttake[v.ss] = 1;
			} 
		}
	}
}

int main(){
	// ios_base::sync_with_stdio(false);

	int n,k,u,v;


	cin>>n>>k>>d;

	for(int i=1;i<=k;i++){
		scanf("%d",&u);
		
		if(police[u]==0){
			vis[u]=1;
			Q.push(u);
			police[u] = 1;
			par[u] = -1;
		}
	}
	Q.push(-1);

	for(int i=1;i<=n-1;i++){
		scanf("%d %d",&u,&v);
		gr[u].pb(mp(v,i));
		gr[v].pb(mp(u,i));
	}
	// cout<<"Doing bfs\n";
	bfs();
	// cout<<k-1<<endl;
	int c = 0;
		for(int i=1;i<n;i++){
		if(!donttake[i])
			c++;
	}
	cout<<c<<endl;
	for(int i=1;i<n;i++){
		if(!donttake[i])
			printf("%d ",i);
	}

	cout<<endl;

}