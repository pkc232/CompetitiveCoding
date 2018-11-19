#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

long long int sum(long long int n)
{
    long long int root = sqrt(n);
    long long int ans = 0;
 	set<ll> s;
    for (int i = 1; i <= root; i++){
        // ans += n / i;
    	s.insert(n/i);
    } 
     
    // ans = 2 * ans - (root * root);
    return (ll)s.size();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	cout<<sum(n)<<endl;
}