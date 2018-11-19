#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

vector<ll> arr;
int n;

ll getCount(int ind){
	if(ind>=n)
		return 0;

	ll cnt = 1;
	ll elem = arr[ind];
	for(int i=ind+1;i<n;i++)
	{
		// cout<<arr[i]<<" "<<elem<<endl;
		if(arr[i]==elem)
			cnt++;
		else
			break;
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);

	int t;
	cin>>t;
	ll x;
	while(t--){
		cin>>n;
		arr.clear();
		for(int i=0;i<n;i++)
		{
			cin>>x;
			arr.pb(x);
		}
		sort(arr.rbegin(), arr.rend());
		ll prod=1;

		int ind=0;
		ll mxcnt,smxcnt;
		ll prevRem = 0;

		while(ind<n){
			if(prevRem == 0){
				mxcnt = getCount(ind);
				smxcnt = getCount(ind+mxcnt);
				// cout<<mxcnt<<" "<<smxcnt<<" in prevRem==0\n";
				ind += mxcnt;
				ind += smxcnt;
				prevRem = abs(mxcnt-smxcnt);
				ll p1 = max(mxcnt*smxcnt,1ll);
				prod *= p1;
				prod %= MOD;
				
			}
			else
			{
				mxcnt = prevRem;
				smxcnt = getCount(ind);
				prod *= mxcnt;
				prod %= MOD;
				prod *= smxcnt;
				prevRem = abs(mxcnt-smxcnt);
				ind += smxcnt;
			}

			// cout<<ind<<" "<<mxcnt<<" "<<smxcnt<<" "<<prod<<endl;
		}

		cout<<prod<<endl;


	}

 


}