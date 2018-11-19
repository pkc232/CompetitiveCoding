#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

struct node{
	int x;
};

node segtree[400007];
int arr[100007];

node merge(node &n1,node &n2){
	node n;
	n.x=n1.x+n2.x;
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

void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        // Leaf node
        arr[idx] = val;
        segtree[node].x=val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        segtree[node] = merge(segtree[2*node],segtree[2*node+1]);
    }
}





int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>arr[i];

	constructTree(1,1,n);

	int q,st,e,c;
	cin>>q;
	while(q--){
		cin>>c>>st>>e;
		if(c==1)
		cout<<(query(1,1,n,st,e)).x<<endl;
		else
		update(1,1,n,st,e);
	}
}