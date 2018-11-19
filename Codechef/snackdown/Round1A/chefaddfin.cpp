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

int dp[34][34][34][2];
int C[34];

int getcnt(int num){
	int c=0;
	while(num){
		if(num&1)
			c++;
		num>>=1;
	}
	return c;
}

void store(int c){
	int i = 32;
	while(c){
		if(c&1)
			C[i] = 1;
		else
			C[i] = 0;
		i--;
		c>>=1;
	}
}

int count(int c1, int c2, int ind, int car){
	
	if(ind==0){
		if(c1==0&&c2==0&&car==0)
			return 1;
		else
			return 0;
	}
	if(c1<0||c2<0)
		return 0;


	if(dp[c1][c2][ind][car] != -1)
		return dp[c1][c2][ind][car];
	cout<<c1<<" "<<c2<<" "<<ind<<" "<<car<<endl;

	int ans=0;
	if(C[ind] == 1){
		if(car){
			ans = count(c1,c2,ind-1,0);
		}
		else
		{
			int x=0,y=0;
			if(c1)
				x = count(c1-1,c2,ind-1,0);
			if(c2)
				y = count(c1,c2-1,ind-1,0);
			ans = x+y;
		}
	}
	else
	{
		if(car){
			int x=0,y=0;
			if(c1)
				x = count(c1-1,c2,ind-1,0);
			if(c2)
				y = count(c1,c2-1,ind-1,0);
			ans = x+y;
		}
		else
		{
			int x=0, y=0;
				x = count(c1,c2,ind-1,0);
			if(c1&&c2)
				y = count(c1-1,c2-1,ind-1,1);
			ans = x+y;
		}
	}

	return dp[c1][c2][ind][car] = ans;


}


int main(){
	ios_base::sync_with_stdio(false);


	int t;
	cin>>t;
	int a,b,c;

	while(t--){
		cin>>a>>b>>c;
		int c1 = getcnt(a);
		int c2 = getcnt(b);
		store(c);
		memset(dp,-1,sizeof(dp));
		cout<<count(c1,c2,32,0)<<endl;
	}
}