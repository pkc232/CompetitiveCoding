#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define pii pair<int,int>
using namespace std;

#define NOV 100005

int arr[NOV];
int n;

int check(int val){
	int i;
	i = 0;
	while(i<n&&arr[i]==-1)
		i++;
	if(i==n)
		return 1;
	int cur = arr[i]-1;
	for(;i<n;i++,cur++){
		if(arr[i]==-1)
			continue;
		else if(arr[i]==(cur%val)+1)
			continue;
		else
			break;
	}
	return (i==n);
}

int main(){
	ios_base::sync_with_stdio(false);

	int t;
	cin>>t;
	
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		int mx = 1e7;
		

		if(check(mx)){
			cout<<"inf"<<endl;
			continue;
		}
		int k;
		for(k = 1000001;k>=1;k--){
			if(check(k))
			{
				cout<<k<<endl;
				break;
			}
		}
		if(k==0)
			cout<<"impossible"<<endl;
		// cout<<"uf\n";
	}
}