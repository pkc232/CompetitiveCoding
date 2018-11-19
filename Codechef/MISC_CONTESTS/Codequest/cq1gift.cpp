#include <bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pb push_back
using namespace std;

int prim[100005];
set<ll> prims;

void sieve(){
	memset(prim,-1,sizeof(prim));
	prim[1]=0;
	for(int i=2;i<=100005;i++){
		if(prim[i]==-1)
		{
			prim[i]=1;
			prims.insert(i);
			for(int j=i+i;j<=100005;j+=i)
				prim[j]=0;
		}
	}
}


int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	vector<ll> arr(n+2);ll x,y;
	cin>>x>>y;

	for(int i=0;i<n;i++)
		cin>>arr[i];
	arr[n]=x;
	arr[n+1]=y;
	n+=2;
	sort(arr.begin(), arr.end());

	ll dist =0 ;


	int xpos = lower_bound(arr.begin(), arr.end(),x)-arr.begin();
	int ypos = lower_bound(arr.begin(), arr.end(),y)-arr.begin();

	for(int i = min(xpos,ypos);i>0;i--)
		dist+=2*(arr[i]-arr[i-1]);
	for(int i=max(xpos,ypos);i<n-1;i++)
		dist+=2*(arr[i+1]-arr[i]);
	for(int i=min(xpos,ypos);i<max(xpos,ypos);i++)
		dist+=arr[i+1]-arr[i];
	cout<<dist<<endl;
	return 0;
}