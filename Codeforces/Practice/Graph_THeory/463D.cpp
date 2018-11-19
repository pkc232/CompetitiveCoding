#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

int graph[1005][1005];
int outdeg[1005];
int dist[1005];
int main(){
	ios_base::sync_with_stdio(false);
	int n,k,u,v;
	cin>>n>>k;
	int arr[n+3];
	while(k--){
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}	
		for(int i=1;i<=n;i++){
			u = arr[i];
			for(int j=i+1;j<=n;j++){
				v = arr[j];
				if(graph[v][u]==1)
				{
					graph[u][v] = graph[v][u] = -1;
				}
				else if(graph[u][v]==0 || graph[u][v]==1)
				{
					graph[u][v] = 1;
				}
			}
		}
	}
	queue<int> Q;

	for(int i=1;i<=n;i++)
	{
		outdeg[i] = 0;
		for(int j=1;j<=n;j++){
			if(graph[i][j]==-1)
				graph[i][j] = 0;
			if(graph[i][j])
				outdeg[i]++;
		}
		if(!outdeg[i]){
			Q.push(i);
			dist[i] = 0;
		}
	}

	while(!Q.empty()){
		u = Q.front();
		Q.pop();
		for(int i=1;i<=n;i++){
			if(graph[i][u]){
				dist[i] = max(dist[i], dist[u]+1);
				outdeg[i]--;
				if(!outdeg[i])
					Q.push(i);
			}
		}
	}
	int d = 0;
	for(int i=1;i<=n;i++)
		d=max(d,dist[i]);
	cout<<d+1<<endl;
}