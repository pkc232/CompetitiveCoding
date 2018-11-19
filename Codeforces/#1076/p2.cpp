#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define pii pair<int,int>
#define large_int 2139062143
#define large_long_long_int 9187201950435737471
using namespace std;

#define NOV 1000005

int isPrime[NOV];

void sieve(){
	isPrime[1] = 0;
	for(ll i=2;i<=1e6;i++){
		if(isPrime[i]==-1){
			isPrime[i]=1;
			for(ll j=i*2;j<=1e6;j+=i)
				isPrime[j]=0;
		}
	}
}

int recur(int n){
	if(n==0)
		return 0;
	int ans = -1;
	for(int i=2;i<=n;i++){
		if(n%i==0)
		{
			ans = i;
			break;
		}
	}

	return 1+recur(n-ans);
}

int main(){
	ios_base::sync_with_stdio(false);
	memset(isPrime,-1,sizeof(isPrime));
	sieve();

	ll n;
	cin>>n;
	// for(int i=1;i<=25;i++)
	{
		// n=i;
		if(n%2==0)
			cout<<n/2<<endl;
		else
		{
			ll x = sqrt(n);
	
			for(ll i=3;i<=x;i++){
				if(n%i==0)
				{
					n -= i;
					break;
				}
			}
			if(n%2){
				cout<<1<<endl;
			}
			else
				cout<<n/2+1<<endl;
		}

		// cout<<recur(i)<<endl;
	}
	
}