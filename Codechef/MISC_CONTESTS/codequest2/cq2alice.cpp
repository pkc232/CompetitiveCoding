#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

ll nearest(ll num){
	ll ans=0,c=0;
	while(num){
		if(num&1)
		{
			ll ck = 1<<c;
			ans=max(ans,ck);
		}
		c++;
		num>>=1;
	}
	return ans;
}

ll count(ll l,ll w){

	if(w==0)
		return 0;
	if(l==1)
		return 1;

	ll num = nearest(w);

	ll l1 = w;
	ll w1 = w-num;
	return 1+count(min(num,w-num),max(num,w-num))+count()
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll x;
	while(1){
		cin>>x;
	}


}