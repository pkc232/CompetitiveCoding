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

int gcd(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}


int main(){
	ios_base::sync_with_stdio(false);

	// int t;
	// cin>>t;
	int a,b,c,g,x,y,x0,y0;
	// for(int ti = 1;ti<=t;ti++){
		cin>>a>>b>>c;
		g = gcd(a,b,x,y);
		// cout<<"Case "<<ti<<": ";
		if(c%g)
		{
			cout<<"No\n";
		}
		else
		{
			if(x>=0&&y<0)
				cout<<"No\n";
			else
				cout<<"Yes\n";
		}

	// }
}