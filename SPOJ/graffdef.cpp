#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

#define NOV 500007

vector<int> gr[NOV];
vector<int> ngr[NOV];
set<pair<int,int> > done;


int fup[NOV], tin[NOV];
int tim,cnt;
int vis[NOV];

void dfs(int u,int p){
	tin[u] = tim++;
	fup[u] = tin[u];
	for(int v:gr[u]){
		if(v==p)
			continue;
		if(tin[v]==-1){
			dfs(v,u);
			fup[u] = min(fup[u],fup[v]);
		}
		else if(tin[v]<tin[u])
			fup[u] = min(fup[u],tin[v]);
		if(fup[v]<=tin[u]){
			if(done.find(mp(u,v))!=done.end())
				continue;

			ngr[v].pb(u);
			ngr[u].pb(v);
			done.insert(mp(u,v));
			done.insert(mp(v,u));
		}
	}
}

void getcnt(int u){
	vis[u] = 1;
	cnt++;
	for(int v:ngr[u]){
		if(!vis[v])
			getcnt(v);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	ll n,m,u,v;

	cin>>n>>m;
	memset(tin,-1,sizeof(tin));

	while(m--){
		cin>>u>>v;
		gr[u].pb(v);
		gr[v].pb(u);
	}
	tim=0;
	dfs(1,-1);

	// for(int i=1;i<=n;i++)
	// {
	// 	cout<<i<<":";
	// 	for(int p:ngr[i])
	// 		cout<<p<<" ";
	// 	cout<<endl;
	// }
	ll c = 0,x;
	cnt = 0;
	for(int i=1;i<=n;i++){
		if(!vis[i])
		{
			cnt = 0;
			getcnt(i);
			x = cnt;
			// cout<<"cnt:"<<x<<endl;
			c += (x*(x-1))/2; 
		}
	}

	ll rem = (n*(n-1))/2;
	double ans;
	if(rem==0)
		ans=0;
	else
		ans = (double)(c)/(double)rem;
	printf("%.5f\n",ans);

}