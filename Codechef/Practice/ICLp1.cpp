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

	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;

		int arr[n][m];

		int s1=0,s2=0;
		std::vector<int> v;

		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				cin>>arr[i][j];
				s1+=arr[i][j];
				v.pb(arr[i][j]);
			}

		sort(v.begin(), v.end());

		int l=v.size();

		for(int i=l-1;i>=0;i-=2){
			s2+=v[i];
		}

		if(s1-s2==s2)
			cout<<"Draw\n";
		else
			cout<<"Cyborg\n"; 	

	}
}