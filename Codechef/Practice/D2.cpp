#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;
int arr[3*10007];
int dp[3*10007];



int main(){
	ios_base::sync_with_stdio(false);

	int t;
	cin>>t;
	int n;
	
	while(t--){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	for(int j=n+1;j<2*n;j++)
		arr[j]=arr[j-n];

	dp[1]=1;

	for(int i=2;i<2*n;i++){
		int c=0;
		dp[i]=1;
		for(int j=i-1;j>=0&&c<n-1;j--,c++){
			if(arr[i]>arr[j]){
				dp[i]=max(dp[i],1+dp[j]);
			}
		}
	}
	cout<<dp[2*n-1]<<endl;





	}


}