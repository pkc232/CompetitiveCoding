#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
using namespace std;


int main(int argc, char const *argv[])
{
	int n,pos,l,r,ans=0;
	cin>>n>>pos>>l>>r;


	if(pos<l){
		ans+=l-pos;
		pos=l;
	}
	else if(pos>r){
		ans+=pos-r;
		pos=r;
	}

	if(l>1&&r<n){
		ans+=2*min(r-pos,pos-l)+max(r-pos,pos-l)+2;
	}
	else
	{
		if(l==1&&r<n)
		{
			ans+=r-pos+1;
		}
		else if(r==n&&l>1){
			ans+=pos-l+1;
		}

	}
	cout<<ans<<endl;
	return 0;
}