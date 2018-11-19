#include<bits/stdc++.h>
using namespace std;


int main(){
	int n,m,i,j,l,r;
	cin>>n>>m;

	int arr[n+5];
	for(i=1;i<=n;i++)
		cin>>arr[i];

	int incr[n+5],decr[n+5];

	incr[n]=n;
	decr[n]=n;

	i=n-1;
	while(i>0){
		if(arr[i]>=arr[i+1])
			decr[i]=decr[i+1];
		else
			decr[i]=i;

		if(arr[i]<=arr[i+1])
			incr[i]=incr[i+1];
		else
			incr[i]=i;
		i--;
	}
	while(m--){
		cin>>l>>r;
		if(decr[incr[l]]>=r)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}


}