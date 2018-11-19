#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

#define NOV 2005

int n,m;
struct node{
	int r;
	int c;
	int x;
	int y;
};

char arr[2005][2005];
int vis[2005][2005];

int isFeasible(int r,int c){
	return (((r>=1&&r<=n)&&(c>=1&&c<=m))&&(arr[r][c]=='.')&&(!vis[r][c]));
}

int bfs01(int r,int c,int x,int y){
	// fill(dis,dis+NOV,9999999);
	
	node temp;
	temp.r = r;
	temp.c = c;
	temp.x = x;
	temp.y = y;

	deque<node> q;
	q.push_front(temp);
	memset(vis,0,sizeof(vis));
	vis[r][c] = 1;
	node p;
	int nr,nc;
	while(!q.empty()){
		p = q.front();
		q.pop_front();
		r = p.r;
		c = p.c;
		
		// cout<<r<<" "<<c<<" "<<dis[r][c]<<endl;

		nr = r-1, nc = c;
		if(isFeasible(nr,nc))
		{
			node temp1;
			temp1.r = nr;
			temp1.c = nc;
			temp1.x = p.x;
			temp1.y = p.y;
			q.push_front(temp1);
			vis[nr][nc] = 1;
		}

		nr = r+1, nc = c;
		if(isFeasible(nr,nc))
		{
			node temp1;
			temp1.r = nr;
			temp1.c = nc;
			temp1.x = p.x;
			temp1.y = p.y;
			q.push_front(temp1);
			vis[nr][nc] = 1;
		}

		nr = r, nc = c+1;
		if(isFeasible(nr,nc))
		{
			node temp1;
			temp1.r = nr;
			temp1.c = nc;
			temp1.y = p.y;
			temp1.x = p.x;
			if(temp1.y){
				temp1.y--;
				q.push_back(temp1);
				vis[nr][nc] = 1;
			}
		}

		nr = r, nc = c-1;
		if(isFeasible(nr,nc))
		{
			node temp1;
			temp1.r = nr;
			temp1.c = nc;
			temp1.y = p.y;
			temp1.x = p.x;
			if(temp1.x){
				temp1.x--;
				q.push_back(temp1);
				vis[nr][nc] = 1;
			}
		}
	} 
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	int r,c,x,y;
	cin>>r>>c;
	cin>>x>>y;

	memset(vis,0,sizeof(vis));

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>arr[i][j];

	bfs01(r,c,x,y);
	int cnt = 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(vis[i][j])
				cnt++;

	cout<<cnt<<endl;

}