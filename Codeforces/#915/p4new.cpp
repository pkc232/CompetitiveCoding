#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
using namespace std;


int gr[505][505];
int vis[505];
int ret[505];
int n;
int par[505];
int s,t;
bool ans= 0;
bool isCyclic(int u,int fl){
	vis[u]=1;
	for(int i=1;i<=n;i++){
		if(ans)
			return 1;
		if(fl)
		cout<<u<<" "<<i<<endl;
		if(!gr[u][i])
			continue;
		if(vis[i]){
			if(ret[i])
				continue;
			if(fl==1){
				s=i,t=u;
			}
			cout<<u<<" "<<i<<"me cycle hai\n";
			return true;
		}
		else
		{
			par[i]=u;
			ans|=isCyclic(i,fl);
		}
	}
	ret[u]=1;
	return ans;
}
bool allVis(){
	for(int i=1;i<=n;i++)
		if(!vis[i])
			return 0;
	return 1;
}


bool CycleF(int fl){
	bool ans_=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			ans=0;
			ans_|=isCyclic(i,fl);
		}
	}
	return ans_;
}
void check(){

	memset(vis,0,sizeof(vis));
	memset(ret,0,sizeof(ret));
	if(CycleF(1)){
		cout<<t<<" "<<s<<endl;
		memset(vis,0,sizeof(vis));
		memset(ret,0,sizeof(ret));
		gr[t][s]=0;
		if(!CycleF(0))
		{
			cout<<"YES\n";
			return;
		}
		gr[t][s]=1;

		while(t!=s){
			cout<<t<<" "<<s<<endl;
			memset(vis,0,sizeof(vis));
			memset(ret,0,sizeof(ret));
			gr[par[t]][t]=0;
			cout<<par[t]<<"=> "<<t<<endl;
			if(!CycleF(0)){
				//if(allVis())
				{	
				cout<<"YES\n";
				return;
				}
			}
			gr[par[t]][t]=1;
			t=par[t];
		}
		cout<<"NO\n";
	}
	else
		cout<<"YES\n";
}


int main(int argc, char const *argv[])
{
	int m,x,y;
	cin>>n>>m;
	memset(gr,0,sizeof(gr));
	while(m--){
		cin>>x>>y;
		gr[x][y]=1;
	}
	check();
	return 0;
}