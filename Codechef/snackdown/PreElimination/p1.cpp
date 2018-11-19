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

	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;

		ll A[n+5], B[m+5];
		ll s1 = 0, s2 = 0;
		vector<ll> v1,v2;
		for(int i=1;i<=n;i++){
			cin>>A[i];
			if(A[i])
			v1.pb(A[i]);
			
		}

		for(int i=1;i<=m;i++){
			cin>>B[i];
			if(B[i])
			v2.pb(B[i]);
			
		}
		
			
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		
		if(v1!=v2)
			cout<<"Alice\n";
		else
			cout<<"Bob\n";
	
		
	}




	
}