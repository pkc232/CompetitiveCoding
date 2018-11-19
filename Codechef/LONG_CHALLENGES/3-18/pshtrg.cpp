#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

struct node{
	vector<ll> v;
};

node tree[300007];
ll arr[100007];

node merge(node &n1,node &n2){
	node n;
	vector<ll> temp;

	int i=0,j=0,k=0,l1=(n1.v).size(),l2=(n2.v).size();

	while(i<l1&&j<l2&&k<46){
		if(n1.v[i]>=n2.v[j])
		{
			temp.pb(n1.v[i]);
			i++;
		}
		else
		{
			temp.pb(n2.v[j]);
			j++;	
		}
		k++;
	}
	while(i<l1&&k<46){
		temp.pb(n1.v[i]);
			i++;
			k++;
	}
	while(j<l2&&k<46){
		temp.pb(n2.v[j]);
			j++;
			k++;
	}
	// for(int i=0;i<temp.size();i++)
	{
		n.v=temp;
	}
	return n;
}

void constructTree(int cur,int l,int r){
	if(l>r)
		return;
	if(l==r)
	{
		(tree[cur].v).pb(arr[l]);
		return;
	}

	int mid = l+(r-l)/2;
	constructTree(2*cur,l,mid);
	constructTree(2*cur+1,mid+1,r);

	tree[cur]=merge(tree[2*cur],tree[2*cur+1]);
}

node query(int cur,int l,int r,int st,int e){
	node temp;
	if(l>r)
		return temp;
	if(st>r||e<l)
		return temp;
	if(st<=l&&e>=r){
		temp=tree[cur];
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
        (tree[node].v)[0]=val;
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
        tree[node] = merge(tree[2*node],tree[2*node+1]);
    }
}





int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int q,st,e,c;
	int n;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>arr[i];

	constructTree(1,1,n);

	while(q--){
		cin>>c>>st>>e;
		if(c==2){
		ll mx =0;
		vector<ll> v=(query(1,1,n,st,e)).v;
		for(int i=0;i<=((int)(v.size())-3);i++){
			if(v[i]<v[i+1]+v[i+2])
			{
				mx=v[i]+v[i+1]+v[i+2];
				break;
			}
		}
		cout<<mx<<endl;
		}
		else
		update(1,1,n,st,e);
	}
}