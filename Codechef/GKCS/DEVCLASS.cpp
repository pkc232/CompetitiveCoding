#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;


vector<int>gr[1000007];
int n;
int a[1000007];
int present[1000007];
int indeg[1000007];

ll ans[1000007];

ll topoSort(){
	queue<int> Q;
	for(int i=1;i<=n;i++){
		if(indeg[a[i]]==0)
			Q.push(a[i]);
	}

	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		ans[u]+=1;
		for(int i=0;i<gr[u].size();i++){
			ans[gr[u][i]]+=ans[u];
			ans[gr[u][i]]%=MOD;
			indeg[gr[u][i]]--;
			if(indeg[gr[u][i]]==0)
				Q.push(gr[u][i]);
		}
	}
	ll finans = 0;
	for(int i=1;i<=n;i++){
		// cout<<a[i]<<" "<<ans[a[i]]<<endl;
		finans+=ans[a[i]];
		finans%=MOD;
	}
	return finans;
}

int main(){
	ios_base::sync_with_stdio(false);

	int t;
	cin>>t;
	while(t--){

		memset(present,0,sizeof(present));
		memset(indeg,0,sizeof(indeg));
		memset(ans,0,sizeof(ans));
		cin>>n;
		for(int i=1;i<=n;i++)
			gr[i].clear();

		for(int i=1;i<=n;i++){
			cin>>a[i];
			gr[a[i]].clear();
			present[a[i]]=1;
		}

		for(int i=1;i<=n;i++){
			int num = a[i];

			for(int j=num*2;j<1000002;j+=num){
				if(present[j]){
					gr[j].pb(a[i]);
					indeg[a[i]]++;
				}
			}
		}

		ll p = topoSort();
		cout<<p%MOD<<endl;

	}



}