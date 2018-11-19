#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

ll modmul(ll a, ll b, ll mod){
	return (((a%mod)*(b%mod))%mod);
}

ll modexp(ll x, ll n, ll mod){
	if(n==0)
		return (1%mod);
	if(n==1)
		return (x%mod);
	if(n&1){
		ll a = modexp(x,n-1,mod);
		return modmul(x,a,mod);
	}
	else{
		ll a = modexp(x,n>>1,mod);
		return modmul(a,a,mod);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		ll a,b,n;
		cin>>a>>b>>n;
		std::vector<ll> factors;
		ll num = abs(a-b);
		if(num==0){
			ll x1 = modexp(a,n,MOD);
			ll x2 = modexp(b,n,MOD);
			cout<<(x1+x2)%MOD<<endl;
			continue;
		}
		ll sqn = (ll)sqrt(num);
		for(ll i=1;i<=sqn;i++){
			if((num%i)==0){
				factors.pb(i);
				factors.pb(num/i);
			}
		}
		sort(factors.rbegin(), factors.rend());
		for(int i=0;i<factors.size();i++){
			ll mod = factors[i];
			
			ll x1 = modexp(a,n,mod);
			ll x2 = modexp(b,n,mod);
			if(((x1+x2)%mod)){
				// cout<<mod<<" No"<<endl;
			}
			else
			{
				// cout<<mod<<" yes"<<endl;
				cout<<(mod%MOD)<<endl;
					break;
			}
		}	
	}
		
}