#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;

	int freq[105];
	memset(freq,0,sizeof(freq));
	int ans=0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		freq[x]++;
		ans=max(ans,freq[x]);
	}
	cout<<ans<<endl;
}