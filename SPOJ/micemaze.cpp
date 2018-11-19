#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define pii pair<int,int> 
using namespace std;

#define NOV 10005



vector<pair<int,int> > gr[NOV];
int dis[NOV];
int n;

void dijkstra(int s){
	for(int i=1;i<=n;i++)
		dis[i] = INT_MAX;
	dis[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > pq;

	pq.push(mp(dis[s],s));

	while(!pq.empty()){
		pii top = pq.top();
		pq.pop();

		int v = top.ss, d = top.ff;
		if(d<=dis[v]){
			for(pii p:gr[v]){
				int v2 = p.ff, cost = p.ss;
				if(dis[v2] > dis[v] + cost){
					dis[v2] = dis[v] + cost;
					pq.push(mp(dis[v2],v2));
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	//construct graph
	
	cin>>n;
	int e;
	cin>>e;

	int t;
	cin>>t;
	int m;
	cin>>m;
	int u,v,w;
	while(m--){
		cin>>u>>v>>w;
		gr[v].pb(mp(u,w));
	}

	dijkstra(e);

	int cnt = 0;
	for(int i=1;i<=n;i++){
		if(dis[i]<=t)
			cnt++;
		// cout<<dis[i]<<" "<<endl;
	}

	cout<<cnt<<endl;
	return 0;
}