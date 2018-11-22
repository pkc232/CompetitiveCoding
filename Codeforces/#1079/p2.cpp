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

	// cout<<s.length()<<endl;
	int l = s.length();
	int c,r;

	for(r=1;r<=5;r++){
		c = (l+(r-1))/r;
		if(c<=20)
			break;
	}

	int ast = c*r-l;
	char ans[r+5][c+5];
	memset(ans,'.',sizeof(ans));
	for(int j=1;j<=c;j++){
		if(ast==0)
			break;
		for(int i=1;i<=r;i++){
			ans[i][j] = '*';
			ast--;
			if(ast==0)
				break;
		}
	}
	int charc = 0;
	cout<<r<<" "<<c<<endl;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			if(ans[i][j]=='*')
				cout<<ans[i][j];
			else
				cout<<s[charc++];
		}
		cout<<endl;
	}

}