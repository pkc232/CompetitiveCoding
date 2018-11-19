#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

ll n,k;
ll s[100007],d[100007];


double f(double T){
	double mx = -1/0.0, mn = 1/0.0;
	double val;
	for(int i=1;i<=n;i++)
	{	
		val = s[i]*T+d[i];
		mx  = max(mx,val);
		mn  = min(mn,val);
	}
	return mx-mn;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n>>k;

	for(int i=1;i<=n;i++){
		cin>>s[i]>>d[i];
	}

	double eps = 1e-9;

	double lo = 0.0, hi = (double)k;
	double mid1,mid2;
	int i;
	double ans = 1/0.0;
	double diff,v1,v2;
	for(int i=1;i<=200;i++){
		diff = (hi-lo)/3.0;

		mid1 = lo+diff;
		mid2 = hi-diff;

		v1 = f(mid1);
		v2 = f(mid2);

		ans = min(ans,v1);
		ans = min(ans,v2);

		if(v1>v2)
			lo = mid1;
		else
			hi = mid2;
	}
	

	printf("%.6f\n",ans);
}