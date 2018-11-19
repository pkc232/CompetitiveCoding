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

	ll n;
	cin>>n;

	ll x,y;
	cin>>x>>y;

	ll s1 = 0;
	if(x<y){
		s1 += x-1;
		s1 += y-x;
	}
	else
	{
		s1 += y-1;
		s1 += x-y;
	}

	ll s2 = 0;
	if(x>y){
		s2 += n-x;
		s2 += x-y;
	}
	else
	{
		s2 += n-y;
		s2 += (y-x);
	}

	// cout<<s1<<" "<<s2<<endl;

	if(s1<=s2)
		cout<<"White\n";
	else
		cout<<"Black\n";
}