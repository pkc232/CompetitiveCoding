#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

int isLucky(int x){
	stringstream ss;
	ss<<x;
	string t;
	ss>>t;
	for(int i=0;i<t.length();i++){
		if(t[i]=='4'||t[i]=='7')
			continue;
		return 0;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int q = sqrt(n);
	int f =0;
	for(int i=1;i<=q;i++){
		if(n%i==0){
			f|=isLucky(i);
			f|=isLucky(n/i);
			// cout<<i<<" "<<n/i<<" "<<f<<endl;
		}
	}
	if(f)
		cout<<"YES\n";
	else
		cout<<"NO\n";
}