#include <bits/stdc++.h>
#include <functional>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000009
#define pii pair<int,int>
#define large_int 2139062143
#define large_long_long_int 9187201950435737471

using namespace std;

#define NOV 1000005
string s;
string s1,s2;
int lenS,lenS1;

ll powers_p[1000005];

ll inv(ll a, ll b){
 return 1<a ? b - inv(b%a,a)*b/a : 1;
}

void precomputePower(){
	const ll p = 31;
	powers_p[0] = 1;
	for(int i=1;i<=1000000;i++){
		powers_p[i] = ((powers_p[i-1]*p)%MOD);
	}
}

ll compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

int findinmiddle(){
	ll firstHash = 0;
	for(int i=0;i<lenS1;i++){
		firstHash = ((firstHash + (s1[i]-'a'+1)*powers_p[i])%MOD);
	}
	ll curr = firstHash;
	for(int i=lenS1;i<lenS-1;i++){
		curr = (curr-(s[i-lenS1]-'a'+1) + MOD)%MOD;
		curr 
	}
}


int main(){
	ios_base::sync_with_stdio(false);

	
	cin>>s;
	lenS = s.length();
	int lo = 0,hi = len;
	int ans = 0;
	int mid;
	
	while(lo<=hi){
		mid = lo +(hi-lo)/2;

		s1 = s.substr(0,mid);
		s2 = s.substr(len-mid,len);
		if(s1!=s2){
			hi = mid-1;
		}
		else
		{
			lenS1 = mid;
			if(findinmiddle()){
				ans = max(ans,mid);
				lo = mid+1;
			}
			else
				hi = mid-1;
		}

	}

}