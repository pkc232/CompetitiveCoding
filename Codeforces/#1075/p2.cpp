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

#define NOV 100005


int main(){
	ios_base::sync_with_stdio(false);

	int n,m;
	cin>>n>>m;

	ll arr[n+m+5];
	
	vector<ll> rider,driver;
	for(int i=1;i<=n+m;i++)
	{
		cin>>arr[i];
	}
	int d;
	for(int i=1;i<=n+m;i++){
		cin>>d;
		if(d)
		{
			driver.pb(arr[i]);
		}
		else
		{
			rider.pb(arr[i]);
		}
	}

	int cnt[n+m+5];
	memset(cnt,0,sizeof(cnt));
	int len = driver.size();

	// for(ll d:driver)
	// 	cout<<d<<" ";
	// cout<<endl;

	for(ll r:rider){
		// cout<<r<<" "<<ind1<<" "<<ind2<<endl; 
		ll lo =0, hi =len-1;
		ll a1=-1;
		while(lo<=hi){
			ll mid = lo+(hi-lo)/2;
			if(driver[mid]<r){
				a1 = max(a1,mid);
				lo=mid+1;
			}
			else
			{
				hi=mid-1;
			}
		}
		ll a2=len;
		lo =0, hi =len-1;
		while(lo<=hi){
			ll mid = lo+(hi-lo)/2;
			if(driver[mid]>r){
				a2 = min(a2,mid);
				hi=mid-1;
			}
			else
			{
				lo=mid+1;
			}
		}
		// cout<<r<<" "<<a1<<" "<<a2<<endl;
		if(a1==-1){
			cnt[a2]++;
		}
		else if(a2==len)
			cnt[a1]++;
		else{
			if(r-driver[a1]<=driver[a2]-r){
				cnt[a1]++;
			}
			else
				cnt[a2]++;
		}
	}

	for(int i=0;i<len;i++)
		cout<<cnt[i]<<" ";
	cout<<endl;	

}