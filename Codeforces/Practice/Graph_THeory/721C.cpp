#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;
int n,m;
ll T;
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return ((h1+h2)*(h1+h2+1))/2 + h2;
        return h1 ^ h2;  
    }
};

vector<pair<int,ll> > gr[5007];
vector<pair<int,ll> > revGraph[5007];
unordered_map<pair<int,int>, pair<ll,int>, pair_hash > dp; 
int vis[5007];
void toposort(){
	int u,v;
	for(int i=2;i<=n;i++){
		queue<int> Q;
		Q.push(1);
		memset(vis,0,sizeof(vis));
		vis[1]=1;
		while(!Q.empty()){
			// cout<<u<<endl;
			u = Q.front();
			Q.pop();
			vis[u]=1;
			for(int j=0;j<gr[u].size();j++){
				v = gr[u][j].ff;
				if(dp.find(mp(u,i-1))!=dp.end())
				{
					if(dp.find(mp(v,i))==dp.end())
						dp[mp(v,i)] = mp(dp[mp(u,i-1)].ff + gr[u][j].ss,u);
					if(dp[mp(v,i)].ff>dp[mp(u,i-1)].ff + gr[u][j].ss)
					dp[mp(v,i)] = mp(dp[mp(u,i-1)].ff + gr[u][j].ss,u);
				}
				if(!vis[v])
				Q.push(v);
			}
			
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n>>m>>T;
	int u,v;
	ll t;
	while(m--){
		cin>>u>>v>>t;
		gr[u].pb(mp(v,t));
		revGraph[v].pb(mp(u,t));
	}
	dp[mp(1,1)] = mp(0,-1);
	toposort();
	stack<int> ans;
	for(int i=n;i>=2;i--){
		if(dp.find(mp(n,i))!=dp.end()){
			if(dp[mp(n,i)].ff<=T){
				cout<<i<<endl;
				int k = i;
				v = n;
				while(k>0){
					ans.push(v);
					u = dp[mp(v,k)].ss;
					k--;
					v=u;
				}
				while(!ans.empty())
				{
					u = ans.top();
					ans.pop();
					cout<<u<<" ";
				}
				cout<<endl;
				break;
			}
		}
	}
}