#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

#define NOV 100005


int main(){
	ios_base::sync_with_stdio(false);
	int arr[3];
	for(int i=0;i<3;i++)
		cin>>arr[i];
	sort(arr,arr+3);

	int t=0;

	while(1){
		if(arr[0]+arr[1]>arr[2]){
			break;
		}
		arr[0]++;
		sort(arr,arr+3);
		t++;
	}
	cout<<t<<endl;
}