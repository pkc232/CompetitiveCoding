#include <bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pb push_back
#define inf 100000000007
using namespace std;

int n;
ll ht[20];
ll dp[(1<<15)+7][16];

int bitcnt(ll num){
	int c=0;
	while(num){
		c+=(num&1);
		num>>=1;
	}
	return c;
}

ll MaxPer(ll num,ll curr,int prev){
	{
		if(bitcnt(num)==n)
			return curr;
	}

	if(dp[num][prev]!=-1)
		return dp[num][prev];
	ll mx=0;
	for(int i=0;i<n;i++){
		if(!(num&(1<<i))){
			ll ncr=curr-ht[prev]+abs(ht[curr]-ht[prev])+ht[curr]+1;
			mx=max(mx,ncr+MaxPer(num|(1<<i),ncr,i));
		}
	}

	return mx;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;

	while(t){
	n=t;
	for(int i=0;i<n;i++)
		cin>>ht[i];
	memset(dp,-1,sizeof(dp));

	ll mx=0;

	for(int i=0;i<n;i++){
		mx=max(mx,MaxPer((1<<i),2*ht[i]+1,i));
	}
	cout<<mx<<endl;
	cin>>t;
	}
	return 0;
}