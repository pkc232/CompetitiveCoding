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

#define NOV 1005


long double arr[NOV];

int main(){
	ios_base::sync_with_stdio(false);

	int t;
	cin>>t;

	while(t--){
		int n;
		long double p,q;
		cin>>n>>p>>q;
		long double cos = p/q;
		vector< pair<ll, ll> > indexes;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			indexes.push_back( make_pair(arr[i], i+1) );
		}
		sort(indexes.begin(), indexes.end());
		for(int i=0;i<n;i++)
			arr[i] = indexes[i].first;
		long double x,y,z,z2;
		int ax=-1,ay=-1,az=-1;
		long double anscos = 2;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				x = arr[i],y=arr[j];
				z2 = x*x+y*y-2*x*y*cos;
				z = sqrt(z2);
				// cout<<"\nrequired z = "<<z<<endl;
				z = floor(z);
				int ind = upper_bound(arr,arr+n,z)-arr;
				// cout<<endl<<i<<" "<<j<<" "<<ind<<" : ";
				if(ind==0)
					continue;
				ind--;
				if(ind==j){
					ind--;
				}
				if(ind==i)
					ind--;
				if(ind<0)
					continue;
				// cout<<i<<" "<<j<<" "<<ind<<endl;
				z = arr[ind];
				if(z>=abs(x-y)){
					double curcos = x*x+y*y-z*z;
					curcos /= 2*x*y;
					if(curcos<anscos){
					ax=indexes[i].second;
					ay=indexes[j].second;
					az=indexes[ind].second;
					anscos = curcos;	
					}

				}
			}
		}

		if(ax==-1)
			cout<<-1<<endl;
		else
			cout<<az<<" "<<ax<<" "<<ay<<endl;

	}
}