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
	cin.tie(NULL);

	int t;
	cin>>t;
	ll x,y,cn,cs,ce,cw,p;

	while(t--){

		cin>>x>>y>>cn>>cs>>ce>>cw>>p;


		ll s1=ce+cw,s2=cn+cs;

		ll r = p-ce*x-cn*y;

		if(r<0)
		{
			cout<<-1<<endl;
		}

		else
		{	
			ll mn=INT_MAX;
			for(ll p2=0;p2<=100000;p2++){
				if(p2*s1>r)
					break;
				ll chk = r - p2*s1;
				if(chk%s2==0)
					mn=min(mn,p2+chk/s2);
			}

			if(mn==INT_MAX)
				cout<<-1<<endl;
			else
			{
				ll ans = 2*mn+x+y;
				cout<<ans<<endl;
			}
		}

	}
}