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


int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	string s;
	cin>>s;
	string ans;
	for(int i=1;i<s.length();i++){
		if(s[i]!=s[i-1]){
			cout<<"YES\n";
			ans = s[i-1];
			ans += s[i];
			cout<<ans<<endl;
			return 0;
		}
	}

	cout<<"NO\n";
}