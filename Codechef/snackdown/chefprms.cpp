#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

int finres[300];
int isSemiPrime[300];
int isPrime[300];

int checkPrime(int n){

	if(isPrime[n]!=-1)
		return isPrime[n];

	int p = sqrt(n);
	for(int i=2;i<=p;i++){
		if((n%i==0))
			return isPrime[n] = 0;
	}
	return isPrime[n] = 1;
} 

void findSemiPrimes(){
	for(int i=1;i<=200;i++){
		if(checkPrime(i)){
			for(int j=i+1;j*i<=205;j++){
				if(checkPrime(j)){
					isSemiPrime[i*j] = 1;
				}
			}	
		}
	}
}

void preprocess(){
	findSemiPrimes();
	for(int i=1;i<=201;i++){
		for(int j=i;j+i<=201;j++){
			if(isSemiPrime[i]&&isSemiPrime[j])
				finres[i+j]=1;
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	memset(isPrime,-1,sizeof(isPrime));
	isPrime[1]=0;
	preprocess();

	// for(int i=1;i<=201;i++)
	// 	if(isPrime[i])
	// 		cout<<i<<" ";

	// cout<<"SemiPrimes\n";
	// for(int i=1;i<=201;i++)
	// 	if(isSemiPrime[i])
	// 		cout<<i<<" ";
	int t,n;
	cin>>t;

	while(t--){
		cin>>n;
		if(finres[n])
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}