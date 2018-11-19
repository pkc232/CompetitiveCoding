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

#define NOV 100005

char grid[300][300];
int vis[300][300];
int isborder = 0;
int sheep = 0, wolf = 0;
int n,m;

int ispossib(int i,int j){
	if(i>0&&j>0&&i<=n&&j<=m&&grid[i][j]!='#'&&!vis[i][j])
		return 1;
	return 0;
}

int border(int i,int j){
	if(i==1||i==n||j==1||j==m)
		return 1;
	return 0;
}

void dfs(int i, int j){
	if(grid[i][j]=='k')
		sheep++;
	else if(grid[i][j]=='v')
		wolf++;
	vis[i][j] = 1;
	int nr,nc;
	nr = i+1,nc = j;
	if(ispossib(nr,nc)){
		dfs(nr,nc);
		isborder |= border(nr,nc);
	}

	nr = i,nc = j+1;
	if(ispossib(nr,nc)){
		dfs(nr,nc);
		isborder |= border(nr,nc);
	}

	nr = i,nc = j-1;
	if(ispossib(nr,nc)){
		dfs(nr,nc);
		isborder |= border(nr,nc);
	}

	nr = i-1,nc = j;
	if(ispossib(nr,nc)){
		dfs(nr,nc);
		isborder |= border(nr,nc);
	}
}

int main(){
	ios_base::sync_with_stdio(false);


	
	cin>>n>>m;

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>grid[i][j];

	int s=0,w=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(!vis[i][j]&&grid[i][j]!='#'){
				sheep = 0;
				wolf = 0;
				isborder = 0;
				dfs(i,j);
				if(isborder){
					s += sheep;
					w += wolf;
				}
				else
				{
					if(sheep<=wolf)
						w += wolf;
					else
						s += sheep;
				}
			}
		}

		cout<<s<<" "<<w<<endl;




}