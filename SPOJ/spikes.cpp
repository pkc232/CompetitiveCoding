#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

char arr[50][50];
int N,M,J;



int isPossib(int r,int c,int s){
	if(s<0)
		return 0;
	if(r>N||r<=0||c>M||c<=0)
		return 0;
	if(arr[r][c]=='#')
		return 0;

}

int main(){
	ios_base::sync_with_stdio(false);

	

	cin>>N>>M>>J;

	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			cin>>arr[i][j];




}