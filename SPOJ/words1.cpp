#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

int gr[26][26];
int indeg[26];
int outdeg[26];
int n;
int visited[26];

void dfs(int u){
	visited[u] = 1;
	for(int i=0;i<26;i++)
	{
		if(gr[u][i]){
			if(!visited[i])
				dfs(i);
		}
	}
}

int checkEulerCycle(){
	int fl = 1;
	vector<int> pres;
	for(int i=0;i<26;i++){
		fl &= (indeg[i]==outdeg[i]);
		if(indeg[i])
			pres.pb(i);
	}

	if(!fl)
		return fl;
	// cout<<"Euler cycle can be \n";
	memset(visited,0,sizeof(visited));
	dfs(pres[0]);

	for(int i=1;i<pres.size();i++)
		if(!visited[pres[i]])
			return 0;
	return 1;
}

int checkEulerPath(){
	int fl = 1;
	int c1=0,c2=0;

	int strt=-1,en=-1;
	for(int i=0;i<26;i++){
		if(indeg[i]==outdeg[i])
			continue;
		else if(indeg[i]>outdeg[i])
		{
			if(indeg[i]-outdeg[i]==1){
				en = i;
				c1++;
			}
			else
				return 0;
		}
		else
		{
			if(-indeg[i]+outdeg[i]==1){
				strt = i;
				c2++;
			}
			else
				return 0;
		}
	}

	if(c1>1||c2>1)
		return 0;
	if(strt==-1||en==-1)
		return 0;
	// cout<<"Euler path can be\n";
	gr[en][strt] = 1;
	indeg[strt]++;
	outdeg[en]++;
	return checkEulerCycle();

}

int main(){
	ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	int t;
	cin>>t;
	string s;
	int l1,l2;
	while(t--){

		memset(indeg,0,sizeof(indeg));
		memset(outdeg,0,sizeof(outdeg));
		memset(gr,0,sizeof(gr));

		cin>>n;
		while(n--){
			cin>>s;
			l1 = s[0]-'a';
			l2 = s[s.length()-1] - 'a';
			outdeg[l1]++;
			indeg[l2]++;
			gr[l1][l2] = 1;
		}

		if(checkEulerCycle()||checkEulerPath())
			cout<<"Ordering is possible.\n";
		else
			cout<<"The door cannot be opened.\n";
	}
}