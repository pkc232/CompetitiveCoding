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

ll dp[NOV];

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
    	a %= MOD;
        if (b & 1){
            res = (((res) * (a)));
            res %= MOD;
        }
        a = (a*a);
        a %= MOD;
        b >>= 1;
    }
    return (res%MOD);
}

ll calc(ll num){
	if(num==1)
		return 1;
	ll p = (num-2)/3;
	ll rem = num - 3*p;
	rem %= MOD;
	ll prod = binpow(3,p);
	return ((prod*rem)%MOD);
}

int main(){
	ios_base::sync_with_stdio(false);

	int t;
	cin>>t;
	ll num;
	while(t--){
		cin>>num;
		cout<<calc(num)<<endl;
	}
	return 0;

	// dp[0] = 1;
	// for(int i=1;i<=20;i++){
	// 	dp[i] = 1; 
	// 	// cout<<"For i = "<<i<<endl;
	// 	for(int j=0;j<=i;j++){
	// 		if(dp[j]*(i-j)>dp[i]){
	// 			dp[i] = max(dp[i],dp[j]*(i-j));
	// 			// mxind[i] = j;
	// 		}
	// 		// cout<<j<<" "<<dp[j]*(i-j)<<endl;
	// 	}
	// }
	


	// for(int i=1;i<=20;i++)
	// 	cout<<i<<" "<<dp[i]<<" "<<calc(i)<<"\n";//<<mxind[i]<<endl;

}