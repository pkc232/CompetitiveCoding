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

unordered_map<string,int> cities;
vector<pair<int,int> > gr[NOV];
int dis[NOV];
int n;

int dijkstra(int s,int t){
	for(int i=1;i<=n;i++)
		dis[i] = INT_MAX;
	dis[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > pq;

	pq.push(mp(dis[s],s));

	while(!pq.empty()){
		pii top = pq.top();
		pq.pop();

		int v = top.ss, d = top.ff;
		if(v==t)
			return dis[t];
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
	return dis[t];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	int m;
	int u,w,q;
	cin>>t;
	string city, city1,city2;
	while(t--){
		cin>>n;
		cities.clear();

		for(int i=1;i<=n;i++){
			cin>>city;
			cities[city] = i;
			cin>>m;
			gr[i].clear();
			while(m--){
				cin>>u>>w;
				gr[i].pb(mp(u,w));
			}	
		}

		cin>>q;

		while(q--){
			cin>>city1>>city2;
			cout<<dijkstra(cities[city1],cities[city2])<<endl;
		}

	}
}