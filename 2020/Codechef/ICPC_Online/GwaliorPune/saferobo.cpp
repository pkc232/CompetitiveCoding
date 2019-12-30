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


int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int sa, sb;
		cin >> sa >> sb;
		int l = s.length();
		int posa = -1, posb = -1;
		for (int i = 0; i < l; i++) {
			if (s[i] == 'A')
				posa = i + 1;
			else if (s[i] == 'B')
				posb = i + 1;
		}
		
		int len = posb - posa;
		if (len == 0)
			cout << "safe" << endl;
		else {
			if (len % (sa + sb) == 0)
				cout << "unsafe" << endl;
			else
				cout << "safe" << endl;
		}
	}
}