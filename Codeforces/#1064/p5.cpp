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
	cin>>n;
	string col;
	map<string,int> cols;

	int lo = 0, hi = 1e9;
	cout<<"0 1"<<endl;
	cin>>col;

	if(col == "black"){
		cols["black"] = 0;
		cols["white"] = 1;
	}
	else{
		cols["white"] = 0;
		cols["black"] = 1;
	}

	n--;
	int mid;
	int ans;
	while(n--){
		mid = lo + (hi-lo)/2;
		cout<<mid<<" "<<1<<endl;
		// cout<<mid<<" "<<col<<endl;
		cin>>col;
		if(cols[col]){
			hi = mid;
		}
		else
		{
			lo = mid;
		}
	}

	cout<<lo<<" "<<2<<" "<<hi<<" "<<0<<endl;

}