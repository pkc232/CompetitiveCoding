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


	int n;
	cin>>n;

	int arr[n+5];
	arr[0] = 0;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	ll s=0;
	int x[n+5];
	vector<int> ans;
	for(int k=1;k<=n;k++){
		for(int i=0;i<k;i++){
			x[i] = arr[i+1]-arr[i];
		}
		int fl=0;
		for(int i=k;i<n;i++){
			if(arr[i+1]!=arr[i]+x[i%k])
			{
				fl=1;
				break;
			}
		}
		if(!fl)
			ans.pb(k);
	}
	cout<<ans.size()<<endl;
	for(int i:ans)
		cout<<i<<" ";
	cout<<endl;
}