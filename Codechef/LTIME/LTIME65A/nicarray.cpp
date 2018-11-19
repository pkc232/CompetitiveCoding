#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define pii pair<int,int>
#define large_int 2139062143
#define large_long_long_int 9187201950435737471
using namespace std;

#define NOV 100005

int gcd[51][51];

void preprocess(){
	for(int i=1;i<=50;i++){
		for(int j=1;j<=50;j++)
		{
			gcd[i][j] = __gcd(i,j);
		}
	}
}

ll dp[]

int main(){
	ios_base::sync_with_stdio(false);
	preprocess();
}