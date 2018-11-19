#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll a[3];

ll count(ll num){
	ll x= sqrt(num);
	ll n1,n2,c=0;
	for(ll i=1;i<=x;i++){
		if((num%i)==0)
		{
			n1= i;
			n2=num/i;
			if(n1<=a[1]&&n2<=a[2]){
				c++;
			}

			if(n2<=a[1]){
				if(n1!=n2)
					c++;
			}
		}
	}

	return c;
}

int main(int argc, char const *argv[])
{
	/* code */

	int t;
	cin>>t;

	while(t--){
		ll n;
		cin>>n>>a[0]>>a[1]>>a[2];
		ll cnt=0;
		sort(a,a+3);

		for(ll i=1;i<=a[0];i++){
			if((n%i)==0)
			{
				cnt+=count(n/i);
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}