#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
using namespace std;


int main(int argc, char const *argv[])
{
	int n,a,b,c;
	cin>>n;
	cin>>a>>b>>c;

	int ans=0;
	n--;
	int d1=a,d2=b,d3=c;
	if(n>0){
		if(d1<d2){
			ans+=d1;
		}
		else
			ans+=d2;
	}

	n--;

	if(n>0)
		ans+=n*min(a,min(b,c));

	cout<<ans<<endl;
	return 0;
}