#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define pii pair<ll,ll>
#define large_int 2139062143
#define large_long_long_ll 9187201950435737471
using namespace std;

#define NOV 400005


vector<pair<ll,ll> > gr[NOV];
ll dis[NOV];
ll n;
map<pair<ll,ll>,ll> edges;
ll par[NOV];
ll cnt = 0,k;
vector<ll> ans;

void dijkstra(ll s){
	for(ll i=1;i<=n;i++)
		dis[i] = large_long_long_ll;
	dis[s] = 0;
	par[s]=-1;
	priority_queue<pii, vector<pii>, greater<pii> > pq;

	pq.push(mp(dis[s],s));

	while(!pq.empty()){
		if(cnt==k)
			return;
		pii top = pq.top();
		pq.pop();

		ll v = top.ss, d = top.ff;
		if(d<=dis[v]){
			// cout<<v<<" "<<par[v]<<endl;
			if(par[v]!=-1){
				ans.pb(edges[mp(v,par[v])]);
				cnt++;
			}
			for(pii p:gr[v]){
				ll v2 = p.ff, cost = p.ss;
				if(dis[v2] > dis[v] + cost){
					dis[v2] = dis[v] + cost;
					par[v2] = v;
					pq.push(mp(dis[v2],v2));
				}
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);

	ll m;
	cin>>n>>m>>k;
	ll u,v,w;
	for(ll i=1;i<=m;i++){
		cin>>u>>v>>w;
		gr[u].pb(mp(v,w));
		gr[v].pb(mp(u,w));
		edges[mp(u,v)] = edges[mp(v,u)] = i;
	}

	dijkstra(1);
	cout<<ans.size()<<endl;
	for(ll v:ans)
		cout<<v<<" ";
	cout<<endl;

}