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

int nbits[NOV];

int cntbits(int num){
	int c = 0;
	while(num){
		if(num&1)
			c++;
		num>>=1;
	}
	return c;
}

void preprocess(){
	for(int i=1;i<NOV;i++){
		nbits[i] = cntbits(i);
	}
}

int sameBits(int a,int b){
	return nbits[a]==nbits[b];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	preprocess();
	int t;
	cin>>t;
	int a,b,c,cnt;
	while(t--){
		cin>>a>>b>>c;
		cnt = 0;
		for(int i=1;i<=c-1;i++){
			if(sameBits(a,i)&&sameBits(b,c-i))
				cnt++;
		}
		cout<<cnt<<endl;
	}
}