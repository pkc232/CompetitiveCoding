#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

int arr[100007];
int timing[100098];
vector<int> gr[100007];
int k;
vector<int> ans;
int done = 0;

void printCycle(int t1,int t2){
	while(t1>=t2){
		ans.pb(timing[t1]);
		t1--;
	}
}


void dfs(int u, int tim){
	if(done)
		return;
	if(!ans.empty())
		return;
	int v;
	for(int i=0;i<gr[u].size();i++){
		if(done)
			return;
		v = gr[u][i];
		if(arr[v] == -1)
		{
			arr[v] = ++tim;
			timing[tim] = v;
			// cout<<"Arrived at "<<v<<" from "<<u<<" on "<<tim<<endl;
			dfs(v,tim);
		}
		else
		{
			// cout<<"Found cyclic edge from "<<v<<" "<<u<<endl;
			// cout<<arr[v]<<" "<<arr[u]<<" "<<k<<endl;
			if(arr[u]-arr[v]+1>=k+1){
				// cout<<"Printing cycle\n";
				printCycle(arr[u],arr[v]);
				done = 1;
				return;
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m>>k;
	int u,v;
	while(m--){
		cin>>u>>v;
		gr[u].pb(v);
		gr[v].pb(u);
	}
	memset(arr,-1,sizeof(arr));
	arr[1] = 0;
	timing[0] = 1;
	dfs(1,0);
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	cout<<endl;

}