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
#define datatype pair<pair<int,int>,int>
#define NOV 100005

int n,m,k;
set<pair<pair<int,int>,int> > s;
unordered_map<int,int> newvertex;
vector<int> gr[NOV];




int main(){
	ios_base::sync_with_stdio(false);

	cin>>n>>m>>k;
	int u,v,a,b,c;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		gr[u].pb(v);
		gr[v].pb(u);
	}

	for(int i=1;i<=k;i++){
		cin>>a>>b>>c;
		s.insert(mp(mp(a,b),c));
	}
	int cnt = n+1,fl=0;
	for(auto it = s.begin();it!=s.end();it++){
		auto p = (*it);
		a = p.ff.ff;
		b = p.ff.ss;
		c = p.ss;
		fl = 0;
		for(int x:gr[b]){
			if(x==a||x==c)
				continue;
			datatype d1 = mp(mp(a,b),x);
			datatype d2 = mp(mp(x,b),c);
			if(s.find(d1)==s.end()&&s.find(d2)==s.end()){
				gr[b].pb(cnt);
				newvertex[cnt] = x;
				gr[cnt].pb(b);
				fl = 1;
				cnt++;
				break;
			}
		}
	}

	n = cnt;
	for(int i=1;i<=n;i++)
	{
		cout<<i<<": ";
		for(int v:gr[i])
			cout<<v<<" ";
		cout<<endl;
	}


}