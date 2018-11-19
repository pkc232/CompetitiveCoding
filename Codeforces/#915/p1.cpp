#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
using namespace std;



int main(int argc, char const *argv[])
{
	int n,k;
	cin>>n>>k;
	unordered_set<int> uo;
	uo.insert(n);
	uo.insert(k);

	cout<<uo.size()<<endl;
	// int arr[n];
	// int no=INT_MAX,ans=1;
	// for(int i=0;i<n;i++){
	// 	cin>>arr[i];
		
	// 	if(k%arr[i]==0){
	// 		ans=max(ans,arr[i]);
	// 	}
	// }
	// cout<<k/ans<<endl;
	// return 0;
}