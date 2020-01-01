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
		int k;
		string s;
		cin >> s >> k;
		int cnt[26];
		memset(cnt, 0, sizeof(cnt));
		for (char c : s) 
			cnt[c - 'a'] = 1;
		int l = s.length();
		string s2 = "";
		int ch = 0;
		while (1) {
			if (l == 0 || ch == 26)
				break;
			if (cnt[ch] == 0) {
				s2 += (char)(ch+'a');
				l--;
			}
			else
			{
				if (k)
				{
					s2 += (char)(ch + 'a');
					k--;
					l--;
				}
			}
			ch++;
		}
		//cout << "Hello" << endl;
		if (l)
			cout << "NOPE" << endl;
		else
			cout << s2 << endl;
	}
}