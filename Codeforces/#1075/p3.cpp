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
	int n,m;
	cin>>n>>m;
	vector<ll> x,y;
	ll val,x1,x2,yy;
	for(int i=0;i<n;i++){
		cin>>val;
		x.pb(val);
	}
	for(int i=0;i<m;i++){
		cin>>x1>>x2>>yy;
		if(x1==1){
			y.pb(x2);
		}
	}
	x.pb(1e9);
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	int xptr = 0, yptr = 0;
	int xs = x.size();
	int ys = y.size();
	int ans = large_int;

	while(xptr<xs){
		while(yptr<ys&&y[yptr]<x[xptr])
			yptr++;
		ans = min(ans,xptr+ys-yptr);
		xptr++;
	}
	cout<<ans<<endl;
}