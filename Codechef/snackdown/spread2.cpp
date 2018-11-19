#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

ll arr[100007];


int main(){

	int t,n;
	scanf("%d",&t);

	while(t--){
		scanf("%d",&n);

		for(int i=1;i<=n;i++)
			scanf("%lld",&arr[i]);
		
		// memset(curr,0,sizeof(curr));
		
		ll d = 0;
		
		ll curr = arr[1],ind=2,ncur;
		
		while(1){
			if(ind>n)
				break;
			ncur = curr;
			for(ll i=1;i<=curr;i++){
				ncur += arr[ind];
				ind++;
				if(ind>n)
					break;
			}
			curr = ncur;
			d++;
		}
		
		printf("%lld\n",d);
	}
}