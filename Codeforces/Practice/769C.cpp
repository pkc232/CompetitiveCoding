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
char posn[4] = {'D','L','R','U'};
map<char,char> opp;
int dist[NOV][NOV];
int vis[NOV][NOV];

int n,m,k;
string ans="";

int isValid(int r,int c){
	if(r<=n&&c<=m&&r>=1&&c>=1&&grid[r][c]!='*')
		return 1;
	return 0;
}

void calcdist(int r,int c){
	queue<pii> Q;
	Q.push(mp(r,c));

	dist[r][c] = 0;
	vis[r][c] = 1;
	pii p;
	int nr,nc;
	while(!Q.empty()){
		p = Q.front();
		Q.pop();
		r = p.ff;
		c = p.ss;

		nr = r+1;
		nc = c;
		if(isValid(nr,nc)&&!vis[nr][nc]){
			dist[nr][nc] = dist[r][c] + 1;
			vis[nr][nc] = 1;
			Q.push(mp(nr,nc));
		}

		nr = r-1;
		nc = c;
		if(isValid(nr,nc)&&!vis[nr][nc]){
			dist[nr][nc] = dist[r][c] + 1;
			vis[nr][nc] = 1;
			Q.push(mp(nr,nc));
		}

		nr = r;
		nc = c+1;
		if(isValid(nr,nc)&&!vis[nr][nc]){
			dist[nr][nc] = dist[r][c] + 1;
			vis[nr][nc] = 1;
			Q.push(mp(nr,nc));
		}

		nr = r;
		nc = c-1;
		if(isValid(nr,nc)&&!vis[nr][nc]){
			dist[nr][nc] = dist[r][c] + 1;
			vis[nr][nc] = 1;
			Q.push(mp(nr,nc));
		}
	}

}

void dfs(int r,int c,int k){
	if(k==0)
		return;
	
	if(isValid(r+1,c)&&dist[r+1][c]<=k){
		ans += 'D';
		dfs(r+1,c,k-1);
	}
	else if(isValid(r,c-1)&&dist[r][c-1]<=k){
		ans += 'L';
		dfs(r,c-1,k-1);
	}	
	else if(isValid(r,c+1)&&dist[r][c+1]<=k){
		ans += 'R';
		dfs(r,c+1,k-1);
	}
	else if(isValid(r-1,c)&&dist[r-1][c]<=k){
		ans += 'U';
		dfs(r-1,c,k-1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);

	opp['D'] = 'U';
	opp['U'] = 'D';
	opp['L'] = 'R';
	opp['R'] = 'L';

	

	cin>>n>>m>>k;


	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>grid[i][j];

	if(k%2)
		cout<<"IMPOSSIBLE\n";
	else
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				if(grid[i][j]=='X'){
					calcdist(i,j);
					string s="";
					dfs(i,j,k);
				 	int l = ans.size();
				 	if(l==0)
				 	{
				 		cout<<"IMPOSSIBLE\n";
				 		return 0;
				 	}

				 	// cout<<ans<<endl;
				 	string nans = ans;
				 	// for(int p=l-1;p>=0;p--){
				 	// 	nans += opp[ans[p]];
				 	// }
				 	cout<<nans<<endl;
				}
			}
	}

}