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
	int s=0;
	int n,x,mx=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		mx=max(mx,x);
		s+=x;
	}

	for(int k=mx;k<=100005;k++){
		if(n*k-s>s)
		{
			cout<<k<<endl;
			return 0;
		}
	}
}