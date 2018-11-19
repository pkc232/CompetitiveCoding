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
	int n,s;
	cin>>n>>s;

	int a[n+5],b[n+5];

	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];

	if(s==1)
	{
		cout<<"YES\n";
		return 0;
	}
	if(a[1]==0)
	{
		cout<<"NO\n";
		return 0;
	}
	if(a[s])
	{
		cout<<"YES\n";
		return 0;
	}
	if(b[s]==0)
	{
		cout<<"NO\n";
		return 0;
	}
	for(int i=s+1;i<=n;i++){
		if(a[i]&&b[i]){
			cout<<"YES\n";
			return 0;
		}
	}

	cout<<"NO\n";
		return 0;
}