#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

vector<pair<int,int> > rests;
int main(){
	// ios_base::sync_with_stdio(false);
	// ifstream fin;
	// fin.open("input_restaurants_4.txt");
	// ofstream fout;
	// fout.open("output_restaurants_4.txt");
	int t;
	cin>>t;
	int ki=1;
	while(t--){
		rests.clear();
		int n,x,y;
		cin>>n;
		// cout<<n<<endl;
		while(n--){
			cin>>x>>y;
			// cout<<ki<<" "<<x<<" "<<y<<endl;
			rests.pb(mp(x,y));
		}
		sort(rests.rbegin(), rests.rend());
		int c=0,ymx=INT_MIN,prevx = INT_MIN;
		for(int i=0;i<rests.size();i++){
			// cout<<rests[i].ff<<" "<<rests[i].ss<<" "<<prevx<<endl;
			if(rests[i].ss>=ymx){
				c++;
				ymx=max(ymx,rests[i].ss);
			}
			else if(rests[i].ff>=prevx)
				c++;
			prevx = max(rests[i].ff,prevx);
		}
		cout<<c<<endl;
		// ki++;
	}
}