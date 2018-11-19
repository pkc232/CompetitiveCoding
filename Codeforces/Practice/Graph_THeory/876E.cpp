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

unordered_set<int> pres[NOV];
vector<int> gr[NOV];
int indeg[NOV], outdeg[NOV];
int upper[NOV];

int LESS(int x1,int x2){
	if(upper[x1]==1&&upper[x2]==0)
		return 0;
	if(upper[x1]==0&&upper[x2]==1){
		if(x1<=x2)
			return 1;
		else
			return -1;
	}
	if(upper[x1]==0&&upper[x2]==0)
	{
		if(x1<=x2)
			return 0;
		else
			return 1;
	}
	if(upper[x1]==1&&upper[x2]==1)
	{
		if(x1<=x2)
			return 0;
		else
			return -1;
	}
}

int main(){
	ios_base::sync_with_stdio(false);


	int n,m;
	cin>>n>>m;
	int l,x;
	vector<int> prev,curr;
	int fl = 0;
	for(int i=1;i<=n;i++){
		curr.clear();
		cin>>l;
		while(l--){
			cin>>x;
			curr.pb(x);
		}
		int j;
		for(j=0;j<min(prev.size(),curr.size());j++){
			if(prev[j]!=curr[j])
			{
				if(pres[curr[j]].find(prev[j])==pres[curr[j]].end()){
					gr[curr[j]].pb(prev[j]);
					indeg[prev[j]]++;
					outdeg[curr[j]]++;
					pres[curr[j]].insert(prev[j]);
				}
				break;
			}
		}
		if(j==curr.size()&&curr.size()<prev.size()){
			fl = 1;
		}

		prev = curr;
	}

	// for(int i=1;i<=m;i++){
	// 	cout<<i<<" : ";
	// 	for(int v:gr[i])
	// 		cout<<v<<" ";
	// 	cout<<endl;
	// }
	if(fl)
	{
		cout<<"No\n";
		return 0;
	}
	queue<int> Q;
	for(int i=1;i<=m;i++){
		if(indeg[i]==0)
			Q.push(i);
	}
	int u,val;
	
	while(!Q.empty()){
		if(fl)
			break;
		u = Q.front();
		Q.pop();

		for(int v:gr[u]){
			val = LESS(v,u);
			if(val==-1)
			{
				fl=1;
				break;
			}
			if(val==1)
				upper[v]=1;
			indeg[v]--;
			if(indeg[v]==0)
				Q.push(v);
		}
	}

	if(fl){
		cout<<"No"<<endl;
		return 0;
	}
	

	for(int i=1;i<=m;i++)
		if(indeg[i]){
			cout<<"No"<<endl;
			return 0;
		}

	cout<<"Yes\n";
	int c = 0;
	for(int i=1;i<=m;i++)
		if(upper[i]){
			c++;
			// cout<<i<<" ";
		}

	cout<<c<<endl;
	for(int i=1;i<=m;i++)
	if(upper[i]){
		// c++;
		cout<<i<<" ";
	}
	cout<<endl;

}