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

set<pii> intev;
int n,k,a;

unordered_set<int> pres;

int func(int l,int r){
	int len = r-l;

	int num = (len+1)/(a+1);
	return num;
}

void printset(set<pii> s){
	int li,ri;
	cout<<"----"<<endl;
	for(auto it = s.begin();it!=s.end();it++){
		pii p = (*it);
		li = p.ff;
		ri = p.ss;
		cout<<li<<" "<<ri<<endl;
	}
	cout<<"---"<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);


	
	cin>>n>>k>>a;

	int m;

	cin>>m;

	intev.insert(mp(0,n));
	int cnt = func(0,n);

	int x;
	set<pii> ::iterator it;

	int li,ri;

	int xi[m+5];
	for(int i=1;i<=m;i++)
		cin>>xi[i];
	for(int i=1;i<=m;i++){
		// printset(intev);

		x = xi[i];
		if(pres.find(x)!=pres.end())
			continue;
		pres.insert(x);

		it = intev.upper_bound(mp(x,x-1));
		
		it--;
		pii p = (*it);
		li = p.ff;
		ri = p.ss;

		// cout<<li<<" "<<ri<<endl;

		cnt -= func(li,ri);
		intev.insert(mp(li,x-1));
		intev.insert(mp(x,ri));

		cnt += func(li,x-1);
		cnt += func(x,ri);

		if(cnt<k){
			cout<<i<<endl;
			return 0;
		}
		intev.erase(it);
	}

	cout<<-1<<endl;

}