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
		int n;
		cin >> n;
		ll arr[100005];
		arr[0] = 0;
		ll s[100005];
		s[0] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			s[i] = s[i-1] + arr[i];
		}
		for (int i = n+1; i <= 100000; i++)
		{
			arr[i] = (s[i - 1] - s[i - (n + 1)])/n;
			s[i] = s[i - 1] + arr[i];
		}
		ll lastelm = arr[100000];
		int brkpt = -1;
		for (int i = 100000; i >= n; i--) {
			if (arr[i] != arr[i - 1]) {
				brkpt = i;
				break;
			}
		}

		int q;
		cin >> q;
		while (q--) {
			ll x;
			cin >> x;
			if (x > brkpt) {
				cout << lastelm << endl;
			}
			else
				cout << arr[x] << endl;
		}
			

		
	}
}