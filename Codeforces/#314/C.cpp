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

#define NOV 100005

vector<int> parents[NOV];
vector<pii> gr[NOV];
vector<pii> revgr[NOV];
int sdis[NOV],tdis[NOV];

map<pii,pii> edges;
map<int,int> ans;

int indeg[NOV],outdeg[NOV];
int outdeg_copy[NOV];

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


void rev_dijkstra(int s){
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
			for(pii p:revgr[v]){
				int v2 = p.ff, cost = p.ss;
				if(dis[v2] > dis[v] + cost){
					dis[v2] = dis[v] + cost;
					pq.push(mp(dis[v2],v2));
				}
			}
		}
	}
}


int modified_dijkstra(int s,int p){
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
					for(int x:parents[v2])
						outdeg[x]--;
					parents[v2].clear();]
					parents[v2].pb(v);
					indeg[v2] = 1;
					outdeg[v]+ = 1;

				}
				else if(dis[v2] == dis[v] + cost){
					parents[v2].pb(v);
					outdeg[v]++;
					indeg[v2]++;
				}
			}
		}
	}
	return dis[t];
}


void toposort(int t){
	queue<int> Q;
	Q.push(t);
	int u;
	while(!Q.empty()){
		u = Q.front();
		Q.pop();

		if(outdeg[u])
	}
}

int main(){
	ios_base::sync_with_stdio(false);

	int n,m,s,t,a,b,w,ind;
	cin>>n>>m>>s>>t;

	for(int i=1;i<=m;i++){
		cin>>a>>b>>w;
		edges[mp(a,b)] = mp(i,w);
		gr[a].pb(mp(b,w));
		revgr[b].pb(mp(a,w));
	}

	dijkstra(s);
	for(int i=1;i<=n;i++)
		sdis[i] = dis[i];

	rev_dijkstra(t);
	for(int i=1;i<=n;i++)
		tdis[i] = dis[i];

	int mindis = modified_dijkstra(s,t);

	for(auto it = edges.begin();it!=edges.end();it++){
		pii edge = it->first;
		a = edge.ff;
		b = edge.ss;
		w = (it->ss).ss;
		ind = (it->ss).ff;
		int curdis = sdis[a]+tdis[b]+w;
		if(curdis > mindis){
			if(w-1>curdis-mindis+1)
				ans[ind] = curdis-mindis+1;
			else
				ans[ind] = -1;
		}
	}

	for(int i=1;i<=n;i++)
		outdeg_copy[i] = outdeg[i];


}