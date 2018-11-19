#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
using namespace std;


int prim[1000007];

void sieve(){
	memset(prim,-1,sizeof(prim));
	prim[1]=0;
	for(int i=2;i<=1000001;i++)
	{
		if(prim[i]==-1){
			prim[i]=1;
			for(int j=i+i;j<=1000001;j+=i)
				prim[j]=0;
		}
	}
}

int main(int argc, char const *argv[])
{
	
	return 0;
}