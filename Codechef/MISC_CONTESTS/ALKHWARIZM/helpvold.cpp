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

	int n;
	cin>>n;

	vector<ll> v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}

	sort(v.begin(), v.end());
	ll s=0;
	for(int i=1;i<n;i++)
		s+=v[i]*v[i-1];

	cout<<s<<endl;
}