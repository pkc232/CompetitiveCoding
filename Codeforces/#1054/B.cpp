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
int main(){
	ios_base::sync_with_stdio(false);

	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>arr[i];

	int curr = 0;
	int i=1;
	while(i<=n){
		if(arr[i]>curr)
			break;
		else if(arr[i]==curr){
			curr++;
		}
		i++;
	}

	if(i>n)
		cout<<-1<<endl;
	else
		cout<<i<<endl;
}