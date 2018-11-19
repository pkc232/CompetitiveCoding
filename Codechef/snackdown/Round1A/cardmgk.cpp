#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define pii pair<int,int>
using namespace std;

#define NOV 100005

int arr[NOV];

int main(){
	ios_base::sync_with_stdio(false);

	int incr = 0,decr=0;

	int t,n;
	cin>>t;

	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>arr[i];
		int i = 2;
		int prev = arr[1];
		decr = 0;
		int elem = INT_MAX;
		while(i<=n){
			if(arr[i]<arr[i-1]){
				decr++;
				elem = arr[1];
			}
			i++;
		}
		if(decr>1)
			cout<<"NO\n";
		else{
			if(elem<arr[n])
				cout<<"NO\n";
			else
				cout<<"YES\n";
		}
	}


}