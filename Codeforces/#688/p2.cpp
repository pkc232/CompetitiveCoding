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
	string n;
	cin>>n;
	string t1=n;
	reverse(n.begin(),n.end());
	cout<<t1+n<<endl;
}