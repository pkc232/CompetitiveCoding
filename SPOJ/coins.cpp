#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

#define NOV 100005


unordered_map<ll,ll> dp;

ll count(ll num){
	if(num==1)
		return 1;
	if(num==0)
		return 0;

	if(dp.find(num)!=dp.end())
		return dp[num];
	ll x1 = count(num/2);
	ll x2 = count(num/3);
	ll x3 = count(num/4);

	ll s = x1+x2+x3;
	return dp[num] = max(x1+x2+x3,num);
}

int main(){
	ios_base::sync_with_stdio(false);
	ll n;
	while(cin>>n){
		cout<<count(n)<<endl;
	}
}