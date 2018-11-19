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

	int t,n,k;
	cin>>t;
	while(t--){
		// arr.clear();
		cin>>n>>k;
		int arr[n+5];
		for(int i=0;i<n;i++)
			cin>>arr[i];

		sort(arr,arr+n);
		int i;
		for(i=0;i<n;i++)
			if(arr[i]>k)
				break;
		int l,r;

		int cnt = 0;
		for(int j=i;j<n-1;j++){
			l = arr[j];
			r = arr[j+1];
			arr[j] = k;
			arr[j+1] -= (l-k); 
		}

		int s = 0;
		for(int i=0;i<n;i++)
			s+=arr[i];
		cout<<s<<endl;
	}
}