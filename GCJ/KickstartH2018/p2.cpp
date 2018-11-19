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

#define NOV 5000005

ll prefixSum[NOV];
ll arr[NOV];

int main(){
	// ios_base::sync_with_stdio(false);
	ifstream fin;
	fin.open("ip2.in");
	ofstream fout;
	fout.open("op2.txt");

	int T;
	fin>>T;

	for(int ti=1;ti<=T;ti++){

		ll n;
		fin>>n;
		string s;
		fin>>s;
		prefixSum[0] = 0;
		for(int i=1;i<=n;i++){
			arr[i] = s[i-1]-'0';
			prefixSum[i] = prefixSum[i-1]+arr[i];
		}
		ll ans = 0;
		ll lo,hi;
		for(int i=1;i<=n;i++){
			ll len = n-i+1;
			lo = i;
			hi = lo+(len+1)/2-1;
			ans = max(ans,prefixSum[hi]-prefixSum[lo-1]);

			lo = (i+1)/2, hi = i+(len-1)/2;
			ans = max(ans,prefixSum[hi]-prefixSum[lo]);

			lo = i/2,hi=hi-1;
			ans = max(ans,prefixSum[hi]-prefixSum[lo]);
			// cout<<"For "<<i<<":"<<lo<<" "<<hi<<" "<<arr[i]<<" "<<ans<<endl;
		}
		fout<<"Case #"<<ti<<": "<<ans<<endl;
	}
}