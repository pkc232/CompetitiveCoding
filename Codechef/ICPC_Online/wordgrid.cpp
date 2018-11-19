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

string arr[40];
int n;

char minans[5][5];

void printnot(){
	string ans = "gridsnotpossible";
	int c = 0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<ans[c];
			c++;
		}
		cout<<endl;
	}
}

int checkmin(char grid[5][5]){
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			if(grid[i][j]>minans[i][j])
				return 0;
			else if(grid[i][j]<minans)
				return 1;
		}
	}
	return 0;
}

char** getgrid(string s){
	char **grid = new char[5][5];
	int c=0;
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++,c++)
			grid[i][j] = s[c];
	return grid;
}

string getstring(char grid[5][5]){
	string s="";
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			s += grid[i][j];
	return s;
}

int canfitinrow(int r,string s,char grid[5][5]){
	int c = 0;
	for(int j=1;j<=4;j++,c++){
		if(grid[r][j]!='x'&&grid[r][j]!=s[c])
			return 0;
	}
	return 1;
}

int canfitinrowrev(int r,string s,char grid[5][5]){
	int c = 0;
	for(int j=4;j>=1;j--,c++){
		if(grid[r][j]!='x'&&grid[r][j]!=s[c])
			return 0;
	}
	return 1;
}

int canfitincol(int r,string s,char grid[5][5]){
	int c = 0;
	for(int j=1;j<=4;j++,c++){
		if(grid[j][r]!='x'&&grid[j][r]!=s[c])
			return 0;
	}
	return 1;
}

int canfitincolrev(int r,string s,char grid[5][5]){
	int c = 0;
	for(int j=4;j>=1;j--,c++){
		if(grid[j][r]!='x'&&grid[j][r]!=s[c])
			return 0;
	}
	return 1;
}


void compute(int ind, string curr){
	if(ind>n)
		return;

	char grid[5][5] = getgrid(curr);


} 


int main(){
	ios_base::sync_with_stdio(false);

	int t;
	cin>>t;

	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>arr[i];


	}
}