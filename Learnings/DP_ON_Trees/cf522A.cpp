#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

map<string,int> m;
vector<vector<int> > adj(300);
int dp[300];

int calcLength(int u){
	
	int mx=0;
	for(int i=0;i<adj[u].size();i++){
		mx=max(mx,calcLength(adj[u][i]));
	}
	return 1+mx;

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	string s1,s2,s3;
	int cnt=1;
	while(n--){
		cin>>s1>>s2>>s3;
		std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
		std::transform(s3.begin(), s3.end(), s3.begin(), ::tolower);
		if(m.find(s1)==m.end())
			m[s1]=cnt++;
		if(m.find(s3)==m.end())
			m[s3]=cnt++;

		adj[m[s3]].pb(m[s1]);
	}

	int root=m["polycarp"];
	cout<<calcLength(root)<<endl;

}