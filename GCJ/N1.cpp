#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;


int main(){
	int t;
	cin>>t;
	ll a,b,n,mid;
	string s;
	while(t--){
		cin>>a>>b;
		cin>>n;
		while(n--){
		mid= a+(b-a)/2;
		cout<<mid<<endl;
		cin>>s;
		if(s=="TOO_BIG")
		{
			b=mid;
		}
		else if(s=="TOO_SMALL")
			a=mid;
		else
			break;
		}
	}
}