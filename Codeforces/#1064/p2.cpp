#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

#define NOV 100005


int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	int n,c;
	while(t--){
		cin>>n;
		c=0;
		while(n){
			if(n&1)
				c++;
			n>>=1;
		}
		cout<<(1<<c)<<endl;
	}
}