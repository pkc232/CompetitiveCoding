#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

ll arr1[100007],arr2[100007];
int n;

void troubSort(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-2;j++){
			if(arr2[j]>arr2[j+2])
			{
				swap(arr2[j],arr2[j+2]);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t,i,j;
	cin>>t;

	for(int ti=1;ti<=t;ti++){
		cin>>n;
		cout<<"Case #"<<ti<<":"<<" ";
		for(i=0;i<n;i++){
			cin>>arr1[i];
			arr2[i]=arr1[i];
		}

		// sort(arr1,arr1+n);
		troubSort();

		for(int i=0;i<n-1;i++){
			if(arr2[i]>arr2[i+1])
			{
				cout<<i<<endl;
				goto cont;
			}
		}

		cout<<"OK"<<endl;

		cont:
		continue;

	}
}