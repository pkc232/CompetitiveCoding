#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;
int n;
ll arr[100007];
ll sum[100007];
ll votes[100007];
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		sum[0]=0;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			sum[i]=sum[i-1]+arr[i];
		}
		memset(votes,0,sizeof(votes));

		for(int j=2;j<=n;j++){
			int lo=1,hi=j-1,ans=j-1;
			int mid;
			while(lo<=hi){
				mid=lo+(hi-lo)/2;
				if(sum[j-1]-sum[mid]<=arr[j]){
					ans=min(ans,mid);
					hi=mid-1;
				}
				else
					lo=mid+1;
			}

			votes[ans]+=1;
			votes[j]-=1;
		}
		for(int i=1;i<=n;i++)
			votes[i]=votes[i-1]+votes[i];
		ll narr[n+2];
		memset(narr,0,sizeof(narr));

		for(int j=n-1;j>=1;j--){
			int lo=j+1,hi=n,ans=j+1;
			int mid;
			while(lo<=hi){
				mid=lo+(hi-lo)/2;
				if(sum[mid-1]-sum[j]<=arr[j]){
					ans=max(ans,mid);
					lo=mid+1;
				}
				else
					hi=mid-1;
			}

			narr[j+1]+=1;
			narr[ans+1]-=1;
		}

		for(int i=1;i<=n;i++)
			narr[i]=narr[i-1]+narr[i];

		for(int i=1;i<=n;i++)
			cout<<votes[i]+narr[i]<<" ";
		cout<<endl;		


	}
}