#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll arr[100007];
ll n,k,b;

int len(){
	ll prev=arr[0];
	int l=1;
	for(int i=1;i<n;i++){
		if(arr[i]>=(k*prev+b)){
			l++;
			prev=arr[i];
		}
	}
	return l;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		
		cin>>n>>k>>b;
		for(int i=0;i<n;i++)
			cin>>arr[i];

		sort(arr,arr+n);

		cout<<len()<<endl;

	}
	return 0;
}