#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

std::vector<vector<int> >factrs(800000);
ll cnt[800000];
int prim[800000];


void precompute(){
	for( int i=1;i<=750007;i++ )
		factrs[i].clear();
	for(int i=1;i<=750007;i++){
		for(int j=i;j<=750007;j+=i){
			factrs[j].push_back(i);
		}
	}
}



int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	precompute();
	precompute();
	precompute();
	
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		int a[n];
		for(int i=0;i<n;i++)
			scanf("%d", &a[i]);
		sort(a,a+n);
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;i++){
			ll temp=0;
			for(int j=0;j<factrs[a[i]].size();j++){
				temp+=cnt[factrs[a[i]][j]];
				temp%=mod;
			}
			temp+=1;
			temp%=mod;
			cnt[a[i]]+=temp;
			cnt[a[i]]%=mod;
		}
		ll ans=0;
		for(int i=1;i<=750000;i++){
			/*if(i<=10)
				cout<<cnt[i]<<" ";
			
			if(i==10)
				cout<<endl;*/
			ans+=cnt[i];
			ans%=mod;
		}
		printf("%lld\n", ans);

	}
	return 0;
}