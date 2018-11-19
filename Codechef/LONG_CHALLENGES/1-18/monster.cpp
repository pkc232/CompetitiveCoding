#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
using namespace std;

ll h[3000000];

struct trieNode{
	vector<int> indices;
	trieNode* arr[2];
};

void initialize(trieNode* rt){
	rt->arr[0]=NULL;
	rt->arr[1]=NULL;
}

void insertNd(trieNode* root,int ind,int &act){

	if(ind==0){
		root->indices.pb(act);
		return;
	}
	int rem=(ind&1);
	if(root->arr[rem]==NULL){
		root->arr[rem]=new trieNode;
		initialize(root->arr[rem]);
	}
	ind=(ind>>1);
	insertNd(root->arr[rem],ind,act);
}

int dead(trieNode* root,ll x,ll y){
	if(root==NULL)
		return 0;
	int c=0;
	for(int i=0;i<root->indices.size();i++){
		//if(h[root->indices[i]]>0)
		{
			h[root->indices[i]]-=y;
			if(h[root->indices[i]]<=0){
				// cout<<h[root->indices[i]]<<endl;
				// cout<<root->indices[i]<<" killed\n";
				root->indices.erase(root->indices.begin()+i);
				c++;
			}
		}
	}
	// cout<<x<<endl;
	if(x==0)
		return c;
	int rem = (x&1);
	x=(x>>1);
	if(rem){
	c+=dead(root->arr[rem],x,y);
	c+=dead(root->arr[0],x,y);		
	}
	else
	{
		c+=dead(root->arr[rem],x,y);
	}
	return c;

}

int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	int n,i,j;
	cin>>n;
	
	trieNode* root=new trieNode;
	initialize(root);

	int cnt=n;
	for(i=0;i<n;i++){
		insertNd(root,i,i);
		cin>>h[i];
	}

	int q;
	cin>>q;
	ll x,y;
	while(q--){
		cin>>x>>y;
		cnt-=dead(root,x,y);
		cout<<cnt<<endl;
	}


	return 0;
}
