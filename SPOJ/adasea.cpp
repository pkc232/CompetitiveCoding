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

#define NOV 1005

char grid[NOV][NOV];
ll n,m;
int mark[NOV][NOV];

int isValid(int r,int c){
	if(r>=1&&r<=n&&c>=1&&c<=m&&grid[r][c]=='#'&&!mark[r][c])
		return 1;
	return 0;
}

ll dfs(int r,int c){
	ll cnt=1;
	mark[r][c] = 1;
	int nr,nc;
	nr = r+1,nc =c;
	if(isValid(nr,nc))
		cnt += dfs(nr,nc);
	nr = r-1,nc = c;
	if(isValid(nr,nc))
		cnt += dfs(nr,nc);
	nr = r,nc =c+1;
	if(isValid(nr,nc))
		cnt += dfs(nr,nc);
	nr = r,nc=c-1;
	if(isValid(nr,nc))
		cnt += dfs(nr,nc);
	return cnt;
}


int main(){
	ios_base::sync_with_stdio(false);

	int t;
	cin>>t;

	while(t--){
		cin>>n>>m;

		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>grid[i][j];

		memset(mark,0,sizeof(mark));

		ll totsize = 0,siz;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				if(grid[i][j]=='#'&&mark[i][j]==0){
					
					siz = dfs(i,j);
					totsize += siz*siz;
				}
			}
			// cout<<totsize<<endl;
			ll num = totsize,den = n*m;
			ll g;
			while(1){
				g = __gcd(num,den);
				if(g<=1)
					break;
				num /= g;
				den /= g;
			}
			if(den>1&&num>0)
				cout<<num<<" / "<<den<<endl;
			else
				cout<<num<<endl;

	}

}