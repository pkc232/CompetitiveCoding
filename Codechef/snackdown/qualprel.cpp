#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

int arr[100007];
int n,k,i,x,c,j;

int lowest(int val){
	int lo = 0, hi = n-1;
	int ans = n;
	while(lo<=hi){
		int mid = lo+(hi-lo)/2;
		if(arr[mid]>=val){
			ans = min(ans,mid);
			hi=mid-1;
		}
		else
			lo=mid+1;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	

	while(t--){
		cin>>n>>k;
		c=0;
		k=n-k;
		for(i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,arr+n);
		x = arr[k];
		// cout<<x<<" :"<<endl;
		j = lowest(x);
		cout<<n-j<<endl;

	}
}