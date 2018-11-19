#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
using namespace std;


vector<ll> left,right;
ll cnt;
void into(ll l,ll r){
	int i = lower_bound(left)
}

int main(int argc, char const *argv[])
{
	ll n,q,l,r;
	int cas;
	cin>>n>>q;
	cnt=n;
	while(q--){
		cin>>l>>r>>cas;
		if(cas==1)
			cnt-=into(l,r);
		else
			cnt+=out(l,r);
	}

	return 0;
}