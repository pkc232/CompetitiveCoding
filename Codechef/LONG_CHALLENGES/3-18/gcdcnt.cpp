#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define ump unordered_map<int,int>
#define ITR unordered_map<int,int> :: iterator
using namespace std;

vector<int> prims;
int prim[100007];
int arr[100007];

ump tree[200007];

void merge(ump &u,ump &l,ump &r){
	u.clear();
	ITR it = l.begin();

	while(it!=l.end()){
		if(u.find(it->first)==u.end()){
				u[it->first]=0;
			}
		u[it->first]=it->second;
		if(r.find(it->first)!=r.end()){
			u[it->first]+=r[it->first];
		}
		it++;
	}

	it = r.begin();
	while(it!=r.end()){
		if(u.find(it->first)==u.end()){
				u[it->first]=it->second;
			}
		it++;
	}
}	

void createTree(int lo,int hi,int nd){

	if(lo>hi)
		return;

	if(lo==hi){
		tree[nd].clear();
		int val = arr[lo];
		int x = (sqrt(val));
		for(int i=1;i<=x;i++){

			if((val%i)==0){
			if(prim[i])
				tree[nd][i]=1;
			if(prim[val/i])
				tree[nd][val/i]=1;	
			}
		}
		return;
	}

	int mid = lo+(hi-lo)/2;

	createTree(lo,mid,2*nd);
	createTree(mid+1,hi,2*nd+1);

	merge(tree[nd],tree[2*nd],tree[2*nd+1]);
}

void sieve(){
	prim[1]=0;
	for(int i=2;i<=100002;i++){
		if(prim[i]==-1){
			prim[i]=1;
			prims.pb(i);
			for(int j=i+i;j<=100002;j+=i){
				prim[j]=0;
			}
		}
	}
}

int opert(ump &v,int g,int lo,int hi){
	ITR it = v.begin();
	int x= (sqrt(g));
	int nos= hi-lo+1;
	int ans=nos;
	for(int i=1;i<=x;i++){
		if(g%i==0){
			if(prim[i]){
				if(v.find(i)!=v.end()){
					// cout<<i<<" "<<v[i]<<endl;
					ans=min(ans,nos - v[i]);
				}
			}

			if(prim[g/i]){
				if(v.find(g/i)!=v.end())
					ans=min(ans,nos-v[g/i]);
			}
		}
	}

	return ans;
}

int query(int lo,int hi,int l,int r,int g,int pos){
	if(lo>hi)
		return 0;
	if(r<lo||l>hi)
		return 0;
	if(l<=lo&&r>=hi)
		return opert(tree[pos],g,lo,hi);

	int mid = lo+(hi-lo)/2;

	int s1 = query(lo,mid,l,r,g,2*pos);
	int s2 = query(mid+1,hi,l,r,g,2*pos+1);

	return s1+s2;


}
void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        // Leaf node
        arr[idx] = val;
        tree[node].clear();

        for(int i=1;i<=sqrt(val);i++){
        	if((val%i)==0){
        	if(prim[i])
        		tree[node][i]=1;
			if(prim[val/i])
				tree[node][val/i]=1;        		
        	}

        }
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
        merge(tree[node],tree[2*node],tree[2*node+1]);
    }
}



int main(){
	ios_base::sync_with_stdio(false);
	memset(prim,-1,sizeof(prim));
	sieve();

	int n;
	cin>>n;

	for(int i=1;i<=n;i++)
		cin>>arr[i];

	createTree(1,n,1);

	// cout<<tree[1][2]<<" "<<tree[1][3]<<" "<<tree[1][5]<<endl;

	int q,c,l,r,g,idx,val;
	cin>>q;
	while(q--){
		// cout<<tree[1][2]<<" "<<tree[1][3]<<" "<<tree[1][5]<<endl;
		cin>>c;
		if(c==2){
			cin>>l>>r>>g;
			cout<<query(1,n,l,r,g,1)<<endl;
		}
		else
		{
			cin>>idx>>val;
			update(1,1,n,idx,val);
		}
	}
}