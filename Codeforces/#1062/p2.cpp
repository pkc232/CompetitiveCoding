#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define large_int 2139062143
#define large_long_long_int 9187201950435737471
using namespace std;

#define NOV 100005

ll nearest2(ll x){

	ll c = 0,cnt1=0;
	ll n =x;
	while(x){
		if(x&1)
			cnt1++;
		x>>=1;
		c++;
	}
	if(cnt1==1)
		return n;
	return (1<<(c));
}
int main(){
	ios_base::sync_with_stdio(false);
	ll n;
	cin>>n;

	ll x = sqrt(n);
	int fl = 0;
	vector<ll> v;
	ll c = 0;
	ll prod = 1,mx=1;
	int nfl = 0;
	for(int i=2;i<=n;i++){
		if((n%i)==0){
			fl = 1;
			c=0;
			while((n%i)==0){
				n /= i;
				c++;
			}
			v.pb(c);
			if(c!=mx){
				nfl++;
				mx = max(mx,c);
			}
			prod *= i;
		}
	}

	if(fl==0){
		cout<<n<<" "<<0<<endl;
	}
	else{
		ll cnt = 0,mx = 1;
		for(ll p:v){
			mx = max(mx,nearest2(p));
		}
		
		if(mx>1)
			cnt++;
		cnt += mx/2;
		cout<<prod<<" "<<cnt<<endl;


	}

}