#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

#define NOV 100005

int arr[105][105];
int contain[105][105];

int n,m;


int mxvol(int r,int c){
	
	// cout<<"R:"<<r<<" C:"<<c<<endl;

	// int ht = arr[r][c];
	int mxht = 0;
	int minht = INT_MAX;


	int lr = r-1,rr = r+1;
	while(lr>=1){
		mxht = max(mxht,arr[lr][c]);
		lr--;
	}

	minht = min(minht,mxht);
	// cout<<mxht<<" ";

	mxht = 0;
	while(rr<=n){
		mxht = max(mxht,arr[rr][c]);
		rr++;
	}

	// cout<<mxht<<" ";


	minht = min(minht,mxht);

	int lc = c-1,rc = c+1;
	mxht = 0;
	while(lc>=1){
		mxht = max(mxht,arr[r][lc]);
		lc--;
	}

	minht = min(minht,mxht);

	// cout<<mxht<<" ";

	mxht = 0;
	while(rc<=m){
		mxht = max(mxht,arr[r][rc]);
		rc++;
	}

	// cout<<mxht<<" ";

	// cout<<endl;
	minht = min(minht,mxht);

	// cout<<"MINHT "<<minht<<endl;

	
	// minht = min(minht,mxht);

	return minht;
	// if(minht>ht)
	// 	return ;
	// else
	// 	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);

	int t,i,j;
	cin>>t;

	while(t--){
		cin>>n>>m;

		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++){
				cin>>arr[i][j];
				contain[i][j] = arr[i][j];
			}
		int vol = 0;


		for(int p = 1;p<=n+m;p++){
			for(i=2;i<=n-1;i++){
				for(j=2;j<=m-1;j++){
				int p = mxvol(i,j);
				// cout<<"P "<<p<<endl;
				// contain[i][j] = min(contain[i][j],p);
				// cout<<i<<" "<<j<<" "<<mxvol(i,j)<<endl;
				// vol += mxvol(i,j);
				arr[i][j] = p;
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;	
			}
			cout<<endl<<endl;
		}
		for(i=1;i<=n;i++)
				for(j=1;j<=m;j++){
				// cout<<"P "<<p<<endl;
				vol += max(-contain[i][j]+arr[i][j],0);
				// cout<<i<<" "<<j<<" "<<mxvol(i,j)<<endl;
				// vol += mxvol(i,j);
			}

		cout<<vol<<endl;

	}


}