#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define pii pair<int,int>
using namespace std;

#define NOV 100005

int coprime[52][52];
int isPrime[52];
int isPresent[52];
int arr[52];
int vis[52];
vector<int> gr[52];

int check(int x){
	int p =sqrt(x);
	for(int i=2;i<=p;i++){
		if(x%i==0)
			return 0;
	}
	return 1;
}

void preprocess(){
	int x;
	for(int i=2;i<=50;i++){
		for(int j=2;j<=50;j++){
			x = __gcd(i,j);
			if(x==1)
				coprime[i][j] = 1;
		}

		if(check(i))
			isPrime[i] = 1;
	}
}

void dfs(int u){
	vis[u] = 1;
	// cout<<u<<" "<<endl;
	for(int v:gr[u]){
		if(!vis[v])
			dfs(v);
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	memset(coprime,0,sizeof(coprime));
	preprocess();
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		memset(isPresent,0,sizeof(isPresent));
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			isPresent[arr[i]] = 1;
			gr[i].clear();
		}

		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(coprime[arr[i]][arr[j]])
				{
					gr[i].pb(j);
					gr[j].pb(i);
				}
			}
		}

		memset(vis,0,sizeof(vis));
		int c = 0;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				dfs(i);
				c++;
			}
		}

		if(c==1)
		{
			cout<<0<<endl;
			for(int i=1;i<=n;i++)
				cout<<arr[i]<<" ";
			cout<<endl;
		}
		else
		{
			for(int i=50;i>=2;i--){
				if(isPrime[i]&&!isPresent[i]){
					arr[1] = i;
					break;
				}
			}
			cout<<1<<endl;
			for(int i=1;i<=n;i++)
				cout<<arr[i]<<" ";
			cout<<endl;
		}

	}
}