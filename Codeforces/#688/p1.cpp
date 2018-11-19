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
	int n,d;
	cin>>n>>d;
	int arr[d+4];
	for(int i=0;i<d+4;i++)
		arr[i]=1;
	string s;

	for(int i=0;i<d;i++){
		char x;
		for(int j=0;j<n;j++)
		{
			cin>>x;
			arr[i]&=(int)(x-'0');
		}
	}

	int c=0,ans=0;
	for(int i=0;i<d;i++){
		if(!arr[i]){
			c++;
			ans=max(ans,c);
		}
		else
			c=0;

	}
	cout<<ans<<endl;
}