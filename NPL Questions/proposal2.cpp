#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define large 1000000007
using namespace std;

vector<ll> primeNos;

ll bsearch(ll p){
        ll lo=0,hi=primeNos.size(),mid;
        ll ans=large,num;
        while(lo<=hi){
            mid = lo+(hi-lo)/2;
            num = primeNos[mid];
            if(num<p){
                lo=mid+1;
            }
            else
            {
                ans=min(ans,num);
                hi=mid-1;
            }
        }
        if(ans<large)
        return ans;
        else
            return -1;
}

int isPrime(ll num){
	ll x = sqrt(num);
	for(int i=2;i<=x;i++){
		if(num%i==0)
			return 0;
	}
	return 1;
}

void segmented_sieve(ll l, ll r){
	for(ll i=l;i<=r;i++)
	{
		if(isPrime(i))
			primeNos.pb(i);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		ll l,r,Q,p;
        cin>>l>>r>>Q;
		primeNos.clear();
		segmented_sieve(l,r);
		while(Q--){
                cin>>p;
                cout<<bsearch(p)<<endl;
        }
	}
	
}