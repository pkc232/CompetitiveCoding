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

set<ll> L;
set<ll> R;

ll arr[NOV];
int main(){
	ios_base::sync_with_stdio(false);

	ll n,m,l;
	cin>>n>>m>>l;

	for(int i=1;i<=n;i++)
		cin>>arr[i];

	int left = -1;
	int right = left;

	int i = 1;
	while(i<=n){
		if(arr[i]>l){
			left = i;
			right = i+1;
			while(right<=n&&arr[right]>l){
				right++;
			}
			i = right;
			L.insert(left);
			R.insert(right-1);
		}
		else
			i++;
	}
	int q;
	ll p,d;
	while(m--){
		cin>>q;
		if(q==0){
			cout<<L.size()<<endl;
		}
		else
		{
			cin>>p>>d;
			if(arr[p]<=l&&arr[p]+d>l){
				if(L.find(p+1)!=L.end()&&R.find(p-1)!=R.end()){
					L.erase(p+1);
					R.erase(p-1);
				}
				else if(L.find(p+1)!=L.end()){
					L.erase(p+1);
					L.insert(p);
				}
				else if(R.find(p-1)!=R.end()){
					R.erase(p-1);
					R.insert(p);
				}
				else
				{
					L.insert(p);
					R.insert(p);
				}
			}
			arr[p] += d;
		}
	}

}