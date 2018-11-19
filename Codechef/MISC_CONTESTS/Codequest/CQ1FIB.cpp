#include <bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pb push_back
using namespace std;

int prim[100005];
set<ll> prims;

void sieve(){
	memset(prim,-1,sizeof(prim));
	prim[1]=0;
	for(int i=2;i<=100005;i++){
		if(prim[i]==-1)
		{
			prim[i]=1;
			prims.insert(i);
			for(int j=i+i;j<=100005;j+=i)
				prim[j]=0;
		}
	}
}
int fibo(ll num){
	double root5 = sqrt(5);
    double phi = (1 + root5) / 2;

    ll idx    = (ll)floor( log2(num*root5) / log2(phi) + 0.5 );
    ll u = (ll)floor( pow(phi, idx)/root5 + 0.5);

    return (u == num);
}

int main(int argc, char const *argv[])
{
	unordered_map<ll,int> um;
	int num;
	cin>>num;
	ll x;
	int cnt=0;
	while(num--){
		cin>>x;
		if(um.find(x)==um.end()){
			um[x]=1;
			cnt+=fibo(x);
		}
	}
	cout<<cnt<<endl;
	return 0;
}