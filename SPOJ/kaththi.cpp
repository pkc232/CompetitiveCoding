#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define pii pair<int,int>
using namespace std;

#define NOV 1005

char arr[NOV][NOV];
int n,m;
int dis[NOV][NOV];

int isFeasible(int r,int c){
	return ((r>=1&&r<=n)&&(c>=1&&c<=m)); 
}

int bfs01(int r,int c){
	// fill(dis,dis+NOV,9999999);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			dis[i][j] = 9999999;
	deque<pii> q;
	q.push_front(mp(r,c));
	dis[r][c] = 0;
	pii p;
	int nr,nc;
	while(!q.empty()){
		p = q.front();
		q.pop_front();
		r = p.ff;
		c = p.ss;

		// cout<<r<<" "<<c<<" "<<dis[r][c]<<endl;

		nr = r-1, nc = c;
		if(isFeasible(nr,nc))
		{
			if(arr[nr][nc]==arr[r][c]){
				if(dis[nr][nc] > dis[r][c]){
					dis[nr][nc] = dis[r][c];
					q.push_front(mp(nr,nc));
				}
			}
			else{

				if(dis[nr][nc] > dis[r][c] + 1){
					dis[nr][nc] = dis[r][c] + 1;
					q.push_back(mp(nr,nc));
				}
			}
		}

		nr = r+1, nc = c;
		if(isFeasible(nr,nc))
		{
			if(arr[nr][nc]==arr[r][c]){
				if(dis[nr][nc] > dis[r][c]){
					dis[nr][nc] = dis[r][c];
					q.push_front(mp(nr,nc));
				}
			}
			else{
				
				if(dis[nr][nc] > dis[r][c] + 1){
					dis[nr][nc] = dis[r][c] + 1;
					q.push_back(mp(nr,nc));
				}
			}
		}

		nr = r, nc = c+1;
		if(isFeasible(nr,nc))
		{
			if(arr[nr][nc]==arr[r][c]){
				if(dis[nr][nc] > dis[r][c]){
					dis[nr][nc] = dis[r][c];
					q.push_front(mp(nr,nc));
				}
			}
			else{
				
				if(dis[nr][nc] > dis[r][c] + 1){
					dis[nr][nc] = dis[r][c] + 1;
					q.push_back(mp(nr,nc));
				}
			}
		}

		nr = r, nc = c-1;
		if(isFeasible(nr,nc))
		{
			if(arr[nr][nc]==arr[r][c]){
				if(dis[nr][nc] > dis[r][c]){
					dis[nr][nc] = dis[r][c];
					q.push_front(mp(nr,nc));
				}
			}
			else{
				
				if(dis[nr][nc] > dis[r][c] + 1){
					dis[nr][nc] = dis[r][c] + 1;
					q.push_back(mp(nr,nc));
				}
			}
		}
	}

	return dis[n][m]; 
}

int main(){
	ios_base::sync_with_stdio(false);

	int t;
	cin>>t;

	while(t--){
		cin>>n>>m;

		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>arr[i][j];

		cout<<bfs01(1,1)<<endl;
	}
}