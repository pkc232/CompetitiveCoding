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
ll n,m,x,y;

ll count(ll i, ll j){
	ll ans = 1;
	ans += m-1+n-1;
	ll l = i-1, r = n-i, u = j-1, d = m-j;
	ans += min(l,d);
	ans += min(l,u);
	ans += min(r,u);
	ans += min(r,d);

	if(x==i){
		if(y>j){
			ans -= m-y;
		}
		else
		{
			ans -= y-1;
		}
	}

	else if(y==j){
		if(x>i)
			ans -= n-x;
		else
			ans -= x-1;
	}

	else if(abs(x-i)==abs(y-j)){
		if(x-i>0&&y-j>0){
			ans -= min(r,d);
			ans += x-i;
		}

		if(x-i>0&&y-j<0){
			ans -= min(r,u);
			ans += x-i;
		}
		if(x-i<0&&y-j>0){
			ans -= min(l,d);
			ans += i-x;
		}
		if(x-i<0&&y-j<0){
			ans -= min(l,u);
			ans += i-x;
		}
	}
	else
		ans++;

	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);

	int t;
	cin>>t;

	while(t--){
		
		cin>>n>>m>>x>>y;
		ll totans = 0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(x!=i||y!=j){
					// cout<<i<<" "<<j<<" : "<<count(i,j)<<endl;
					totans += n*m-count(i,j);
				}
			}
		}

		cout<<totans<<endl;
	}
}