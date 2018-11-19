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

#define NOV 1000005

int cnt[NOV];
unordered_set<int> val;

int main(){
	ios_base::sync_with_stdio(false);

	int t;
	cin>>t;
	int n,x,a,b;
	vector<pii> v;
	while(t--){
		cin>>n;
		memset(cnt,0,sizeof(cnt));
		v.clear();
		val.clear();
		for(int i=1;i<=n;i++){
			cin>>x;
			cnt[x]++;
			val.insert(x);
		}
		for(auto it=val.begin();it!=val.end();it++){
			x = (*it);
			v.pb(mp(x,cnt[x]));
		}

		sort(v.begin(), v.end());

		int c = 0;
		int l = v.size();
		int ai,aj,fi,fj;
		for(int i=0;i<l;i++){
			ai = v[i].ff;
			fi = v[i].ss;
			for(int j=0;j<l;j++){
				aj = v[j].ff;
				fj = v[j].ss;
				if(aj>fi)
					break;
				else{
					if(fj>=ai)
						c++;
				}
			}
		}
		cout<<c<<endl;
	}

}