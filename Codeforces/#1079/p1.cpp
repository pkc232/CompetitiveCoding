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

int cnt[1005];

int main(){
	ios_base::sync_with_stdio(false);

	int n,k;
	cin>>n>>k;

	int arr[n+10];

	for(int i=1;i<=n;i++){
		cin>>arr[i];
		cnt[arr[i]]++;
	}
	// int cnt = 0;
	int mx = 0;
	for(int i=1;i<=100;i++){
		if(cnt[i]){
			mx = max(mx, (cnt[i]+k-1)/k);
		}
	}
	// cout<<mx<<endl;
	int ans = 0;
	for(int i=1;i<=100;i++){
		if(cnt[i]){
			ans += k*mx-cnt[i];
		}
	}
	cout<<ans<<endl;
}