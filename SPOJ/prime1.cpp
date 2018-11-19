#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define MAX 1000000005
#define rtmx 1000005
using namespace std;

// const int rtmx = sqrt(MAX);

int isPrime[rtmx+10];
vector<ll> primes;

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

void printPrimes(ll l,ll r){
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
				if(i+l>1)
					cout<<i+l<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	sieve();
	while(t--){
	ll n,m;
	cin>>n>>m;
	printPrimes(n,m);
	cout<<endl;
	}
}