#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int t;
	cin>>t;

	while(t--){
		ll x;
		cin>>x;

		ll lo=1,hi=1e9;
		ll mid;
		ll chk = x;
		ll ans1=LONG_MAX;

		while(lo<=hi){
			mid = lo+(hi-lo)/2;

			ll op = mid*(mid-1)/2;

			if(op>=x)
			{
				ans1=min(ans1,mid);
				hi = mid-1;
			}
			else
				lo=mid+1;
		}

		lo =1,hi = 1e9;
		ll ans2=LONG_MIN;

		while(lo<=hi){
			mid = lo+(hi-lo)/2;

			ll op = mid*(mid-1)/2;

			if(op<=x)
			{
				ans2=max(ans2,mid);
				lo = mid+1;
			}
			else
				hi=mid-1;
		}

		// cout<<ans1<<" "<<ans2<<endl;
		ll ans = min(ans1-1+abs((ans1*(ans1-1))/2-x),ans2-1+abs((ans2*(ans2-1))/2-x));

		cout<<ans<<endl;
	}
}