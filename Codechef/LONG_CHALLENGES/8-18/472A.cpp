#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

int isPrime[1000007];
void sieve(){
	isPrime[1]=0;
	for(int i=2;i<=1000005;i++){
		if(isPrime[i]==-1)
		{
			isPrime[i] = 1;
			for(int j=i+i;j<=1000005;j+=i)
				isPrime[j] = 0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;

}