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
	int n;
	cin>>n;

	int a[n];
	int s1=0,s2=0;
	int x;
	for(int i=0;i<n;i++){
		cin>>x;
		if(x<=0)
			s1+=x;
		else
			s2+=x;
	}

	cout<<abs(s2-s1)<<endl;
}