#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;



struct node{
	vector<int> vec;
};

node segtree[800007];
int arr[200007];

vector<int> mergeVector(vector<int> &v1, vector<int> &v2){
	int s1 = v1.size();
	int s2 = v2.size();

	vector<int> v;
	int i=0,j=0;

	while(i<s1&&j<s2){
		if(v1[i]<=v2[j])
		{
			v.pb(v1[i]);
			i++;
		}
		else
		{
			v.pb(v2[j]);
			j++;
		}
	}

	while(i<s1){
		v.pb(v1[i]);
		i++;
	}

	while(j<s2){
		v.pb(v2[j]);
		j++;
	}

	return v;
}

node merge(node &n1,node &n2){
	node n;
	n.vec = mergeVector(n1.vec,n2.vec);
	return n;
}

void constructTree(int cur,int l,int r){
	if(l==r)
	{
		segtree[cur].vec.pb(arr[l]);
		return;
	}

	int mid = l+(r-l)/2;
	constructTree(2*cur,l,mid);
	constructTree(2*cur+1,mid+1,r);

	segtree[cur]=merge(segtree[2*cur],segtree[2*cur+1]);
}

int getcnt(int ind, int val){
	vector<int> &v = segtree[ind].vec;
	int l = v.size();
	 
	return (int) (v.end() - lower_bound(v.begin(), v.end(),val));
}

int query(int cur,int l,int r,int st,int e, int val){
	int c = 0;
	if(l>r)
		return 0;
	if(st>r||e<l)
		return 0;
	if(st<=l&&e>=r){
		return getcnt(cur,val);
	}
	int mid = l+(r-l)/2;
	int x1 = query(2*cur,l,mid,st,e,val);
	int x2 = query(2*cur+1,mid+1,r,st,e,val);
	return x1+x2;
}

int main(int argc, char const *argv[])
{
	int n;

	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>arr[i];

	constructTree(1,1,n);
	ll s = 0,c;
	for(int i=1;i<=n;i++){
		c = query(1,1,n,i+1,min(arr[i],n),i);
		// cout<<c<<endl;
		s+=c;
	}
	cout<<s<<endl;

	return 0;
}