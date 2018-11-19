#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;


int phi(int n){
	int x = sqrt(n);
	int res=n;
	for(int i=2;i<=x;i++){
		if(n%i==0)
		{
			while(n%i==0&&n>1)
				n/=i;
			res-=res/i;
		}
	}
	if(n>1)
		res-=res/n;
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	int n;
	while(t--){
		cin>>n;
		cout<<phi(n)<<endl;
	}
}