#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;


vector<vector<int> > tree(1007);
int L[1007],T[1007],P[1007];
int h=0;

void assignLevel(int u){
	for(int i=0;i<tree[u].size();i++){
		int v = tree[u][i];
		L[v]=L[T[v]]+1;
		h=max(h,L[v]);
		assignLevel(v);
	}
}

void dfs(int node,int nr){
	if(L[node]<nr)
		P[node]=1;
	else
	{
		if(!(L[node]%nr)){
			P[node]=T[node];
		}
		else
		{
			P[node]=P[T[node]];
		}
	}
}

int lca(int x,int y){
	while(P[x]!=P[y]){
		if(L[x]>L[y])
			x=P[x];
		else
			y=P[y];
	}

	while(x!=y){
		if(L[x]>L[y])
			x=T[x];
		else
			y=T[y];
	}

	return x;
}

int main(){
	ios_base::sync_with_stdio(false);


	int t;
	scanf("%d",&t);

	for(int ti=1;ti<=t;ti++){
		tree.clear();
		int n,m,x;
		scanf("%d",&n);

	for(int i=1;i<=n;i++){
		scanf("%d",&m);
		while(m--){
			scanf("%d",&x);
			tree[i].pb(x);
			T[x]=i;
		}
	}

	L[1]=0;
	h=0;
	assignLevel(1);

	int nr = (int)(ceil(sqrt(h)));

	dfs(1,nr);
	cout<<"Case "<<ti<<":"<<endl;
	int q,u,v;
	scanf("%d",&q);

	
	while(q--){
		scanf("%d %d",&u,&v);
		printf("%d\n", lca(u,v));
	}


	}
	
}