#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;


int d[1000007];
vector<int> primes;
int isPrime[1000007];

void preprocess(){
	memset(isPrime,-1,sizeof(isPrime));
	isPrime[1]=0;

	for(int i=2;i<=1000005;i++){
		if(isPrime[i]==-1)
		{
			isPrime[i]=1;
			primes.pb(i);
			for(int j=i*2;j<=1000005;j+=i)
				isPrime[j]=0;
		}
	}
}

int countDiv(int x){
	int ans=1;
	for(int i=0;i<primes.size();i++){
		int c=0,p=primes[i];
		// cout<<p<<endl;
		if(p>x)
			break;
		while(x%p==0){
			x/=p;
			c++;
		}
		ans*=(c+1);
	}
	return ans;
}

ll fast_exp(ll p, ll k){
	if(k==0)
		return 1;
	if(k==1)
		return p;
	ll x;
	if(k%2==0){
		x = fast_exp(p,k/2);
		return x*x;
	}
	else
		return (p*fast_exp(p,k-1)); 
}

ll sumDiv(ll x){
	int ans=1;
	for(int i=0;i<primes.size();i++){
		int c=0,p=primes[i];
		// cout<<p<<endl;
		if(p>x)
			break;
		while(x%p==0){
			x/=p;
			c++;
		}
		ll x = fast_exp(p,c+1); 
		// cout<<x<<" "<<p<<" "<<c<<endl;
		ans*=(x-1)/(p-1);
		// cout<<ans<<endl;
	}
	return ans;
}

int main(){
	// ios_base::sync_with_stdio(false);
	preprocess();
	int t;
	scanf("%d",&t);
	int a,b,x;
	while(t--){
		scanf("%d",&x);
		// x = __gcd(a,b);
		// cout<<x<<endl;
		printf("%lld\n",sumDiv(x)-x);
	}
}