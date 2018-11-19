#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define MOD 1000000007
#define mp make_pair
using namespace std;

int n;
int arr[105];
ll dp[105][100007];
int bits(ll num){
	int c=0;
	while(num){
		c+=(num%2);
		num/=2;
	}
	return ((c%3)==0);
}

ll count(ll cur,ll num){

	if(num==0)
		return 1;
	if(dp[cur][num]!=-1)
		return dp[cur][num];


	ll ans=0;
	for(int k=1;k<=n;k++){
		if(bits((arr[k]^arr[cur]))){
			ans+=count(k,num-1);
			ans%=MOD;
		}
	}
	return dp[cur][num]=ans;
}

int main(int argc, char const *argv[])
{
	int k;
	cin>>n>>k;
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=count(i,k-1);
		ans%=MOD;
	}
	cout<<ans<<endl;

	return 0;
}


