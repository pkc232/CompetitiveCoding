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

#define NOV 1005

vector<int> tree[NOV];
int dp1[NOV];
int dp2[NOV];

int compute(int u, int par){
	int p;
	int sum = 1;
	int fl = 0;
	int mprod = 1;
	vector<int> prods;
	for(int v:tree[u]){
		if(v==par)
			continue;
		p = compute(v,u);
		if(p==1){
			fl=1;
			sum++;
		}
		else{
			prods.pb(p);
		}
	}
	if(fl==1)
}

int main(){
	ios_base::sync_with_stdio(false);

	int n;
	cin>>n;
	int u,v;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		gr[u].pb(v);
		gr[v].pb(u);
	}
}