#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;


struct node{
	int plmx[104];
	int plmn[104];
	int msmx[104];
	int msmn[104];
	int cnt;
	node* lc;
	node* rc;

	node(){
		memset(mx,0,sizeof(mx));
		memset(mn,0,sizeof(mn));
		cnt=0;
		lc=rc=NULL;
	}
};
string input;
int plus,minus;.


int maxVal(int op){
	int l=input.size();

	stack<node*> s;

	for(int i=0;i<l;i++){
		if(input[i]>='0'&&input[i]<='9')
		{
			node* temp = new node;
			temp->cnt=0;
			temp->lc=temp->rc=NULL;
			temp->plmx[0]=temp->plmn[0]=temp->msmx[0]=temp->msmn[0]=input[i]-'0';
		}
		else if(input[i]==')')
		{
			node* temp = new node();
			node* r=temp->rc = s.top();	s.pop();
			node* l=temp->lc = s.top();	s.pop();

			temp->cnt=l->cnt+r->cnt+1;

			for(int ii=0;ii<=102;ii++){

				for(int jj=0;jj<=102;jj++){
					temp->plmx
				}
			}


		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
	cin>>input;
	
}