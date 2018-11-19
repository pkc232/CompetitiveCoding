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

#define NOV 1000005

int n,k;
string s;
int len;
string totstring;

ll powers_p[NOV];
int sum[NOV];

unordered_map<string,int> dict;
unordered_set<ll> present;

void precomputePower(){
	const ll p = 31;
	powers_p[0] = 1;
	for(int i=1;i<=1000000;i++){
		powers_p[i] = ((powers_p[i-1]*p)%MOD);
	}
}

ll inv(ll a, ll b){
 return 1<a ? b - inv(b%a,a)*b/a : 1;
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

ll hashval(string st){
	ll firstHash = 0;
	for(int i=0;i<k;i++){
		firstHash = ((firstHash + (st[i]-'a'+1)*powers_p[i])%MOD);
	}
	return firstHash;
}

vector<int> ans;

int finalcheck(int pos){
	string sub;
	ans.clear();
	unordered_set<string> done;
	for(int i=0;i<n;i++){
		sub = totstring.substr(pos,k);
		// cout<<sub<<" "<<pos<<" "<<pos+k<<endl;
		if(done.find(sub)!=done.end())
			return 0;
		done.insert(sub);
		ans.pb(dict[sub]);
		pos+=k;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	precomputePower();
	cin>>n>>k;
	
	cin>>s;
	len = s.length();

	int g;
	cin>>g;
	string st;
	ll tot = 0;
	ll hvl;
	totstring = s;
	totstring += s;

	for(int i=1;i<=g;i++){
		cin>>st;
		dict[st] = i;
		hvl = hashval(st);
		present.insert(hvl);
		// cout<<st<<" "<<hvl<<endl;
	}
	generateHashes();
	
	for(int i=0;i<k;i++){
		// cout<<sum[i]<<" ";
		if(sum[i] >= n){
			if(finalcheck(i)){
				cout<<"YES\n";
				for(int p:ans)
					cout<<p<<" ";
				cout<<endl;
				return 0;
			}
		}
	}

	cout<<"NO\n";

}