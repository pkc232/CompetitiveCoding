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

set<int> present;
set<int> pos;

void printset(set<int> s){
	for(auto it = s.begin();it!=s.end();it++){
		cout<<(*it)<<" ";
	}
	cout<<endl;
}

int main(){
	// ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<pair<int,int> > v; 
	char x;
	int num;
	for(int i=1;i<=n;i++){
		cin>>x>>num;
		if(x=='+'){
			v.pb(mp(1,num));
			pos.insert(num);
		}
		else if(x=='-'){
			if(pos.find(num)==pos.end()){
				present.insert(num);
				pos.insert(num);
				// cout<<"insert "<<num<<endl;
			}
			v.pb(mp(0,num));
		}
	}

	int mx=present.size();

	for(pii i:v){
		// printset(present);
		// cout<<present.size()<<endl;
		if(i.ff==1){
			present.insert(i.ss);
			mx= max(mx,(int)(present.size()));
		}
		else{
			present.erase(i.ss);
		}
	}

	cout<<mx<<endl;
}