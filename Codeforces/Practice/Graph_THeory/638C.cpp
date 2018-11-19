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

#define NOV 300005

vector<int> gr[NOV];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int u,v;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		gr[u].insert(v);
		gr[v].insert(u);
	}


}