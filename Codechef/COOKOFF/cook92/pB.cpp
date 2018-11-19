#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);



	int t;
	cin>>t;

	while(t--){
		int n,m,i,j;
		cin>>n>>m;

		ll a[n+2][m+2];
		memset(a,-1,sizeof(a));
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
			{
				// a[i][j]=-444;
				cin>>a[i][j];
				if(a[i][j]==-1){
					a[i][j]=max(a[i][j-1],a[i-1][j]);

					// if(i==1&&j==1)
					// 	a[i][j]=1;
				}
				
			}

		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++)
				if(a[i][j]<a[i][j-1])
					goto no;
		}


		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
				if(a[j][i]<a[j-1][i])
					goto no;
			
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++)
				cout<<a[i][j]<<" ";
			cout<<endl;
		}
		continue;

		no:
		cout<<-1<<endl;

		}
	
}