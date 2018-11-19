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

int dis[1007];

int calc(pii p1,pii p2){
	return abs(p1.ff-p2.ff)+abs(p1.ss-p2.ss);
}

int main(){
	ios_base::sync_with_stdio(false);


	int t;
	cin>>t;
	int n,m;
	vector<pii> v;
	while(t--){
		cin>>n>>m;
		char x;
		v.clear();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
					cin>>x;
					if(x=='1')
						v.pb(mp(i,j));
			}
		sort(v.begin(), v.end());
		int l = v.size();
		memset(dis,0,sizeof(dis));
		int cnt = 0;
		for(int d=1;d<=n+m-2;d++){
			cnt = 0;
			for(int i=0;i<l;i++){
				for(int j=i+1;j<=i+d&&j<l;j++){
					if(calc())
				}
			}
		}

		cout<<endl;
	}
}