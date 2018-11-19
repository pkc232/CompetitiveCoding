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


int main(){
	ios_base::sync_with_stdio(false);

	int n;
	int l[1005];
	int r[1005];

	cin>>n;

	for(int i=0;i<n;i++)
		cin>>l[i];
	for(int j=0;j<n;j++)
		cin>>r[i];

	vector<pii>v;
	for(int i=0;i<n;i++)
		v.pb(mp(l[i]+r[i],i));

	int val[1005];
	sort(v.begin(), v.end());
	int curr = n;
	int prev = 0;

	int i=0;
	while(i<n){
		if(v[i].ff==prev){
			val[v[i].ss] = curr;
		}
		else
		{
			curr--;
			val[v[i].ss] = curr;
			prev = v[i].ff;
		}
		i++;
	}

	for(int i=0;i<n;i++){
		int c = 0;
		for(int j=i-1;j>=0;j--){
			if(val[j]>val[i])
				c++;
		}
		if(c!=l[i])
	}






}