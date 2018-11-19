#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define pii pair<int,int>
using namespace std;

#define NOV 100005


int main(){
	ios_base::sync_with_stdio(false);

	int x,y,z,t1,t2,t3;
	cin>>x>>y>>z>>t1>>t2>>t3;

	int tim1 = abs(x-y)*t1;

	int tim2 = abs(x-z)*t2+abs(x-y)*t2+3*t3;

	if(tim1>=tim2)
		cout<<"YES\n";
	else
		cout<<"NO\n";
}