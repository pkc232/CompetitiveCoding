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
	s += 'A';
	string ans = "";
	int i=0;
	for(i=0;i<s.length()-1;i++){
		// cout<<s[i]<<" "<<s[i+1]<<endl;
		if(s[i]>s[i+1]){
			break;
		}
		else
			ans += s[i];
	}
	i++;
	while(i<s.length()-1){
		ans += s[i];
		i++;
	}
	cout<<ans<<endl;


}