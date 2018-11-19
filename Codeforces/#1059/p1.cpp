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
	ll n,L,a;
	ll t[100007],l[100007];

	cin>>n>>L>>a;
	for(int i=0;i<n;i++){
		cin>>t[i]>>l[i];
	}
	int i=0;
	ll c=0,prev=0;
	while(i<n){
		if(t[i]>prev){
			c+=(t[i]-prev)/a;
			prev=t[i];
		}
		else
		{
			prev = t[i]+l[i];
			i++;
		}
	}
	c+=(L-prev)/a;
	cout<<c<<endl;
}