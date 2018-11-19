#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define MAX 1000000005
#define rtmx 1000005
#define large 1000000007
using namespace std;

// const int rtmx = sqrt(MAX);

int isPrime[rtmx+10];
vector<ll> primes;
vector<ll> primeNos;

void sieve(){
	memset(isPrime,-1,sizeof(isPrime));
	isPrime[1]=0;
	for(int i=2;i<=rtmx+1;i++){
		if(isPrime[i]==-1){
			isPrime[i]=1;
			primes.pb(i);
			for(int j=i*2;j<=rtmx+1;j+=i)
				isPrime[j]=0;
		}
	}
}

void segmented_sieve(ll l,ll r){
	int segPrime[r-l+10];
	memset(segPrime,-1,sizeof(segPrime));
	ll base,currPrime;
	for(int i=0;(primes[i]*primes[i])<=r;i++){
		currPrime = primes[i];
		// cout<<"Current prime "<<currPrime<<endl;
		base = (l/currPrime)*currPrime;
		// cout<<base<<endl;
		if(base<l)
			base += currPrime;
		for(ll j=base;j<=r;j+=currPrime)
			segPrime[j-l] = 0;
		if(base == currPrime)
			segPrime[base-l] = 1;
	}
		for(ll i=0;i<=r-l;i++)
			if(segPrime[i])
				if(i+l>1){
					// cout<<i+l<<endl;
					primeNos.pb(i+l);
				}
}


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

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	sieve();
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