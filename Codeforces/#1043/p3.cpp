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

	string s;
	cin>>s;

	int len = s.length();
	char frst = s[0];
	s+='b';
	for(int i=0;i<len;i++){
		if(frst==s[i+1]){
			cout<<1<<" ";
			frst = s[i];
		}
		else
			cout<<0<<" ";
	}
	cout<<endl;
}