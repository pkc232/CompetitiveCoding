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
		ll n, a, b, c, d;
		cin >> n >> a >> b >> c >> d;
		ll p, q, y;
		cin >> p >> q >> y;
		map<ll, ll> m;
		for (int i = 1; i <= n; i++) {
			ll x;
			cin >> x;
			m[i] = x;
		}
		ll normTim = abs(m[a] - m[b])*p;
		ll trainTim = large_long_long_int;

		if (abs(m[a] - m[c]) * p <= y) {
			trainTim = y + abs(m[c] - m[d]) * q + abs(m[d] - m[b]) * p;
		}

		cout << min(normTim, trainTim)<<endl;

			

	}
}