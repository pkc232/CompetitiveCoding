#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;
node tree[400007];
int arr[100007];

struct node{
	int x;
};

node merge(node &n1,node &n2){
	node n;
	n.x=n1.x+n2.x;
	return n;
}

void constructTree(int cur,int l,int r){
	if(l==r)
	{
		tree[cur].x=arr[l];
		return;
	}

	int mid = l+(r-l)/2;
	constructTree(2*cur,l,mid);
	constructTree(2*cur+1,mid+1,r);

	tree[cur]=merge(tree[2*cur],tree[2*cur+1]);
}

node query(int cur,int l,int r,int st,int e){
	node temp;
	temp.x=0;
	if(l>r)
		return temp;
	if(st>r||e<l)
		return temp;
	if(st<=l&&e>=r){
		temp=tree[cur];
		return;
	}
	int mid = l+(r-l)/2;
	node x1 = query(2*cur,l,mid,st,e);
	node x2 = query(2*cur+1,mid+1,r,st,e);
	return merge(x1,x2);
}





int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
}