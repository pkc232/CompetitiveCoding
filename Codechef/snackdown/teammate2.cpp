#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

ll cnt[1000007];
unordered_set<int> u;
vector<int> v;

int main(){
	ios_base::sync_with_stdio(false);

	int t,n,x;
	cin>>t;

	while(t--){
		cin>>n;
		memset(cnt,0,sizeof(cnt));
		v.clear();
		u.clear();
		for(int i=1;i<=n;i++){
			cin>>x;
			cnt[x]++;
			if(u.insert(x).second)
				v.pb(x);
		}

		sort(v.rbegin(), v.rend());

		ll prod = 1, prev=0, p1,c;

		for(int i=0;i<v.size();i++){
			if(prev){
				prod *= cnt[v[i]];
				prod %= MOD;
				cnt[v[i]]--;
			}

			c = cnt[v[i]];
			// cout<<c<<endl;
			if(c>1){
				p1 = (c*(c-1))/2;
				p1 %= MOD;
			}
			else
				p1 = 1;

			prod *= p1;
			prod %= MOD;
			prev = (c&1);
		}
		cout<<prod%MOD<<endl;	
	}
}