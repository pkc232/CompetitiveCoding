#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define MOD 1000000007
#define mp make_pair
using namespace std;


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int c=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++){
			int xr= (i^j);
			if((xr<(i+j))&&(xr>=j)&&(xr<=n)){
				// cout<<i<<" "<<j<<" "<<xr<<endl;
				c++;
			}
		}
	}	

	cout<<c<<endl;
	return 0;
}
