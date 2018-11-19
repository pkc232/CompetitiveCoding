#include <bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pb push_back
#define ump unordered_map
#define omp map
#define ff first
#define ss second
#define MAX (1+(1<<6)) 
#define inf 0x7fffffff
using namespace std;

vector<pair<ll,ll> > xpos;
ll tree[3*100005];
omp<ll,ll> hts; 
omp<ll,ll> ans; 


void build_tree(int node, ll a, ll b) {
  	if(a > b) return; // Out of range
  	
  	if(a == b) { // Leaf node
    		tree[node] = xpos[a].second; // Init value
		return;
	}
	
	build_tree(node*2+1, a, (a+b)/2); // Init left child
	build_tree(node*2+2, 1+(a+b)/2, b); // Init right child
	
	tree[node] = max(tree[node*2+1], tree[node*2+2]); // Init root value
}

ll query_tree(int node, ll a, ll b, ll i, ll j) {
	
	if(a > b || a > j || b < i) return -inf; // Out of range

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	ll q1 = query_tree(node*2+1, a, (a+b)/2, i, j); // Query left child
	ll q2 = query_tree(2+node*2, 1+(a+b)/2, b, i, j); // Query right child

	ll res = max(q1, q2); // Return final result
	
	return res;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;

	ll x[n+1],h[n+1];vector<ll>norm;

	for(int i=0;i<n;i++){
		cin>>x[i]>>h[i];
		norm.pb(x[i]);
		xpos.pb(mp(x[i],x[i]+h[i]));
		hts[norm[i]]=h[i];
	}

	sort(xpos.begin(), xpos.end());
	sort(norm.begin(), norm.end());
	build_tree(0,0,n-1);

	// cout<<query_tree(0,0,n-1,5,6)<<endl;


	for(int i=n-1;i>=0;i--)
	{
		ll mxrch = norm[i]+hts[norm[i]];

		int ub = upper_bound(norm.begin(), norm.end(),mxrch)-norm.begin();
		ub--;
		
		ans[norm[i]]=query_tree(0,0,n-1,i,ub);
		// cout<<ans[x[i]]<<endl;
	}

	for(int i=0;i<n;i++)
		cout<<ans[x[i]]<<endl;



	return 0;
}