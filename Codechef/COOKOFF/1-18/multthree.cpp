#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

ll matrixExpo(ll num){
	if(num==0)
		return 1;
	if(num==1)
		return 2;
	ll x;
	if((num&1)==0)
	{
		x =matrixExpo(num/2);
		return ((((x%10)*(x%10))%10));
	}
	else
	{
		x= matrixExpo(num-1);
		// cout<<"Here "<<x<<endl;
		return (((2*(x%10))%10));
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	ll k,d0,d1;
	cin>>t;
	while(t--)
	{
	cin>>k>>d0>>d1;
	cout<<endl;
	cout<<d0<<d1;
	for(int i=2;i<k;i++)
		cout<<((matrixExpo(i-2)*(d0+d1))%10);
	cout<<endl;
	ll s = ((matrixExpo(k-1)*(d0+d1))%10);
	cout<<s<<endl;
	}

}