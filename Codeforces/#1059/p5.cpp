#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;


vector<int> tree1[100007];
vector<int> tree2[100007];

int indeg[100007];
ll w[100007];
queue<int> zero;
int flag=0;

ll n,L,S;

void removeChildren(int u,int c){
	for(int i=0;i<tree2.size();i++){
		
	}
}

void removeMax(int u,int c, ll sum,int prev){
	removeChildren(u,prev);


}


int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n>>L>>S;


	for(int i=1;i<=n;i++){
		cin>>w[i];
		if(w[i]>S)
			flag=1;
	}
	if(flag){
		cout<<-1<<endl;
		return 0;
	}

	int x;
	for(int i=2;i<=n;i++)
	{
		cin>>x;
		tree1[x].pb(i);
		tree2[i].pb(x);
		indeg[x]++;
	}
	for(int i=1;i<=n;i++){
		if(indeg[i]==0){
			zero.push(i);
		}
	}

	int cnt=0;
	while(!zero.empty()){
		int u = zero.front();
		zero.pop();
		removeMax(u,1,w[u]);
	}


}