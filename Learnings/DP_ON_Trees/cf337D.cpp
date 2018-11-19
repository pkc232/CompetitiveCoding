#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;


int in[100007],out[100007];
int n,m,d;
int cnt[100007];
int fl[100007];
std::vector<vector<int> > adj;


void dfs1(int u,int p){

	if(fl[u])
		in[u]=0;
	else
		in[u]=INT_MIN;

	int mx=0;
	for(int i=0;i<adj[u].size();i++){
		if(adj[u][i]!=p){
			dfs1(adj[u][i],u);
			mx=max(mx,in[adj[u][i]]);
		}
	}

	in[u]+=mx;
}

void dfs2(int u,int p){
	int mx1=INT_MIN,mx2=INT_MIN;


	for(int i=0;i<adj[u].size();i++){
		if(adj[u][i]!=p){
			if(in[v]>=mx1){
				mx2=mx1;
				mx1=in[v];
			}
			else if(in[v]>mx2)
				mx2=in[v];
		}
	}

	for(int i=0;i<adj[u].size();i++){
		int v = adj[u][i];
		if(v==p)
			continue;
		int use=mx1;
		if(in[v]==mx1)
			use=mx2;
		out[v]=max(1+out[u],2+use);
		dfs2(v,u);
	}

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	
	cin>>n>>m>>d;


}