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

#define NOV 10005

vector<pair<int, int> > gr[NOV];
int dis[NOV];
int N;

int dijkstra(int s, int t) {
	for (int i = 0; i <= N+1; i++)
		dis[i] = INT_MAX;
	dis[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > pq;

	pq.push(mp(dis[s], s));

	while (!pq.empty()) {
		pii top = pq.top();
		pq.pop();

		int v = top.ss, d = top.ff;
		if (v == t)
			return dis[t];
		if (d <= dis[v]) {
			for (pii p : gr[v]) {
				int v2 = p.ff, cost = p.ss;
				if (dis[v2] > dis[v] + cost) {
					dis[v2] = dis[v] + cost;
					pq.push(mp(dis[v2], v2));
				}
			}
		}
	}
	return dis[t];
}

int getdiff(int x1, int x2, int n) {
	int i1 = (x1-1) / n + 1;
	int j1 = (x1 - 1) % n + 1;

	int i2 = (x2 - 1) / n + 1;
	int j2 = (x2 - 1) % n + 1;

	return abs(i1 - i2) + abs(j1 - j2);
}

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		for (int i = 0; i < NOV; i++) {
			gr[i].clear();
		}
		int n, K;
		cin >> n >> K;
		N = n*n;
		int arr[n + 2][n + 2];
		vector<int> lst[N+5];
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> arr[i][j];
				lst[arr[i][j]].pb((i - 1) * n + j);
			}
		}

		for (int i = 1; i < K; i++) {
			for (int j = 0; j < lst[i].size(); j++) {
				for (int k = 0; k < lst[i + 1].size(); k++) {
					int x1 = lst[i][j], x2 = lst[i + 1][k], dist = getdiff(x1, x2, n);
					//cout << "Between " << x1 << " " << x2 << " " << dist << endl;
					gr[x1].pb(mp(x2, dist));
				}
			}
		}

		int mindist = INT_MAX;;
		for (int i = 0; i < lst[1].size(); i++) {
			gr[0].pb(mp(lst[1][i],0));
		}
		for (int i = 0; i < lst[K].size(); i++) {
			gr[lst[K][i]].pb(mp(N + 1,0));
		}
		cout << dijkstra(0,N+1) << endl;
	}
}