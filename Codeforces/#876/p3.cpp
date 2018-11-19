#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
using namespace std;


int noOfDig(ll num){
	int c=0;
	while(num){
		num/=10;
		c++;
	}
	return c;
}

int sod(ll num){
	int c=0;
	while(num){
		c+=(num%10);
		num/=10;
		
	}
	return c;
}

int main(int argc, char const *argv[])
{
	ll num;
	cin>>num;

	int mx=9*noOfDig(num),c=0;
	std::vector<ll> v;
	for(int i=0;i<=mx;i++){
		if(sod(num-i)==i)
		{
			v.pb(num-i);
			c++;
		}
	}

	cout<<c<<endl;
	sort(v.begin(), v.end());
	for(int i=0;i<c;i++){
		cout<<v[i]<<endl;
	}
	return 0;
}