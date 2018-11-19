#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

int prime[1000007];
ll possibSum;
vector<int> primes;

void sieve(){
	memset(prime,-1,sizeof(prime));
	prime[1]=0;
	for(int i=2;i<=1000006;i++){
		if(prime[i]==-1)
		{
			prime[i]=1;
			primes.pb(i);
			for(int j=i*2;j<=1000006;j+=i)
				prime[j]=0;
		}
	}
}

int ifPossib(int len){
	ll s =0;
	int ans=0;
	int i;
	for(i=0;i<len;i++){
		s+=primes[i];
	}
	if(s>=1000000)
		return ans;
	if(prime[s])
	{
		possibSum=s;
		return 1;
	}
	while(i<primes.size()){
		s-=primes[i-len];
		s+=primes[i];
		if(s>=1000000)
			return ans;
		if(prime[s])
	{
		possibSum=s;
		return 1;
	}
	i++;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	sieve();
	int lo = 1, hi = (int)primes.size();
	ll ans=0;
	int len=0;
	// while(lo<=hi){
	// 	int mid = (lo+hi)/2;

	// 	if(ifPossib(mid)){
	// 		lo=mid+1;
	// 		ans=possibSum;
	// 		len=max(len,mid);
	// 		cout<<"True for "<<mid<<endl;
	// 	}
	// 	else{
	// 		cout<<"Not true for "<<mid<<endl;
	// 		hi=mid-1;
	// 	}
	// }

	for(int i=1;i<=10;i++){
		if(ifPossib(i)){
			cout<<possibSum<<" "<<i<<endl;
		}
	}

	// cout<<ans<<" "<<len<<endl;

}