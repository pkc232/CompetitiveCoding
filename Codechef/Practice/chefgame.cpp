#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 747474747
using namespace std;

vector<vector<ll> >gr(7000);
int n,d;
ll PQ[7000];


ll dist(int u,int v)
{
	ll d=0;
	for(int i=0;i<d;i++)
		d+=(gr[u][i]-gr[v][i])*(gr[u][i]-gr[v][i]);
	return d;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	

	while(t--){
		cin>>n>>d;

		gr.clear();
		ll x;
		for(int i=1;i<=n;i++){
			for(int j=0;j<d;j++){
				cin>>x;
				gr[i].pb(x);
			}
		}

		memset(PQ,0,sizeof(PQ));
		
		PQ[1]=0;
		for(int i=1;i<=n;i++){
			ll ma=0;
			ll maind=1;

			for(int j=1;j<=n;j++){
				if(PQ[j]==-1)
					continue;

				if(PQ[j]>ma){
					ma=PQ[j];
					maind=j;
				}
			}

			for(int j=1;j<=n;j++){
				
			}

		}



	}
}