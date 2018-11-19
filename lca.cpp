#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

//Data structures
vector<int> tree[100005];
vector<int> euler_tour;
int ht[100005];
int first[100005];

int c=1;	
int len;	//length of euler tour

struct node{
	int x;
};

node segtree[400007];
int arr[100007];


//Methods

//Segment Tree construction

//merging two nodes
node merge(node &n1,node &n2){
	node n;
	if(ht[n1.x]<ht[n2.x])
		n.x=n1.x;
	else
		n.x=n2.x;
	return n;
}

void constructTree(int cur,int l,int r){
	if(l==r)
	{
		segtree[cur].x=arr[l];
		return;
	}

	int mid = l+(r-l)/2;
	constructTree(2*cur,l,mid);
	constructTree(2*cur+1,mid+1,r);

	segtree[cur]=merge(segtree[2*cur],segtree[2*cur+1]);
}

node query(int cur,int l,int r,int st,int e){
	node temp;
	temp.x=0;
	if(l>r)
		return temp;
	if(st>r||e<l)
		return temp;
	if(st<=l&&e>=r){
		temp=segtree[cur];
		return temp;
	}
	int mid = l+(r-l)/2;
	node x1 = query(2*cur,l,mid,st,e);
	node x2 = query(2*cur+1,mid+1,r,st,e);
	return merge(x1,x2);
}

//Finding LCA

void euler(int u,int h){
	ht[u]=h;
	first[u]=c;
	euler_tour.pb(u);
	c++;
	int v;
	for(int i=0;i<tree[u].size();i++){
		v = tree[u][i];
		euler(v,h+1);
		euler_tour.pb(u);
		c++;
	}
}

int lca(int v,int w){
	int u1,u2;
	if(first[v]<first[w]){
		u1 = first[v];
		u2 = first[w];
	}
	else{
		u1 = first[w];
		u2 = first[v];
	}
	return query(1,1,len,u1,u2).x;
}

//The input specified
void input_tree(){
	int n,m,x;
	cin>>n;
	for(int i=1;i<=n;i++){
		tree[i].clear();
		cin>>m;
		while(m--){
			cin>>x;
			tree[i].pb(x);
		}
	}
}	


int main(){
	ios_base::sync_with_stdio(false);
	
	int t;
	cin>>t;
	int tc=0;
	while(t--)
	{
	tc++;
	input_tree();
	
	euler_tour.clear();
	c=1;
	euler(1,1);

	//segmentTree Array
	for(int i=0;i<euler_tour.size();i++){
		arr[i+1] = euler_tour[i];
	}

	//construct the segment tree
	len = euler_tour.size()+1;
	ht[0]=INT_MAX;
	constructTree(1,1,len);

	//Output as specified
	int q;
	cin>>q;

	cout<<"Case "<<tc<<":"<<endl;
	while(q--){
		int v,w;
		cin>>v>>w;
		cout<<lca(v,w)<<endl;
		}		
	}


}