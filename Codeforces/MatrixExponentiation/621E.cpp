#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define MOD 1000000007
#define mp make_pair
using namespace std;

ll cnt[12];
ll n,b,k,x;

ll matrix[12][12];

int isMod(ll i,ll j){
	return (((i*10+j)%x)==k);
}

void construct(){
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
				matrix[i][j]=isMod(i,j);
		}
	}
}

void multiply(ll m1[12][12],ll m2[12][12]){
	
}


int main(int argc, char const *argv[])
{
	memset(cnt,0,sizeof(cnt));

	
	cin>>n>>b>>k>>x;
	
	int num;
	for(int i=1;i<=n;i++)
	{
		cin>>num;
		cnt[num]++;
	}

	construct();

	return 0;
}