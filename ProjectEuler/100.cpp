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

	ll i = 1000001;
	ll p,sq;
	while(1){
		p = i*(i-1);
		p*=2;
		sq = sqrt(p);
		if(sq*(sq+1)==p)
			break;
		i++;
	}
	cout<<i<<" "<<p<<" "<<sq<<endl;


}