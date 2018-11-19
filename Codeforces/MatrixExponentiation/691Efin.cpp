#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define MOD 1000000007
#define mp make_pair
using namespace std;


int n;
ll arr[105];
ll gr[105][105];



int bits(ll num){
	int c=0;
	while(num){
		c+=(num%2);
		num/=2;
	}
	return ((c%3)==0);
}



void multiply(ll m1[105][105],ll m2[105][105]){

	ll mult[105][105];

	// memset(mult,0,sizeof(mult));

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			mult[i][j]=0;
			for(int k=1;k<=n;k++){
				mult[i][j]+=(((m1[i][k])*(m2[k][j])));
				mult[i][j]%=MOD;
			}
		}
	}

	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			m1[i][j]=mult[i][j];
}

void matrix_expo(ll k,ll ans[105][105]){
	while(k>0){
		if(k&1)
			multiply(ans,gr);
		multiply(gr,gr);
		k>>=1;
	}
}

int main(int argc, char const *argv[])
{
	ll k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>arr[i];

	if(k==1)
	{
		cout<<n<<endl;
		return 0;
	}

	ll ans[105][105];
	// memset(ans,0,sizeof(ans));


	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans[i][j]=0;
			gr[i][j]=(bits((arr[i]^arr[j])));
			if(i==j)
			ans[i][j]=1;
		}
	}


	matrix_expo(k-1,ans);

	ll c=0;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			c+=ans[i][j];
			c%=MOD;
		}
	}

	cout<<c<<endl;







	return 0;
}