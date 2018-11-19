#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

vector<int> gr[2007];

int vis[2007];
int assoc[2007];



int main(){
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;

	int val[2007];
	for(int i=1;i<=n;i++)
		cin>>val[i];

	int u,v,ans=0;
	while(m--){
		cin>>u>>v;
		ans+=min(val[u],val[v]);
	}
	cout<<ans<<endl;
}