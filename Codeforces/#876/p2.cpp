#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
using namespace std;

int cnt[100007];

int main(int argc, char const *argv[])
{
	int n,k,m;
	cin>>n>>k>>m;
	ll x;
	vector<ll> arr(n);
	for(int i=0;i<n;i++){
		cin>>x;
		arr[i]=x;
		cnt[(x%m)]++;
	}

	for(int i=0;i<m;i++){
		if(cnt[i]>=k){
			cout<<"Yes\n";
			for(int j=0;j<n&&k;j++){
				if((arr[j]%m)==i){
					cout<<arr[j]<<" ";
					k--;
				}
			}
			cout<<endl;
			return 0;
		}
	}

	cout<<"No\n";




	return 0;
}