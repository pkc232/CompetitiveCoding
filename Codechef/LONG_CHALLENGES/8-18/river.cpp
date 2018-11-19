#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

vector<int> tree[10007];

int vis[10007], par[10007];
int dp1[10007], dp2[10007];
void mds(int v, int par){
	for(int i=0;i<tree[v].size();i++){
		int child = tree[v][i];
		if(child!=par){
			mds(child,v);
		}
	}

	int s1 = 0, s2=0;
	int s3 = INT_MAX;
	for(int i=0;i<tree[v].size();i++){
		int child = tree[v][i];
		if(child!=par){
			s1+=dp1[child];
			s2+=dp2[child];
		}
	}
	for(int i=0;i<tree[v].size();i++){
		int d = tree[v][i];
		int ts = 0;
		if(d!=par)
		{
			for(int j=0;j<tree[d].size();j++)
			{
				int g = tree[d][j];
				if(g!=v)
				ts+=dp2[g];
			}
		}
		s3 = min(s3,1+ts+s1-dp1[d]);
	}
	dp1[v] = min(1+s2,s3);
	dp2[v] = min(1+s2,s1);
	// cout<<v<<" "<<dp1[v]<<" "<<dp2[v]<<endl;
}

int vcov(int v,int par){
	for(int i=0;i<tree[v].size();i++){
		int child = tree[v][i];
		if(child!=par){
			vcov(child,v);
		}
	}
	dp1[v]=1;
	dp2[v]=0;
	for(int i=0;i<tree[v].size();i++){
		int child = tree[v][i];
		if(child!=par){
			dp1[v]+=dp2[child];
			dp2[v]+=dp1[child];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			tree[i].clear();
		int v;
		for(int i=2;i<=n;i++){
			cin>>v;
			tree[v].pb(i);
			// tree[i].pb(v);
			// mds(1,-1);
			vcov(1,-1);
			cout<<1+min(dp1[1],dp2[1])<<" ";
		}
		cout<<endl;
			
	}
}