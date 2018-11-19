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

int allpresent(string grid){
	unordered_set<string> pres;
	string s;	
	for(int i=0;i<4;i++){
		s = "";
		for(int j=0;j<4;j++)
		{
			s+=grid[i*4+j];
		}
		pres.insert(s);
		s="";

		for(int j=3;j>=0;j--)
		{
			s+=grid[i*4+j];
		}
		pres.insert(s);
	}

	for(int j=0;j<4;j++){
		s = "";
		for(int i=0;i<4;i++)
		{
			s+=grid[i*4+j];
		}
		pres.insert(s);
		s="";

		for(int i=3;i>=0;i--)
		{
			s+=grid[i*4+j];
		}
		pres.insert(s);
	}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
			cout<<grid[i*4+j];
		cout<<endl;
	}
	return (pres.size()>=n);
}

void printGrid(string grid){
	cout<<grid<<endl;
}

int compute(int ind, string grid){
	if(ind>=n)
		return allpresent(grid);
	cout<<ind<<endl;
	printGrid(grid);
	int ans = 0,fl=0;

	for(int i=0;i<4;i++){
		fl=0;
		if(ans)
			return 1;
		for(int j=0;j<4;j++){
			if(grid[i*4+j]!='x'&&grid[i*4+j]!=arr[ind][j]){
				fl=1;
			}
		}
		if(fl)
			continue;
		else
		{
			string ngrid = grid;
			for(int j=0;j<4;j++){
				ngrid[i*4+j] = arr[ind][j];
			}
			ans |= compute(ind+1,grid);
			if(ans)
				return 1;
		}

		fl=0;
		for(int j=3;j>=0;j--){
			if(grid[i*4+j]!='x'&&grid[i*4+j]!=arr[ind][4-j-1]){
				fl=1;
			}
		}
		if(fl)
			continue;
		else
		{
			for(int j=3;j>=0;j--){
				grid[i*4+j] = arr[ind][4-j-1];
			}
			ans |= compute(ind+1,grid);
			if(ans)
				return 1;
		}
	}


	if(ans)
		return 1;

	for(int j=0;j<4;j++){
		fl=0;
		if(ans)
			return 1;
		for(int i=0;i<4;i++){
			if(grid[i*4+j]!='x'&&grid[i*4+j]!=arr[ind][i]){
				fl=1;
			}
		}
		if(fl)
			continue;
		else
		{
			for(int i=0;i<4;i++){
				grid[i*4+j] = arr[ind][i];
			}
			ans |= compute(ind+1,grid);
			if(ans)
				return 1;
		}

		fl=0;
		for(int i=3;i>=0;i--){
			if(grid[i*4+j]!='x'&&grid[i*4+j]!=arr[ind][4-i-1]){
				fl=1;
			}
		}
		if(fl)
			continue;
		else
		{
			for(int i=3;i>=0;i--){
				grid[i*4+j] = arr[ind][4-i-1];
			}
			ans |= compute(ind+1,grid);
			if(ans)
				return 1;
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);

	int t;
	cin>>t;
	
	while(t--){
		cin>>n;
		
		for(int i=0;i<n;i++)
			cin>>arr[i];

		if(n>16)
		{
			printnot();
		}
		else
		{
			sort(arr,arr+n);
			string grid;
			for(int i=0;i<16;i++)
				grid += 'x';
			cout<<compute(0,grid)<<endl;

		}
	}
}