#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;


void agrt(ll &a,ll &b){
	a%=(2*b);
	return;
}

void bgrt(ll &a,ll &b){
	b%=(2*a);
	return;
}


int main(){
	ios_base::sync_with_stdio(false);
	ll n,m,a,b;
	cin>>n>>m;
	a=n,b=m;
	while(a&&b){
		if(a>=(2*b))
			agrt(a,b);
		else if((b>=(2*a)))
			bgrt(a,b);
		else
			break;
	}
	cout<<a<<" "<<b<<endl;

}