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

char grid[1005][1005];

void color(int r,int c){
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++)
		{
			if(grid[r+i][c+j]=='#')
				return;
		}
	}

	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++)
		{
			grid[r+i][c+j] = 'C';
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);


	int t,n,m;
	cin>>t;

	while(t--){
		cin>>n>>m;

		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>grid[i][j];

		for(int i=1;i<=n-1;i++){
			for(int j=1;j<=m-1;j++)
				color(i,j);
		}
		int f=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				if(grid[i][j]=='.'){
					f=1;
					break;
				}
			}
			if(f)
				cout<<"NO\n";
			else
				cout<<"YES\n";
	}
}