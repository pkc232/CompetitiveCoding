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

#define NOV 2005

int n;
ll dist[NOV][NOV];
unordered_map<ll, vector<int> > stor;

int main(){
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin>>dist[i][j];
			stor[dist[i][j]].pb(j);
		}


	int r = 1;
	int u,v,duv,drv,dru,dxv,dxu,drx,dux,dvx;
	int fl=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			u = i;
			v = j;
			duv = dist[u][v];
			drv = dist[r][v];
			dru = dist[r][u];
			drx = (drv+dru) - duv; 
			if((drx)%2)
			{
				fl=1;
				goto no;
			}
			else
			{
				drx /= 2;
				int cnt = 0;
				for(int x:stor[drx]){
					if(dist[r][x] == drx){
						if(dist[u][x]+dist[v][x]==duv)
							cnt++;
					}
				}
				if(cnt!=1)
				{
					fl=1;
					goto no;
				}
			}
		}
	}

	if(!fl)
		goto yes;

	no:{
		cout<<"NO\n";
		return 0;
	}

	yes:
		cout<<"YES\n";
		return 0;

}