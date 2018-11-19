#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

int graph[10][10];
int shortest[10][10][10][10];
int vis[10][10];

void bfs(int r,int c){
	memset(vis,0,sizeof(vis));
	queue<pair<int,int> > Q;
	shortest[r][c][r][c] = 0;
	Q.push(mp(r,c));
	pair<int,int> p;
	int u,v,nu,nv;
	vis[r][c] = 1;
	while(!Q.empty()){
		p = Q.front();
		Q.pop();
		u = p.ff;
		v = p.ss;

		nu = u+2,nv = v+1;
		if(nu<=8&&nv<=8){
			if(!vis[nu][nv])
			{
				shortest[r][c][nu][nv] = shortest[r][c][u][v]+1;
				vis[nu][nv] = 1;
				Q.push(mp(nu,nv));
			}
		}

		nu = u+2,nv = v-1;
		if(nu<=8&&nv>=1){
			if(!vis[nu][nv])
			{
				shortest[r][c][nu][nv] = shortest[r][c][u][v]+1;
				vis[nu][nv] = 1;
				Q.push(mp(nu,nv));
			}
		}

		nu = u-2,nv = v+1;
		if(nu>=1&&nv<=8){
			if(!vis[nu][nv])
			{
				shortest[r][c][nu][nv] = shortest[r][c][u][v]+1;
				vis[nu][nv] = 1;
				Q.push(mp(nu,nv));
			}
		}

		nu = u-2,nv = v-1;
		if(nu>=1&&nv>=1){
			if(!vis[nu][nv])
			{
				shortest[r][c][nu][nv] = shortest[r][c][u][v]+1;
				vis[nu][nv] = 1;
				Q.push(mp(nu,nv));
			}
		}

		nu = u+1,nv = v+2;
		if(nu<=8&&nv<=8){
			if(!vis[nu][nv])
			{
				shortest[r][c][nu][nv] = shortest[r][c][u][v]+1;
				vis[nu][nv] = 1;
				Q.push(mp(nu,nv));
			}
		}

		nu = u+1,nv = v-2; 
		if(nu<=8&&nv>=1){
			if(!vis[nu][nv])
			{
				shortest[r][c][nu][nv] = shortest[r][c][u][v]+1;
				vis[nu][nv] = 1;
				Q.push(mp(nu,nv));
			}
		}

		nu = u-1,nv = v+2; 
		if(nu>=1&&nv<=8){
			if(!vis[nu][nv])
			{
				shortest[r][c][nu][nv] = shortest[r][c][u][v]+1;
				vis[nu][nv] = 1;
				Q.push(mp(nu,nv));
			}
		}

		nu = u-1,nv = v-2; 
		if(nu>=1&&nv>=1){
			if(!vis[nu][nv])
			{
				shortest[r][c][nu][nv] = shortest[r][c][u][v]+1;
				vis[nu][nv] = 1;
				Q.push(mp(nu,nv));
			}
		}

	} 
}

void preprocess(){
	for(int i=1;i<=8;i++)
	{
		for(int j=1;j<=8;j++)
			bfs(i,j);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	preprocess();
	int t;
	cin>>t;
	int r1,c1,r2,c2;
	string s1,s2;
	while(t--){
		cin>>s1>>s2;
		r1 = (int)(s1[0]-'a')+1;
		c1 = (int)(s1[1]-'0');
		r2 = (int)(s2[0]-'a')+1;
		c2 = (int)(s2[1]-'0');
		cout<<shortest[r1][c1][r2][c2]<<endl;
	}
}