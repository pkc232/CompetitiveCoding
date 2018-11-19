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

unordered_map<string,int> present;

unordered_map<char,int> val;

int gettime(string s){

	if(present.find(s)!=present.end())
		return (present[s]/2);
	int l = s.length();
	int cur = val[s[0]];
	int tim = 2;
	for(int i=1;i<l;i++){
		// cout<<cur<<" "<<val[s[i]]<<endl;
		if(val[s[i]]!=cur)
			tim+=2;
		else
			tim+=4;
		cur = val[s[i]];
	}
	// cout<<tim<<endl;
	return present[s] = tim;
}

int main(){
	ios_base::sync_with_stdio(false);
	val['d'] = val['f'] = 0;
	val['j'] = val['k'] = 1;
	int t,n;
	cin>>t;
	string s;
	while(t--){
		present.clear();
		cin>>n;
		int sum=0;
		while(n--){
			cin>>s;
			sum+=gettime(s);
			// cout<<sum<<endl;
		}
		cout<<sum<<endl;

	}
}