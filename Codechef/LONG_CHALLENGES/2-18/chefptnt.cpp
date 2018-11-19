#include <bits/stdc++.h>
#define ll long long int
using namespace std;


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;

	while(t--){
		ll n,m,x,k;
		int ev=0,od=0;
		cin>>n>>m>>x>>k;
		char c;
		for(int i=0;i<m;i++){
			cin>>c;
			ev+=(c=='E');
			od+=(c=='O');
		}

		int evm=m/2,odm=(m+1)/2;

		n-=min(ev/x+ev%x,evm*x);
		n-=min(od/x+od%x,odm*x);

		if(n<=0)
			cout<<"yes\n";
		else
			cout<<"no\n";

	}
	return 0;
}
