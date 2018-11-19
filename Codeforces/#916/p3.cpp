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


int	main(){
	ios_base::sync_with_stdio(false);
	ll n,m;
	cin>>n>>m;
	sieve();

	set<ll> :: iterator it;
	it= prims.lower_bound(n-1);

	ll ms= (*it);
	cout<<ms<<" "<<ms<<endl;
	for(int i=1;i<n-1;i++){
		cout<<i<<" "<<i+1<<" "<<1<<endl;
	}
	cout<<n-1<<" "<<n<<" "<<(ms-(n-2))<<endl;

	m-=(n-1);
	int i=1,cnt=2;
	while(m--){
		if(i+cnt>n)
		{
			i++;
			cnt=2;
		}
		cout<<i<<" "<<i+cnt<<" "<<ms+1<<endl;
		cnt++;
	}
}