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

#define NOV 200005

ll arr[NOV];
ll lft[NOV], rgt[NOV];
unordered_map<ll,ll> val;

int main(){
	ios_base::sync_with_stdio(false);

	ll n;
	cin>>n;

	for(int i=1;i<=n;i++)
		cin>>arr[i];

	stack<ll> s;
	int i = 1;
	while(i<=n){
		if(s.empty()){
			s.push(i);
			i++;
		}
		else{
			ll ind = s.top();
			if(arr[i]>=arr[ind])
			{
				s.push(i);
				i++;
			}
			else
			{
				rgt[ind] = i;
				s.pop();
			}
		}
	}
	while(!s.empty()){
		ll ind = s.top();
		s.pop();
		rgt[ind] = n+1;
	}

	i = n;
	while(i>=1){
		if(s.empty()){
			s.push(i);
			i--;
		}
		else{
			ll ind = s.top();
			if(arr[i]>=arr[ind])
			{
				s.push(i);
				i--;
			}
			else
			{
				lft[ind] = i;
				s.pop();
			}
		}
	}
	while(!s.empty()){
		ll ind = s.top();
		s.pop();
		lft[ind] = 0;
	}

	// for(int i=1;i<=n;i++)
	// 	cout<<lft[i]<<" ";
	// cout<<endl;

	// for(int i=1;i<=n;i++)
	// 	cout<<rgt[i]<<" ";
	// cout<<endl;

	ll cnt;
	for(int i=1;i<=n;i++){
		cnt = rgt[i]-lft[i]-1;
		if(val.find(cnt)==val.end())
			val[cnt] = arr[i];
		else
			val[cnt] = max(val[cnt],arr[i]);
	}
	ll ans[NOV];
	ans[n] = val[n];
	ll prev = n;
	for(int i=n-1;i>=1;i--){
		// cout<<"Here\n";
		if(val.find(i)!=val.end()){
			ans[i] = val[i];
			prev = i;
		}
		else
			ans[i] = val[prev];
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	
}