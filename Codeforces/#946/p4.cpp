#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);

	int n,m,k;
	cin>>n>>m>>k;

	char arr[n+3][m+3];

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>arr[i][j];

	int dp[n+3][k+3];

	for(int i=0;i<=k;i++)
		dp[0][i]=0;

	for(int i=1;i<=n;i++){
		int j=1,c=0,fl=0;
		while(j<=m){
			if(arr[i][j]=='0'){
				j++;
				if(fl)
					c++;
			}
			else
			{
				fl=1;
				j++;
				c++;
			}
		}
		dp[i][0]=c;
	}

	for(int i=1;i<=k;i++){
		for(int p=1;p<=n;p++){
			for(int j=1;j)
		}
	}

}