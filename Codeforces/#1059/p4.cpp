#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;


ll x[100005],y[100005];
int n;

double getRad(double a){
	double mx = 0;
	double val;
	for(int i=1;i<=n;i++){
		val = (x[i]-a)*(x[i]-a);
		// cout<<a<<" "<<x[i]-a<<endl;
		val += y[i]*y[i];
		val /= 2.0;
		if(y[i]==0)
			continue;
		val /= (double)y[i];
		// cout<<val<<endl;
		mx = max(mx,abs(val));
	}
	return mx;
}


int precheck(){
	int cnt0=0,cntp=0,cntn=0;
	for(int i=1;i<=n;i++)
	{
		if(y[i]>0)
			cntp++;
		else if(y[i]<0)
			cntn++;
		else
			cnt0++;
	}
	if(cntp&&cntn)
		return 1;
	if(cnt0>1)
		return 1;
	return 0;

}

int main(){
	ios_base::sync_with_stdio(false);

	cin>>n;
	int ind=-1;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		if(y[i]==0)
			ind=i;
	}

	if(precheck())
	{
		printf("-1\n");
		return 0;
	}

	if(ind!=-1){
		double r = getRad(x[ind]);
		printf("%.8f\n",r);
		return 0;
	}

	double mid1,mid2;
	double lo = -1e15,hi=1e15,r1,r2;
	double ans = 1e15;
	for(int i=1;i<=200;i++){
		double diff = (hi-lo)/3.0;
		mid1 = lo + diff;
		mid2 = hi - diff;
		r1 = getRad(mid1);
		r2 = getRad(mid2);
		// cout<<"diff "<<diff<<endl;
		// cout<<"mid1 "<<mid1<<endl;
		// cout<<"mid2 "<<mid2<<endl;
		// cout<<"r1 "<<r1<<endl;
		// cout<<"r2 "<<r2<<endl;
		ans = min(ans,r1);
		ans = min(ans,r2);
		if(r1>r2)
			lo = mid1;
		else
			hi = mid2;

	}	
	printf("%.8f\n",ans);
}