#include <bits/stdc++.h>
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

#define NOV 100005

ll powers_p[1000005][2];
set<pair<ll,ll> >hashes;


void precomputePower(){
	const ll p0 = 53, p1=57;
	powers_p[0][0] = powers_p[0][1] =1;
	for(int i=1;i<=1000000;i++){
		powers_p[i][0] = ((powers_p[i-1][0]*p0)%MOD);
		powers_p[i][1] = ((powers_p[i-1][1]*p1)%MOD);
	}
}

pair<ll,ll> compute_hash(string const& s) {
    
    const ll m = 1e9 + 9;
    ll hash_value0 = 0, hash_value1 = 0;
    int i=0;
    for (char c : s) {
        hash_value0 = (hash_value0 + (c - 'A' + 1) * powers_p[i][0]) % m;
        hash_value1 = (hash_value1 + (c - 'A' + 1) * powers_p[i][1]) % m;
        i++;
    }
    return mp(hash_value0,hash_value1);
}

void generateHashes(){
	ll firstHash = 0;
	for(int i=0;i<k;i++){
		firstHash = ((firstHash + (s[i]-'a'+1)*powers_p[i])%MOD);
	}
	ll p = 31;
	ll invrs = inv(p,MOD);
	if(present.find(firstHash)!=present.end())
		sum[0] = 1;
	int dbl =totstring.length();
	for(int i=1;i<len;i++){
		// cout<<"current firsthash"<<firstHash<<endl;
		firstHash = ((firstHash - (totstring[i-1]-'a'+1) + MOD)%MOD);
		firstHash = ((firstHash*invrs+MOD)%MOD);
		firstHash = ((firstHash + (totstring[i+k-1]-'a'+1)*powers_p[k-1])%MOD);
		// cout<<i<<" "<<firstHash<<endl;
		if(present.find(firstHash)!=present.end())
			sum[i%k]++;
	}

}

int main(){
	ios_base::sync_with_stdio(false);


}