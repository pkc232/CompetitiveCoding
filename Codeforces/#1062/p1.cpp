#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define pii pair<int,int>
#define large_int 2139062143
#define large_long_long_int 9187201950435737471
using namespace std;

#define NOV 100005


int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;

	ll arr[105];
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	arr[n+1] = 1001;
	arr[0] = 0;
	int actarr[1005];
	for(int i=1;i<=1001;i++)
		actarr[i] = i;

	int lo=0,cnt=0,c=0,i=0;
	while(lo<=n+1&&i<=1001){
		// cout<<lo<<endl;
		if(arr[lo]==actarr[i]){
			c++;
			i++;
			lo++;
		}
		else
		{
			if(c>1){
				cnt += c-2;
			}
			c=0;
			i++;
		}
	}
	if(c>1)
		cnt += c-2;
	cout<<cnt<<endl;

}