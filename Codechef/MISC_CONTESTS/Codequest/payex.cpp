#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll G[105][105];
int vis[105];
int from[105];
int src;
int sink;
int n,vn;
ll arr[105];
ll sum=0;

ll bfs(){
	queue<int> Q;
	Q.push(src);

	fill(from+1,from+n+1,-1);
	fill(vis+1,vis+n+1,0);

	vis[src]=1;

	

	int where,prev;

	while(!Q.empty()){
		where = Q.front();
		Q.pop();

		for(int i=1;i<=n;i++){
			if(G[where][i]){
				if(!vis[i]){
					Q.push(i);
					vis[i]=1;
					from[i]=where;
				}
				if(i==sink)
					goto outwhile;
			}
		}
	}

	//finding out the min capacity edge along the path

	outwhile:
		ll path_cap = LONG_MAX;
		where = sink;

		while(from[where]>-1){
			prev=from[where];
			path_cap=min(path_cap,G[prev][where]);
			where = prev;
		}

		if(path_cap==LONG_MAX)
			return 0;

	//updating the residual network

		where = sink;
		while(from[where]>-1){
			prev = from[where];
			G[prev][where]-= path_cap;
			G[where][prev]+=path_cap;
			where = prev;
		}
		return path_cap;
}

ll maxFlow(){
	ll res=0;
	ll path_cap;
	while(1){
		path_cap = bfs();
		// cout<<"idhr\n";
		if(path_cap==0)
			break;
		else
			res+=path_cap;
	}
	return res;
}

int check(ll x){
	sum=0;
	for(int i=1;i<=vn;i++){
		if(arr[i]>0){
			G[vn+1][i]=arr[i];
			sum+=arr[i];
		}
		else if(arr[i]<0)
			G[i][vn+2]=-arr[i];
	}

	for(int i=1;i<=n-2;i++){
		for(int j=1;j<=n-2;j++)
			if(i!=j)
			G[i][j]=x;
	}

	// for(int i=1;i<=n;i++)
	// {
	// 	for(int j=1;j<=n;j++)
	// 		cout<<G[i][j]<<" ";
	// 	cout<<endl;
	// }
	ll mxfl =maxFlow(); 
	// cout<<"Current "<<mxfl<<endl;
	return mxfl==sum;
}

int main(int argc, char const *argv[])
{
	cin>>vn;

	n=vn+2;
	src = n-1;
	sink=n;
	for(int i=1;i<=vn;i++){
		cin>>arr[i];
		if(arr[i]>0){
			G[vn+1][i]=arr[i];
			sum+=arr[i];
		}
		else if(arr[i]<0)
			G[i][vn+2]=-arr[i];
	}

	ll lo=0,hi=10000007;
	ll ans=LONG_MAX;
	while(lo<=hi){
		ll mid= lo+(hi-lo)/2;
		// cout<<"hello " <<mid<<endl;
		if(check(mid))
		{
			ans=min(ans,mid);
			hi=mid-1;
		}
		else
			lo=mid+1;
		// break;
	}

	cout<<ans<<endl;




	// cout<<maxFlow()<<endl;
	
	return 0;
}