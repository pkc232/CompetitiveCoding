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

ll ans;
ll one = 1;
struct node{
	int noc;
	node *lc, *rc;
	int isLeaf;
};

void initialize(node *n){
	n->noc = 0;
	n->lc = n->rc = NULL;
	n->isLeaf = 0;
}

void addWord(string w,node *n,int ind){
	if(ind==w.length())
	{
		n->isLeaf = 1;
		return;
	}
	if(w[ind]=='B'){
		if(n->lc==NULL){
			n->lc = new node();
			initialize(n->lc);
		}
		addWord(w,n->lc,ind+1);
	}
	else{
		if(n->rc==NULL){
			n->rc = new node();
			initialize(n->rc);
		}
		addWord(w,n->rc,ind+1);
	}
}

void compute(node *n,ll ht){
	if(n==NULL)
		return;
	if(n->isLeaf){
		ans -= one<<ht;
		return;
	}
	compute(n->lc,ht-1);
	compute(n->rc,ht-1);
}

int main(){
	// ios_base::sync_with_stdio(false);
	ifstream fin;
	fin.open("ip1.in");
	ofstream fout;
	fout.open("op1.txt");

	int T;
	fin>>T;
	string s;
	for(int ti=1;ti<=T;ti++){
		vector<pair<ll,string> > v;
		ll n,p;
		fin>>n>>p;
		node *root = new node();
		initialize(root);
		for(int i=0;i<p;i++){
			fin>>s;
			// v.pb(mp(s.length(),s));
			addWord(s,root,0);
		}
		// sort(v.begin(), v.end());
		
		ans = one<<n;
		compute(root,n);
		fout<<"Case #"<<ti<<": "<<ans<<endl;
	}
}